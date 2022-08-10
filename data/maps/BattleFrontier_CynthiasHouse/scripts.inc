.set LOCALID_CYNTHIA, 1

BattleFrontier_CynthiasHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_CynthiasHouse_OnFrame
	.byte 0

BattleFrontier_CynthiasHouse_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_CynthiasHouse_EventScript_CynthiaEncounter
	.2byte 0


BattleFrontier_CynthiasHouse_EventScript_CynthiaEncounter_Cancel::
	end


BattleFrontier_CynthiasHouse_EventScript_CynthiaEncounter::
	setvar VAR_TEMP_0, 1
	goto_if_set TRAINER_FLAG_CYNTHIA_1, BattleFrontier_CynthiasHouse_EventScript_CynthiaEncounter_Cancel
	lockall
	playbgm DP_SEQ_EYE_CHAMP, TRUE
	applymovement LOCALID_CYNTHIA, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CYNTHIA, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_CYNTHIA, BattleFrontier_CynthiasHouse_WalkToPlayer
	waitmovement 0
	goto_if_set FLAG_ENCOUNTERED_CYNTHIA, BattleFrontier_CynthiasHouse_EventScript_CynthiaRetry
	setflag FLAG_ENCOUNTERED_CYNTHIA
	msgbox BattleFrontier_Text_CynthiaIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_CynthiasHouse_EventScript_CynthiaEncounter_Decline
	goto_if_eq VAR_RESULT, YES, BattleFrontier_CynthiasHouse_EventScript_CynthiaEncounter_Accept
	end


BattleFrontier_CynthiasHouse_EventScript_CynthiaEncounter_Decline::
	msgbox BattleFrontier_Text_CynthiaIntro_No, MSGBOX_AUTOCLOSE
	savebgm MUS_DUMMY
	fadedefaultbgm
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 20
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 11
	releaseall
	end


BattleFrontier_CynthiasHouse_EventScript_CynthiaEncounter_Accept::
	msgbox BattleFrontier_Text_CynthiaIntro_Yes, MSGBOX_AUTOCLOSE
	waitmessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	trainerbattle_no_intro TRAINER_CYNTHIA_1, BattleFrontier_Text_CynthiaDefeat
	goto BattleFrontier_CynthiasHouse_EventScript_CynthiaDefeated
	end


BattleFrontier_CynthiasHouse_EventScript_Cynthia::
	applymovement LOCALID_CYNTHIA, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_unset FLAG_RECEIVED_CYNTHIA_EGG, BattleFrontier_CynthiasHouse_EventScript_CynthiaEggNotReceived
	goto_if_set FLAG_SHOWN_OLD_SEA_MAP, BattleFrontier_CynthiasHouse_EventScript_CynthiaRematch1
	msgbox BattleFrontier_Text_CynthiaOldSeaMapDesc, MSGBOX_AUTOCLOSE
	releaseall
	end


BattleFrontier_CynthiasHouse_EventScript_CynthiaRetry::
	msgbox BattleFrontier_Text_CynthiaIntro2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_CynthiasHouse_EventScript_CynthiaEncounter_Decline
	goto_if_eq VAR_RESULT, YES, BattleFrontier_CynthiasHouse_EventScript_CynthiaEncounter_Accept
	end


BattleFrontier_CynthiasHouse_EventScript_CynthiaRematch1::
	goto_if_set FLAG_SHOWN_MYSTIC_TICKET, BattleFrontier_CynthiasHouse_EventScript_CynthiaRematch2
	goto_if_unset TRAINER_FLAG_CYNTHIA_2, BattleFrontier_CynthiasHouse_EventScript_CynthiaRematch1_Battle
	msgbox BattleFrontier_Text_CynthiaMysticTicketDesc, MSGBOX_AUTOCLOSE
	end


BattleFrontier_CynthiasHouse_EventScript_CynthiaIntro3::
	setvar VAR_TEMP_0, 2
	msgbox BattleFrontier_Text_CynthiaIntro3, MSGBOX_DEFAULT
	return


BattleFrontier_CynthiasHouse_EventScript_CynthiaRematch1_Battle::
	lockall
	playbgm DP_SEQ_EYE_CHAMP, TRUE
	call_if_eq VAR_TEMP_0, 1, BattleFrontier_CynthiasHouse_EventScript_CynthiaIntro3
	msgbox BattleFrontier_Text_CynthiaBeMyOpponent, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_CynthiasHouse_EventScript_CynthiaRematch_Decline
	msgbox BattleFrontier_Text_CynthiaIntro3_Yes, MSGBOX_AUTOCLOSE
	savebgm MUS_DUMMY
	fadedefaultbgm
	trainerbattle_no_intro TRAINER_CYNTHIA_2, BattleFrontier_Text_CynthiaDefeat
	goto BattleFrontier_CynthiasHouse_EventScript_CynthiaDefeated2
	end


