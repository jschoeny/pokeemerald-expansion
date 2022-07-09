enum {  // MAIN
    RAND_MENU_ITEM_SEED,
    RAND_MENU_ITEM_TYPE,
    RAND_MENU_ITEM_ABILITY,
    RAND_MENU_ITEM_MOVE,
    RAND_MENU_ITEM_SPECIES,
    RAND_MENU_ITEM_PALETTE,
    RAND_MENU_ITEM_CHALLENGE,
    RAND_MENU_ITEM_DONE,
};

enum {  // SPECIES
    RAND_MENU_ITEM_SPECIES_WILD,
    RAND_MENU_ITEM_SPECIES_TRAINER,
    RAND_MENU_ITEM_SPECIES_STARTERS,
    RAND_MENU_ITEM_SPECIES_FILTER,
    RAND_MENU_ITEM_SPECIES_SIMILAR,
    RAND_MENU_ITEM_SPECIES_DONE,
};

enum {  // CHALLENGE
    RAND_MENU_ITEM_CHALLENGE_STRONGERENEMIES,
    RAND_MENU_ITEM_CHALLENGE_LEVELCAP,
    RAND_MENU_ITEM_CHALLENGE_DELAYEDEXP,
    RAND_MENU_ITEM_CHALLENGE_DONE
};

static const u8 gRandText_MoreInfo[] = _("{FONT_NARROW}For more info:\n{FONT_NORMAL}{COLOR BLUE}{SHADOW LIGHT_BLUE}bit.ly/ErisDoc");

static const u8 gRandText_Seed[] = _("Seed");
static const u8 gRandText_Type[] = _("Type Settings");
static const u8 gRandText_Ability[] = _("Ability Settings");
static const u8 gRandText_Move[] = _("Move Settings");
static const u8 gRandText_Species[] = _("{COLOR BLUE}{SHADOW LIGHT_BLUE}Species Settings");
static const u8 gRandText_Palette[] = _("Palette Mode");
static const u8 gRandText_Challenge[] = _("{COLOR BLUE}{SHADOW LIGHT_BLUE}Challenge Mode");
static const u8 gRandText_Done[] = _("{COLOR RED}{SHADOW LIGHT_RED}DONE");
static const u8 gRandText_Back[] = _("BACK");

static const u8 gRandText_Species_Wild[] = _("Wild Encounters");
static const u8 gRandText_Species_Trainer[] = _("Trainer Teams");
static const u8 gRandText_Species_Starters[] = _("Starter POKéMON");
static const u8 gRandText_Species_Filter[] = _("Filter");
static const u8 gRandText_Species_Similar[] = _("Similar Stats");

static const u8 gRandText_Challenge_StrongerEnemies[] = _("Stronger Enemies");
static const u8 gRandText_Challenge_LevelCap[] = _("Level Cap");
static const u8 gRandText_Challenge_DelayedExp[] = _("EXP After Battle");

static const u8 gRandText_Option_NoChange[] = _("No change");
static const u8 gRandText_Option_PureRandom[] = _("Pure random");
static const u8 gRandText_Option_Enable[] = _("Enable");
static const u8 gRandText_Option_Disable[] = _("Disable");
static const u8 gRandText_Option_MatchType[] = _("Match type");
static const u8 gRandText_Option_1_1[] = _("1 to 1");
static const u8 gRandText_Option_1_2[] = _("1 to 2");
static const u8 gRandText_Option_BySpecies[] = _("By species");
static const u8 gRandText_Option_ByArea[] = _("By area");
static const u8 gRandText_Option_ByTrainer[] = _("By Trainer");
static const u8 gRandText_Option_AllMons[] = _("All POKéMON");
static const u8 gRandText_Option_TypeColors[] = _("Type Colors");
static const u8 gRandText_Option_HoennDex[] = _("Hoenn Dex");
static const u8 gRandText_Option_RareCandy[] = _("Rare Candy");
static const u8 gRandText_Option_Normal[] = _("Normal");
static const u8 gRandText_Option_Hard[] = _("Hard");
static const u8 gRandText_Option_Off[] = _("Off");
static const u8 gRandText_Option_Yes[] = _("YES");
static const u8 gRandText_Option_No[] = _("NO");

