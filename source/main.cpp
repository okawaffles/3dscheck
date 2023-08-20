// by okawaffles, 2021 - 2023

#include "common.hpp"
#include "control.hpp"
#include "textManager.hpp"
#include "graphics.hpp"
#include "menu.hpp"
#include "checks.hpp"

// constants
// screen size
#define SCREEN_WIDTH_TOP 400
#define SCREEN_WIDTH_BOTTOM 320
#define SCREEN_HEIGHT 240

#define __DEBUG

// variables
bool n3ds = false;
u8 systemModel = CFG_MODEL_3DS; // defualt to normal 3DS
u8 systemLang = 0; // ddefault is JP.

int main()
{
    // initialize some things we'll need for various features
    srvInit(); // used for ???
    cfguInit(); // used for getting system preferences
    aptInit(); // used for opening system settings
    hidInit(); // used for HID
    mcuHwcInit(); // used for battery

    // link to 3dslink host
    //link3dsConnectToHost(true, true);
    printf("Linked to 3DSlink\n");

    // start graphics
    gfxInitDefault();
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE); // 3D graphics
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS); // 2D graphics
    C2D_Prepare();
#ifdef __DEBUG
    consoleInit(GFX_BOTTOM, NULL);
    printf("Console init'd bottom.\n");
#endif

    // load resources
    printf("(main) load resources\n");
    CFGU_GetSystemLanguage(&systemLang);
    CFGU_GetSystemModel(&systemModel);
    AppTextManager ATM(systemLang);

    // runs forever, break when we want to exit.
    printf("(main) starting aptMainLoop()\n");
    while (aptMainLoop())
    {
        // needed only once
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);

        /* TOP SCREEN */

        // needed for each screen: [1]
        // clear screen
        C2D_TargetClear(top, Colors_BackgroundPrimary);
        C2D_SceneBegin(top);
        C3D_FrameDrawOn(top);
        // end [1]

        // draw the top bar
        GFX_DrawRect(0, 0, SCREEN_WIDTH_TOP, 20, Colors_BackgroundLighter);
        ATM.DrawText(StrId_3DSCheck, 2, 2);
        
        // draw respective things
        unsigned int FN = GetCurrentFunction();
        if (FN == MAIN_MENU) DrawMenu(systemModel, &ATM);


#ifndef __DEBUG
        /* BOTTOM SCREEN */
        // clear screen
        C2D_TargetClear(bottom, Colors_BackgroundPrimary);
        C2D_SceneBegin(bottom);
        C3D_FrameDrawOn(bottom);

        // later, execute bottom drawing
#endif

        // done drawing
        C3D_FrameEnd(0);


        // buttons on the menu!
        if (GetCurrentFunction() == MAIN_MENU)
        {
            // scan controls for START to exit:
            if (ButtonPressed(KEY_START)) break;

            // scan controls for the different functions
            // later, will add options for touching things on the bottom screen too
            if (ButtonPressed(KEY_A)) { // <---- TODO: not working!
                printf("(main) set current function: SCREEN_CHECK");
                // A is special because we will show two different strings based on the model of the device.
                if ((systemModel == CFG_MODEL_2DS) || (systemModel == CFG_MODEL_N2DSXL))
                {
                    SetCurrentFunction(SCREEN_CHECK_2D);
                }
                else SetCurrentFunction(SCREEN_CHECK_3D);
            }
        }

#ifdef __DEBUG
        // debugging will allow us to use START+SELECT anywhere so we don't get trapped
        if (ButtonPressed(KEY_START) && ButtonHeld(KEY_SELECT)) break;
#endif
    }

    // Exit and clean up
    hidExit(); // Deinitialize the HID module
    aptExit();
    srvExit();
    mcuHwcExit();

    C2D_Fini();
	C3D_Fini();
	gfxExit();

    return 0;
}