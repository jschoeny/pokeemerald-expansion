#include "global.h"
#include "event_data.h"
#include "list_menu.h"
#include "main.h"
#include "map_name_popup.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "script.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text_window.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "mgba_printf/mgba.h"
#include "randomizer.h"
#include "randomizer_strings.h"

#define RAND_MENU_HEIGHT 12
#define RAND_MENU_WIDTH 14
#define RAND_MENU_WINDOW2 (RAND_MENU_HEIGHT * RAND_MENU_WIDTH)

#define RAND_DATA_TASK              0
#define RAND_DATA_WIN               1
#define RAND_DATA_HELP              2
#define RAND_DATA_VAR               3
#define RAND_DATA_OPT               4
#define RAND_DATA_POS               5
#define RAND_DATA_OPT_TSK           6
#define RAND_DATA_OPT_POS           7
#define RAND_DATA_SEED_POS1         8
#define RAND_DATA_SEED_POS2         9
#define RAND_DATA_SEED_POS3         10
#define RAND_DATA_SEED_POS4         11
#define RAND_DATA_SEED_POSSETTING   12
#define RAND_DATA_SEED_CURRPOS      13
#define RAND_DATA_MORE_TSK          14
#define RAND_DATA_CHANGE            15

void Rand_ShowMainMenu(void);
void Rand_ShowMainMenuView(bool8);
static void Rand_DestroyMainMenu(u8);
static void Rand_OpenMoreInfo(u8);
static void Rand_DestroyMoreInfo(u8);
static void RandAction_OpenMoreOptions(u8);
static void RandAction_OpenSeedChooser(u8);
static void RandAction_OpenOption(u8);
static void RandAction_Set(u8);
static void RandAction_Done(u8);
static void RandAction_Exit(u8);
static void RandTask_HandleMainMenuInput(u8);
static void RandTask_HandleMoreInput(u8);
static void RandTask_HandleSeedChooserInput(u8);
static void RandTask_HandleOptionInput(u8 taskId);
static void RandHelper_DescText(u8 taskId, u8 pos);
static void RandHelper_ChallengeDescText(u8 taskId, u8 pos);
static void RandHelper_SpeciesDescText(u8 taskId, u8 pos);
static void RandHelper_OptionDescText(u8 helpWindowId, u8 posWin, u8 pos, u8 moreTaskId);
static void RandHelper_SetSaveBlockOption(u8 moreTaskId, u8 option, u16 value);
static u16 RandHelper_GetSaveBlockOption(u8 option);
static u16 RandHelper_GetSaveBlockOptionMore(u8 posWin, u8 option);
static u16 RandHelper_SeedPositionsToValue(u8 taskId);
static void RandHelper_SetSeedDataFromValue(u8 taskId);

static void (*const sRandMenuActions[])(u8) =
{
    [RAND_MENU_ITEM_SEED] = RandAction_OpenSeedChooser,
    [RAND_MENU_ITEM_TYPE] = RandAction_OpenOption,
    [RAND_MENU_ITEM_ABILITY] = RandAction_OpenOption,
    [RAND_MENU_ITEM_MOVE] = RandAction_OpenOption,
    [RAND_MENU_ITEM_SPECIES] = RandAction_OpenMoreOptions,
    [RAND_MENU_ITEM_PALETTE] = RandAction_OpenOption,
    [RAND_MENU_ITEM_CHALLENGE] = RandAction_OpenMoreOptions,
    [RAND_MENU_ITEM_DONE] = RandAction_OpenOption,
};

static void (*const sRandMenuActions_Species[])(u8) =
{
    [RAND_MENU_ITEM_SPECIES_WILD] = RandAction_OpenOption,
    [RAND_MENU_ITEM_SPECIES_TRAINER] = RandAction_OpenOption,
    [RAND_MENU_ITEM_SPECIES_STARTERS] = RandAction_OpenOption,
    [RAND_MENU_ITEM_SPECIES_FILTER] = RandAction_OpenOption,
    [RAND_MENU_ITEM_SPECIES_SIMILAR] = RandAction_OpenOption,
    [RAND_MENU_ITEM_SPECIES_DONE] = NULL,
};

static void (*const sRandMenuActions_Challenge[])(u8) =
{
    [RAND_MENU_ITEM_CHALLENGE_STRONGERENEMIES] = RandAction_OpenOption,
    [RAND_MENU_ITEM_CHALLENGE_TRAINER_KEEPTYPE] = RandAction_OpenOption,
    [RAND_MENU_ITEM_CHALLENGE_LEVELCAP] = RandAction_OpenOption,
    [RAND_MENU_ITEM_CHALLENGE_DELAYEDEXP] = RandAction_OpenOption,
    [RAND_MENU_ITEM_CHALLENGE_NOEVS] = RandAction_OpenOption,
    [RAND_MENU_ITEM_CHALLENGE_DONE] = NULL,
};

static const struct WindowTemplate sRandMenuWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = RAND_MENU_WIDTH,
    .height = RAND_MENU_HEIGHT,
    .paletteNum = 15,
    .baseBlock = 1,
};

static const struct WindowTemplate sRandHelpWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 2,
    .tilemapTop = 15,
    .width = 27,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 1 + RAND_MENU_WINDOW2,
};

static const struct WindowTemplate sRandVarWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = RAND_MENU_WIDTH + 4,
    .tilemapTop = 11,
    .width = 10,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 1 + RAND_MENU_WINDOW2 + 110,
};

static const struct ListMenuTemplate sRandMenuListTemplate =
{
    .items = sRandMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .totalItems = ARRAY_COUNT(sRandMenuItems),
    .maxShowed = RAND_MENU_HEIGHT / 2,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = 1,
    .cursorKind = 0
};