static const u8 gRandMenuDesc_Seed[]        = _("Change the randomizer seed.\n0000 uses your Trainer ID as the seed.");
static const u8 gRandMenuDesc_Type[]        = _("Change how the types of POKéMON\nare randomized.");
static const u8 gRandMenuDesc_Ability[]     = _("Change how the abilities of POKéMON\nare randomized.");
static const u8 gRandMenuDesc_Move[]        = _("Change how the learnsets of POKéMON\nare randomized.");
static const u8 gRandMenuDesc_Species[]     = _("Change how the species of POKéMON\nare randomized.");
static const u8 gRandMenuDesc_Palette[]     = _("(Unfinished) POKéMON colors changed\nto match their new random types.");
static const u8 gRandMenuDesc_Challenge[]   = _("Select to choose more difficulty\noptions.");
static const u8 gRandMenuDesc_Done[]        = _("Saves your current settings.\n{COLOR RED}{SHADOW LIGHT_RED}THIS CANNOT BE CHANGED ONCE SET!");
static const u8 gRandMenuDesc_Close[]       = _("Close the randomizer preview.");
static const u8 gRandMenuDesc_Finish[]      = _("Are you sure?\n{COLOR RED}{SHADOW LIGHT_RED}THIS CANNOT BE CHANGED ONCE SET!");

static const u8 gRandMenuDesc_Species_Wild[]    = _("Change how wild POKéMON encounters\nare randomized.");
static const u8 gRandMenuDesc_Species_Trainer[] = _("Change how POKéMON TRAINER teams\nare randomized.");
static const u8 gRandMenuDesc_Species_Starters[] = _("Change whether the starter POKéMON\nare randomized.");
static const u8 gRandMenuDesc_Species_Filter[] = _("Change what POKéMON can appear\nwhen randomized.");
static const u8 gRandMenuDesc_Species_Similar[] = _("POKéMON are only swapped with\nthose of similar strength.");
static const u8 gRandMenuDesc_Species_Done[] = _("Finish adjusting Species Settings.");

static const u8 gRandMenuDesc_Type_Options_0[] = _("All POKéMON keep their original\ntypings.");
static const u8 gRandMenuDesc_Type_Options_1[] = _("Every individual POKéMON gets their\ntype(s) randomly swapped.");
static const u8 gRandMenuDesc_Type_Options_2[] = _("Every individual POKéMON is capable\nof having any type combination.");
static const u8 gRandMenuDesc_Type_Options_3[] = _("Random type combinations randomize\nupon evolution.");

static const u8 gRandMenuDesc_Ability_Options_0[] = _("All POKéMON keep their original\nabilities.");
static const u8 gRandMenuDesc_Ability_Options_1[] = _("(Unfinished) Abilities determined\nby the random type of the POKéMON.");
static const u8 gRandMenuDesc_Ability_Options_2[] = _("Every species of POKéMON will get\na new random ability.");
static const u8 gRandMenuDesc_Ability_Options_3[] = _("Any individual POKéMON can have\nany possible ability.");

static const u8 gRandMenuDesc_Move_Options_0[] = _("All POKéMON keep their original\nmovepool.");
static const u8 gRandMenuDesc_Move_Options_1[] = _("(Unfinished) POKéMON will have\nmovepool changed to match typing.");
static const u8 gRandMenuDesc_Move_Options_2[] = _("Every species of POKéMON will get\na new random movepool.");
static const u8 gRandMenuDesc_Move_Options_3[] = _("Any individual POKéMON can have a\nmovepool of any variation.");

static const u8 gRandMenuDesc_Wild_Options_0[] = _("All wild POKéMON encounters will\nremain unchanged.");
static const u8 gRandMenuDesc_Wild_Options_1[] = _("Each species of POKéMON will be\nrandomly swapped out with another.");
static const u8 gRandMenuDesc_Wild_Options_2[] = _("Wild POKéMON will be randomized\naccording to their route/location.");
static const u8 gRandMenuDesc_Wild_Options_3[] = _("Every single wild encounter can\nbe any possible random POKéMON.");

static const u8 gRandMenuDesc_Trainer_Options_0[] = _("All POKéMON Trainers will keep\ntheir original team of POKéMON.");
static const u8 gRandMenuDesc_Trainer_Options_1[] = _("All POKéMON Trainers will have\neach species randomly swapped.");
static const u8 gRandMenuDesc_Trainer_Options_2[] = _("Each POKéMON Trainer will have\na random team of POKéMON.");
static const u8 gRandMenuDesc_Trainer_Options_3[] = _("POKéMON Trainers will a have a\nnew random team every rematch.");

static const u8 gRandMenuDesc_Species_Filter_Options_0[] = _("All species of POKéMON are used\nfor the randomizer.");
static const u8 gRandMenuDesc_Species_Filter_Options_1[] = _("Only POKéMON with the type-palette\nimplemented are used.");
static const u8 gRandMenuDesc_Species_Filter_Options_2[] = _("Only POKéMON that are in the\nHoenn dex are used.");

