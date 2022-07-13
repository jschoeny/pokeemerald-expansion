Route117_PokemonDayCare_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
	.byte 0

Route117_PokemonDayCare_OnTransition:
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
	end

Route117_PokemonDayCare_EventScript_TypeBreeder::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TYPE_CHARM, Route117_PokemonDayCare_EventScript_TypeCharmExplanation
	msgbox Route117_PokemonDayCare_Text_UsedTypeCharm, MSGBOX_DEFAULT
	giveitem ITEM_TYPE_CHARM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route117_PokemonDayCare_Text_TypeCharmExplanation, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TYPE_CHARM
	release
	end

Route117_PokemonDayCare_EventScript_TypeCharmExplanation::
	msgbox Route117_PokemonDayCare_Text_TypeCharmExplanation, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_Kirlia::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_Kirlia, MSGBOX_DEFAULT
	waitmoncry
	release
	end


Route117_PokemonDayCare_Text_UsedTypeCharm:
	.string "I love Fairy-type POKéMON!\p"
	.string "Which is why I used this Type Charm\n"
	.string "to make it easier for Kirlia and I to\l"
	.string "find other Fairy POKéMON.\p"
	.string "But now I almost have more POKéMON\n"
	.string "than I can handle…\p"
	.string "Here, you can have it.\n"
	.string "I'm sure it will come in handy.$"

Route117_PokemonDayCare_Text_TypeCharmExplanation:
	.string "Give that Type Charm to any POKéMON\n"
	.string "in your party.\p"
	.string "Wild POKéMON will then be more likely\n"
	.string "to have the same type.$"

Route117_PokemonDayCare_Text_Kirlia:
	.string "Liiih!$"
