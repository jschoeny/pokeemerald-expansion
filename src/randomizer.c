#include "global.h"
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
#define RAND_DATA_SEED_ACTIVE       14

void Rand_ShowMainMenu(void);
static void Rand_DestroyMainMenu(u8);
static void RandAction_OpenSeedChooser(u8);
static void RandAction_OpenOption(u8);
static void RandAction_Set(u8);
static void RandAction_Done(u8);
static void RandAction_Exit(u8);
static void RandTask_HandleMainMenuInput(u8);
static void RandTask_HandleSeedChooserInput(u8);
static void RandTask_HandleOptionInput(u8 taskId);
static void RandHelper_DescText(u8 taskId, u8 pos);
static void RandHelper_OptionDescText(u8 helpWindowId, u8 posWin, u8 pos);
static void RandHelper_SetSaveBlockOption(u8 option, u16 value);
static u16 RandHelper_GetSaveBlockOption(u8 option);
static u16 RandHelper_SeedPositionsToValue(u8 taskId);
static void RandHelper_SetSeedDataFromValue(u8 taskId);

static void (*const sRandMenuActions[])(u8) =
{
    [RAND_MENU_ITEM_SEED] = RandAction_OpenSeedChooser,
    [RAND_MENU_ITEM_TYPE] = RandAction_OpenOption,
    [RAND_MENU_ITEM_ABILITY] = RandAction_OpenOption,
    [RAND_MENU_ITEM_MOVE] = RandAction_OpenOption,
    [RAND_MENU_ITEM_WILD] = RandAction_OpenOption,
    [RAND_MENU_ITEM_TRAINER] = RandAction_OpenOption,
    [RAND_MENU_ITEM_PALETTE] = RandAction_OpenOption,
    [RAND_MENU_ITEM_CHALLENGE] = RandAction_OpenOption,
    [RAND_MENU_ITEM_DONE] = RandAction_OpenOption,
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
    .tilemapLeft = RAND_MENU_WIDTH + 5,
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
    struct ListMenuTemplate menuTemplate;
    u8 windowId, helpWindowId, varWindowId;
    u8 menuTaskId;
    u8 inputTaskId;
    u8 i;

    // create window
    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sRandMenuWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);

    LoadUserWindowBorderGfx(0, 0x250, 0xd0);
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
    for(i = 0; i < 4; i++)
    {
        gTasks[inputTaskId].data[RAND_DATA_SEED_POS1 + i] = Random() % 0x10;
    }
    gTasks[inputTaskId].data[RAND_DATA_SEED_CURRPOS] = 0;
    gTasks[inputTaskId].data[RAND_DATA_SEED_ACTIVE] = FALSE;

    gSaveBlock2Ptr->optionsRandomizerSeed = RandHelper_SeedPositionsToValue(inputTaskId);

    RandHelper_DescText(inputTaskId, 0);
    CopyWindowToVram(helpWindowId, 3);
    CopyWindowToVram(varWindowId, 3);
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

        if(gTasks[taskId].data[RAND_DATA_POS] == RAND_MENU_ITEM_DONE) {
            ClearStdWindowAndFrame(gTasks[taskId].data[RAND_DATA_VAR], TRUE);
            RemoveWindow(gTasks[taskId].data[RAND_DATA_VAR]);
            gTasks[taskId].data[RAND_DATA_VAR] = 0;
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
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        if ((func = sRandMenuActions[input]) != NULL)
            func(taskId);
    }
}

