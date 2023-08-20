#include "menu.hpp"


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
}