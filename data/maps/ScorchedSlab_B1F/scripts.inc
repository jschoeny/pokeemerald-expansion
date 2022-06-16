ScorchedSlab_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ScorchedSlab_B1F_OnLoad
	.byte 0

ScorchedSlab_B1F_OnLoad:
	call_if_unset FLAG_SYS_NATIONAL_DEX, ScorchedSlab_B1F_EventScript_HideHeatranCave
	end

ScorchedSlab_B1F_EventScript_HideHeatranCave::
	setmetatile 14, 1, 0x219, TRUE
	setmetatile 15, 1, 0x219, TRUE
	setmetatile 16, 1, 0x219, TRUE
	setmetatile 14, 2, 0x219, TRUE
	setmetatile 15, 2, 0x219, TRUE
	setmetatile 16, 2, 0x219, TRUE
	return