BattleFrontier_CynthiasHouse_EventScript_CynthiaRematch2::
	goto_if_unset TRAINER_FLAG_CYNTHIA_3, BattleFrontier_CynthiasHouse_EventScript_CynthiaRematch2_Battle
	msgbox BattleFrontier_Text_CynthiaAuroraTicketDesc, MSGBOX_AUTOCLOSE
	releaseall
	end


BattleFrontier_CynthiasHouse_EventScript_CynthiaRematch2_Battle::
	lockall
	playbgm DP_SEQ_EYE_CHAMP, TRUE
	call_if_eq VAR_TEMP_0, 1, BattleFrontier_CynthiasHouse_EventScript_CynthiaIntro3
	msgbox BattleFrontier_Text_CynthiaBeMyOpponent, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_CynthiasHouse_EventScript_CynthiaRematch_Decline
	msgbox BattleFrontier_Text_CynthiaIntro3_Yes, MSGBOX_AUTOCLOSE
	savebgm MUS_DUMMY
	fadedefaultbgm
	trainerbattle_no_intro TRAINER_CYNTHIA_3, BattleFrontier_Text_CynthiaDefeat
	goto BattleFrontier_CynthiasHouse_EventScript_CynthiaDefeated3
	end


BattleFrontier_CynthiasHouse_EventScript_CynthiaRematch_Decline::
	msgbox BattleFrontier_Text_CynthiaIntro3_No, MSGBOX_AUTOCLOSE
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end


BattleFrontier_CynthiasHouse_EventScript_CynthiaDefeated::
	msgbox BattleFrontier_Text_CynthiaPostBattle
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox BattleFrontier_Text_CynthiaRewardEgg
	goto BattleFrontier_CynthiasHouse_EventScript_CynthiaGiveEgg
	end


BattleFrontier_CynthiasHouse_EventScript_CynthiaGiveEgg::
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, BattleFrontier_CynthiasHouse_EventScript_CynthiaNoRoomForEgg
	setflag FLAG_RECEIVED_CYNTHIA_EGG
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_Text_ReceivedTheEgg
	waitfanfare
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	msgbox BattleFrontier_Text_CynthiaOldSeaMapDesc
	specialvar VAR_GIFT_UNUSED_1, CalculatePlayerPartyCount
	giveegg SPECIES_TOGEPI, TRUE
	setmonmetlocation VAR_GIFT_UNUSED_1, 0xFC
	vgoto_if_eq VAR_GIFT_UNUSED_1, 1, BattleFrontier_CynthiasHouse_Egg_Slot1
	vgoto_if_eq VAR_GIFT_UNUSED_1, 2, BattleFrontier_CynthiasHouse_Egg_Slot2
	vgoto_if_eq VAR_GIFT_UNUSED_1, 3, BattleFrontier_CynthiasHouse_Egg_Slot3
	vgoto_if_eq VAR_GIFT_UNUSED_1, 4, BattleFrontier_CynthiasHouse_Egg_Slot4
	vgoto_if_eq VAR_GIFT_UNUSED_1, 5, BattleFrontier_CynthiasHouse_Egg_Slot5
	end


BattleFrontier_CynthiasHouse_Egg_Slot1:
	setmonmove 1, 2, MOVE_EXTRASENSORY
	release
	return

BattleFrontier_CynthiasHouse_Egg_Slot2::
	setmonmove 2, 2, MOVE_EXTRASENSORY
	release
	return

BattleFrontier_CynthiasHouse_Egg_Slot3:
	setmonmove 3, 2, MOVE_EXTRASENSORY
	release
	return

BattleFrontier_CynthiasHouse_Egg_Slot4:
	setmonmove 4, 2, MOVE_EXTRASENSORY
	release
	return

BattleFrontier_CynthiasHouse_Egg_Slot5:
	setmonmove 5, 2, MOVE_EXTRASENSORY
	release
	return


BattleFrontier_CynthiasHouse_EventScript_CynthiaDefeated2::
	msgbox BattleFrontier_Text_CynthiaPostBattle
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox BattleFrontier_Text_CynthiaReward2
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	msgbox BattleFrontier_Text_CynthiaMysticTicketDesc
	release
	end


BattleFrontier_CynthiasHouse_EventScript_CynthiaDefeated3::
	msgbox BattleFrontier_Text_CynthiaPostBattle
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox BattleFrontier_Text_CynthiaReward2
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	msgbox BattleFrontier_Text_CynthiaAuroraTicketDesc
	release
	end


BattleFrontier_CynthiasHouse_EventScript_CynthiaEggNotReceived::
	msgbox BattleFrontier_Text_CynthiaRewardEgg
	goto BattleFrontier_CynthiasHouse_EventScript_CynthiaGiveEgg
	end