static const u8 gRandMenuDesc_Challenge_StrongerEnemies[] = _("Trainers are smarter, teams and wild\nPOKéMON are stronger.");
static const u8 gRandMenuDesc_Challenge_LevelCap[] = _("Limits ability to level up by the\nnumber of gym badges.");
static const u8 gRandMenuDesc_Challenge_DelayedExp[] = _("Experience not earned until after\nthe battle is won.");
static const u8 gRandMenuDesc_Challenge_Done[] = _("Finish adjusting Challenge Mode\nsettings.");

static const u8 gRandMenuDesc_Challenge_LevelCap_Options_0[] = _("POKéMON can level up like normal.");
static const u8 gRandMenuDesc_Challenge_LevelCap_Options_1[] = _("Rare Candies useless at the highest\nPOKéMON level of the next GYM.");
static const u8 gRandMenuDesc_Challenge_LevelCap_Options_2[] = _("Cannot level up past the highest\nPOKéMON level of the next GYM.");
static const u8 gRandMenuDesc_Challenge_LevelCap_Options_3[] = _("Cannot level up past the lowest\nPOKéMON level of the next GYM.");

static const u8 gRandText_Seed_Value0[]     = _("0");
static const u8 gRandText_Seed_Value1[]     = _("1");
static const u8 gRandText_Seed_Value2[]     = _("2");
static const u8 gRandText_Seed_Value3[]     = _("3");
static const u8 gRandText_Seed_Value4[]     = _("4");
static const u8 gRandText_Seed_Value5[]     = _("5");
static const u8 gRandText_Seed_Value6[]     = _("6");
static const u8 gRandText_Seed_Value7[]     = _("7");
static const u8 gRandText_Seed_Value8[]     = _("8");
static const u8 gRandText_Seed_Value9[]     = _("9");
static const u8 gRandText_Seed_ValueA[]     = _("A");
static const u8 gRandText_Seed_ValueB[]     = _("B");
static const u8 gRandText_Seed_ValueC[]     = _("C");
static const u8 gRandText_Seed_ValueD[]     = _("D");
static const u8 gRandText_Seed_ValueE[]     = _("E");
static const u8 gRandText_Seed_ValueF[]     = _("F");
static const u8 gRandText_Seed_Red[]        = _("{COLOR RED}{SHADOW LIGHT_RED}");
static const u8 gRandText_Seed_Normal[]     = _("{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}");
static const u8 gRandText_Seed_Space[]      = _(" ");
static const u8 gRandText_Seed_Random[]     = _("{FONT_NARROW}    RANDOM");
static const u8 gRandText_Seed_Reset[]      = _("{FONT_NARROW}     RESET");
static const u8 gRandText_Seed_Set[]        = _("{FONT_NARROW}      SET");
static const u8 gRandText_Seed_TrainerId[]  = _("{FONT_NARROW}Trainer ID No.");

static const u8 *const sRandMenuDescPointers[] =
{
    [RAND_MENU_ITEM_SEED] = gRandMenuDesc_Seed,
    [RAND_MENU_ITEM_TYPE] = gRandMenuDesc_Type,
    [RAND_MENU_ITEM_ABILITY] = gRandMenuDesc_Ability,
    [RAND_MENU_ITEM_MOVE] = gRandMenuDesc_Move,
    [RAND_MENU_ITEM_SPECIES] = gRandMenuDesc_Species,
    [RAND_MENU_ITEM_PALETTE] = gRandMenuDesc_Palette,
    [RAND_MENU_ITEM_CHALLENGE] = gRandMenuDesc_Challenge,
    [RAND_MENU_ITEM_DONE] = gRandMenuDesc_Done,
};

static const u8 *const sRandMenuDescPointers_Species[] =
{
    [RAND_MENU_ITEM_SPECIES_WILD] = gRandMenuDesc_Species_Wild,
    [RAND_MENU_ITEM_SPECIES_TRAINER] = gRandMenuDesc_Species_Trainer,
    [RAND_MENU_ITEM_SPECIES_STARTERS] = gRandMenuDesc_Species_Starters,
    [RAND_MENU_ITEM_SPECIES_FILTER] = gRandMenuDesc_Species_Filter,
    [RAND_MENU_ITEM_SPECIES_SIMILAR] = gRandMenuDesc_Species_Similar,
    [RAND_MENU_ITEM_SPECIES_DONE] = gRandMenuDesc_Species_Done,
};

