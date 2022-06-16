.set HEARTSCALE_PRICE, 10000

FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_HeartScaleSalesman::
	lock
	faceplayer
	showmoneybox 0, 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq FallarborTown_EventScript_AskBuyHeartScaleMale
	compare VAR_RESULT, FEMALE
	goto_if_eq FallarborTown_EventScript_AskBuyHeartScaleFemale
	end

FallarborTown_EventScript_AskBuyHeartScaleMale::
	msgbox FallarborTown_Text_HeartScaleSalesman_Male, MSGBOX_YESNO
	goto FallarborTown_EventScript_TryBuyHeartScale
	end

FallarborTown_EventScript_AskBuyHeartScaleFemale::
	msgbox FallarborTown_Text_HeartScaleSalesman_Female, MSGBOX_YESNO
	goto FallarborTown_EventScript_TryBuyHeartScale
	end

FallarborTown_EventScript_TryBuyHeartScale::
	compare VAR_RESULT, NO
	goto_if_eq FallarborTown_EventScript_DeclineHeartScale
	checkmoney HEARTSCALE_PRICE
	compare VAR_RESULT, FALSE
	goto_if_eq FallarborTown_EventScript_NotEnoughMoney
	removemoney HEARTSCALE_PRICE
	updatemoneybox
	giveitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_EventScript_NoRoomInBag
	hidemoneybox
	release
	end

FallarborTown_EventScript_DeclineHeartScale::
	msgbox FallarborTown_Text_HeartScaleSalesmanNo
	hidemoneybox
	release
	end

FallarborTown_EventScript_NotEnoughMoney::
	msgbox FallarborTown_Text_HeartScaleSalesman_NeedMoreMoney
	hidemoneybox
	release
	end

FallarborTown_EventScript_NoRoomInBag::
	msgbox FallarborTown_Text_HeartScaleSalesman_NoRoomInBag
	hidemoneybox
	release
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Something's happening,\n"
	.string "and I don't like it!\p"
	.string "I've seen shady characters wandering\n"
	.string "in and out of PROF. COZMO's home…$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "This region's been known for meteors\n"
	.string "since the olden days.\p"
	.string "They say METEOR FALLS was gouged out\n"
	.string "by a falling meteorite long ago.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "See! Take a look!\n"
	.string "This is my precious AZURILL!\p"
	.string "It's slick and smooth and plushy, too!$"

FallarborTown_Text_Azurill:
	.string "AZURILL: Rooreelooo.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "Have you already challenged FLANNERY,\n"
	.string "the LEADER of LAVARIDGE GYM?\p"
	.string "The girl's grandfather was famous.\n"
	.string "He was one of the ELITE FOUR in the\l"
	.string "POKéMON LEAGUE at one point.\p"
	.string "It wouldn't surprise me to see FLANNERY\n"
	.string "become a great TRAINER in her own\l"
	.string "right.$"

FallarborTown_Text_BattleTentSign:
	.string "BATTLE TENT FALLARBOR SITE\n"
	.string "“May the Greatest Teams Gather!”$"

FallarborTown_Text_TownSign:
	.string "FALLARBOR TOWN\n"
	.string "“A farm community with small gardens.”$"

FallarborTown_Text_MoveTutorSign:
	.string "MOVE TUTOR'S HOUSE\n"
	.string "“New moves taught to POKéMON.”$"

FallarborTown_Text_HeartScaleSalesman_Male:
	.string "MAN: Hello there, laddie!\n"
    .string "Have I got a deal just for you!\p"
    .string "I'll let you have a rare item -\n"
    .string "a HEART SCALE - for just ¥10000!\p"
    .string "So, you'll buy it, am I right?$"

FallarborTown_Text_HeartScaleSalesman_Female:
	.string "MAN: Hello there, sweetie pie!\n"
    .string "Have I got a deal just for you!\p"
    .string "I'll let you have a rare item -\n"
    .string "a HEART SCALE - for just ¥10000!\p"
    .string "So, you'll buy it, am I right?$"

FallarborTown_Text_HeartScaleSalesmanPaid:
    .string "{PLAYER} paid ¥10000\n"
    .string "and bought the HEART SCALE…$"

FallarborTown_Text_HeartScaleSalesmanNo:
    .string "No? You say no? I'm only doing this\n"
    .string "as a favor to you!$"

FallarborTown_Text_HeartScaleSalesman_NeedMoreMoney:
    .string "You'll need more money than that!$"

FallarborTown_Text_HeartScaleSalesman_NoRoomInBag:
	.string "It appears you have no room for\n"
	.string "this HEART SCALE…"
