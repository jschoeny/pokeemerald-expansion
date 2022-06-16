@ Note: LOCALID_FARAWAY_ISLAND_MEW is a local id for this map used elsewhere. It's defined in event_objects.h
.set HELDITEM, VAR_SLATE_MON_ITEM
.set MONLEVEL, VAR_SLATE_MON_LEVEL

FarawayIsland_Interior_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, FarawayIsland_Interior_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Interior_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FarawayIsland_Interior_OnFrame
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, FarawayIsland_Interior_OnReturnToField
	map_script MAP_SCRIPT_ON_LOAD, FarawayIsland_Interior_OnLoad
	.byte 0

FarawayIsland_Interior_OnReturnToField:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FarawayIsland_Interior_EventScript_TrySetMewAboveGrass
	end

FarawayIsland_Interior_EventScript_TrySetMewAboveGrass::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FarawayIsland_Interior_EventScript_SetMewAboveGrass
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FarawayIsland_Interior_EventScript_SetMewAboveGrass
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FarawayIsland_Interior_EventScript_SetMewAboveGrass
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, FarawayIsland_Interior_EventScript_SetMewAboveGrass
	return

FarawayIsland_Interior_EventScript_SetMewAboveGrass::
	setvar VAR_0x8004, 1
	special SetMewAboveGrass
	return

FarawayIsland_Interior_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FarawayIsland_Interior_EventScript_TryRemoveMew
	end

FarawayIsland_Interior_EventScript_TryRemoveMew::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

FarawayIsland_Interior_OnTransition:
	setvar VAR_FARAWAY_ISLAND_STEP_COUNTER, 0
	setvar VAR_TEMP_1, 1
	call_if_unset FLAG_CAUGHT_MEW, FarawayIsland_Interior_EventScript_TryShowMew
	end

FarawayIsland_Interior_OnLoad:
	call_if_unset FLAG_CAUGHT_MEW, FarawayIsland_Interior_EventScript_HideSlateSlot
	end

FarawayIsland_Interior_EventScript_TryShowMew::
	goto_if_set FLAG_DEFEATED_MEW, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_MEW
	setvar VAR_TEMP_1, 0
	return

FarawayIsland_Interior_EventScript_HideSlateSlot::
	setobjectxyperm 2, 0, 0
	setobjectxyperm 3, 0, 0
	setmetatile 13, 4, METATILE_General_RockWall_GrassBase, TRUE
	return

FarawayIsland_Interior_OnFrame:
	map_script_2 VAR_TEMP_1, 0, FarawayIsland_Interior_EventScript_FindMew
	.2byte 0

FarawayIsland_Interior_EventScript_FindMew::
	lockall
	playse SE_PIN
	applymovement LOCALID_FARAWAY_ISLAND_MEW, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FARAWAY_ISLAND_MEW, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_FARAWAY_ISLAND_MEW, FarawayIsland_Interior_Movement_MewMoveAndHide
	waitmovement 0
	copyobjectxytoperm LOCALID_FARAWAY_ISLAND_MEW
	setvar VAR_TEMP_1, 1
	releaseall
	end

FarawayIsland_Interior_Movement_MewMoveAndHide:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	set_invisible
	step_end

FarawayIsland_Interior_Movement_MewAppear:
	set_visible
	step_end

FarawayIsland_Interior_Movement_MewFloatUpNorth:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_down
	walk_in_place_down
	step_end

FarawayIsland_Interior_Movement_MewFloatUpSouth:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_up
	walk_in_place_up
	step_end

FarawayIsland_Interior_Movement_MewFloatUpWest:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_right
	walk_in_place_right
	step_end

FarawayIsland_Interior_Movement_MewFloatUpEast:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_left
	walk_in_place_left
	step_end

