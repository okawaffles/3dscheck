#include "check_screen.hpp"

void DrawScreenCheckTop(u8 model, AppTextManager *ATM)
{
    GFX_DrawRect(0, 0, 400, 240, Colors_White);
    
    if (!(model == CFG_MODEL_2DS) && !(model == CFG_MODEL_N2DSXL))
        ATM->DrawText(StrId_Screens_3DCheck, 200, 120, 1.0f, C2D_WithColor | C2D_AlignCenter, 0.5f, 0.5f, Colors_Black);
}


void DrawScreenCheckBottom(AppTextManager *ATM)
{

}