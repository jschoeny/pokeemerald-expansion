Mart_Clerk_EventScript_HowMayIServeYou::
	goto_if_set FLAG_IS_CHAMPION, Mart_Clerk_EventScript_HowMayIServeYouChampion
	message gText_HowMayIServeYou
	return

Mart_Clerk_EventScript_HowMayIServeYouChampion::
	message gText_HowMayIServeYouChampion
	return

gText_HowMayIServeYou::
	.string "Welcome!\p"
	.string "How may I serve you?$"

gText_HowMayIServeYouChampion::
	.string "Welcome, Champion!\p"
	.string "How may I serve you?$"

gText_PleaseComeAgain::
	.string "Please come again!$"

gText_PlayerWhatCanIDoForYou::
	.string "{PLAYER}{STRING 5}, welcome!\p"
	.string "What can I do for you?$"