FarawayIsland_Interior_EventScript_Mew::
	lock
	faceplayer
	applymovement LOCALID_FARAWAY_ISLAND_MEW, FarawayIsland_Interior_Movement_MewAppear
	waitmovement 0
	setvar VAR_0x8004, 0
	special SetMewAboveGrass
	message FarawayIsland_Interior_Text_Mew
	waitse
	playmoncry SPECIES_MEW, CRY_MODE_ENCOUNTER
	call_if_eq VAR_FACING, DIR_NORTH, FarawayIsland_Interior_EventScript_FoundMewNorth
	call_if_eq VAR_FACING, DIR_SOUTH, FarawayIsland_Interior_EventScript_FoundMewSouth
	call_if_eq VAR_FACING, DIR_WEST, FarawayIsland_Interior_EventScript_FoundMewWest
	call_if_eq VAR_FACING, DIR_EAST, FarawayIsland_Interior_EventScript_FoundMewEast
	special DestroyMewEmergingGrassSprite
	delay 40
	waitmoncry
	seteventmon SPECIES_MEW, 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FarawayIsland_Interior_EventScript_MewDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FarawayIsland_Interior_EventScript_PlayerOrMewRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FarawayIsland_Interior_EventScript_PlayerOrMewRan
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, FarawayIsland_Interior_EventScript_PlayerOrMewRan
	setflag FLAG_CAUGHT_MEW
	release
	end

FarawayIsland_Interior_EventScript_MewDefeated::
	setflag FLAG_DEFEATED_MEW
	setvar VAR_0x8004, SPECIES_MEW
	goto Common_EventScript_LegendaryFlewAway
	end

FarawayIsland_Interior_EventScript_PlayerOrMewRan::
	setvar VAR_0x8004, SPECIES_MEW
	goto Common_EventScript_LegendaryFlewAway
	end

FarawayIsland_Interior_EventScript_FoundMewNorth::
	applymovement LOCALID_FARAWAY_ISLAND_MEW, FarawayIsland_Interior_Movement_MewFloatUpNorth
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_FoundMewSouth::
	applymovement LOCALID_FARAWAY_ISLAND_MEW, FarawayIsland_Interior_Movement_MewFloatUpSouth
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_FoundMewWest::
	applymovement LOCALID_FARAWAY_ISLAND_MEW, FarawayIsland_Interior_Movement_MewFloatUpWest
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_FoundMewEast::
	applymovement LOCALID_FARAWAY_ISLAND_MEW, FarawayIsland_Interior_Movement_MewFloatUpEast
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_HideMewWhenGrassCut::
	lockall
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_MEW
	removeobject LOCALID_FARAWAY_ISLAND_MEW
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox FarawayIsland_Interior_Text_TheFeelingOfBeingWatchedFaded, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

FarawayIsland_Interior_EventScript_SlateSlot::
	msgbox FarawayIsland_Interior_Text_SlotCanFitASlate, MSGBOX_DEFAULT
	@ call_if_unset FLAG_DAILY_SLATE, FarawayIsland_Interior_EventScript_FindSlate
	special IsSlateInBag
	goto_if_eq VAR_RESULT, TRUE, FarawayIsland_Interior_EventScript_UseSlate
	release
	end

FarawayIsland_Interior_EventScript_FindSlate::
	finditem ITEM_SLATE_TIME
	finditem ITEM_SLATE_SPACE
	finditem ITEM_SLATE_JOHTO, 3
	setflag FLAG_DAILY_SLATE
	return

FarawayIsland_Interior_EventScript_UseSlate::
	message FarawayIsland_Interior_Text_ChooseASlate
	waitmessage
	special ScriptMenu_CreateSlateMultichoice
	waitstate
	closemessage
	special GetSlateSelection
	switch VAR_RESULT
	case 0, FarawayIsland_Interior_EventScript_UseSlateKanto
	case 1, FarawayIsland_Interior_EventScript_UseSlateGenome
	case 2, FarawayIsland_Interior_EventScript_UseSlateJohto
	case 4, FarawayIsland_Interior_EventScript_UseSlateTime
	case 5, FarawayIsland_Interior_EventScript_UseSlateSpace
	case 6, FarawayIsland_Interior_EventScript_UseSlateDistortion
	case SLATE_ITEMS_COUNT, FarawayIsland_Interior_EventScript_ExitSlateSelect
	case MULTI_B_PRESSED, FarawayIsland_Interior_EventScript_ExitSlateSelect
	return

FarawayIsland_Interior_EventScript_AskUseSlate::
	bufferitemnameplural STR_VAR_1, ITEMID, VAR_0x8005
	buffernumberstring STR_VAR_2, VAR_0x8005
	msgbox FarawayIsland_Interior_EventScript_UseSlateQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FarawayIsland_Interior_EventScript_UseSlate
	closemessage
	return

