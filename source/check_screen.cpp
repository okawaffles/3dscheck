#include "check_screen.hpp"
#include "control.hpp"

u8 mcuhwc_3d_level;

void DrawScreenCheckTop3D(u8 model, AppTextManager *ATM)
{
    GFX_DrawRect(0, 0, 400, 240, Colors_White);
    
    // commented code below does not work for some reason so i have to manually read the register, cool.
    // MCUHWC_Get3dSliderLevel(&mcuhwc_3d_level);
    MCUHWC_ReadRegister(8, &mcuhwc_3d_level, 1);
    // printf("MCUHWC 3D SLIDER LEVEL: %u\n", mcuhwc_3d_level); // was used for debugging.

    // i don't think the slider has a physical "switch" to control the display, 
    // so i'm just guessing the notch is at least >20
    if (mcuhwc_3d_level > 20) {
        /*ATM->DrawText(StrId_Screens_3DCheck, 200, 100, 0.0f, C2D_WithColor | C2D_AlignCenter, 1.0f, 1.0f, Colors_BackgroundPrimary);
        ATM->DrawText(StrId_Screens_3DCheck, 198, 99, 1.0f, C2D_WithColor | C2D_AlignCenter, 1.0f, 1.0f, Colors_BackgroundLighter);*/

        GFX_DrawRect(100, 40, 300, 200, Colors_BackgroundPrimary, 0.0f);
        GFX_DrawRect(90, 30, 290, 190, Colors_BackgroundLighter, 1.0f);
    }
    else if (!(ButtonHeld(KEY_L)||ButtonHeld(KEY_R)))
    {
        ATM->DrawText(StrId_Screens_3DCheck, 2, 2, 0, C2D_WithColor, 0.5f, 0.5f, Colors_Black);
    }
}

void DrawScreenCheckTop3DRight(AppTextManager *ATM)
{
    if (mcuhwc_3d_level > 20) {
        /*ATM->DrawText(StrId_Screens_3DCheck, 200, 100, 0.0f, C2D_WithColor | C2D_AlignCenter, 1.0f, 1.0f, Colors_BackgroundPrimary);
        ATM->DrawText(StrId_Screens_3DCheck, 198, 99, 1.0f, C2D_WithColor | C2D_AlignCenter, 1.0f, 1.0f, Colors_BackgroundLighter);*/

        GFX_DrawRect(100, 40, 300, 200, Colors_BackgroundPrimary, -1.0f);
        GFX_DrawRect(87, 30, 287, 190, Colors_BackgroundLighter, 1.0f);
    }
}

void DrawScreenCheckTop2D(u8 model, AppTextManager *ATM)
{
    GFX_DrawRect(0, 0, 400, 240, Colors_White);
}

void DrawScreenCheckBottom(AppTextManager *ATM)
{
    GFX_DrawRect(0, 0, 320, 240, Colors_White);
}