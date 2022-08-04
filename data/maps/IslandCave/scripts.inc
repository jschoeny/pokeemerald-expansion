IslandCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, IslandCave_OnResume
	map_script MAP_SCRIPT_ON_LOAD, IslandCave_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, IslandCave_OnTransition
	.byte 0

IslandCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, IslandCave_EventScript_TryRemoveRegice
	end

IslandCave_EventScript_TryRemoveRegice::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

IslandCave_OnLoad:
	setvar VAR_TEMP_1, 1
	call_if_unset FLAG_SYS_BRAILLE_REGICE_COMPLETED, IslandCave_EventScript_HideRegiEntrance
	call_if_set FLAG_DEFEATED_REGICE, IslandCave_EventScript_EnableRegigigasTrigger
	end

IslandCave_EventScript_HideRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

IslandCave_OnTransition:
	setflag FLAG_LANDMARK_ISLAND_CAVE
	call IslandCave_EventScript_ClearSteps
	call_if_unset FLAG_DEFEATED_REGICE, IslandCave_EventScript_ShowRegice
	end

IslandCave_EventScript_ShowRegice::
	clearflag FLAG_HIDE_REGICE
	return

IslandCave_EventScript_EnableRegigigasTrigger::
	goto_if_set FLAG_DEFEATED_REGIGIGAS, Common_EventScript_NopReturn
	goto_if_set FLAG_CAUGHT_REGIGIGAS, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	return

IslandCave_EventScript_OpenRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_SealedChamberEntrance_TopLeft, TRUE
	setmetatile 8, 19, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
	setmetatile 9, 19, METATILE_Cave_SealedChamberEntrance_TopRight, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberEntrance_BottomLeft, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
	setmetatile 9, 20, METATILE_Cave_SealedChamberEntrance_BottomRight, TRUE
	special DrawWholeMapView
	playse SE_BANG
	setflag FLAG_SYS_BRAILLE_REGICE_COMPLETED
	end

IslandCave_EventScript_CaveEntranceMiddle::
	lockall
	call_if_set FLAG_TEMP_3, IslandCave_EventScript_ClearSteps
	goto_if_set FLAG_SYS_BRAILLE_REGICE_COMPLETED, IslandCave_EventScript_BigHoleInWall
	braillemessage IslandCave_Braille_RunLapAroundWall
	setflag FLAG_TEMP_2
	special ShouldDoBrailleRegicePuzzle
	goto IslandCave_EventScript_CloseBrailleMsg
	end

IslandCave_EventScript_BigHoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

IslandCave_EventScript_CaveEntranceSide::
	lockall
	call_if_set FLAG_TEMP_3, IslandCave_EventScript_ClearSteps
	braillemessage IslandCave_Braille_RunLapAroundWall
	goto_if_set FLAG_SYS_BRAILLE_REGICE_COMPLETED, IslandCave_EventScript_CloseBrailleMsg
	setflag FLAG_TEMP_2
	special ShouldDoBrailleRegicePuzzle
	goto IslandCave_EventScript_CloseBrailleMsg
	end

IslandCave_EventScript_CloseBrailleMsg::
	waitbuttonpress
	closebraillemessage
	releaseall
	end

IslandCave_EventScript_ClearSteps::
	setvar VAR_REGICE_STEPS_1, 0
	setvar VAR_REGICE_STEPS_2, 0
	setvar VAR_REGICE_STEPS_3, 0
	clearflag FLAG_TEMP_3
	return

IslandCave_EventScript_Regice::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGICE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	checkchallengemode
	call_if_eq VAR_RESULT, TRUE, IslandCave_EventScript_TotemLegendary
	setflag B_FLAG_3_MAX_IVS
	setwildbattle SPECIES_REGICE, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, IslandCave_EventScript_DefeatedRegice
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IslandCave_EventScript_RanFromRegice
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, IslandCave_EventScript_RanFromRegice
	setflag FLAG_DEFEATED_REGICE
	release
	end

IslandCave_EventScript_DefeatedRegice::
	setflag FLAG_DEFEATED_REGICE
	goto Common_EventScript_RemoveStaticPokemon
	end

IslandCave_EventScript_RanFromRegice::
	setvar VAR_0x8004, SPECIES_REGICE
	goto Common_EventScript_LegendaryFlewAway
	end

IslandCave_EventScript_RegigigasTrigger::
	setvar VAR_0x8004, SPECIES_REGICE
	specialvar VAR_RESULT, ScriptGetPartyHasSpecies
	goto_if_eq VAR_RESULT, FALSE, IslandCave_EventScript_RegigigasPresence
	setvar VAR_0x8004, SPECIES_REGISTEEL
	specialvar VAR_RESULT, ScriptGetPartyHasSpecies
	goto_if_eq VAR_RESULT, FALSE, IslandCave_EventScript_RegigigasPresence
	setvar VAR_0x8004, SPECIES_REGIROCK
	specialvar VAR_RESULT, ScriptGetPartyHasSpecies
	goto_if_eq VAR_RESULT, FALSE, IslandCave_EventScript_RegigigasPresence
	goto IslandCave_EventScript_Regigigas
	end

IslandCave_EventScript_RegigigasPresence::
	lockall
	msgbox IslandCave_Text_RegigigasPresence, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 1
	releaseall
	end

IslandCave_EventScript_Regigigas::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox IslandCave_Text_RegigigasEncounter, MSGBOX_AUTOCLOSE
	waitmessage
	delay 20
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 10  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 10  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 40
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	message IslandCave_Text_RegigigasCry
	playmoncry SPECIES_REGIGIGAS, CRY_MODE_ENCOUNTER
	waitmoncry
	checkchallengemode
	call_if_eq VAR_RESULT, TRUE, IslandCave_EventScript_TotemLegendary
	setflag B_FLAG_3_MAX_IVS
	setwildbattle SPECIES_REGIGIGAS, 70
	special BattleSetup_StartLegendaryBattle
	waitstate
	setvar VAR_TEMP_1, 1
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, IslandCave_EventScript_RegigigasDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IslandCave_EventScript_PlayerOrRegigigasRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, IslandCave_EventScript_PlayerOrRegigigasRan
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, IslandCave_EventScript_PlayerOrRegigigasRan
	setflag FLAG_CAUGHT_REGIGIGAS
	releaseall
	end

IslandCave_EventScript_RegigigasDefeated::
	setflag FLAG_DEFEATED_REGIGIGAS
	msgbox IslandCave_Text_RegigigasDisappeared, MSGBOX_DEFAULT
	releaseall
	end

IslandCave_EventScript_PlayerOrRegigigasRan::
	msgbox IslandCave_Text_RegigigasDisappeared, MSGBOX_DEFAULT
	releaseall
	end

IslandCave_EventScript_TotemLegendary::
	settotemboost 1, 2, 2, 2, 2, 2
	return

IslandCave_Text_RegigigasPresence::
	.string "…?\p"
	.string "There seemed to be some\n"
	.string "presence here,\l"
	.string "but it disappeared in an instant…$"

IslandCave_Text_RegigigasEncounter::
	.string "The very earth is quaking!\p"
	.string "Is something approaching?!$"

IslandCave_Text_RegigigasCry::
	.string "Zut zutt!$"

IslandCave_Text_RegigigasDisappeared::
	.string "The Regigigas disappeared!$"