FarawayIsland_Interior_EventScript_UseSlateKanto::
	setvar ITEMID, ITEM_SLATE_KANTO
	call FarawayIsland_Interior_EventScript_AskUseSlate
	random 3
	switch VAR_RESULT
	case 0, FarawayIsland_Interior_EventScript_UseSlateKanto1
	case 1, FarawayIsland_Interior_EventScript_UseSlateKanto2
	case 2, FarawayIsland_Interior_EventScript_UseSlateKanto3
	end

FarawayIsland_Interior_EventScript_UseSlateKanto1::
	goto_if_unset FLAG_CAUGHT_ARTICUNO, FarawayIsland_Interior_EventScript_Articuno
	goto_if_unset FLAG_CAUGHT_ZAPDOS, FarawayIsland_Interior_EventScript_Zapdos
	goto_if_unset FLAG_CAUGHT_MOLTRES, FarawayIsland_Interior_EventScript_Moltres
	goto FarawayIsland_Interior_EventScript_SlateNoEffect
	end

FarawayIsland_Interior_EventScript_UseSlateKanto2::
	goto_if_unset FLAG_CAUGHT_ZAPDOS, FarawayIsland_Interior_EventScript_Zapdos
	goto_if_unset FLAG_CAUGHT_MOLTRES, FarawayIsland_Interior_EventScript_Moltres
	goto_if_unset FLAG_CAUGHT_ARTICUNO, FarawayIsland_Interior_EventScript_Articuno
	goto FarawayIsland_Interior_EventScript_SlateNoEffect
	end

FarawayIsland_Interior_EventScript_UseSlateKanto3::
	goto_if_unset FLAG_CAUGHT_MOLTRES, FarawayIsland_Interior_EventScript_Moltres
	goto_if_unset FLAG_CAUGHT_ARTICUNO, FarawayIsland_Interior_EventScript_Articuno
	goto_if_unset FLAG_CAUGHT_ZAPDOS, FarawayIsland_Interior_EventScript_Zapdos
	goto FarawayIsland_Interior_EventScript_SlateNoEffect
	end

FarawayIsland_Interior_EventScript_UseSlateGenome::
	setvar ITEMID, ITEM_SLATE_GENOME
	call FarawayIsland_Interior_EventScript_AskUseSlate
	goto_if_unset FLAG_CAUGHT_MEWTWO, FarawayIsland_Interior_EventScript_Mewtwo
	goto FarawayIsland_Interior_EventScript_SlateNoEffect
	end

FarawayIsland_Interior_EventScript_UseSlateJohto::
	setvar ITEMID, ITEM_SLATE_JOHTO
	call FarawayIsland_Interior_EventScript_AskUseSlate
	random 3
	switch VAR_RESULT
	case 0, FarawayIsland_Interior_EventScript_UseSlateJohto1
	case 1, FarawayIsland_Interior_EventScript_UseSlateJohto2
	case 2, FarawayIsland_Interior_EventScript_UseSlateJohto3

FarawayIsland_Interior_EventScript_UseSlateJohto1::
	goto_if_unset FLAG_CAUGHT_SUICUNE, FarawayIsland_Interior_EventScript_Suicune
	goto_if_unset FLAG_CAUGHT_RAIKOU, FarawayIsland_Interior_EventScript_Raikou
	goto_if_unset FLAG_CAUGHT_ENTEI, FarawayIsland_Interior_EventScript_Entei
	goto FarawayIsland_Interior_EventScript_SlateNoEffect
	end

FarawayIsland_Interior_EventScript_UseSlateJohto2::
	goto_if_unset FLAG_CAUGHT_RAIKOU, FarawayIsland_Interior_EventScript_Raikou
	goto_if_unset FLAG_CAUGHT_ENTEI, FarawayIsland_Interior_EventScript_Entei
	goto_if_unset FLAG_CAUGHT_SUICUNE, FarawayIsland_Interior_EventScript_Suicune
	goto FarawayIsland_Interior_EventScript_SlateNoEffect
	end