static const struct WindowTemplate sRandMoreInfoWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = RAND_MENU_WIDTH + 5,
    .tilemapTop = 1,
    .width = 10,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 1 + RAND_MENU_WINDOW2 + 110 + 20,
};
static const struct WindowTemplate sRandSetWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = RAND_MENU_WIDTH + 3,
    .tilemapTop = 1,
    .width = 10,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 1 + RAND_MENU_WINDOW2 + 110 + 20,
};
static const struct WindowTemplate sRandYesNoWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = RAND_MENU_WIDTH + 7,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 1 + RAND_MENU_WINDOW2 + 110 + 20,
};
static const struct WindowTemplate sRandToggleWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = RAND_MENU_WIDTH + 3,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 1 + RAND_MENU_WINDOW2 + 110 + 20,
};
static const struct ListMenuTemplate sRandSetListTemplate =
{
    .items = 0,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .totalItems = ARRAY_COUNT(sRandMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = 1,
    .cursorKind = 0
};

void Rand_ShowMainMenu(void) {
    Rand_ShowMainMenuView(TRUE);
}

void Rand_ShowMainMenuView(bool8 changeSettings) {
    struct ListMenuTemplate menuTemplate;
    u8 windowId, helpWindowId, varWindowId;
    u8 menuTaskId;
    u8 inputTaskId;
    u8 i;

    MgbaPrintf(MGBA_LOG_INFO, "--RANDOMIZER SETTINGS--");
    MgbaPrintf(MGBA_LOG_INFO, "  Version: %d", gSaveBlock2Ptr->optionsRandomizerVersion);
    MgbaPrintf(MGBA_LOG_INFO, "  Seed: %x", gSaveBlock2Ptr->optionsRandomizerSeed);
    MgbaPrintf(MGBA_LOG_INFO, "  Type: %d", gSaveBlock2Ptr->optionsRandomizerType);
    MgbaPrintf(MGBA_LOG_INFO, "  Ability: %d", gSaveBlock2Ptr->optionsRandomizerAbility);
    MgbaPrintf(MGBA_LOG_INFO, "  Moves: %d", gSaveBlock2Ptr->optionsRandomizerMoves);
    MgbaPrintf(MGBA_LOG_INFO, "  --SPECIES--");
    MgbaPrintf(MGBA_LOG_INFO, "    Wild: %d", gSaveBlock2Ptr->optionsRandomizerWild);
    MgbaPrintf(MGBA_LOG_INFO, "    Trainer: %d", gSaveBlock2Ptr->optionsRandomizerTrainer);
    MgbaPrintf(MGBA_LOG_INFO, "    Starter: %d", gSaveBlock2Ptr->optionsRandomizerStarter);
    MgbaPrintf(MGBA_LOG_INFO, "    Filter: %x", gSaveBlock2Ptr->optionsRandomizerSpeciesFilter);
    MgbaPrintf(MGBA_LOG_INFO, "    Pal Ready Only: %d", FlagGet(FLAG_RNDM_PALETTE_READY_ONLY));
    MgbaPrintf(MGBA_LOG_INFO, "    Similar Stats: %d", FlagGet(FLAG_RNDM_SIMILAR_STATS));
    MgbaPrintf(MGBA_LOG_INFO, "  Palette: %d", gSaveBlock2Ptr->optionsRandomizerPalette);
    MgbaPrintf(MGBA_LOG_INFO, "  --CHALLENGE--");
    MgbaPrintf(MGBA_LOG_INFO, "    Stronger Teams: %d", gSaveBlock2Ptr->optionsChallengeStrongerTeams);
    MgbaPrintf(MGBA_LOG_INFO, "    Level Cap: %d", gSaveBlock2Ptr->optionsChallengeLevelCap);
    MgbaPrintf(MGBA_LOG_INFO, "    Delayed Exp: %d", FlagGet(FLAG_DIFF_DELAYEDEXP));
    MgbaPrintf(MGBA_LOG_INFO, "    No EVs: %d", FlagGet(FLAG_DIFF_NOEVS));

    // create window
    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sRandMenuWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);

    helpWindowId = AddWindow(&sRandHelpWindowTemplate);
    DrawDialogueFrame(helpWindowId, FALSE);

    LoadUserWindowBorderGfx(0, 0x250, 0xd0);
    varWindowId = AddWindow(&sRandVarWindowTemplate);
    DrawStdWindowFrame(varWindowId, FALSE);

    // create list menu
    menuTemplate = sRandMenuListTemplate;
    menuTemplate.windowId = windowId;
    menuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    // draw everything
    CopyWindowToVram(windowId, 3);

    // create input handler task
    inputTaskId = CreateTask(RandTask_HandleMainMenuInput, 3);
    gTasks[inputTaskId].data[RAND_DATA_TASK] = menuTaskId;
    gTasks[inputTaskId].data[RAND_DATA_WIN] = windowId;
    gTasks[inputTaskId].data[RAND_DATA_HELP] = helpWindowId;
    gTasks[inputTaskId].data[RAND_DATA_VAR] = varWindowId;
    gTasks[inputTaskId].data[RAND_DATA_OPT] = 0;
    gTasks[inputTaskId].data[RAND_DATA_POS] = 0;
    gTasks[inputTaskId].data[RAND_DATA_OPT_TSK] = 0;
    gTasks[inputTaskId].data[RAND_DATA_OPT_POS] = 0;
    if(changeSettings) {
        gSaveBlock2Ptr->optionsRandomizerVersion = OPTIONS_RANDOMIZER_VERSION;
        for(i = 0; i < 4; i++)
        {
            gTasks[inputTaskId].data[RAND_DATA_SEED_POS1 + i] = Random() % 0x10;
        }
    }
    else {
        RandHelper_SetSeedDataFromValue(inputTaskId);
    }
    gTasks[inputTaskId].data[RAND_DATA_SEED_CURRPOS] = 0xFF;
    gTasks[inputTaskId].data[RAND_DATA_CHANGE] = changeSettings;

    gSaveBlock2Ptr->optionsRandomizerSeed = RandHelper_SeedPositionsToValue(inputTaskId);

    RandHelper_DescText(inputTaskId, 0);
    CopyWindowToVram(helpWindowId, 3);
    CopyWindowToVram(varWindowId, 3);

    Rand_OpenMoreInfo(inputTaskId);
}

static void Rand_DestroyMainMenu(u8 taskId)
{
    ClearDialogWindowAndFrame(gTasks[taskId].data[RAND_DATA_HELP], TRUE);
    RemoveWindow(gTasks[taskId].data[RAND_DATA_HELP]);
    if(gTasks[taskId].data[RAND_DATA_VAR] != 0) {
        ClearStdWindowAndFrame(gTasks[taskId].data[RAND_DATA_VAR], TRUE);
        RemoveWindow(gTasks[taskId].data[RAND_DATA_VAR]);
    }
    DestroyListMenuTask(gTasks[taskId].data[RAND_DATA_TASK], NULL, NULL);
    ClearStdWindowAndFrame(gTasks[taskId].data[RAND_DATA_WIN], TRUE);
    RemoveWindow(gTasks[taskId].data[RAND_DATA_WIN]);
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

static void Rand_OpenMoreInfo(u8 taskId)
{
    u8 windowId;

    LoadUserWindowBorderGfx(0, 0x250, 0xd0);
    windowId = AddWindow(&sRandMoreInfoWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);
    gTasks[taskId].data[RAND_DATA_OPT] = windowId;

    AddTextPrinterParameterized(windowId, FONT_NORMAL, gRandText_MoreInfo, 2, 0, 0, NULL);
    CopyWindowToVram(windowId, 3);
}

static void Rand_DestroyMoreInfo(u8 taskId)
{
    ClearStdWindowAndFrame(gTasks[taskId].data[RAND_DATA_OPT], TRUE);
    RemoveWindow(gTasks[taskId].data[RAND_DATA_OPT]);
    gTasks[taskId].data[RAND_DATA_OPT] = 0;
}

static void RandTask_HandleMainMenuInput(u8 taskId)
{
    void (*func)(u8);
    u32 input = ListMenu_ProcessInput(gTasks[taskId].data[RAND_DATA_TASK]);
    u8 helpWindowId = gTasks[taskId].data[RAND_DATA_HELP];
    u8 varWindowId = gTasks[taskId].data[RAND_DATA_VAR];
    u8 pos = gTasks[taskId].data[RAND_DATA_POS];

    struct ListMenu *list = (void*) gTasks[gTasks[taskId].data[RAND_DATA_TASK]].data;
    if(pos != list->scrollOffset + list->selectedRow)
    {
        gTasks[taskId].data[RAND_DATA_POS] = list->scrollOffset + list->selectedRow;

        if(gTasks[taskId].data[RAND_DATA_POS] == RAND_MENU_ITEM_DONE
         || gTasks[taskId].data[RAND_DATA_POS] == RAND_MENU_ITEM_CHALLENGE
         || gTasks[taskId].data[RAND_DATA_POS] == RAND_MENU_ITEM_SPECIES) {
            if(gTasks[taskId].data[RAND_DATA_VAR] != 0) {
                ClearStdWindowAndFrame(gTasks[taskId].data[RAND_DATA_VAR], TRUE);
                RemoveWindow(gTasks[taskId].data[RAND_DATA_VAR]);
                gTasks[taskId].data[RAND_DATA_VAR] = 0;
            }
        }
        else if(gTasks[taskId].data[RAND_DATA_VAR] == 0){
            u8 varWindowId;
            LoadUserWindowBorderGfx(0, 0x250, 0xd0);
            varWindowId = AddWindow(&sRandVarWindowTemplate);
            DrawStdWindowFrame(varWindowId, FALSE);
            gTasks[taskId].data[RAND_DATA_VAR] = varWindowId;
            CopyWindowToVram(varWindowId, 3);
        }

        RandHelper_DescText(taskId, list->scrollOffset + list->selectedRow);
    }
    if(gTasks[taskId].data[RAND_DATA_CHANGE])
    {
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            if ((func = sRandMenuActions[input]) != NULL)
                func(taskId);
        }
    }
    else
    {
        if ((gMain.newKeys & A_BUTTON) && (sRandMenuActions[input] == RandAction_OpenMoreOptions))
        {
            PlaySE(SE_SELECT);
            if ((func = sRandMenuActions[input]) != NULL)
                func(taskId);
        }
        if(gMain.newKeys & B_BUTTON || (gMain.newKeys & A_BUTTON && pos == RAND_MENU_ITEM_DONE))
        {
            PlaySE(SE_PC_OFF);
            Rand_DestroyMoreInfo(taskId);
            Rand_DestroyMainMenu(taskId);
            ClearStdWindowAndFrameToTransparent(0, FALSE);
            ClearWindowTilemap(0);
        }
    }
}

