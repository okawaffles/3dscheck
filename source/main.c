#include <citro2d.h>
#include <3ds.h>
#include "mochalibs.h"
#include "touchscreen.h"
#include "buttons.h"
#include "screens.h"
#include "sticks.h"
#define SCREEN_WIDTH_TOP 400
#define SCREEN_HEIGHT_TOP 240
#define SCREEN_WIDTH_BOTTOM 320
#define SCREEN_HEIGHT_BOTTOM 240
int loaded = 0;

int pxx, pyy;

C2D_TextBuf mainTextBuf, timeBuf, buttonsBuf;
C2D_Text modesText[5], uiText[5], sysTime, buttons[14], enabled3D;
static char timeString[9];

static void sceneInit()
{

    mainTextBuf = C2D_TextBufNew(4096); // create text buffer
    timeBuf = C2D_TextBufNew(4096);     // create text buffer
    buttonsBuf = C2D_TextBufNew(4096);  // create text buffer

    C2D_TextParse(&modesText[0], mainTextBuf, "Buttons "); // parse the texts :: i honestly won't care if you yell at me about how untidy this is, if it works, leave it.
    C2D_TextParse(&modesText[1], mainTextBuf, "Screens ");
    C2D_TextParse(&modesText[2], mainTextBuf, "Touchscreen ");
    C2D_TextParse(&modesText[3], mainTextBuf, "Return to HBL ");
    C2D_TextParse(&modesText[4], mainTextBuf, "Stick ");
    C2D_TextOptimize(&modesText[0]);
    C2D_TextOptimize(&modesText[1]);
    C2D_TextOptimize(&modesText[2]);
    C2D_TextOptimize(&modesText[3]);
    C2D_TextOptimize(&modesText[4]);
    C2D_TextParse(&uiText[0], mainTextBuf, "3DS Check [1.0_O3DS]");
    C2D_TextParse(&uiText[1], mainTextBuf, " Back");
    C2D_TextParse(&uiText[2], mainTextBuf, "START +  Back");
    C2D_TextParse(&uiText[3], mainTextBuf, "Sys. Opt.");
    C2D_TextParse(&uiText[4], mainTextBuf, "Restart");
    C2D_TextParse(&enabled3D, mainTextBuf, "3D SCREEN TEST");
    C2D_TextOptimize(&enabled3D);
    C2D_TextOptimize(&uiText[0]);
    C2D_TextOptimize(&uiText[1]);
    C2D_TextOptimize(&uiText[2]);
    C2D_TextOptimize(&uiText[3]);
    C2D_TextOptimize(&uiText[4]);

    C2D_TextParse(&buttons[0], buttonsBuf, "A");
    C2D_TextParse(&buttons[1], buttonsBuf, "B");
    C2D_TextParse(&buttons[2], buttonsBuf, "X");
    C2D_TextParse(&buttons[3], buttonsBuf, "Y");
    C2D_TextParse(&buttons[4], buttonsBuf, "DU");
    C2D_TextParse(&buttons[5], buttonsBuf, "DD");
    C2D_TextParse(&buttons[6], buttonsBuf, "DL");
    C2D_TextParse(&buttons[7], buttonsBuf, "DR");
    C2D_TextParse(&buttons[8], buttonsBuf, "L");
    C2D_TextParse(&buttons[9], buttonsBuf, "R");
    C2D_TextParse(&buttons[10], buttonsBuf, "SELECT");
    C2D_TextParse(&buttons[11], buttonsBuf, "START");
    C2D_TextParse(&buttons[12], buttonsBuf, "ZL");
    C2D_TextParse(&buttons[13], buttonsBuf, "ZR");
    for (size_t i = 0; i < 13; i++)
    {
        C2D_TextOptimize(&buttons[i]);
    }
}

static void sceneExit(void)
{
    // Delete the text buffers
    C2D_TextBufDelete(mainTextBuf);
    C2D_TextBufDelete(timeBuf);
}