FarawayIsland_Interior_EventScript_UseSlateJohto3::
	goto_if_unset FLAG_CAUGHT_ENTEI, FarawayIsland_Interior_EventScript_Entei
	goto_if_unset FLAG_CAUGHT_SUICUNE, FarawayIsland_Interior_EventScript_Suicune
	goto_if_unset FLAG_CAUGHT_RAIKOU, FarawayIsland_Interior_EventScript_Raikou
	goto FarawayIsland_Interior_EventScript_SlateNoEffect
	end

FarawayIsland_Interior_EventScript_UseSlateTime::
	setvar ITEMID, ITEM_SLATE_TIME
	call FarawayIsland_Interior_EventScript_AskUseSlate
	goto_if_unset FLAG_CAUGHT_GIRATINA, FarawayIsland_Interior_EventScript_Dialga
	goto FarawayIsland_Interior_EventScript_SlateNoEffect
	end

FarawayIsland_Interior_EventScript_UseSlateSpace::
	setvar ITEMID, ITEM_SLATE_SPACE
	call FarawayIsland_Interior_EventScript_AskUseSlate
	goto_if_unset FLAG_CAUGHT_GIRATINA, FarawayIsland_Interior_EventScript_Palkia
	goto FarawayIsland_Interior_EventScript_SlateNoEffect
	end

FarawayIsland_Interior_EventScript_UseSlateDistortion::
	setvar ITEMID, ITEM_SLATE_DISTORTION
	call FarawayIsland_Interior_EventScript_AskUseSlate
	goto_if_unset FLAG_CAUGHT_GIRATINA, FarawayIsland_Interior_EventScript_Giratina
	goto FarawayIsland_Interior_EventScript_SlateNoEffect
	end

FarawayIsland_Interior_EventScript_SlateNoEffect::
	msgbox FarawayIsland_Interior_Text_SlateNoEffect, MSGBOX_DEFAULT
	goto FarawayIsland_Interior_EventScript_UseSlate
	end

FarawayIsland_Interior_EventScript_ExitSlateSelect::
	release
	end

FarawayIsland_Interior_EventScript_SetSlateHoleInserted::
	setmetatile 13, 4, METATILE_General_SlateSlotInserted, TRUE
	special DrawWholeMapView
	return

FarawayIsland_Interior_EventScript_SetSlateHoleOpen::
	setmetatile 13, 4, METATILE_General_RedCaveOpen, TRUE
	special DrawWholeMapView
	return

FarawayIsland_Interior_EventScript_UseSlateEffect::
	special Script_FadeOutMapMusic
	delay 20
	playse SE_UNLOCK
	call FarawayIsland_Interior_EventScript_SetSlateHoleInserted
	delay 60
	waitse
	playse SE_M_REFLECT
	fadescreen FADE_TO_WHITE
	call FarawayIsland_Interior_EventScript_SetSlateHoleOpen
	setflag FLAG_SMART_WILD_AI
	removeitem ITEMID
	fadescreen FADE_FROM_WHITE
	return

FarawayIsland_Interior_EventScript_InsertSlateEffect::
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	return

FarawayIsland_Interior_EventScript_InsertSlateEffect2::
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	return

FarawayIsland_Interior_EventScript_CloseSlateHoleEffect::
	fadescreen FADE_TO_BLACK
	setmetatile 13, 4, METATILE_General_RedCaveIndent, TRUE
	special DrawWholeMapView
	clearflag FLAG_SMART_WILD_AI
	playse SE_UNLOCK
	fadescreen FADE_FROM_BLACK
	delay 20
	return

FarawayIsland_Interior_EventScript_SlateEncounter::
	call FarawayIsland_Interior_EventScript_UseSlateEffect
	delay 80
	call FarawayIsland_Interior_EventScript_InsertSlateEffect
	delay 80
	call FarawayIsland_Interior_EventScript_InsertSlateEffect2
	waitse

FarawayIsland_Interior_EventScript_SlateEncounterStart::
	playmoncry VAR_SPECIES_ID, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	checkchallengemode
	call_if_eq VAR_RESULT, TRUE, FarawayIsland_Interior_EventScript_TotemLegendary1
	setwildbattlevars VAR_SPECIES_ID, MONLEVEL, HELDITEM
	special BattleSetup_StartLegendaryBattle
	waitstate
	delay 20
	call FarawayIsland_Interior_EventScript_CloseSlateHoleEffect
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FarawayIsland_Interior_EventScript_LegendaryFlewAway
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FarawayIsland_Interior_EventScript_LegendaryFlewAway
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FarawayIsland_Interior_EventScript_LegendaryFlewAway
	return