static void RandAction_OpenSeedChooser(u8 taskId)
{
    gTasks[taskId].data[RAND_DATA_SEED_ACTIVE] = TRUE;
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

    u8 optionId;
    if(posWin == RAND_MENU_ITEM_DONE)
        optionId = AddWindow(&sRandYesNoWindowTemplate);
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
    else if(posWin == RAND_MENU_ITEM_WILD) {
        menuTemplate.items = sRandMenuOptionItems_Wild;
        menuTemplate.totalItems = ARRAY_COUNT(sRandMenuOptionItems_Wild);
    }
    else if(posWin == RAND_MENU_ITEM_TRAINER) {
        menuTemplate.items = sRandMenuOptionItems_Trainer;
        menuTemplate.totalItems = ARRAY_COUNT(sRandMenuOptionItems_Trainer);
    }
    else if(posWin == RAND_MENU_ITEM_PALETTE || posWin == RAND_MENU_ITEM_CHALLENGE) {
        menuTemplate.items = sRandMenuOptionItems_Toggle;
        menuTemplate.totalItems = ARRAY_COUNT(sRandMenuOptionItems_Toggle);
    }
    else {
        menuTemplate.items = sRandMenuOptionItems_YesNo;
        menuTemplate.totalItems = ARRAY_COUNT(sRandMenuOptionItems_YesNo);
    }
    menuTemplate.windowId = optionId;
    menuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    gTasks[taskId].data[RAND_DATA_OPT] = optionId;
    gTasks[taskId].data[RAND_DATA_OPT_TSK] = menuTaskId;

    list = (void*) gTasks[menuTaskId].data;

    pos = RandHelper_GetSaveBlockOption(RAND_MENU_ITEM_SEED + posWin);
    if(pos > 0)
        ListMenuChangeSelection(list, TRUE, pos, TRUE);

    gTasks[taskId].data[RAND_DATA_OPT_POS] = pos;

    CopyWindowToVram(optionId, 3);
    RandHelper_OptionDescText(helpWindowId, posWin, pos);

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

    struct ListMenu *list = (void*) gTasks[gTasks[taskId].data[RAND_DATA_OPT_TSK]].data;
    if(pos != list->scrollOffset + list->selectedRow)
    {
        RandHelper_OptionDescText(helpWindowId, posWin, list->scrollOffset + list->selectedRow);
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
        RandHelper_DescText(taskId, posWin);
        gTasks[taskId].func = RandTask_HandleMainMenuInput;
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
            if(gTasks[taskId].data[posIndex] > 2)
                gTasks[taskId].data[posIndex]--;
            else
                gTasks[taskId].data[posIndex] = 0xF;
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
            gTasks[taskId].data[RAND_DATA_SEED_ACTIVE] = FALSE;
            RandHelper_SetSaveBlockOption(RAND_MENU_ITEM_SEED, RandHelper_SeedPositionsToValue(taskId));
            RandHelper_DescText(taskId, 0);
            gTasks[taskId].func = RandTask_HandleMainMenuInput;
        }
    }
    else if(gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].data[RAND_DATA_SEED_ACTIVE] = FALSE;
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
    else if(pos == RAND_MENU_ITEM_WILD)
        AddTextPrinterParameterized(varWindowId, FONT_NORMAL,
            sRandMenuOptionItems_Wild[RandHelper_GetSaveBlockOption(RAND_MENU_ITEM_WILD)].name, 2, 1, 0, NULL);
    else if(pos == RAND_MENU_ITEM_TRAINER)
        AddTextPrinterParameterized(varWindowId, FONT_NORMAL,
            sRandMenuOptionItems_Trainer[RandHelper_GetSaveBlockOption(RAND_MENU_ITEM_TRAINER)].name, 2, 1, 0, NULL);
    else if(pos == RAND_MENU_ITEM_PALETTE)
        AddTextPrinterParameterized(varWindowId, FONT_NORMAL,
            sRandMenuOptionItems_Toggle[RandHelper_GetSaveBlockOption(RAND_MENU_ITEM_PALETTE)].name, 2, 1, 0, NULL);
    else if(pos == RAND_MENU_ITEM_CHALLENGE)
        AddTextPrinterParameterized(varWindowId, FONT_NORMAL,
            sRandMenuOptionItems_Toggle[RandHelper_GetSaveBlockOption(RAND_MENU_ITEM_CHALLENGE)].name, 2, 1, 0, NULL);
    else if(pos == RAND_MENU_ITEM_SEED) {
        u8 buffer[32] = _("");
        u8 i;
        u8 seedPos = gTasks[taskId].data[RAND_DATA_SEED_CURRPOS];
        for(i = 0; i < 4; i++)
        {
            if(seedPos == i && gTasks[taskId].data[RAND_DATA_SEED_ACTIVE])
                StringAppend(buffer, gRandText_Seed_Red);
            if(i > 0)
                StringAppend(buffer, gRandText_Seed_Space);
            StringAppend(buffer, sRandSeedCharacters[gTasks[taskId].data[RAND_DATA_SEED_POS1 + i]]);
            if(seedPos == i && gTasks[taskId].data[RAND_DATA_SEED_ACTIVE])
                StringAppend(buffer, gRandText_Seed_Normal);
        }
        if(gTasks[taskId].data[RAND_DATA_SEED_ACTIVE]) {
            if(seedPos == 4)
                StringAppend(buffer, gRandText_Seed_Red);
            switch(gTasks[taskId].data[RAND_DATA_SEED_POSSETTING]) {
                case 0: StringAppend(buffer, gRandText_Seed_Random); break;
                case 1: StringAppend(buffer, gRandText_Seed_Reset); break;
                case 2: StringAppend(buffer, gRandText_Seed_Set); break;
            }
        }
        AddTextPrinterParameterized(varWindowId, FONT_NORMAL, buffer, 2, 1, 0, NULL);
    }

    CopyWindowToVram(varWindowId, 3);
}

static void RandHelper_OptionDescText(u8 helpWindowId, u8 posWin, u8 pos)
{
    FillWindowPixelBuffer(helpWindowId, PIXEL_FILL(1));

    if(posWin == RAND_MENU_ITEM_TYPE)
        AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, sRandOptionMenuDescPointers_Type[pos], 0, 1, 0, NULL);
    else if(posWin == RAND_MENU_ITEM_ABILITY)
        AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, sRandOptionMenuDescPointers_Ability[pos], 0, 1, 0, NULL);
    else if(posWin == RAND_MENU_ITEM_MOVE)
        AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, sRandOptionMenuDescPointers_Move[pos], 0, 1, 0, NULL);
    else if(posWin == RAND_MENU_ITEM_WILD)
        AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, sRandOptionMenuDescPointers_Wild[pos], 0, 1, 0, NULL);
    else if(posWin == RAND_MENU_ITEM_TRAINER)
        AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, sRandOptionMenuDescPointers_Trainer[pos], 0, 1, 0, NULL);
    else if(posWin == RAND_MENU_ITEM_DONE)
        AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, gRandMenuDesc_Finish, 0, 1, 0, NULL);
    else
        AddTextPrinterParameterized(helpWindowId, FONT_NORMAL, sRandMenuDescPointers[posWin], 0, 1, 0, NULL);

    CopyWindowToVram(helpWindowId, 3);
}

