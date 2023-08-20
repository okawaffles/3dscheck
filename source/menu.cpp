#include "menu.hpp"


static unsigned int currentFunction = 0;

unsigned int GetCurrentFunction()
{
    return currentFunction;
}
void SetCurrentFunction(unsigned int function)
{
    currentFunction = function;
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