FarawayIsland_Interior_EventScript_SlateEncounterWeather::
	call FarawayIsland_Interior_EventScript_UseSlateEffect
	delay 40
	doweather
	delay 120
	call FarawayIsland_Interior_EventScript_InsertSlateEffect
	delay 80
	call FarawayIsland_Interior_EventScript_InsertSlateEffect2
	waitse
	playmoncry VAR_SPECIES_ID, CRY_MODE_ENCOUNTER
	waitmoncry
	checkchallengemode
	call_if_eq VAR_RESULT, TRUE, FarawayIsland_Interior_EventScript_TotemLegendary1
	setwildbattlevars VAR_SPECIES_ID, MONLEVEL, HELDITEM
	special BattleSetup_StartLegendaryBattle
	waitstate
	resetweather
	doweather
	waitstate
	delay 40
	specialvar VAR_RESULT, GetBattleOutcome
	call_if_eq VAR_RESULT, B_OUTCOME_WON, FarawayIsland_Interior_EventScript_SlateFaintCry
	call_if_eq VAR_RESULT, B_OUTCOME_RAN, FarawayIsland_Interior_EventScript_SlateFaintCry
	call_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FarawayIsland_Interior_EventScript_SlateFaintCry
	call FarawayIsland_Interior_EventScript_CloseSlateHoleEffect
	delay 20
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FarawayIsland_Interior_EventScript_LegendaryFlewAway
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FarawayIsland_Interior_EventScript_LegendaryFlewAway
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FarawayIsland_Interior_EventScript_LegendaryFlewAway
	return

FarawayIsland_Interior_EventScript_SlateFaintCry::
	playmoncry VAR_SPECIES_ID, CRY_MODE_FAINT
	waitmoncry
	return

FarawayIsland_Interior_EventScript_Articuno::
	setweather WEATHER_SNOW
	setvar VAR_SPECIES_ID, SPECIES_ARTICUNO
	setvar MONLEVEL, 70
	setvar HELDITEM, ITEM_NONE
	call FarawayIsland_Interior_EventScript_SlateEncounterWeather
	setflag FLAG_CAUGHT_ARTICUNO
	release
	end

FarawayIsland_Interior_EventScript_Zapdos::
	setweather WEATHER_RAIN_THUNDERSTORM
	setvar VAR_SPECIES_ID, SPECIES_ZAPDOS
	setvar MONLEVEL, 70
	setvar HELDITEM, ITEM_NONE
	call FarawayIsland_Interior_EventScript_SlateEncounterWeather
	setflag FLAG_CAUGHT_ZAPDOS
	release
	end

FarawayIsland_Interior_EventScript_Moltres::
	setweather WEATHER_DROUGHT
	setvar VAR_SPECIES_ID, SPECIES_MOLTRES
	setvar MONLEVEL, 70
	setvar HELDITEM, ITEM_NONE
	call FarawayIsland_Interior_EventScript_SlateEncounterWeather
	setflag FLAG_CAUGHT_MOLTRES
	release
	end

FarawayIsland_Interior_EventScript_Mewtwo::
	setweather WEATHER_FOG_DIAGONAL
	setvar VAR_SPECIES_ID, SPECIES_MEWTWO
	setvar MONLEVEL, 70
	setvar HELDITEM, ITEM_NONE
	call FarawayIsland_Interior_EventScript_SlateEncounterWeather
	setflag FLAG_CAUGHT_MEWTWO
	release
	end

FarawayIsland_Interior_EventScript_Suicune::
	setweather WEATHER_RAIN
	setvar VAR_SPECIES_ID, SPECIES_SUICUNE
	setvar MONLEVEL, 70
	setvar HELDITEM, ITEM_NONE
	call FarawayIsland_Interior_EventScript_SlateEncounterWeather
	setflag FLAG_CAUGHT_SUICUNE
	release
	end

