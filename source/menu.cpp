#include "menu.hpp"
#include <iostream>
#include <sstream>
#include <3ds.h>
#include "control.hpp"

static unsigned int currentFunction = 0;

unsigned int GetCurrentFunction()
{
    return currentFunction;
}
void SetCurrentFunction(unsigned int function)
{
    currentFunction = function;
    printf("set current function: %d\n", function);
}

bool gameCardInserted = false;

// draw the main menu
void DrawMenu(u8 model, AppTextManager *ATM)
{
    // draw the option rectangles
    for (int yStart = 25; yStart < 145; yStart += 30)
    {
        GFX_DrawRect(0, yStart, 170, yStart + 25, Colors_BackgroundLighter);

        switch (yStart)
        {
        // screen
        case 25:
            // draw the correct text based on model
            if ((model == CFG_MODEL_2DS) || (model == CFG_MODEL_N2DSXL))
                ATM->DrawText(StrId_Screens_2DS, 3, yStart + 4);
            else
                ATM->DrawText(StrId_Screens_3DS, 3, yStart + 4);

            break;

        // touchscreen
        case 55:
            ATM->DrawText(StrId_Touchscreen, 3, yStart + 4);
            break;

        // buttons
        case 85:
            ATM->DrawText(StrId_Buttons, 3, yStart + 4);
            break;

        // slider pad
        case 115:
            ATM->DrawText(StrId_SlidePad, 3, yStart + 4);
            break;

        default:
            break;
        }
    }
}


void DrawMenuBottom(u8 model, AppTextManager *ATM)
{
    switch (model)
    {
    case CFG_MODEL_2DS:
        ATM->DrawText(StrId_Models_O2DS, 2, 2);
        break;
    case CFG_MODEL_3DS:
        ATM->DrawText(StrId_Models_O3DS, 2, 2);
        break;
    case CFG_MODEL_3DSXL:
        ATM->DrawText(StrId_Models_O3DSXL, 2, 2);
        break;
    case CFG_MODEL_N3DS:
        ATM->DrawText(StrId_Models_N3DS, 2, 2);
        break;
    case CFG_MODEL_N3DSXL:
        ATM->DrawText(StrId_Models_N3DSXL, 2, 2);
        break;
    case CFG_MODEL_N2DSXL:
        ATM->DrawText(StrId_Models_N2DSXL, 2, 2);
        break;
    
    default:
        break;
    }

    // check if a game card is inserted
    FSUSER_CardSlotIsInserted(&gameCardInserted);
    if (gameCardInserted)
    {        
        // get title ID
        u32 count = 1;
        u64 titleId;
        AM_TitleEntry t;
        u64 titleName;
        u32 titlesread;
        AM_GetTitleList(&titlesread, MEDIATYPE_GAME_CARD, count, &titleId);

        // get title name
        AM_GetTitleInfo(MEDIATYPE_GAME_CARD, count, &titleId, &t);

        std::stringstream s;
        s << titleName << "(0x" << std::hex << titleId << ")";
        
        ATM->RefreshCR();
        ATM->ParseCR(s.str().c_str());
        ATM->DrawCR(2, 225, C2D_WithColor, 0.5f, 0.5f, Colors_Green);

        //ATM->DrawText(StrId_GameCard_In, 2, 225, 0, C2D_WithColor, 0.5f, 0.5f, Colors_Green);
        
        // option to launch gamecard
        UpdateTouch();
        if (TouchIsWithin(0, 222, 100, 240))
        {
            aptSetChainloader(titleId, MEDIATYPE_GAME_CARD);
            SetCurrentFunction(APP_EXIT);
        }
    }
    else
        ATM->DrawText(StrId_GameCard_None, 2, 225, 0, C2D_WithColor, 0.5f, 0.5f, Colors_Red);
}