static void RandAction_OpenMoreOptions(u8 taskId)
{
    struct ListMenuTemplate menuTemplate;
    u8 posWin = gTasks[taskId].data[RAND_DATA_POS];
    u8 helpWindowId = gTasks[taskId].data[RAND_DATA_HELP];
    u8 menuTaskId;
    u8 varWindowId;

    LoadUserWindowBorderGfx(0, 0x250, 0xd0);
    varWindowId = AddWindow(&sRandVarWindowTemplate);
    DrawStdWindowFrame(varWindowId, FALSE);
    gTasks[taskId].data[RAND_DATA_VAR] = varWindowId;
    CopyWindowToVram(varWindowId, 3);

    menuTemplate = sRandMenuListTemplate;
    if(posWin == RAND_MENU_ITEM_SPECIES) {
        menuTemplate.items = sRandMenuItems_Species;
        menuTemplate.totalItems = ARRAY_COUNT(sRandMenuItems_Species);
    }
    else if(posWin == RAND_MENU_ITEM_CHALLENGE) {
        menuTemplate.items = sRandMenuItems_Challenge;
        menuTemplate.totalItems = ARRAY_COUNT(sRandMenuItems_Challenge);
    }
    if(posWin == RAND_MENU_ITEM_CHALLENGE)
        RandHelper_ChallengeDescText(taskId, 0);
    else if(posWin == RAND_MENU_ITEM_SPECIES)
        RandHelper_SpeciesDescText(taskId, 0);

    menuTemplate.windowId = gTasks[taskId].data[RAND_DATA_WIN];
    menuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    gTasks[taskId].data[RAND_DATA_MORE_TSK] = menuTaskId;
    gTasks[menuTaskId].data[RAND_DATA_POS] = 0;
    gTasks[taskId].func = RandTask_HandleMoreInput;
}

static void RandTask_HandleMoreInput(u8 taskId)
{
    void (*func)(u8);
    u32 input = ListMenu_ProcessInput(gTasks[taskId].data[RAND_DATA_MORE_TSK]);
    u8 posMain = gTasks[taskId].data[RAND_DATA_POS];
    u8 moreTaskId = gTasks[taskId].data[RAND_DATA_MORE_TSK];
    u8 helpWindowId = gTasks[taskId].data[RAND_DATA_HELP];
    u8 pos = gTasks[moreTaskId].data[RAND_DATA_POS];

    struct ListMenu *list = (void*) gTasks[moreTaskId].data;
    if(pos != list->scrollOffset + list->selectedRow)
    {
        u8 donePos = 0xFF;
        if(posMain == RAND_MENU_ITEM_SPECIES)
            donePos = RAND_MENU_ITEM_SPECIES_DONE;
        else if(posMain == RAND_MENU_ITEM_CHALLENGE)
            donePos = RAND_MENU_ITEM_CHALLENGE_DONE;

        gTasks[moreTaskId].data[RAND_DATA_POS] = list->scrollOffset + list->selectedRow;

        if(gTasks[moreTaskId].data[RAND_DATA_POS] == donePos) {
            if(gTasks[taskId].data[RAND_DATA_VAR] != 0) {
                ClearStdWindowAndFrame(gTasks[taskId].data[RAND_DATA_VAR], TRUE);
                RemoveWindow(gTasks[taskId].data[RAND_DATA_VAR]);
                gTasks[taskId].data[RAND_DATA_VAR] = 0;
            }
        }
        else if(gTasks[taskId].data[RAND_DATA_VAR] == 0){
            u8 varWindowId;
            LoadUserWindowBorderGfx(0, 0x250, 0xd0);
            varWindowId = AddWindow(&sRandVarWindowTemplate);
            DrawStdWindowFrame(varWindowId, FALSE);
            gTasks[taskId].data[RAND_DATA_VAR] = varWindowId;
            CopyWindowToVram(varWindowId, 3);
        }
        if(posMain == RAND_MENU_ITEM_CHALLENGE)
            RandHelper_ChallengeDescText(taskId, list->scrollOffset + list->selectedRow);
        else if(posMain == RAND_MENU_ITEM_SPECIES)
            RandHelper_SpeciesDescText(taskId, list->scrollOffset + list->selectedRow);
    }
    if(gTasks[taskId].data[RAND_DATA_CHANGE]
     || (gTasks[taskId].data[RAND_DATA_POS] == RAND_MENU_ITEM_SPECIES
        && gTasks[moreTaskId].data[RAND_DATA_POS] == RAND_MENU_ITEM_SPECIES_DONE)
     || (gTasks[taskId].data[RAND_DATA_POS] == RAND_MENU_ITEM_CHALLENGE
        && gTasks[moreTaskId].data[RAND_DATA_POS] == RAND_MENU_ITEM_CHALLENGE_DONE)
     )
    {
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            if(gTasks[taskId].data[RAND_DATA_POS] == RAND_MENU_ITEM_SPECIES) {
                if(gTasks[moreTaskId].data[RAND_DATA_POS] == RAND_MENU_ITEM_SPECIES_DONE) {
                    PlaySE(SE_SELECT);
                    DestroyListMenuTask(gTasks[taskId].data[RAND_DATA_MORE_TSK], NULL, NULL);
                    gTasks[taskId].data[RAND_DATA_MORE_TSK] = 0;
                    RedrawListMenu(gTasks[taskId].data[RAND_DATA_TASK]);
                    RandHelper_DescText(taskId, posMain);
                    gTasks[taskId].func = RandTask_HandleMainMenuInput;
                }
                else {
                    if ((func = sRandMenuActions_Species[input]) != NULL)
                        func(taskId);
                }
            }
            else if(gTasks[taskId].data[RAND_DATA_POS] == RAND_MENU_ITEM_CHALLENGE) {
                if(gTasks[moreTaskId].data[RAND_DATA_POS] == RAND_MENU_ITEM_CHALLENGE_DONE) {
                    PlaySE(SE_SELECT);
                    DestroyListMenuTask(gTasks[taskId].data[RAND_DATA_MORE_TSK], NULL, NULL);
                    gTasks[taskId].data[RAND_DATA_MORE_TSK] = 0;
                    RedrawListMenu(gTasks[taskId].data[RAND_DATA_TASK]);
                    RandHelper_DescText(taskId, posMain);
                    gTasks[taskId].func = RandTask_HandleMainMenuInput;
                }
                else {
                    if ((func = sRandMenuActions_Challenge[input]) != NULL)
                        func(taskId);
                }
            }
        }
    }

    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        DestroyListMenuTask(gTasks[taskId].data[RAND_DATA_MORE_TSK], NULL, NULL);
        gTasks[taskId].data[RAND_DATA_MORE_TSK] = 0;
        RedrawListMenu(gTasks[taskId].data[RAND_DATA_TASK]);
        RandHelper_DescText(taskId, posMain);
        if(gTasks[taskId].data[RAND_DATA_VAR] != 0) {
            ClearStdWindowAndFrame(gTasks[taskId].data[RAND_DATA_VAR], TRUE);
            RemoveWindow(gTasks[taskId].data[RAND_DATA_VAR]);
            gTasks[taskId].data[RAND_DATA_VAR] = 0;
        }
        gTasks[taskId].func = RandTask_HandleMainMenuInput;
    }
}