FarawayIsland_Interior_EventScript_Raikou::
	setweather WEATHER_RAIN_THUNDERSTORM
	setvar VAR_SPECIES_ID, SPECIES_RAIKOU
	setvar MONLEVEL, 70
	setvar HELDITEM, ITEM_NONE
	call FarawayIsland_Interior_EventScript_SlateEncounterWeather
	setflag FLAG_CAUGHT_RAIKOU
	release
	end

FarawayIsland_Interior_EventScript_Entei::
	setweather WEATHER_DROUGHT
	setvar VAR_SPECIES_ID, SPECIES_ENTEI
	setvar MONLEVEL, 70
	setvar HELDITEM, ITEM_NONE
	call FarawayIsland_Interior_EventScript_SlateEncounterWeather
	setflag FLAG_CAUGHT_ENTEI
	release
	end

FarawayIsland_Interior_EventScript_Dialga::
	setweather WEATHER_FOG_HORIZONTAL
	setvar VAR_SPECIES_ID, SPECIES_DIALGA
	setvar MONLEVEL, 70
	setvar HELDITEM, ITEM_ADAMANT_ORB
	call FarawayIsland_Interior_EventScript_SlateEncounterWeather
	setflag FLAG_CAUGHT_DIALGA
	release
	end

FarawayIsland_Interior_EventScript_Palkia::
	setweather WEATHER_FOG_HORIZONTAL
	setvar VAR_SPECIES_ID, SPECIES_PALKIA
	setvar MONLEVEL, 70
	setvar HELDITEM, ITEM_LUSTROUS_ORB
	call FarawayIsland_Interior_EventScript_SlateEncounterWeather
	setflag FLAG_CAUGHT_PALKIA
	release
	end

FarawayIsland_Interior_EventScript_Giratina::
	call FarawayIsland_Interior_EventScript_UseSlateEffect
	delay 40
	fadescreenspeed FADE_TO_BLACK, 30, 0, 6
	call FarawayIsland_Interior_EventScript_InsertSlateEffect
	delay 60
	fadescreen FADE_TO_BLACK, 0, 9
	fadescreen FADE_FROM_BLACK, 9, 7
	delay 30
	call FarawayIsland_Interior_EventScript_InsertSlateEffect2
	delay 30
	fadescreen FADE_TO_BLACK, 0, 10
	fadescreen FADE_FROM_BLACK, 10, 8
	waitse
	setvar VAR_SPECIES_ID, SPECIES_GIRATINA_ORIGIN
	setvar MONLEVEL, 70
	setvar HELDITEM, ITEM_GRISEOUS_ORB
	setvar VAR_BATTLEBG_BLEND, BG_FADE_GIRATINA
	call FarawayIsland_Interior_EventScript_SlateEncounterStart
	setflag FLAG_CAUGHT_GIRATINA
	release
	end

FarawayIsland_Interior_EventScript_LegendaryFlewAway::
	bufferspeciesname STR_VAR_1, VAR_SPECIES_ID
	msgbox FarawayIsland_Interior_Text_LegendaryFlewAway, MSGBOX_DEFAULT
	release
	end

FarawayIsland_Interior_EventScript_TotemLegendary1::
	settotemboost 1, 2, 2, 2, 2, 2
	return

FarawayIsland_Interior_EventScript_TotemLegendary2::
	settotemboost 1, 3, 3, 3, 3, 3
	return

FarawayIsland_Interior_Text_TheFeelingOfBeingWatchedFaded:
	.string "The feeling of being watched faded…$"

FarawayIsland_Interior_Text_SlotCanFitASlate:
	.string "It appears to be able to hold a\n"
	.string "particular slate…$"

FarawayIsland_Interior_Text_ChooseASlate:
	.string "Choose a slate to use.$"

FarawayIsland_Interior_Text_LegendaryFlewAway:
	.string "{STR_VAR_1} disappeared back into\n"
	.string "the hole.$"

FarawayIsland_Interior_Text_SlateNoEffect:
	.string "It won't have any effect.$"

FarawayIsland_Interior_EventScript_UseSlateQuestion:
	.string "You have {STR_VAR_2} {STR_VAR_1}(s)\n"
	.string "remaining.\p"
	.string "Would you like to use one?$"
