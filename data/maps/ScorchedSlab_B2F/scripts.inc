ScorchedSlab_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ScorchedSlab_B2F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ScorchedSlab_B2F_OnFrameTable
	.byte 0

ScorchedSlab_B2F_OnTransition:
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 1
	setvar VAR_TEMP_3, 1
	setvar VAR_TEMP_4, 1
	call_if_unset FLAG_CAUGHT_HEATRAN, ScorchedSlab_B2F_EventScript_TryEncounterHeatran
	end

ScorchedSlab_B2F_EventScript_TryEncounterHeatran::
	goto_if_set FLAG_DEFEATED_HEATRAN, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	return

ScorchedSlab_B2F_OnFrameTable:
	map_script_2 VAR_TEMP_1, 0, ScorchedSlab_B2F_EventScript_CantStopSweating
	.2byte 0

ScorchedSlab_B2F_EventScript_CantStopSweating::
	lockall
	msgbox ScorchedSlab_B2F_Text_CantStopSweating, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 1
	releaseall
	end

ScorchedSlab_B2F_EventScript_Shake1::
	goto_if_set FLAG_DEFEATED_HEATRAN, Common_EventScript_NopReturn
	goto_if_set FLAG_CAUGHT_HEATRAN, Common_EventScript_NopReturn
	lockall
	special Script_FadeOutMapMusic
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 12  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 20
	setvar VAR_TEMP_2, 1
	releaseall
	end

ScorchedSlab_B2F_EventScript_Shake2::
	goto_if_set FLAG_DEFEATED_HEATRAN, Common_EventScript_NopReturn
	goto_if_set FLAG_CAUGHT_HEATRAN, Common_EventScript_NopReturn
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 20
	setvar VAR_TEMP_3, 1
	releaseall
	end

ScorchedSlab_B2F_EventScript_Heatran::
	goto_if_set FLAG_DEFEATED_HEATRAN, Common_EventScript_NopReturn
	goto_if_set FLAG_CAUGHT_HEATRAN, Common_EventScript_NopReturn
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 24  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	playmoncry SPECIES_HEATRAN, CRY_MODE_ENCOUNTER
	waitmoncry
	checkchallengemode
	call_if_eq VAR_RESULT, TRUE, ScorchedSlab_B2F_EventScript_TotemLegendary
	setflag B_FLAG_3_MAX_IVS
	setwildbattle SPECIES_HEATRAN, 70
	special BattleSetup_StartLegendaryBattle
	waitstate
	setvar VAR_TEMP_4, 1
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FarawayIsland_Interior_EventScript_HeatranDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FarawayIsland_Interior_EventScript_PlayerOrHeatranRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FarawayIsland_Interior_EventScript_PlayerOrHeatranRan
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, FarawayIsland_Interior_EventScript_PlayerOrHeatranRan
	setflag FLAG_CAUGHT_HEATRAN
	releaseall
	end

FarawayIsland_Interior_EventScript_HeatranDefeated::
	setflag FLAG_DEFEATED_HEATRAN
	msgbox ScorchedSlab_B2F_Text_HeatranDisappeared, MSGBOX_DEFAULT
	releaseall
	end

FarawayIsland_Interior_EventScript_PlayerOrHeatranRan::
	msgbox ScorchedSlab_B2F_Text_HeatranDisappeared, MSGBOX_DEFAULT
	releaseall
	end

ScorchedSlab_B2F_EventScript_TotemLegendary::
	settotemboost 1, 2, 2, 2, 2, 2
	return

ScorchedSlab_B2F_Text_CantStopSweating:
	.string "It's so hot that you can't\n"
	.string "stop sweating…\p"
	.string "Merely breathing is difficult…$"

ScorchedSlab_B2F_Text_HeatranDisappeared:
	.string "The Heatran sank back down\n"
	.string "into the lava…$"