static void RandAction_OpenSeedChooser(u8 taskId)
{
    gTasks[taskId].data[RAND_DATA_SEED_CURRPOS] = 0;
    gTasks[taskId].data[RAND_DATA_SEED_POSSETTING] = 0;
    RandHelper_DescText(taskId, 0);
    gTasks[taskId].func = RandTask_HandleSeedChooserInput;
}

static void RandAction_OpenOption(u8 taskId)
{
    struct ListMenuTemplate menuTemplate;
    struct ListMenu *list;
    u8 menuTaskId;
    u8 pos = 1;
    u8 posWin = gTasks[taskId].data[RAND_DATA_POS];
    u8 helpWindowId = gTasks[taskId].data[RAND_DATA_HELP];
    u8 moreTaskId = gTasks[taskId].data[RAND_DATA_MORE_TSK];
    u8 optionId;

    Rand_DestroyMoreInfo(taskId);

    if(moreTaskId == 0) {
        if(posWin == RAND_MENU_ITEM_DONE)
            optionId = AddWindow(&sRandYesNoWindowTemplate);
        else if(posWin == RAND_MENU_ITEM_PALETTE)
            optionId = AddWindow(&sRandToggleWindowTemplate);
        else
            optionId = AddWindow(&sRandSetWindowTemplate);
        DrawStdWindowFrame(optionId, FALSE);

        menuTemplate = sRandSetListTemplate;
        if(posWin == RAND_MENU_ITEM_TYPE) {
            menuTemplate.items = sRandMenuOptionItems_Type;
            menuTemplate.totalItems = ARRAY_COUNT(sRandMenuOptionItems_Type);
        }
        else if(posWin == RAND_MENU_ITEM_ABILITY || posWin == RAND_MENU_ITEM_MOVE) {
            menuTemplate.items = sRandMenuOptionItems_AbilityMove;
            menuTemplate.totalItems = ARRAY_COUNT(sRandMenuOptionItems_AbilityMove);
        }
        else if(posWin == RAND_MENU_ITEM_PALETTE) {
            menuTemplate.items = sRandMenuOptionItems_Toggle;
            menuTemplate.totalItems = ARRAY_COUNT(sRandMenuOptionItems_Toggle);
        }
        else {
            menuTemplate.items = sRandMenuOptionItems_YesNo;
            menuTemplate.totalItems = ARRAY_COUNT(sRandMenuOptionItems_YesNo);
        }
    }
    else {
        u8 posWinMore = gTasks[moreTaskId].data[RAND_DATA_POS];
        if(posWin == RAND_MENU_ITEM_SPECIES) {
            if(posWinMore == RAND_MENU_ITEM_SPECIES_STARTERS
             || posWinMore == RAND_MENU_ITEM_SPECIES_SIMILAR)
                optionId = AddWindow(&sRandToggleWindowTemplate);
            else
                optionId = AddWindow(&sRandSetWindowTemplate);
            DrawStdWindowFrame(optionId, FALSE);

            menuTemplate = sRandSetListTemplate;
            if(posWinMore == RAND_MENU_ITEM_SPECIES_WILD) {
                menuTemplate.items = sRandMenuOptionItems_Species_Wild;
                menuTemplate.totalItems = ARRAY_COUNT(sRandMenuOptionItems_Species_Wild);
            }
            else if(posWinMore == RAND_MENU_ITEM_SPECIES_TRAINER) {
                menuTemplate.items = sRandMenuOptionItems_Species_Trainer;
                menuTemplate.totalItems = ARRAY_COUNT(sRandMenuOptionItems_Species_Trainer);
            }
            else if(posWinMore == RAND_MENU_ITEM_SPECIES_FILTER) {
                menuTemplate.items = sRandMenuOptionItems_Species_Filter;
                menuTemplate.totalItems = ARRAY_COUNT(sRandMenuOptionItems_Species_Filter);
            }
            else if(posWinMore == RAND_MENU_ITEM_SPECIES_STARTERS
             || posWinMore == RAND_MENU_ITEM_SPECIES_SIMILAR) {
                 menuTemplate.items = sRandMenuOptionItems_Toggle;
                 menuTemplate.totalItems = ARRAY_COUNT(sRandMenuOptionItems_Toggle);
            }
        }
        else if(posWin == RAND_MENU_ITEM_CHALLENGE) {
            if(posWinMore == RAND_MENU_ITEM_CHALLENGE_LEVELCAP)
                optionId = AddWindow(&sRandSetWindowTemplate);
            else
                optionId = AddWindow(&sRandToggleWindowTemplate);
            DrawStdWindowFrame(optionId, FALSE);

            menuTemplate = sRandSetListTemplate;
            if(posWinMore == RAND_MENU_ITEM_CHALLENGE_LEVELCAP) {
                menuTemplate.items = sRandMenuOptionItems_Challenge_LevelCap;
                menuTemplate.totalItems = ARRAY_COUNT(sRandMenuOptionItems_Challenge_LevelCap);
            }
            else {
                menuTemplate.items = sRandMenuOptionItems_Toggle;
                menuTemplate.totalItems = ARRAY_COUNT(sRandMenuOptionItems_Toggle);
            }
        }
    }
    menuTemplate.windowId = optionId;
    menuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    gTasks[taskId].data[RAND_DATA_OPT] = optionId;
    gTasks[taskId].data[RAND_DATA_OPT_TSK] = menuTaskId;

    list = (void*) gTasks[menuTaskId].data;

    if(moreTaskId == 0) {
        if(posWin < RAND_MENU_ITEM_DONE)
            pos = RandHelper_GetSaveBlockOption(RAND_MENU_ITEM_SEED + posWin);
        else
            pos = 1;

        if(pos > 0)
            ListMenuChangeSelection(list, TRUE, pos, TRUE);
    }
    else {
        u8 posWinMore = gTasks[moreTaskId].data[RAND_DATA_POS];
        pos = RandHelper_GetSaveBlockOptionMore(posWin, posWinMore);
        if(pos > 0)
            ListMenuChangeSelection(list, TRUE, pos, TRUE);
    }

    gTasks[taskId].data[RAND_DATA_OPT_POS] = pos;

    CopyWindowToVram(optionId, 3);
    RandHelper_OptionDescText(helpWindowId, posWin, pos, moreTaskId);

    gTasks[taskId].func = RandTask_HandleOptionInput;
}

