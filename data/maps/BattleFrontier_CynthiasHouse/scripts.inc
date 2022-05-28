BattleFrontier_CynthiasHouse_MapScripts::
	.byte 0

BattleFrontier_CynthiasHouse_EventScript_Cynthia::
	trainerbattle_single TRAINER_CYNTHIA_1, BattleFrontier_Text_CynthiaIntro, BattleFrontier_Text_CynthiaDefeat, BattleFrontier_CynthiasHouse_EventScript_CynthiaDefeated
	goto_if_unset FLAG_RECEIVED_CYNTHIA_EGG, BattleFrontier_CynthiasHouse_EventScript_CynthiaEggNotReceived
	msgbox BattleFrontier_Text_CynthiaTakeCareOfEgg, MSGBOX_AUTOCLOSE
	end

BattleFrontier_CynthiasHouse_EventScript_CynthiaDefeated::
	msgbox BattleFrontier_Text_CynthiaPostBattle
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, BattleFrontier_CynthiasHouse_EventScript_CynthiaNoRoomForEgg
	setflag FLAG_RECEIVED_CYNTHIA_EGG
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_TOGEPI
	release
	end

BattleFrontier_CynthiasHouse_EventScript_CynthiaEggNotReceived::
	msgbox BattleFrontier_Text_CynthiaReadyForEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, BattleFrontier_CynthiasHouse_EventScript_CynthiaNoRoomForEgg
	setflag FLAG_RECEIVED_CYNTHIA_EGG
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_TOGEPI
	release
	end


BattleFrontier_CynthiasHouse_EventScript_CynthiaNoRoomForEgg::
	msgbox BattleFrontier_Text_CynthiaNoRoomForThisEgg
	release
	end

BattleFrontier_Text_CynthiaIntro:
	.string "???: What's this?\p"
	.string "What an uncanny resemblance…\p"
	.string "It's surprising to meet another Trainer\n"
	.string "who has intense eyes like that\l"
	.string "POKéMON Trainer.\p"
	.string "What's your name?\p"
	.string "…\p"
	.string "OK. I'll remember that!\p"
	.string "{PLAYER}, nice to meet you.\p"
	.string "I'm Cynthia.\n"
	.string "I'm a POKéMON Trainer, too, like you.\p"
	.string "I have an insatiable curiosity for\n"
	.string "researching POKéMON myths.\p"
	.string "In order to get to know each other\n"
	.string "better as POKéMON Trainers, I would\l"
	.string "like our POKéMON to have a match.\p"
	.string "Hope you're ready!$"

BattleFrontier_Text_CynthiaDefeat:
	.string "My heart is pounding so hard because I\n"
	.string "had such a heated battle with you.\p"
	.string "You are a really great Trainer!!$"

BattleFrontier_Text_CynthiaPostBattle:
	.string "That was beyond my expectation!\n"
	.string "What an exceptional battle!\p"
	.string "As a reward for defeating me,\n"
	.string "I would like you to have this.$"

BattleFrontier_Text_CynthiaReadyForEgg:
	.string "As a reward for defeating me,\n"
	.string "I would like you to have this.$"

BattleFrontier_Text_ReceivedTheEgg:
	.string "{PLAYER} received the EGG.$"

BattleFrontier_Text_CynthiaNoRoomForThisEgg:
	.string "Oh? You've too many POKéMON.\n"
	.string "There's no room for this EGG…\p"
	.string "Come back when you have room.$"

BattleFrontier_Text_CynthiaTakeCareOfEgg:
	.string "Take good care of that egg!$"