static const u8 *const sRandMenuDescPointers_Challenge[] =
{
    [RAND_MENU_ITEM_CHALLENGE_STRONGERENEMIES] = gRandMenuDesc_Challenge_StrongerEnemies,
    [RAND_MENU_ITEM_CHALLENGE_LEVELCAP] = gRandMenuDesc_Challenge_LevelCap,
    [RAND_MENU_ITEM_CHALLENGE_DELAYEDEXP] = gRandMenuDesc_Challenge_DelayedExp,
    [RAND_MENU_ITEM_CHALLENGE_DONE] = gRandMenuDesc_Challenge_Done,
};

static const u8 *const sRandSeedCharacters[] =
{
    gRandText_Seed_Value0,
    gRandText_Seed_Value1,
    gRandText_Seed_Value2,
    gRandText_Seed_Value3,
    gRandText_Seed_Value4,
    gRandText_Seed_Value5,
    gRandText_Seed_Value6,
    gRandText_Seed_Value7,
    gRandText_Seed_Value8,
    gRandText_Seed_Value9,
    gRandText_Seed_ValueA,
    gRandText_Seed_ValueB,
    gRandText_Seed_ValueC,
    gRandText_Seed_ValueD,
    gRandText_Seed_ValueE,
    gRandText_Seed_ValueF,
};
static const u8 *const sRandOptionMenuDescPointers_Type[] =
{
    [0] = gRandMenuDesc_Type_Options_0,
    [1] = gRandMenuDesc_Type_Options_1,
    [2] = gRandMenuDesc_Type_Options_2,
    [3] = gRandMenuDesc_Type_Options_3,
};
static const u8 *const sRandOptionMenuDescPointers_Ability[] =
{
    [0] = gRandMenuDesc_Ability_Options_0,
    [1] = gRandMenuDesc_Ability_Options_1,
    [2] = gRandMenuDesc_Ability_Options_2,
    [3] = gRandMenuDesc_Ability_Options_3,
};
static const u8 *const sRandOptionMenuDescPointers_Move[] =
{
    [0] = gRandMenuDesc_Move_Options_0,
    [1] = gRandMenuDesc_Move_Options_1,
    [2] = gRandMenuDesc_Move_Options_2,
    [3] = gRandMenuDesc_Move_Options_3,
};
static const u8 *const sRandOptionMenuDescPointers_Wild[] =
{
    [0] = gRandMenuDesc_Wild_Options_0,
    [1] = gRandMenuDesc_Wild_Options_1,
    [2] = gRandMenuDesc_Wild_Options_2,
    [3] = gRandMenuDesc_Wild_Options_3,
};
static const u8 *const sRandOptionMenuDescPointers_Trainer[] =
{
    [0] = gRandMenuDesc_Trainer_Options_0,
    [1] = gRandMenuDesc_Trainer_Options_1,
    [2] = gRandMenuDesc_Trainer_Options_2,
    [3] = gRandMenuDesc_Trainer_Options_3,
};
static const u8 *const sRandOptionMenuDescPointers_Species_Filter[] =
{
    [0] = gRandMenuDesc_Species_Filter_Options_0,
    [1] = gRandMenuDesc_Species_Filter_Options_1,
    [2] = gRandMenuDesc_Species_Filter_Options_2,
};
static const u8 *const sRandOptionMenuDescPointers_Challenge_LevelCap[] =
{
    [0] = gRandMenuDesc_Challenge_LevelCap_Options_0,
    [1] = gRandMenuDesc_Challenge_LevelCap_Options_1,
    [2] = gRandMenuDesc_Challenge_LevelCap_Options_2,
    [3] = gRandMenuDesc_Challenge_LevelCap_Options_3,
};