static void sceneRenderTop()
{
    C2D_TextBufClear(timeBuf); // reset time buffer

    u64 timeInSeconds = osGetTime() / 1000;                    // --------------------------------- //
    u64 dayTime = timeInSeconds % 86400;                       //                                   //
    u8 hour = dayTime / 3600;                                  // Set up all the stuff for time     //
    u8 min = (dayTime % 3600) / 60;                            // ありがとう fincs!                  //
    u8 seconds = dayTime % 60;                                 //                                   //
    sprintf(timeString, "%02d:%02d:%02d", hour, min, seconds); // --------------------------------- //

    u32 white = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF); // draw main UI
    m_useColor(0x37, 0x67, 0x70);
    adv_background(0x35, 0x3E, 0x4A);
    m_rect(0, 0, 400, 20);
    C2D_DrawText(&uiText[0], C2D_WithColor, 2, 2, 0, 0.5f, 0.5f, white);

    C2D_TextParse(&sysTime, timeBuf, timeString); // draw time
    C2D_TextOptimize(&sysTime);
    C2D_DrawText(&sysTime, C2D_WithColor | C2D_AlignCenter, 200, 2, 0, 0.5f, 0.5f, white);

    if (loaded == 0) // only draw test options if no option is loaded
    {
        // test options
        m_rect(0, 30, 110, 55);
        m_rect(0, 60, 110, 85);
        m_rect(0, 90, 110, 115);
        m_rect(0, 120, 110, 145);
        m_rect(0, 210, 110, 235);
        C2D_DrawText(&modesText[0], C2D_WithColor, 2, 34, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&modesText[1], C2D_WithColor, 2, 64, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&modesText[2], C2D_WithColor, 2, 94, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&modesText[3], C2D_WithColor, 2, 214, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&modesText[4], C2D_WithColor, 2, 124, 0, 0.5f, 0.5f, white);
    }
    else if (loaded == 1)
    {
        checkButtons();
        C2D_DrawText(&uiText[2], C2D_WithColor | C2D_AtBaseline, 2, 236, 0, 0.6f, 0.6f, white);

        C2D_DrawText(&buttons[0], C2D_WithColor, 330, 112, 0, 0.5f, 0.5f, white); // ABXY, DPAD-UDLR
        C2D_DrawText(&buttons[1], C2D_WithColor, 300, 132, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&buttons[2], C2D_WithColor, 300, 92, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&buttons[3], C2D_WithColor, 270, 112, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&buttons[4], C2D_WithColor, 80, 92, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&buttons[5], C2D_WithColor, 80, 132, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&buttons[6], C2D_WithColor, 50, 112, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&buttons[7], C2D_WithColor, 110, 112, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&buttons[10], C2D_WithColor, 245, 192, 0, 0.5f, 0.5f, white); // START/SELECT
        C2D_DrawText(&buttons[11], C2D_WithColor, 105, 192, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&buttons[8], C2D_WithColor, 55, 52, 0, 0.5f, 0.5f, white); // L/R
        C2D_DrawText(&buttons[9], C2D_WithColor, 295, 52, 0, 0.5f, 0.5f, white);
    }
    else if (loaded == 2)
    {
        rgbsTop();
        C2D_DrawText(&uiText[1], C2D_WithColor | C2D_AtBaseline, 2, 236, 0, 0.6f, 0.6f, white);
        C2D_DrawText(&enabled3D, C2D_WithColor | C2D_AtBaseline | C2D_AlignCenter, 202.5f, 120, 0, 1.0f, 1.0f, white);
    } else if (loaded == 4) {
        drawLStick(pxx, pyy);
        C2D_DrawText(&uiText[1], C2D_WithColor | C2D_AtBaseline, 2, 236, 0, 0.6f, 0.6f, white);
    }
    else
    {
        C2D_DrawText(&uiText[1], C2D_WithColor | C2D_AtBaseline, 2, 236, 0, 0.6f, 0.6f, white);
    }
}

static void sceneRenderTop3D() {
    u32 white = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
    if (loaded == 2) {
        rgbsTop();
        C2D_DrawText(&enabled3D, C2D_WithColor | C2D_AtBaseline | C2D_AlignCenter, 197.5f, 120, 0, 1.0f, 1.0f, white);
    }
}

