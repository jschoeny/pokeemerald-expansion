.set LOCALID_RIVAL, 2

Route103_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
	.byte 0

Route103_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	end

Route103_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_OpenAlteringCave
	end

Route103_EventScript_OpenAlteringCave::
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, TRUE
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, FALSE
	return

Route103_EventScript_Rival::
	lockall
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE103_2, Route103_EventScript_AfterBattle_PostGame2
	goto_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_Rival_PostGame
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route103_EventScript_RivalMay
	goto_if_eq VAR_RESULT, FEMALE, Route103_EventScript_RivalBrendan
	end

Route103_EventScript_RivalMay::
	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_MAY, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartMayBattleTreecko
	case 1, Route103_EventScript_StartMayBattleTorchic
	case 2, Route103_EventScript_StartMayBattleMudkip
	end

Route103_EventScript_RivalBrendan::
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartBrendanBattleTreecko
	case 1, Route103_EventScript_StartBrendanBattleTorchic
	case 2, Route103_EventScript_StartBrendanBattleMudkip
	end

Route103_EventScript_StartMayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartBrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_AfterMayBattle::
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_AfterBrendanBattle::
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_RivalExit::
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
	end

Route103_EventScript_RivalExitFacingNorth::
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_RIVAL, Route103_EventScript_RivalExitFacingNorth2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingEastOrWest::
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingSouth::
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalEnd::
	removeobject LOCALID_RIVAL
	setvar VAR_BIRCH_LAB_STATE, 4
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	setvar VAR_OLDALE_RIVAL_STATE, 1
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route103_EventScript_Rival_PostGame::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route103_EventScript_RivalMay_PostGame
	goto_if_eq VAR_RESULT, FEMALE, Route103_EventScript_RivalBrendan_PostGame
	end

Route103_EventScript_AfterBattle_PostGame2::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route103_EventScript_AfterMayBattle_PostGame2
	goto_if_eq VAR_RESULT, FEMALE, Route103_EventScript_AfterBrendanBattle_PostGame2
	end

Route103_EventScript_RivalMay_PostGame::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_MayRoute103PostGame_Intro, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceAwayPlayer
	waitmovement 0
	msgbox Route103_Text_MayRoute103PostGame_Intro2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route103_Text_MayRoute103PostGame_Intro3, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, NO, Route103_EventScript_RivalMay_PostGame_Decline
	delay 20
	playbgm MUS_CREDITS, TRUE
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartMayBattleTreecko_PostGame
	case 1, Route103_EventScript_StartMayBattleTorchic_PostGame
	case 2, Route103_EventScript_StartMayBattleMudkip_PostGame
	end

Route103_EventScript_RivalMay_PostGame_Decline::
	msgbox Route103_Text_MayRoute103PostGame_Waiting, MSGBOX_AUTOCLOSE
	savebgm MUS_DUMMY
	fadedefaultbgm
	applymovement LOCALID_RIVAL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Route103_EventScript_RivalBrendan_PostGame::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_BrendanRoute103PostGame_Intro, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceAwayPlayer
	waitmovement 0
	msgbox Route103_Text_BrendanRoute103PostGame_Intro2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route103_Text_BrendanRoute103PostGame_Intro3, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, NO, Route103_EventScript_RivalBrendan_PostGame_Decline
	delay 20
	playbgm MUS_CREDITS, TRUE
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartBrendanBattleTreecko_PostGame
	case 1, Route103_EventScript_StartBrendanBattleTorchic_PostGame
	case 2, Route103_EventScript_StartBrendanBattleMudkip_PostGame
	end

Route103_EventScript_RivalBrendan_PostGame_Decline::
	msgbox Route103_Text_BrendanRoute103PostGame_Waiting, MSGBOX_AUTOCLOSE
	savebgm MUS_DUMMY
	fadedefaultbgm
	applymovement LOCALID_RIVAL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Route103_EventScript_StartMayBattleTreecko_PostGame::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO_2, Route103_Text_MayDefeated_PostGame
	goto Route103_EventScript_AfterMayBattle_PostGame
	end

Route103_EventScript_StartMayBattleTorchic_PostGame::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC_2, Route103_Text_MayDefeated_PostGame
	goto Route103_EventScript_AfterMayBattle_PostGame
	end

Route103_EventScript_StartMayBattleMudkip_PostGame::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP_2, Route103_Text_MayDefeated_PostGame
	goto Route103_EventScript_AfterMayBattle_PostGame
	end

Route103_EventScript_StartBrendanBattleTreecko_PostGame::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO_2, Route103_Text_BrendanDefeated_PostGame
	goto Route103_EventScript_AfterBrendanBattle_PostGame
	end

Route103_EventScript_StartBrendanBattleTorchic_PostGame::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC_2, Route103_Text_BrendanDefeated_PostGame
	goto Route103_EventScript_AfterBrendanBattle_PostGame
	end