BattleFrontier_CynthiasHouse_EventScript_CynthiaNoRoomForEgg::
	msgbox BattleFrontier_Text_CynthiaNoRoomForThisEgg
	release
	end


BattleFrontier_CynthiasHouse_WalkToPlayer:
	walk_down
	walk_down
	step_end


BattleFrontier_Text_CynthiaIntro:
	.string "???: What's this?\p"
	.string "Those intense eyes…\p"
	.string "The way you carry yourself leads me\n"
	.string "to presume that you are a remarkable\l"
	.string "POKéMON Trainer.\p"
	.string "What's your name?\p"
	.string "…\p"
	.string "OK. I'll remember that!\p"
	.string "{PLAYER}, nice to meet you.\p"
	.string "I'm Cynthia.\n"
	.string "I'm a POKéMON Trainer, too, like you.\p"
	.string "I have an insatiable curiosity for\n"
	.string "researching POKéMON myths.\p"
	.string "I recently became the CHAMPION of\n"
	.string "the SINNOH region and was invited\l"
	.string "here to the BATTLE FRONTIER.\p"
	.string "In order to get to know each other\n"
	.string "better as POKéMON Trainers, I would\l"
	.string "like our POKéMON to have a match.\p"
	.string "Would you care to be my opponent?$"

BattleFrontier_Text_CynthiaIntro_No:
	.string "Ha ha. You prefer to take things\n"
	.string "slowly, am I right?\p"
	.string "When you're ready, come and talk to me.\n"
	.string "I'll be happy to see you.$"

BattleFrontier_Text_CynthiaIntro_Yes:
	.string "Before I send out my POKéMON,\n"
	.string "my heart always begins to race…\p"
	.string "Interesting…\p"
	.string "My POKéMON in their POKé BALLs are\n"
	.string "radiating a happy feeling.\p"
	.string "Are you the reason?\n"
	.string "What are you?$"

BattleFrontier_Text_CynthiaIntro2:
	.string "Oh. You've had a chance to get ready?\p"
	.string "I do want our POKéMON to have\n"
	.string "a match…\p"
	.string "Are you prepared to be my opponent?$"

BattleFrontier_Text_CynthiaDefeat:
	.string "My heart is pounding so hard because I\n"
	.string "had such a heated battle with you.\p"
	.string "You are a really great Trainer!!$"

BattleFrontier_Text_CynthiaPostBattle:
	.string "That was beyond my expectation!\n"
	.string "What an exceptional battle!\p"
	.string "Here, let me heal your POKéMON\n"
	.string "for you.$"

BattleFrontier_Text_CynthiaRewardEgg:
	.string "As a reward for defeating me,\n"
	.string "I would like you to have these.$"

BattleFrontier_Text_CynthiaReward2:
	.string "As a reward for defeating me again,\n"
	.string "I would like you to have this.$"

BattleFrontier_Text_ReceivedTheEgg:
	.string "{PLAYER} received the EGG.$"

BattleFrontier_Text_CynthiaNoRoomForThisEgg:
	.string "Oh? You have too many POKéMON.\n"
	.string "There's no room for this EGG…\p"
	.string "Come back when you have room.$"

BattleFrontier_Text_CynthiaAuroraTicketDesc:
	.string "That AURORA TICKET can be used\n"
	.string "at the FERRY in LILYCOVE.\p"
	.string "I've heard rumors that a rare and\n"
	.string "powerful POKéMON can be found there.$"

BattleFrontier_Text_CynthiaMysticTicketDesc:
	.string "That MYSTIC TICKET can be used\n"
	.string "at the FERRY in LILYCOVE.\p"
	.string "I've heard rumors that a rare and\n"
	.string "powerful POKéMON can be found there.$"

BattleFrontier_Text_CynthiaOldSeaMapDesc:
	.string "Try showing that OLD SEA MAP\n"
	.string "at the FERRY in LILYCOVE.\p"
	.string "Who knows where it might lead!$"

BattleFrontier_Text_CynthiaIntro3:
	.string "How terrific to see you again!\p"
	.string "I've got to tell you…\p"
	.string "My POKéMON are excited to\n"
	.string "battle yours.$"

BattleFrontier_Text_CynthiaBeMyOpponent:
	.string "Would you care to be my opponent?$"

BattleFrontier_Text_CynthiaIntro3_Yes:
	.string "This will be such fun!\n"
	.string "No holds barred!$"

BattleFrontier_Text_CynthiaIntro3_No:
	.string "Oh, what a pity.\p"
	.string "Elsewhere in HOENN, I feel like I'm\n"
	.string "on holiday.\l"
	.string "I forget about battling!\p"
	.string "But here at the BATTLE FRONTIER,\n"
	.string "I feel like getting worked up with\l"
	.string "a good battle.$"
