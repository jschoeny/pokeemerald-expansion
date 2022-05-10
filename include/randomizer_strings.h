enum {
    RAND_MENU_ITEM_TYPE,
    RAND_MENU_ITEM_ABILITY,
    RAND_MENU_ITEM_MOVE,
    RAND_MENU_ITEM_WILD,
    RAND_MENU_ITEM_TRAINER,
    RAND_MENU_ITEM_PALETTE,
    RAND_MENU_ITEM_CHALLENGE,
    RAND_MENU_ITEM_DONE,
};

static const u8 gRandText_Type[] = _("Type Settings");
static const u8 gRandText_Ability[] = _("Ability Settings");
static const u8 gRandText_Move[] = _("Move Settings");
static const u8 gRandText_Wild[] = _("Wild Encounters");
static const u8 gRandText_Trainer[] = _("Trainer Teams");
static const u8 gRandText_Palette[] = _("Palette Mode");
static const u8 gRandText_Challenge[] = _("Challenge Mode");
static const u8 gRandText_Done[] = _("Done");

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
static const u8 gRandText_Option_Yes[] = _("YES");
static const u8 gRandText_Option_No[] = _("NO");

static const u8 gRandMenuDesc_Type[]    = _("Change how the types of POKéMON\nare randomized.");
static const u8 gRandMenuDesc_Ability[] = _("Change how the abilities of POKéMON\nare randomized.");
static const u8 gRandMenuDesc_Move[]    = _("Change how the learnsets of POKéMON\nare randomized.");
static const u8 gRandMenuDesc_Wild[]    = _("Change how wild POKéMON encounters\nare randomized.");
static const u8 gRandMenuDesc_Trainer[] = _("Change how POKéMON TRAINER teams\nare randomized.");
static const u8 gRandMenuDesc_Palette[] = _("(Unfinished) POKéMON colors changed\nto match their new random types.");
static const u8 gRandMenuDesc_Challenge[]  = _("Increases difficulty, like giving\nall trainers CHAMPION-level AI.");
static const u8 gRandMenuDesc_Done[]    = _("Saves your current settings.\nTHIS CANNOT BE CHANGED ONCE SET!");
static const u8 gRandMenuDesc_Finish[]  = _("Are you sure you?\nTHIS CANNOT BE CHANGED ONCE SET!");

//TODO: Change to single-array with another const variable acting as pointers
static const u8 gRandMenuDesc_Type_Options_0[] = _("All POKéMON keep their original\ntypings.");
static const u8 gRandMenuDesc_Type_Options_1[] = _("Every individual POKéMON gets their\ntype(s) randomly swapped.");
static const u8 gRandMenuDesc_Type_Options_2[] = _("Every individual POKéMON is capable\nof having any type combination.");
static const u8 gRandMenuDesc_Type_Options_3[] = _("Random type combinations can change\nupon evolution.");

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
static const u8 gRandMenuDesc_Wild_Options_2[] = _("Wild POKéMON will be randomized\naccordingto their route/location.");
static const u8 gRandMenuDesc_Wild_Options_3[] = _("Every single wild encounter can\nbe any possible random POKéMON.");

static const u8 gRandMenuDesc_Trainer_Options_0[] = _("All POKéMON Trainers will keep\ntheir original team of POKéMON.");
static const u8 gRandMenuDesc_Trainer_Options_1[] = _("All POKéMON Trainers will have\neach species randomly swapped.");
static const u8 gRandMenuDesc_Trainer_Options_2[] = _("Each POKéMON Trainer will have\na random team of POKéMON.");
static const u8 gRandMenuDesc_Trainer_Options_3[] = _("POKéMON Trainers will a have a\nnew random team every rematch.");

static const u8 *const sRandMenuDescPointers[] =
{
    [RAND_MENU_ITEM_TYPE] = gRandMenuDesc_Type,
    [RAND_MENU_ITEM_ABILITY] = gRandMenuDesc_Ability,
    [RAND_MENU_ITEM_MOVE] = gRandMenuDesc_Move,
    [RAND_MENU_ITEM_WILD] = gRandMenuDesc_Wild,
    [RAND_MENU_ITEM_TRAINER] = gRandMenuDesc_Trainer,
    [RAND_MENU_ITEM_PALETTE] = gRandMenuDesc_Palette,
    [RAND_MENU_ITEM_CHALLENGE] = gRandMenuDesc_Challenge,
    [RAND_MENU_ITEM_DONE] = gRandMenuDesc_Done,
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
static const struct ListMenuItem sRandMenuOptionItems_Wild[] =
{
    [0] = {gRandText_Option_NoChange, 0},
    [1] = {gRandText_Option_BySpecies, 1},
    [2] = {gRandText_Option_ByArea, 2},
    [3] = {gRandText_Option_PureRandom, 3},
};
static const struct ListMenuItem sRandMenuOptionItems_Trainer[] =
{
    [0] = {gRandText_Option_NoChange, 0},
    [1] = {gRandText_Option_BySpecies, 1},
    [2] = {gRandText_Option_ByTrainer, 2},
    [3] = {gRandText_Option_PureRandom, 3},
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
    [RAND_MENU_ITEM_TYPE] = {gRandText_Type, RAND_MENU_ITEM_TYPE},
    [RAND_MENU_ITEM_ABILITY] = {gRandText_Ability, RAND_MENU_ITEM_ABILITY},
    [RAND_MENU_ITEM_MOVE] = {gRandText_Move, RAND_MENU_ITEM_MOVE},
    [RAND_MENU_ITEM_WILD] = {gRandText_Wild, RAND_MENU_ITEM_WILD},
    [RAND_MENU_ITEM_TRAINER] = {gRandText_Trainer, RAND_MENU_ITEM_TRAINER},
    [RAND_MENU_ITEM_PALETTE] = {gRandText_Palette, RAND_MENU_ITEM_PALETTE},
    [RAND_MENU_ITEM_CHALLENGE] = {gRandText_Challenge, RAND_MENU_ITEM_CHALLENGE},
    [RAND_MENU_ITEM_DONE] = {gRandText_Done, RAND_MENU_ITEM_DONE},
};