static const struct ListMenuItem sRandMenuOptionItems_Type[] =
{
    [0] = {gRandText_Option_NoChange, 0},
    [1] = {gRandText_Option_1_1, 1},
    [2] = {gRandText_Option_1_2, 2},
    [3] = {gRandText_Option_PureRandom, 3},
};
static const struct ListMenuItem sRandMenuOptionItems_AbilityMove[] =
{
    [0] = {gRandText_Option_NoChange, 0},
    [1] = {gRandText_Option_MatchType, 1},
    [2] = {gRandText_Option_BySpecies, 2},
    [3] = {gRandText_Option_PureRandom, 3},
};
static const struct ListMenuItem sRandMenuOptionItems_Species_Wild[] =
{
    [0] = {gRandText_Option_NoChange, 0},
    [1] = {gRandText_Option_BySpecies, 1},
    [2] = {gRandText_Option_ByArea, 2},
    [3] = {gRandText_Option_PureRandom, 3},
};
static const struct ListMenuItem sRandMenuOptionItems_Species_Trainer[] =
{
    [0] = {gRandText_Option_NoChange, 0},
    [1] = {gRandText_Option_BySpecies, 1},
    [2] = {gRandText_Option_ByTrainer, 2},
    [3] = {gRandText_Option_PureRandom, 3},
};
static const struct ListMenuItem sRandMenuOptionItems_Species_Filter[] =
{
    [0] = {gRandText_Option_AllMons, 0},
    [1] = {gRandText_Option_TypeColors, 1},
    [2] = {gRandText_Option_HoennDex, 2},
};
static const struct ListMenuItem sRandMenuOptionItems_Challenge_LevelCap[] =
{
    [0] = {gRandText_Option_Off, 0},
    [1] = {gRandText_Option_RareCandy, 1},
    [2] = {gRandText_Option_Normal, 2},
    [3] = {gRandText_Option_Hard, 3},
};
static const struct ListMenuItem sRandMenuOptionItems_Toggle[] =
{
    [0] = {gRandText_Option_Enable, 0},
    [1] = {gRandText_Option_Disable, 1},
};
static const struct ListMenuItem sRandMenuOptionItems_YesNo[] =
{
    [0] = {gRandText_Option_Yes, 0},
    [1] = {gRandText_Option_No, 1},
};

static const struct ListMenuItem sRandMenuItems[] =
{
    [RAND_MENU_ITEM_SEED] = {gRandText_Seed, RAND_MENU_ITEM_SEED},
    [RAND_MENU_ITEM_TYPE] = {gRandText_Type, RAND_MENU_ITEM_TYPE},
    [RAND_MENU_ITEM_ABILITY] = {gRandText_Ability, RAND_MENU_ITEM_ABILITY},
    [RAND_MENU_ITEM_MOVE] = {gRandText_Move, RAND_MENU_ITEM_MOVE},
    [RAND_MENU_ITEM_SPECIES] = {gRandText_Species, RAND_MENU_ITEM_SPECIES},
    [RAND_MENU_ITEM_PALETTE] = {gRandText_Palette, RAND_MENU_ITEM_PALETTE},
    [RAND_MENU_ITEM_CHALLENGE] = {gRandText_Challenge, RAND_MENU_ITEM_CHALLENGE},
    [RAND_MENU_ITEM_DONE] = {gRandText_Done, RAND_MENU_ITEM_DONE},
};

static const struct ListMenuItem sRandMenuItems_Species[] =
{
    [RAND_MENU_ITEM_SPECIES_WILD] = {gRandText_Species_Wild, RAND_MENU_ITEM_SPECIES_WILD},
    [RAND_MENU_ITEM_SPECIES_TRAINER] = {gRandText_Species_Trainer, RAND_MENU_ITEM_SPECIES_TRAINER},
    [RAND_MENU_ITEM_SPECIES_STARTERS] = {gRandText_Species_Starters, RAND_MENU_ITEM_SPECIES_STARTERS},
    [RAND_MENU_ITEM_SPECIES_FILTER] = {gRandText_Species_Filter, RAND_MENU_ITEM_SPECIES_FILTER},
    [RAND_MENU_ITEM_SPECIES_SIMILAR] = {gRandText_Species_Similar, RAND_MENU_ITEM_SPECIES_SIMILAR},
    [RAND_MENU_ITEM_SPECIES_DONE] = {gRandText_Back, RAND_MENU_ITEM_SPECIES_DONE},
};

static const struct ListMenuItem sRandMenuItems_Challenge[] =
{
    [RAND_MENU_ITEM_CHALLENGE_STRONGERENEMIES] = {gRandText_Challenge_StrongerEnemies, RAND_MENU_ITEM_CHALLENGE_STRONGERENEMIES},
    [RAND_MENU_ITEM_CHALLENGE_LEVELCAP] = {gRandText_Challenge_LevelCap, RAND_MENU_ITEM_CHALLENGE_LEVELCAP},
    [RAND_MENU_ITEM_CHALLENGE_DELAYEDEXP] = {gRandText_Challenge_DelayedExp, RAND_MENU_ITEM_CHALLENGE_DELAYEDEXP},
    [RAND_MENU_ITEM_CHALLENGE_DONE] = {gRandText_Back, RAND_MENU_ITEM_CHALLENGE_DONE},
};
