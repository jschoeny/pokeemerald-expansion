.set LOCALID_SAILOR, 1
.set LOCALID_SS_TIDAL, 2

FarawayIsland_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FarawayIsland_Entrance_OnFrame
	.byte 0

FarawayIsland_Entrance_OnTransition:
	setflag FLAG_ARRIVED_ON_FARAWAY_ISLAND
	end

FarawayIsland_Entrance_OnFrame:
	map_script_2 VAR_FARAWAY_ISLAND_STATE, 1, FarawayIsland_Entrance_EventScript_Quake
	.2byte 0

FarawayIsland_Entrance_EventScript_Quake::
	lockall
	special HideMapNamePopUpWindow
	delay 20
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 10  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 20
	msgbox FarawayIsland_Entrance_Text_Quake, MSGBOX_DEFAULT
	waitmessage
	setvar VAR_FARAWAY_ISLAND_STATE, 2
	releaseall
	end

FarawayIsland_Entrance_EventScript_SetCloudsWeather::
	setweather WEATHER_SUNNY_CLOUDS
	doweather
	end

FarawayIsland_Entrance_EventScript_ClearWeather::
	setweather WEATHER_NONE
	doweather
	end

FarawayIsland_Entrance_EventScript_Sailor::
	lock
	faceplayer
	msgbox FarawayIsland_Entrance_Text_SailorReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FarawayIsland_Entrance_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_SAILOR, MAP_FARAWAY_ISLAND_ENTRANCE
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

FarawayIsland_Entrance_EventScript_AsYouLike::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

FarawayIsland_Entrance_EventScript_Sign::
	msgbox FarawayIsland_Entrance_Text_Sign, MSGBOX_SIGN
	end

FarawayIsland_Entrance_Text_Quake:
	.string "Something seemed to move from back\n"
	.string "within the forest…$"