static void RandTask_HandleOptionInput(u8 taskId)
{
    void (*func)(u8);
    u32 input = ListMenu_ProcessInput(gTasks[taskId].data[RAND_DATA_OPT_TSK]);
    u8 helpWindowId = gTasks[taskId].data[RAND_DATA_HELP];
    u8 optionId = gTasks[taskId].data[RAND_DATA_OPT];
    u8 posWin = gTasks[taskId].data[RAND_DATA_POS];
    u8 pos = gTasks[taskId].data[RAND_DATA_OPT_POS];
    u8 moreTaskId = gTasks[taskId].data[RAND_DATA_MORE_TSK];

    struct ListMenu *list = (void*) gTasks[gTasks[taskId].data[RAND_DATA_OPT_TSK]].data;
    if(pos != list->scrollOffset + list->selectedRow)
    {
        RandHelper_OptionDescText(helpWindowId, posWin, list->scrollOffset + list->selectedRow, moreTaskId);
        gTasks[taskId].data[RAND_DATA_OPT_POS] = list->scrollOffset + list->selectedRow;
    }
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].func = RandAction_Set;
    }
    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        DestroyListMenuTask(gTasks[taskId].data[RAND_DATA_OPT_TSK], NULL, NULL);
        ClearStdWindowAndFrame(gTasks[taskId].data[RAND_DATA_OPT], TRUE);
        RemoveWindow(gTasks[taskId].data[RAND_DATA_OPT]);
        Rand_OpenMoreInfo(taskId);
        if(moreTaskId == 0) {
            RandHelper_DescText(taskId, posWin);
            gTasks[taskId].func = RandTask_HandleMainMenuInput;
        }
        else {
            u8 posWinMore = gTasks[moreTaskId].data[RAND_DATA_POS];
            if(posWin == RAND_MENU_ITEM_SPECIES)
                RandHelper_SpeciesDescText(taskId, posWinMore);
            else if(posWin == RAND_MENU_ITEM_CHALLENGE)
                RandHelper_ChallengeDescText(taskId, posWinMore);
            gTasks[taskId].func = RandTask_HandleMoreInput;
        }
    }
}

static void RandTask_HandleSeedChooserInput(u8 taskId)
{
    u8 posIndex = RAND_DATA_SEED_POS1 + gTasks[taskId].data[RAND_DATA_SEED_CURRPOS];
    if(JOY_NEW(DPAD_LEFT))
    {
        PlaySE(SE_SELECT);
        if(gTasks[taskId].data[RAND_DATA_SEED_CURRPOS] > 0)
            gTasks[taskId].data[RAND_DATA_SEED_CURRPOS]--;
        else
            gTasks[taskId].data[RAND_DATA_SEED_CURRPOS] = 4;

        RandHelper_DescText(taskId, 0);
    }
    else if(JOY_NEW(DPAD_RIGHT))
    {
        PlaySE(SE_SELECT);
        if(gTasks[taskId].data[RAND_DATA_SEED_CURRPOS] < 4)
            gTasks[taskId].data[RAND_DATA_SEED_CURRPOS]++;
        else
            gTasks[taskId].data[RAND_DATA_SEED_CURRPOS] = 0;

        RandHelper_DescText(taskId, 0);
    }
    else if(JOY_NEW(DPAD_UP))
    {
        PlaySE(SE_SELECT);
        if(gTasks[taskId].data[RAND_DATA_SEED_CURRPOS] < 4) {
            if(gTasks[taskId].data[posIndex] < 0xF)
                gTasks[taskId].data[posIndex]++;
            else
                gTasks[taskId].data[posIndex] = 0x0;
        }
        else {
            if(gTasks[taskId].data[posIndex] < 2)
                gTasks[taskId].data[posIndex]++;
            else
                gTasks[taskId].data[posIndex] = 0;
        }

        RandHelper_DescText(taskId, 0);
    }
    else if(JOY_NEW(DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        if(gTasks[taskId].data[RAND_DATA_SEED_CURRPOS] < 4) {
            if(gTasks[taskId].data[posIndex] > 0x0)
                gTasks[taskId].data[posIndex]--;
            else
                gTasks[taskId].data[posIndex] = 0xF;
        }
        else {
            if(gTasks[taskId].data[posIndex] > 0)
                gTasks[taskId].data[posIndex]--;
            else
                gTasks[taskId].data[posIndex] = 2;
        }

        RandHelper_DescText(taskId, 0);
    }
    else if(gMain.newKeys & SELECT_BUTTON)
    {
        u8 i;

        if(gTasks[taskId].data[RAND_DATA_SEED_CURRPOS] < 4) {
            PlaySE(SE_SELECT);
            for(i = 0; i < 4; i++)
            {
                gTasks[taskId].data[RAND_DATA_SEED_POS1 + i] = Random() % 0x10;
            }
            RandHelper_DescText(taskId, 0);
        }
    }
    else if(gMain.newKeys & START_BUTTON)
    {
        u8 i;
        if(gTasks[taskId].data[RAND_DATA_SEED_CURRPOS] < 4) {
            PlaySE(SE_SELECT);
            for(i = 0; i < 4; i++)
            {
                gTasks[taskId].data[RAND_DATA_SEED_POS1 + i] = 0;
            }
            RandHelper_DescText(taskId, 0);
        }
    }
    else if(gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        if(gTasks[taskId].data[RAND_DATA_SEED_CURRPOS] == 4 && gTasks[taskId].data[RAND_DATA_SEED_POSSETTING] < 2) {
            u8 i;
            switch(gTasks[taskId].data[RAND_DATA_SEED_POSSETTING]) {
                case 0:
                    for(i = 0; i < 4; i++)
                    {
                        gTasks[taskId].data[RAND_DATA_SEED_POS1 + i] = Random() % 0x10;
                    }
                    break;
                case 1:
                    for(i = 0; i < 4; i++)
                    {
                        gTasks[taskId].data[RAND_DATA_SEED_POS1 + i] = 0;
                    }
                    break;
            }
            RandHelper_DescText(taskId, 0);
        }
        else {
            gTasks[taskId].data[RAND_DATA_SEED_CURRPOS] = 0xFF;
            RandHelper_SetSaveBlockOption(0, RAND_MENU_ITEM_SEED, RandHelper_SeedPositionsToValue(taskId));
            RandHelper_DescText(taskId, 0);
            gTasks[taskId].func = RandTask_HandleMainMenuInput;
        }
    }
    else if(gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].data[RAND_DATA_SEED_CURRPOS] = 0xFF;
        RandHelper_SetSeedDataFromValue(taskId);
        RandHelper_DescText(taskId, 0);
        gTasks[taskId].func = RandTask_HandleMainMenuInput;
    }
}

