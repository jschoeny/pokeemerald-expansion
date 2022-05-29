BattleFrontier_CynthiasHouse_MapScripts::
	.byte 0


BattleFrontier_CynthiasHouse_EventScript_Cynthia::
	trainerbattle_single TRAINER_CYNTHIA_1, BattleFrontier_Text_CynthiaIntro, BattleFrontier_Text_CynthiaDefeat, BattleFrontier_CynthiasHouse_EventScript_CynthiaDefeated
	goto_if_unset FLAG_RECEIVED_CYNTHIA_EGG, BattleFrontier_CynthiasHouse_EventScript_CynthiaEggNotReceived
	goto_if_set FLAG_SHOWN_AURORA_TICKET BattleFrontier_CynthiasHouse_EventScript_CynthiaRematch1
	msgbox BattleFrontier_Text_CynthiaAuroraTicketDesc, MSGBOX_AUTOCLOSE
	end


BattleFrontier_CynthiasHouse_EventScript_CynthiaRematch1::
	goto_if_set FLAG_SHOWN_MYSTIC_TICKET BattleFrontier_CynthiasHouse_EventScript_CynthiaRematch2
	trainerbattle_single TRAINER_CYNTHIA_2, BattleFrontier_Text_CynthiaIntro2, BattleFrontier_Text_CynthiaDefeat, BattleFrontier_CynthiasHouse_EventScript_CynthiaDefeated
	msgbox BattleFrontier_Text_CynthiaHopeToBattleAgain, MSGBOX_AUTOCLOSE
	end


BattleFrontier_CynthiasHouse_EventScript_CynthiaRematch2::
	trainerbattle_single TRAINER_CYNTHIA_3, BattleFrontier_Text_CynthiaIntro2, BattleFrontier_Text_CynthiaDefeat, BattleFrontier_CynthiasHouse_EventScript_CynthiaDefeated
	msgbox BattleFrontier_Text_CynthiaHopeToBattleAgain, MSGBOX_AUTOCLOSE
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
	giveitem ITEM_AURORA_TICKET
	msgbox BattleFrontier_Text_CynthiaAuroraTicketDesc
	specialvar VAR_GIFT_UNUSED_1, CalculatePlayerPartyCount
	giveegg SPECIES_TOGEPI
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
	msgbox BattleFrontier_Text_CynthiaMysticTicketDesc
	release
	end


BattleFrontier_CynthiasHouse_EventScript_CynthiaDefeated3::
	msgbox BattleFrontier_Text_CynthiaPostBattle
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox BattleFrontier_Text_CynthiaReward2
	giveitem ITEM_OLD_SEA_MAP
	msgbox BattleFrontier_Text_CynthiaOldSeaMapDesc
	setflag FLAG_HIDE_CYNTHIA
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
	.string "I hope you're ready!$"

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
	.string "at the FERRY.\p"
	.string "I've heard rumors that a rare and\n"
	.string "powerful POKéMON can be found there.$"

BattleFrontier_Text_CynthiaMysticTicketDesc:
	.string "That MYSTIC TICKET can be used\n"
	.string "at the FERRY.\p"
	.string "I've heard rumors that a rare and\n"
	.string "powerful POKéMON can be found there.$"

BattleFrontier_Text_CynthiaOldSeaMapDesc:
	.string "Try showing that OLD SEA MAP\n"
	.string "at the FERRY.\p"
	.string "Who knows where it might lead!$"

BattleFrontier_Text_CynthiaHopeToBattleAgain:
	.string "I hope to battle again soon!$"

BattleFrontier_Text_CynthiaIntro2:
	.string "I see you are ready for a rematch.\p"
	.string "I won't go as easy this time.$"