static void RandAction_Set(u8 taskId)
{
    u8 posWin = gTasks[taskId].data[RAND_DATA_POS];
    u8 pos = gTasks[taskId].data[RAND_DATA_OPT_POS];

    if(posWin < RAND_MENU_ITEM_DONE) {
        RandHelper_SetSaveBlockOption(RAND_MENU_ITEM_SEED + posWin, pos);
    }

    DestroyListMenuTask(gTasks[taskId].data[RAND_DATA_OPT_TSK], NULL, NULL);
    ClearStdWindowAndFrame(gTasks[taskId].data[RAND_DATA_OPT], TRUE);
    RemoveWindow(gTasks[taskId].data[RAND_DATA_OPT]);

    if(posWin < RAND_MENU_ITEM_DONE || pos == 1) {
        RandHelper_DescText(taskId, posWin);
        gTasks[taskId].func = RandTask_HandleMainMenuInput;
    }
    else {
        gTasks[taskId].func = RandAction_Done;
    }
}

static void RandAction_Done(u8 taskId)
{
    PlaySE(SE_SAVE);

    MgbaPrintf(MGBA_LOG_INFO, "--RANDOMIZER SETTINGS SET--");
    MgbaPrintf(MGBA_LOG_INFO, "  Type: %d", gSaveBlock2Ptr->optionsRandomizerType);
    MgbaPrintf(MGBA_LOG_INFO, "  Ability: %d", gSaveBlock2Ptr->optionsRandomizerAbility);
    MgbaPrintf(MGBA_LOG_INFO, "  Moves: %d", gSaveBlock2Ptr->optionsRandomizerMoves);
    MgbaPrintf(MGBA_LOG_INFO, "  Wild: %d", gSaveBlock2Ptr->optionsRandomizerWild);
    MgbaPrintf(MGBA_LOG_INFO, "  Trainer: %d", gSaveBlock2Ptr->optionsRandomizerTrainer);
    MgbaPrintf(MGBA_LOG_INFO, "  Palette: %d", gSaveBlock2Ptr->optionsRandomizerPalette);
    MgbaPrintf(MGBA_LOG_INFO, "  Challenge: %d", gSaveBlock2Ptr->optionsRandomizerChallenge);
    MgbaPrintf(MGBA_LOG_INFO, "  Seed: %x", gSaveBlock2Ptr->optionsRandomizerSeed);

    Rand_DestroyMainMenu(taskId);
    ClearStdWindowAndFrameToTransparent(0, FALSE);
    ClearWindowTilemap(0);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    gTasks[taskId].func = RandAction_Exit;
}

static void RandAction_Exit(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
}

static void RandHelper_SetSaveBlockOption(u8 option, u16 value)
{
    switch(option)
    {
        case RAND_MENU_ITEM_SEED:
            gSaveBlock2Ptr->optionsRandomizerSeed = value;
            break;
        case RAND_MENU_ITEM_TYPE:
            gSaveBlock2Ptr->optionsRandomizerType = value;
            break;
        case RAND_MENU_ITEM_ABILITY:
            gSaveBlock2Ptr->optionsRandomizerAbility = value;
            break;
        case RAND_MENU_ITEM_MOVE:
            gSaveBlock2Ptr->optionsRandomizerMoves = value;
            break;
        case RAND_MENU_ITEM_WILD:
            gSaveBlock2Ptr->optionsRandomizerWild = value;
            break;
        case RAND_MENU_ITEM_TRAINER:
            gSaveBlock2Ptr->optionsRandomizerTrainer = value;
            break;
        case RAND_MENU_ITEM_PALETTE:
            gSaveBlock2Ptr->optionsRandomizerPalette = (value == 0 ? TRUE : FALSE);
            break;
        case RAND_MENU_ITEM_CHALLENGE:
            gSaveBlock2Ptr->optionsRandomizerChallenge = (value == 0 ? TRUE : FALSE);
            break;
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
        case RAND_MENU_ITEM_WILD:
            return gSaveBlock2Ptr->optionsRandomizerWild;
        case RAND_MENU_ITEM_TRAINER:
            return gSaveBlock2Ptr->optionsRandomizerTrainer;
        case RAND_MENU_ITEM_PALETTE:
            return (gSaveBlock2Ptr->optionsRandomizerPalette ? 0 : 1);
        case RAND_MENU_ITEM_CHALLENGE:
            return (gSaveBlock2Ptr->optionsRandomizerChallenge ? 0 : 1);
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
