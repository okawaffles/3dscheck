#include "common.hpp"


// colors
u32 Colors_Clear = C2D_Color32(0xFF, 0xD8, 0xB0, 0x68);
u32 Colors_White = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
u32 Colors_Black = C2D_Color32(0x00, 0x00, 0x00, 0xFF);
u32 Colors_BackgroundPrimary = C2D_Color32(0x42, 0x5e, 0x55, 0xFF);
u32 Colors_BackgroundLighter  = C2D_Color32(0x64, 0x8f, 0x81, 0xFF);

// screens
C3D_RenderTarget *top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
C3D_RenderTarget *top3D = C2D_CreateScreenTarget(GFX_TOP, GFX_RIGHT);
C3D_RenderTarget *bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);