Route103_EventScript_StartBrendanBattleMudkip_PostGame::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP_2, Route103_Text_BrendanDefeated_PostGame
	goto Route103_EventScript_AfterBrendanBattle_PostGame
	end

Route103_EventScript_AfterMayBattle_PostGame::
	msgbox Route103_Text_MayPostBattle_PostGame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_FaceAwayPlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_MayPostBattle_PostGame2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_MayPostBattle_PostGame3, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	setvar VAR_DISTRIBUTE_EON_TICKET, 0
	waitmessage
	msgbox Route103_Text_BrendanPostBattle_PostGame4, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DEFEATED_RIVAL_ROUTE103_2
	setflag FLAG_HIDE_ROUTE_103_RIVAL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route103_EventScript_AfterMayBattle_PostGame2::
	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_AUTOCLOSE
	release
	end

Route103_EventScript_AfterBrendanBattle_PostGame::
	msgbox Route103_Text_BrendanPostBattle_PostGame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_FaceAwayPlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_BrendanPostBattle_PostGame2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_BrendanPostBattle_PostGame3, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_EON_TICKET
	waitmessage
	msgbox Route103_Text_BrendanPostBattle_PostGame4, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DEFEATED_RIVAL_ROUTE103_2
	setflag FLAG_HIDE_ROUTE_103_RIVAL
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route103_EventScript_AfterBrendanBattle_PostGame2::
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_AUTOCLOSE
	release
	end

Route103_Movement_RivalExitFacingNorth1:
	walk_left
	walk_down
	step_end

Route103_EventScript_RivalExitFacingNorth2:
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingNorth:
	delay_16
	delay_4
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

Route103_Movement_RivalExit1:
	walk_down
	step_end

Route103_Movement_RivalExit2:
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingEastOrWest:
	delay_16
	walk_in_place_faster_down
	step_end

Route103_EventScript_Boy::
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
	end

Route103_EventScript_Man::
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
	end

Route103_EventScript_RouteSign::
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
	end

Route103_EventScript_Daisy::
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Amy::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_AmyRematch
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_AmyRegisterMatchCallAfterBattle::
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_AmyRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Liv::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_LivRematch
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_LivRegisterMatchCallAfterBattle::
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_LivRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Andrew::
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Miguel::
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route103_EventScript_MiguelRematch
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_MiguelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_MIGUEL_1
	release
	end

Route103_EventScript_MiguelRematch::
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Marcos::
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Rhett::
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Pete::
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Isabelle::
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_Text_MayRoute103Pokemon:
	.string "MAY: Let's see… The POKéMON found\n"
	.string "on ROUTE 103 include…$"

Route103_Text_MayLetsBattle:
	.string "Oh, hi, {PLAYER}{KUN}!\p"
	.string "…Oh, I see, my dad gave you\n"
	.string "a POKéMON as a gift.\p"
	.string "Since we're here, let's have a quick\n"
	.string "battle!\p"
	.string "I'll give you a taste of what being\n"
	.string "a TRAINER is like.$"

Route103_Text_MayDefeated:
	.string "Wow! That's great!\n"
	.string "{PLAYER}{KUN}, you're pretty good!$"

Route103_Text_MayTimeToHeadBack:
	.string "MAY: I think I know why my dad has\n"
	.string "an eye out for you now.\p"
	.string "I mean, you just got that POKéMON,\n"
	.string "but it already likes you.\p"
	.string "You might be able to befriend any\n"
	.string "kind of POKéMON easily.\p"
	.string "Well, it's time to head back to\n"
	.string "the LAB.$"

Route103_Text_MayRoute103PostGame_Intro:
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
	.string "… … …\p"
	.string "Here we are on Route 103 again!\n"
	.string "Wow, it's so nostalgic, you know?$"

Route103_Text_MayRoute103PostGame_Intro2:
	.string "Oh! Remember this spot?\p"
	.string "This is where we first battled,\n"
	.string "isn't it?\p"
	.string "… … …\p"
	.string "…{PLAYER}!\n"
	.string "Could you do something for me?$"

Route103_Text_MayRoute103PostGame_Intro3:
	.string "Come on!\n"
	.string "Let's battle one more time!\p"
	.string "I wanna know what you saw on your\n"
	.string "journey, how you felt, and what you\l"
	.string "experienced out there.\p"
	.string "I want to understand everything about\n"
	.string "you and your POKéMON, {PLAYER}{KUN}!\p"
	.string "And then…\p"
	.string "… … …\p"
	.string "I want you to understand everything\n"
	.string "about me and mine!\p"
	.string "What do you say?$"

Route103_Text_MayRoute103PostGame_Waiting:
	.string "Oh alright.\p"
	.string "I'll be waiting here when you\n"
	.string "change your mind.$"