static void RandHelper_DescText(u8 taskId, u8 pos)
{
    u8 helpWindowId = gTasks[taskId].data[RAND_DATA_HELP];
    u8 varWindowId = gTasks[taskId].data[RAND_DATA_VAR];

    FillWindowPixelBuffer(helpWindowId, PIXEL_FILL(1));
    if(!gTasks[taskId].data[RAND_DATA_CHANGE] && pos == RAND_MENU_ITEM_DONE)
        AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, gRandMenuDesc_Close, 0, 1, 0, NULL);
    else
        AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, sRandMenuDescPointers[pos], 0, 1, 0, NULL);
    CopyWindowToVram(helpWindowId, 3);

    FillWindowPixelBuffer(varWindowId, PIXEL_FILL(1));
    if(pos == RAND_MENU_ITEM_TYPE)
        AddTextPrinterParameterized(varWindowId, FONT_NORMAL,
            sRandMenuOptionItems_Type[RandHelper_GetSaveBlockOption(RAND_MENU_ITEM_TYPE)].name, 2, 1, 0, NULL);
    else if(pos == RAND_MENU_ITEM_ABILITY)
        AddTextPrinterParameterized(varWindowId, FONT_NORMAL,
            sRandMenuOptionItems_AbilityMove[RandHelper_GetSaveBlockOption(RAND_MENU_ITEM_ABILITY)].name, 2, 1, 0, NULL);
    else if(pos == RAND_MENU_ITEM_MOVE)
        AddTextPrinterParameterized(varWindowId, FONT_NORMAL,
            sRandMenuOptionItems_AbilityMove[RandHelper_GetSaveBlockOption(RAND_MENU_ITEM_MOVE)].name, 2, 1, 0, NULL);
    else if(pos == RAND_MENU_ITEM_PALETTE)
        AddTextPrinterParameterized(varWindowId, FONT_NORMAL,
            sRandMenuOptionItems_Toggle[RandHelper_GetSaveBlockOption(RAND_MENU_ITEM_PALETTE)].name, 2, 1, 0, NULL);
    else if(pos == RAND_MENU_ITEM_SEED) {
        u8 buffer[32] = _("");
        u8 i;
        u8 seedPos = gTasks[taskId].data[RAND_DATA_SEED_CURRPOS];
        if(seedPos == 0xFF && gSaveBlock2Ptr->optionsRandomizerSeed == 0) {
            StringAppend(buffer, gRandText_Seed_TrainerId);
        }
        else {
            for(i = 0; i < 4; i++)
            {
                if(seedPos == i)
                    StringAppend(buffer, gRandText_Seed_Red);
                if(i > 0)
                    StringAppend(buffer, gRandText_Seed_Space);
                StringAppend(buffer, sRandSeedCharacters[gTasks[taskId].data[RAND_DATA_SEED_POS1 + i]]);
                if(seedPos == i)
                    StringAppend(buffer, gRandText_Seed_Normal);
            }
            if(seedPos != 0xFF) {
                if(seedPos == 4)
                    StringAppend(buffer, gRandText_Seed_Red);
                switch(gTasks[taskId].data[RAND_DATA_SEED_POSSETTING]) {
                    case 0: StringAppend(buffer, gRandText_Seed_Random); break;
                    case 1: StringAppend(buffer, gRandText_Seed_Reset); break;
                    case 2: StringAppend(buffer, gRandText_Seed_Set); break;
                }
            }
        }
        AddTextPrinterParameterized(varWindowId, FONT_NORMAL, buffer, 2, 1, 0, NULL);
    }

    CopyWindowToVram(varWindowId, 3);
}

static void RandHelper_ChallengeDescText(u8 taskId, u8 pos)
{
    u8 helpWindowId = gTasks[taskId].data[RAND_DATA_HELP];
    u8 varWindowId = gTasks[taskId].data[RAND_DATA_VAR];

    FillWindowPixelBuffer(varWindowId, PIXEL_FILL(1));
    if(pos == RAND_MENU_ITEM_CHALLENGE_LEVELCAP)
        AddTextPrinterParameterized(varWindowId, FONT_NORMAL,
            sRandMenuOptionItems_Challenge_LevelCap[RandHelper_GetSaveBlockOptionMore(RAND_MENU_ITEM_CHALLENGE, pos)].name,
            2, 1, 0, NULL);
    else
        AddTextPrinterParameterized(varWindowId, FONT_NORMAL,
            sRandMenuOptionItems_Toggle[RandHelper_GetSaveBlockOptionMore(RAND_MENU_ITEM_CHALLENGE, pos)].name,
            2, 1, 0, NULL);
    CopyWindowToVram(varWindowId, 3);

    FillWindowPixelBuffer(helpWindowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, sRandMenuDescPointers_Challenge[pos], 0, 1, 0, NULL);
    CopyWindowToVram(helpWindowId, 3);
}

static void RandHelper_SpeciesDescText(u8 taskId, u8 pos)
{
    u8 helpWindowId = gTasks[taskId].data[RAND_DATA_HELP];
    u8 varWindowId = gTasks[taskId].data[RAND_DATA_VAR];

    FillWindowPixelBuffer(varWindowId, PIXEL_FILL(1));
    if(pos == RAND_MENU_ITEM_SPECIES_WILD)
        AddTextPrinterParameterized(varWindowId, FONT_NORMAL,
            sRandMenuOptionItems_Species_Wild[RandHelper_GetSaveBlockOptionMore(RAND_MENU_ITEM_SPECIES, pos)].name,
            2, 1, 0, NULL);
    else if(pos == RAND_MENU_ITEM_SPECIES_TRAINER)
        AddTextPrinterParameterized(varWindowId, FONT_NORMAL,
            sRandMenuOptionItems_Species_Trainer[RandHelper_GetSaveBlockOptionMore(RAND_MENU_ITEM_SPECIES, pos)].name,
            2, 1, 0, NULL);
    else if(pos == RAND_MENU_ITEM_SPECIES_FILTER)
        AddTextPrinterParameterized(varWindowId, FONT_NORMAL,
            sRandMenuOptionItems_Species_Filter[RandHelper_GetSaveBlockOptionMore(RAND_MENU_ITEM_SPECIES, pos)].name,
            2, 1, 0, NULL);
    else
        AddTextPrinterParameterized(varWindowId, FONT_NORMAL,
            sRandMenuOptionItems_Toggle[RandHelper_GetSaveBlockOptionMore(RAND_MENU_ITEM_SPECIES, pos)].name,
            2, 1, 0, NULL);
    CopyWindowToVram(varWindowId, 3);

    FillWindowPixelBuffer(helpWindowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, sRandMenuDescPointers_Species[pos], 0, 1, 0, NULL);
    CopyWindowToVram(helpWindowId, 3);
}

static void RandHelper_OptionDescText(u8 helpWindowId, u8 posWin, u8 pos, u8 moreTaskId)
{
    FillWindowPixelBuffer(helpWindowId, PIXEL_FILL(1));

    if(moreTaskId == 0) {
        if(posWin == RAND_MENU_ITEM_TYPE)
            AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, sRandOptionMenuDescPointers_Type[pos], 0, 1, 0, NULL);
        else if(posWin == RAND_MENU_ITEM_ABILITY)
            AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, sRandOptionMenuDescPointers_Ability[pos], 0, 1, 0, NULL);
        else if(posWin == RAND_MENU_ITEM_MOVE)
            AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, sRandOptionMenuDescPointers_Move[pos], 0, 1, 0, NULL);
        else if(posWin == RAND_MENU_ITEM_DONE)
            AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, gRandMenuDesc_Finish, 0, 1, 0, NULL);
        else
            AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, sRandMenuDescPointers[posWin], 0, 1, 0, NULL);
    }
    else {
        u8 posWinMore = gTasks[moreTaskId].data[RAND_DATA_POS];
        if(posWin == RAND_MENU_ITEM_SPECIES) {
            if(posWinMore == RAND_MENU_ITEM_SPECIES_WILD)
                AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, sRandOptionMenuDescPointers_Wild[pos], 0, 1, 0, NULL);
            else if(posWinMore == RAND_MENU_ITEM_SPECIES_TRAINER)
                AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, sRandOptionMenuDescPointers_Trainer[pos], 0, 1, 0, NULL);
            else if(posWinMore == RAND_MENU_ITEM_SPECIES_STARTERS)
                AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, gRandMenuDesc_Species_Starters, 0, 1, 0, NULL);
            else if(posWinMore == RAND_MENU_ITEM_SPECIES_FILTER)
                AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, sRandOptionMenuDescPointers_Species_Filter[pos], 0, 1, 0, NULL);
            else if(posWinMore == RAND_MENU_ITEM_SPECIES_SIMILAR)
                AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, gRandMenuDesc_Species_Similar, 0, 1, 0, NULL);
        }
        else if(posWin == RAND_MENU_ITEM_CHALLENGE) {
            if(posWinMore == RAND_MENU_ITEM_CHALLENGE_STRONGERENEMIES)
                AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, gRandMenuDesc_Challenge_StrongerEnemies, 0, 1, 0, NULL);
            else if(posWinMore == RAND_MENU_ITEM_CHALLENGE_TRAINER_KEEPTYPE)
                AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, gRandMenuDesc_Challenge_Trainer_KeepType, 0, 1, 0, NULL);
            else if(posWinMore == RAND_MENU_ITEM_CHALLENGE_LEVELCAP)
                AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, sRandOptionMenuDescPointers_Challenge_LevelCap[pos], 0, 1, 0, NULL);
            else if(posWinMore == RAND_MENU_ITEM_CHALLENGE_DELAYEDEXP)
                AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, gRandMenuDesc_Challenge_DelayedExp, 0, 1, 0, NULL);
            else if(posWinMore == RAND_MENU_ITEM_CHALLENGE_NOEVS)
                AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, sRandOptionMenuDescPointers_Challenge_NoEVsMode[pos], 0, 1, 0, NULL);
        }
    }

    CopyWindowToVram(helpWindowId, 3);
}

