#include "check_screen.hpp"
#include "control.hpp"

u8 mcuhwc_3d_level;

void DrawScreenCheckTop3D(u8 model, AppTextManager *ATM)
{
    GFX_DrawRect(0, 0, 400, 240, Colors_White);
    
    // commented code below does not work for some reason so i have to manually read the register, cool.
    // MCUHWC_Get3dSliderLevel(&mcuhwc_3d_level);
    MCUHWC_ReadRegister(8, &mcuhwc_3d_level, 1);
    printf("MCUHWC 3D SLIDER LEVEL: %u\n", mcuhwc_3d_level); // was used for debugging.

    // i don't think the slider has a physical "switch" to control the display, 
    // so i'm just guessing the notch is at least >20
    if (mcuhwc_3d_level > 20) {
        // 3D block
        GFX_DrawRect(100, 40, 300, 200, Colors_BackgroundPrimary, 0.0f);
        GFX_DrawRect(90, 30, 290, 190, Colors_BackgroundLighter, 1.0f);

        // 3D slider value bar
        const int min_slider_value = 15;  // Minimum value of the 3DS slider
        const int max_slider_value = 242; // Maximum value of the 3DS slider
        const int min_bar = 170;
        const int max_bar = 70;
        double bar_val = min_bar + (max_bar - min_bar) * (static_cast<double>(mcuhwc_3d_level - min_slider_value) / (max_slider_value - min_slider_value));
        GFX_DrawRect(390, 70, 400, 170, Colors_Green);
        GFX_DrawRect(390, 70, 400, bar_val, Colors_Red);
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


        // code for moving the block based on slider value
        const int min_movement = 0;  // Minimum movement in pixels
        const int max_movement = 3;  // Maximum movement in pixels
        const int min_slider_value = 15;  // Minimum value of the 3DS slider
        const int max_slider_value = 242; // Maximum value of the 3DS slider
        double movement = min_movement + (max_movement - min_movement) * (static_cast<double>(mcuhwc_3d_level - min_slider_value) / (max_slider_value - min_slider_value));

        GFX_DrawRect(100, 40, 300, 200, Colors_BackgroundPrimary, -1.0f);
        GFX_DrawRect(90-movement, 33-movement, 290-movement, 193-movement, Colors_BackgroundLighter, 1.0f);

        // 3D slider value bar
        const int min_bar = 170;
        const int max_bar = 70;
        double bar_val = min_bar + (max_bar - min_bar) * (static_cast<double>(mcuhwc_3d_level - min_slider_value) / (max_slider_value - min_slider_value));
        GFX_DrawRect(390, 70, 400, 170, Colors_Green);
        GFX_DrawRect(390, 70, 400, bar_val, Colors_Red);
    } else {
        // draw this for the slight bit of time where the 3ds doesn't turn off the right 3D screen to prevent headaches
        ATM->DrawText(StrId_Screens_3DCheck, 2, 2, 0, C2D_WithColor, 0.5f, 0.5f, Colors_Black);
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