Route103_Text_MayDefeated_PostGame:
	.string "… … …$"

Route103_Text_MayPostBattle_PostGame:
	.string "… … …\p"
	.string "Thanks, {PLAYER}{KUN}!\n"
	.string "You really are a Champion!$"

Route103_Text_MayPostBattle_PostGame2:
	.string "… … …\p"
	.string "Meeting so many different people…\p"
	.string "And encountering so many POKéMON…\p"
	.string "It's just really…\p"
	.string "… … …$"

Route103_Text_MayPostBattle_PostGame3:
	.string "It's been really, really fun!\p"
	.string "… … …\p"
	.string "Ah!{PAUSE 30}\n"
	.string "I should get back to my field work.\p"
	.string "But before you go, I want you\n"
	.string "to have this.$"

Route103_Text_MayPostBattle_PostGame4:
	.string "… … …\p"
	.string "Thanks again, {PLAYER}{KUN}!$"

Route103_Text_BrendanRoute103Pokemon:
	.string "BRENDAN: Okay, so it's this one and\n"
	.string "that one that live on ROUTE 103…$"

Route103_Text_BrendanLetsBattle:
	.string "Hey, it's {PLAYER}!\p"
	.string "…Oh, yeah, Dad gave you a POKéMON.\p"
	.string "Since we're here, how about a little\n"
	.string "battle?\p"
	.string "I'll teach you what being a TRAINER's\n"
	.string "about!$"

Route103_Text_BrendanDefeated:
	.string "Huh, {PLAYER}, you're not too shabby.$"

Route103_Text_BrendanTimeToHeadBack:
	.string "BRENDAN: I think I get it.\n"
	.string "I think I know why my dad has his eye\l"
	.string "out for you now.\p"
	.string "Look, your POKéMON already likes you,\n"
	.string "even though you just got it.\p"
	.string "{PLAYER}, I get the feeling that you\n"
	.string "could befriend any POKéMON with ease.\p"
	.string "We should head back to the LAB.$"

Route103_Text_BrendanRoute103PostGame_Intro:
	.string "BRENDAN: Hey, it's {PLAYER}{KUN}!\p"
	.string "… … …\p"
	.string "Man, this is nostalgic.\n"
	.string "Back on Route 103, huh?$"

Route103_Text_BrendanRoute103PostGame_Intro2:
	.string "Remember this spot?\p"
	.string "This is where we battled the\n"
	.string "first time, huh?\p"
	.string "… … …\p"
	.string "Hey, {PLAYER}…\n"
	.string "Do me a favor?$"

Route103_Text_BrendanRoute103PostGame_Intro3:
	.string "Come on!\n"
	.string "Let's battle one more time!\p"
	.string "I wanna know what you saw on your\n"
	.string "journey, how you felt, and what you\l"
	.string "experienced out there.\p"
	.string "I want to know all about you\n"
	.string "and your POKéMON, {PLAYER}{KUN}.\p"
	.string "But that's not all…\p"
	.string "… … …\p"
	.string "I want you to know all about\n"
	.string "me and mine!\p"
	.string "What do you say?$"

Route103_Text_BrendanRoute103PostGame_Waiting:
	.string "Alright.\p"
	.string "Well I'll be out here if you\n"
	.string "change your mind.$"

Route103_Text_BrendanDefeated_PostGame:
	.string "… … …$"

Route103_Text_BrendanPostBattle_PostGame:
	.string "… … …\p"
	.string "Thanks, {PLAYER}{KUN}!\n"
	.string "Just what I'd expect from a Champion!$"

Route103_Text_BrendanPostBattle_PostGame2:
	.string "… … …\p"
	.string "Getting to meet so many different\n"
	.string "people…\p"
	.string "And so many different POKéMON…\p"
	.string "It's like… I don't know…\p"
	.string "… … …$"

Route103_Text_BrendanPostBattle_PostGame3:
	.string "It's been really, really fun!\p"
	.string "… … …\p"
	.string "Ah!{PAUSE 30}\n"
	.string "I should probably get back to my\l"
	.string "field work now.\p"
	.string "But before you go, I want you\n"
	.string "to have this.$"

Route103_Text_BrendanPostBattle_PostGame4:
	.string "… … …\p"
	.string "Thanks again, {PLAYER}{KUN}!$"

Route103_Text_ShouldHaveBroughtPotion:
	.string "My POKéMON is staggeringly tired…\n"
	.string "I should have brought a POTION…$"

Route103_Text_ShortcutToOldale:
	.string "If you cross the sea from here,\n"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
	.string "Fufufu, that's useful, isn't it?$"

Route103_Text_RouteSign:
	.string "ROUTE 103\n"
	.string "{DOWN_ARROW} OLDALE TOWN$"