static void RandAction_Set(u8 taskId)
{
    u8 posWin = gTasks[taskId].data[RAND_DATA_POS];
    u8 pos = gTasks[taskId].data[RAND_DATA_OPT_POS];
    u8 moreTaskId = gTasks[taskId].data[RAND_DATA_MORE_TSK];

    if(moreTaskId == 0) {
        if(posWin < RAND_MENU_ITEM_DONE) {
            RandHelper_SetSaveBlockOption(0, RAND_MENU_ITEM_SEED + posWin, pos);
        }

        DestroyListMenuTask(gTasks[taskId].data[RAND_DATA_OPT_TSK], NULL, NULL);
        ClearStdWindowAndFrame(gTasks[taskId].data[RAND_DATA_OPT], TRUE);
        RemoveWindow(gTasks[taskId].data[RAND_DATA_OPT]);

        if(posWin < RAND_MENU_ITEM_DONE || pos == 1) {
            Rand_OpenMoreInfo(taskId);
            RandHelper_DescText(taskId, posWin);
            gTasks[taskId].func = RandTask_HandleMainMenuInput;
        }
        else {
            gTasks[taskId].func = RandAction_Done;
        }
    }
    else {
        u8 posWinMore = gTasks[moreTaskId].data[RAND_DATA_POS];
        u8 helpWindowId = gTasks[taskId].data[RAND_DATA_HELP];

        RandHelper_SetSaveBlockOption(moreTaskId, posWin, pos);

        DestroyListMenuTask(gTasks[taskId].data[RAND_DATA_OPT_TSK], NULL, NULL);
        ClearStdWindowAndFrame(gTasks[taskId].data[RAND_DATA_OPT], TRUE);
        RemoveWindow(gTasks[taskId].data[RAND_DATA_OPT]);
        Rand_OpenMoreInfo(taskId);

        if(posWin == RAND_MENU_ITEM_CHALLENGE)
            RandHelper_ChallengeDescText(taskId, posWinMore);
        else if(posWin == RAND_MENU_ITEM_SPECIES)
            RandHelper_SpeciesDescText(taskId, posWinMore);

        gTasks[taskId].func = RandTask_HandleMoreInput;
    }
}

static void RandAction_Done(u8 taskId)
{
    PlaySE(SE_SAVE);

    MgbaPrintf(MGBA_LOG_INFO, "--RANDOMIZER SETTINGS SET--");
    MgbaPrintf(MGBA_LOG_INFO, "  Seed: %x", gSaveBlock2Ptr->optionsRandomizerSeed);
    MgbaPrintf(MGBA_LOG_INFO, "  Type: %d", gSaveBlock2Ptr->optionsRandomizerType);
    MgbaPrintf(MGBA_LOG_INFO, "  Ability: %d", gSaveBlock2Ptr->optionsRandomizerAbility);
    MgbaPrintf(MGBA_LOG_INFO, "  Moves: %d", gSaveBlock2Ptr->optionsRandomizerMoves);
    MgbaPrintf(MGBA_LOG_INFO, "  --SPECIES--");
    MgbaPrintf(MGBA_LOG_INFO, "    Wild: %d", gSaveBlock2Ptr->optionsRandomizerWild);
    MgbaPrintf(MGBA_LOG_INFO, "    Trainer: %d", gSaveBlock2Ptr->optionsRandomizerTrainer);
    MgbaPrintf(MGBA_LOG_INFO, "    Starter: %d", gSaveBlock2Ptr->optionsRandomizerStarter);
    MgbaPrintf(MGBA_LOG_INFO, "    Filter: %x", gSaveBlock2Ptr->optionsRandomizerSpeciesFilter);
    MgbaPrintf(MGBA_LOG_INFO, "    Pal Ready Only: %d", FlagGet(FLAG_RNDM_PALETTE_READY_ONLY));
    MgbaPrintf(MGBA_LOG_INFO, "    Similar Stats: %d", FlagGet(FLAG_RNDM_SIMILAR_STATS));
    MgbaPrintf(MGBA_LOG_INFO, "  Palette: %d", gSaveBlock2Ptr->optionsRandomizerPalette);
    MgbaPrintf(MGBA_LOG_INFO, "  --CHALLENGE--");
    MgbaPrintf(MGBA_LOG_INFO, "    Stronger Teams: %d", gSaveBlock2Ptr->optionsChallengeStrongerTeams);
    MgbaPrintf(MGBA_LOG_INFO, "    Level Cap: %d", gSaveBlock2Ptr->optionsChallengeLevelCap);
    MgbaPrintf(MGBA_LOG_INFO, "    Delayed Exp: %d", FlagGet(FLAG_DIFF_DELAYEDEXP));
    MgbaPrintf(MGBA_LOG_INFO, "    No EVs: %d", FlagGet(FLAG_DIFF_NOEVS));

    Rand_DestroyMainMenu(taskId);
    ClearStdWindowAndFrameToTransparent(0, FALSE);
    ClearWindowTilemap(0);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB(23, 29, 26));
    gTasks[taskId].func = RandAction_Exit;
}

static void RandAction_Exit(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
}