static void sceneRenderBottom()
{
    m_useColor(0x35, 0x3E, 0x4A);
    m_background();

    if (loaded == 2)
    {
        rgbsBtm();
    }
    
}

int main()
{
    //init stuff
    srvInit();
    aptInit();
    gfxInitDefault();
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C2D_Prepare();
    u32 clrClear = C2D_Color32(0xFF, 0xD8, 0xB0, 0x68);

    //create screens
    C3D_RenderTarget *top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
    C3D_RenderTarget *top3D = C2D_CreateScreenTarget(GFX_TOP, GFX_RIGHT);
    C3D_RenderTarget *bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
    sceneInit();

    while (aptMainLoop())
    {
        hidScanInput();
        // check buttons
        u32 kDown = hidKeysDown();
        u32 kHeld = hidKeysHeld();
        if (loaded == 0)
        {
            if (kDown & KEY_Y)
                break;
            if (kDown & KEY_A)
                loaded = 1;
            if (kDown & KEY_L)
                loaded = 4;
            if (kDown & KEY_B) {
                gfxSet3D(true);
                loaded = 2;
            }
            if (kDown & KEY_X)
                loaded = 3;
        }
        else if (kDown & KEY_B)
        {
                loaded = 0;
                gfxSet3D(false);
        }

        touchPosition touch;
        hidTouchRead(&touch);
        circlePosition pos;
        hidCircleRead(&pos);
        pxx = pos.dx;
        pyy = pos.dy;

        //render loaded
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);

        C2D_TargetClear(top, clrClear);
        C2D_SceneBegin(top);
        C3D_FrameDrawOn(top);

        sceneRenderTop();

        C2D_TargetClear(top3D, clrClear);
        C2D_SceneBegin(top3D);
        C3D_FrameDrawOn(top3D);

        sceneRenderTop3D();

        C2D_TargetClear(bottom, clrClear);
        C2D_SceneBegin(bottom);
        C3D_FrameDrawOn(bottom);

        if (loaded == 1 || loaded == 2)
        {
            sceneRenderBottom();
        } else if (loaded == 0) {
            touchPosition tc;
            hidTouchRead(&tc);
            sceneRenderBottom();
            m_useColor(0x48, 0x54, 0x63);
            m_rect(5, 5, 100, 30);
            u32 white = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
            C2D_DrawText(&uiText[3], C2D_WithColor | C2D_AtBaseline | C2D_AlignCenter, 50, 23, 0, 0.5f, 0.5f, white);
            if(touchWithin(tc.px, tc.py, 5, 5, 100, 30)) {
                loaded = 5;
            }
        } else if (loaded == 5) {
            touchPosition tc;
            hidTouchRead(&tc);
            sceneRenderBottom();
            m_useColor(0x48, 0x54, 0x63);
            m_rect(5, 55, 100, 80);
            u32 white = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
            C2D_DrawText(&uiText[4], C2D_WithColor | C2D_AtBaseline | C2D_AlignCenter, 50, 73, 0, 0.5f, 0.5f, white);
            if(touchWithin(tc.px, tc.py, 5, 55, 100, 80)) {
                //Reboot Code
			    //aptOpenSession();
			    APT_HardwareResetAsync();
			    //aptCloseSession();
            }
        } else if (loaded == 4) {
            sceneRenderBottom();
        }
        else if (loaded == 3)
        {
            adv_background(0x00, 0x00, 0x00);
            if (kHeld & KEY_TOUCH)
            {
                touchPosLines(touch.px, touch.py);
            }
        }

        C3D_FrameEnd(0);

        u32 reKDown = hidKeysHeld();
        if (reKDown & KEY_B && reKDown & KEY_START && loaded == 1)
            loaded = 0;
    }
    sceneExit();

    // Deinit libs
    C2D_Fini();
    C3D_Fini();
    aptExit();
	srvExit();
    gfxExit();
    return 0;
}