static void RandHelper_SetSaveBlockOption(u8 moreTaskId, u8 option, u16 value)
{
    if(moreTaskId == 0) {
        switch(option)
        {
            case RAND_MENU_ITEM_SEED:
                gSaveBlock2Ptr->optionsRandomizerSeed = value;
                break;
            case RAND_MENU_ITEM_TYPE:
                gSaveBlock2Ptr->optionsRandomizerType = value;
                if(gSaveBlock2Ptr->optionsRandomizerPalette && gSaveBlock2Ptr->optionsRandomizerSpeciesFilter == 0) {
                    if(value > OPTIONS_RANDOMIZER_TYPE_NORMAL)
                        FlagSet(FLAG_RNDM_PALETTE_READY_ONLY);
                    else
                        FlagClear(FLAG_RNDM_PALETTE_READY_ONLY);
                }
                if(gSaveBlock2Ptr->optionsRandomizerAbility == OPTIONS_RANDOMIZER_ABILITY_NORMAL)
                    gSaveBlock2Ptr->optionsRandomizerAbility = OPTIONS_RANDOMIZER_ABILITY_TYPE;
                if(gSaveBlock2Ptr->optionsRandomizerMoves == OPTIONS_RANDOMIZER_MOVES_NORMAL)
                    gSaveBlock2Ptr->optionsRandomizerMoves = OPTIONS_RANDOMIZER_MOVES_TYPE;
                break;
            case RAND_MENU_ITEM_ABILITY:
                gSaveBlock2Ptr->optionsRandomizerAbility = value;
                break;
            case RAND_MENU_ITEM_MOVE:
                gSaveBlock2Ptr->optionsRandomizerMoves = value;
                break;
            case RAND_MENU_ITEM_PALETTE:
                gSaveBlock2Ptr->optionsRandomizerPalette = (value == 0 ? TRUE : FALSE);
                break;
        }
    }
    else {
        u8 posWinMore = gTasks[moreTaskId].data[RAND_DATA_POS];
        if(option == RAND_MENU_ITEM_SPECIES) {
            switch(posWinMore) {
                case RAND_MENU_ITEM_SPECIES_WILD:
                    gSaveBlock2Ptr->optionsRandomizerWild = value;
                    break;
                case RAND_MENU_ITEM_SPECIES_TRAINER:
                    gSaveBlock2Ptr->optionsRandomizerTrainer = value;
                    break;
                case RAND_MENU_ITEM_SPECIES_STARTERS:
                    gSaveBlock2Ptr->optionsRandomizerStarter = (value == 0 ? TRUE : FALSE);
                    break;
                case RAND_MENU_ITEM_SPECIES_FILTER:
                    if(value == 1) {
                        FlagSet(FLAG_RNDM_PALETTE_READY_ONLY);
                        gSaveBlock2Ptr->optionsRandomizerSpeciesFilter = 0;
                    }
                    else if(value == 2) {
                        FlagClear(FLAG_RNDM_PALETTE_READY_ONLY);
                        gSaveBlock2Ptr->optionsRandomizerSpeciesFilter = OPTIONS_RANDOMIZER_FILTER_HOENNDEX;
                    }
                    else {
                        FlagClear(FLAG_RNDM_PALETTE_READY_ONLY);
                        gSaveBlock2Ptr->optionsRandomizerSpeciesFilter = value;
                    }
                    break;
                case RAND_MENU_ITEM_SPECIES_SIMILAR:
                    value == 0 ? FlagSet(FLAG_RNDM_SIMILAR_STATS) : FlagClear(FLAG_RNDM_SIMILAR_STATS);
                    break;
            }
        }
        else if(option == RAND_MENU_ITEM_CHALLENGE) {
            switch(posWinMore)
            {
                case RAND_MENU_ITEM_CHALLENGE_STRONGERENEMIES:
                    gSaveBlock2Ptr->optionsChallengeStrongerTeams = (value == 0 ? TRUE : FALSE);
                    break;
                case RAND_MENU_ITEM_CHALLENGE_TRAINER_KEEPTYPE:
                    value == 0 ? FlagSet(FLAG_DIFF_KEEP_TRAINER_TYPES) : FlagClear(FLAG_DIFF_KEEP_TRAINER_TYPES);
                    break;
                case RAND_MENU_ITEM_CHALLENGE_LEVELCAP:
                    gSaveBlock2Ptr->optionsChallengeLevelCap = value;
                case RAND_MENU_ITEM_CHALLENGE_DELAYEDEXP:
                    value == 0 ? FlagSet(FLAG_DIFF_DELAYEDEXP) : FlagClear(FLAG_DIFF_DELAYEDEXP);
                    break;
                case RAND_MENU_ITEM_CHALLENGE_NOEVS:
                    value == 0 ? FlagSet(FLAG_DIFF_NOEVS) : FlagClear(FLAG_DIFF_NOEVS);
                    break;
            }

        }
    }
}

static u16 RandHelper_GetSaveBlockOption(u8 option)
{
    switch(option)
    {
        case RAND_MENU_ITEM_SEED:
            return gSaveBlock2Ptr->optionsRandomizerSeed;
        case RAND_MENU_ITEM_TYPE:
            return gSaveBlock2Ptr->optionsRandomizerType;
        case RAND_MENU_ITEM_ABILITY:
            return gSaveBlock2Ptr->optionsRandomizerAbility;
        case RAND_MENU_ITEM_MOVE:
            return gSaveBlock2Ptr->optionsRandomizerMoves;
        case RAND_MENU_ITEM_PALETTE:
            return (gSaveBlock2Ptr->optionsRandomizerPalette ? 0 : 1);
    }
    return 0;
}

static u16 RandHelper_GetSaveBlockOptionMore(u8 posWin, u8 option)
{
    if(posWin == RAND_MENU_ITEM_SPECIES)
    {
        u16 filter;
        switch(option)
        {
            case RAND_MENU_ITEM_SPECIES_WILD:
                return gSaveBlock2Ptr->optionsRandomizerWild;
            case RAND_MENU_ITEM_SPECIES_TRAINER:
                return gSaveBlock2Ptr->optionsRandomizerTrainer;
            case RAND_MENU_ITEM_SPECIES_STARTERS:
                return (gSaveBlock2Ptr->optionsRandomizerStarter ? 0 : 1);
            case RAND_MENU_ITEM_SPECIES_FILTER:
                filter = gSaveBlock2Ptr->optionsRandomizerSpeciesFilter;
                if(FlagGet(FLAG_RNDM_PALETTE_READY_ONLY))
                    return 1;
                else if(filter == OPTIONS_RANDOMIZER_FILTER_HOENNDEX)
                    return 2;
                return gSaveBlock2Ptr->optionsRandomizerSpeciesFilter;
            case RAND_MENU_ITEM_SPECIES_SIMILAR:
                return (FlagGet(FLAG_RNDM_SIMILAR_STATS) ? 0 : 1);
        }
    }
    else if(posWin == RAND_MENU_ITEM_CHALLENGE)
    {
        switch(option)
        {
            case RAND_MENU_ITEM_CHALLENGE_STRONGERENEMIES:
                return (gSaveBlock2Ptr->optionsChallengeStrongerTeams ? 0 : 1);
            case RAND_MENU_ITEM_CHALLENGE_TRAINER_KEEPTYPE:
                return (FlagGet(FLAG_DIFF_KEEP_TRAINER_TYPES) ? 0 : 1);
            case RAND_MENU_ITEM_CHALLENGE_LEVELCAP:
                return gSaveBlock2Ptr->optionsChallengeLevelCap;
            case RAND_MENU_ITEM_CHALLENGE_DELAYEDEXP:
                if(gSaveBlock2Ptr->optionsRandomizerVersion == 0)
                    return (gSaveBlock2Ptr->optionsChallengeStrongerTeams ? 0 : 1);
                else
                    return (FlagGet(FLAG_DIFF_DELAYEDEXP) ? 0 : 1);
            case RAND_MENU_ITEM_CHALLENGE_NOEVS:
                return (FlagGet(FLAG_DIFF_NOEVS) ? 0 : 1);
        }
    }

    return 0;
}

static u16 RandHelper_SeedPositionsToValue(u8 taskId)
{
    u8 pos1 = gTasks[taskId].data[RAND_DATA_SEED_POS1];
    u8 pos2 = gTasks[taskId].data[RAND_DATA_SEED_POS2];
    u8 pos3 = gTasks[taskId].data[RAND_DATA_SEED_POS3];
    u8 pos4 = gTasks[taskId].data[RAND_DATA_SEED_POS4];

    u16 value = pos1;
    value = (value << 4) + pos2;
    value = (value << 4) + pos3;
    value = (value << 4) + pos4;

    return value;
}

static void RandHelper_SetSeedDataFromValue(u8 taskId)
{
    u16 value = gSaveBlock2Ptr->optionsRandomizerSeed;

    gTasks[taskId].data[RAND_DATA_SEED_POS1] = (value >> 12);
    gTasks[taskId].data[RAND_DATA_SEED_POS2] = (value >> 8) & 0xF;
    gTasks[taskId].data[RAND_DATA_SEED_POS3] = (value >> 4) & 0xF;
    gTasks[taskId].data[RAND_DATA_SEED_POS4] = value & 0xF;
}
