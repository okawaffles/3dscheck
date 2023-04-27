// libraries
#include <citro2d.h>
#include <3ds.h>
#include <unistd.h>
#include "extra.h"
// external functions
#include "touchscreen.h"
#include "buttons.h"
#include "screens.h"
#include "main.h"
#include "sticks.h"
#include "language.h"
#include "mode.h"
// define some extra stuff 
#define SCREEN_WIDTH_TOP 400
#define SCREEN_HEIGHT_TOP 240
#define SCREEN_WIDTH_BOTTOM 320
#define SCREEN_HEIGHT_BOTTOM 240
#define LANGUAGE_FR 2
#define LANGUAGE_EN 1
#define LANGUAGE_JP 0
// variables
bool n3ds = false; // n3ds to be assigned, false by default
u8 language = 0; // language to be assigned, JP by default
//static u32 wifiStat = 0;
int pxx, pyy; // circle pad vars

// text strings and buffers
C2D_TextBuf mainTextBuf, timeBuf, buttonsBuf; 
C2D_Text modesText[10], uiText[10], sysTime, buttons[14], enabled3D, ver, detailsView[16];

// new buffer for everything but time cause why not
C2D_Text texts[52];

static char timeString[9];

// function to get from language.c/h
// taken from homebrew launcher code
const char* textGetString(StrId id)
{
	const char* str = g_strings[id][language];
	if (!str) str = g_strings[id][CFG_LANGUAGE_EN];
	return str;
}

// initiaize scene
static void sceneInit()
{
    printf("create buffers...");
    mainTextBuf = C2D_TextBufNew(4096); // create text buffers
    timeBuf = C2D_TextBufNew(4096);
    buttonsBuf = C2D_TextBufNew(4096);
    printf("OK\n");

    // load text strings based on language. this is painful
    printf("load language...");

    for (int i = 0; i < 13; i++)
        C2D_TextParse(&texts[i], mainTextBuf, textGetString(langValuesList[i]));

    printf("OK\n");

    // optimize text strings
    printf("optimize ui text...");
    
    for (int i = 0; i < 50; i++)
    {
        C2D_TextOptimize(&texts[i]);
    }

    printf("OK\n");

    // parse and optimize the button strings
    printf("optimize button text...");
    for (size_t i = 0; i < 14; i++)
    {
        C2D_TextParse(&buttons[i], buttonsBuf, returnBtn(i));
        C2D_TextOptimize(&buttons[i]);
    }
    printf("OK\n");
    printf("all OK\n");
}

// runs when program is exiting
static void sceneExit(void)
{
    // Delete the text buffers
    C2D_TextBufDelete(mainTextBuf);
    C2D_TextBufDelete(timeBuf);
    C2D_TextBufDelete(buttonsBuf);
}

// render the common top screen elements
static void sceneRenderTop()
{
    static u8 battery = 0; // battery level
    MCUHWC_GetBatteryLevel(&battery); // get battery level
    C2D_TextBufClear(timeBuf); // reset time buffer

    u64 timeInSeconds = osGetTime() / 1000;                    // --------------------------------- //
    u64 dayTime = timeInSeconds % 86400;                       //                                   //
    u8 hour = dayTime / 3600;                                  // Set up all the stuff for time     //
    u8 min = (dayTime % 3600) / 60;                            // ありがとう whoever did this        //
    u8 seconds = dayTime % 60;                                 //                                   //
    sprintf(timeString, "%02d:%02d:%02d", hour, min, seconds); // --------------------------------- //

    u32 white = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF); // draw main UI

    adv_background(0x35, 0x3E, 0x4A);
    m_useColor(0x22, 0x27, 0x2E);
    m_rect(0, 0, 400, 23); // top bar shadow
    m_useColor(0x37, 0x67, 0x70);
    m_rect(0, 0, 400, 20); // top bar
    C2D_DrawText(&texts[6], C2D_WithColor, 2, 2, 0, 0.5f, 0.5f, white); // 3DSCheck string
    C2D_DrawText(&ver, C2D_WithColor | C2D_AlignRight | C2D_AtBaseline, 398, 238 , 0, 0.5f, 0.5f, white); // Language string

    m_useColor(0x37, 0x67, 0x70); // switch back to normal color regardless of battery

    char btext[32];
    sprintf(btext, "%d", battery);

    C2D_TextParse(&texts[14], mainTextBuf, btext);
    C2D_TextParse(&texts[15], mainTextBuf, "\%");
    C2D_TextOptimize(&texts[14]);
    C2D_TextOptimize(&texts[15]);
    C2D_DrawText(&texts[14], C2D_WithColor | C2D_AlignRight, 385, 2, 0, 0.5f, 0.5f, white);
    C2D_DrawText(&texts[15], C2D_WithColor | C2D_AlignRight, 398, 2, 0, 0.5f, 0.5f, white);

    C2D_TextParse(&sysTime, timeBuf, timeString); // draw time
    C2D_TextOptimize(&sysTime); 
    C2D_DrawText(&sysTime, C2D_WithColor | C2D_AlignCenter, 200, 2, 0, 0.5f, 0.5f, white);

    if (getMode() == 0) // only draw test options if no option is loaded
    {
        // test options
        m_useColor(0x22, 0x27, 0x2E); // shadows
        m_rect(0, 33, 153, 58);
        m_rect(0, 63, 153, 88);
        m_rect(0, 93, 153, 118);
        m_rect(0, 123, 153, 148);
        m_rect(0, 213, 153, 238);
        m_useColor(0x37, 0x67, 0x70);
        m_rect(0, 30, 150, 55);
        m_rect(0, 60, 150, 85);
        m_rect(0, 90, 150, 115);
        m_rect(0, 120, 150, 145);
        m_rect(0, 210, 150, 235);
        C2D_DrawText(&texts[0], C2D_WithColor, 4, 34, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&texts[1], C2D_WithColor, 4, 64, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&texts[2], C2D_WithColor, 4, 94, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&texts[3], C2D_WithColor, 4, 214, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&texts[4], C2D_WithColor, 4, 124, 0, 0.5f, 0.5f, white);
        if (n3ds) { // show cStick option is n3ds is enabled.
            m_useColor(0x22, 0x27, 0x2E);
            m_rect(0, 153, 153, 178);
            m_useColor(0x37, 0x67, 0x70);
            m_rect(0, 150, 150, 175);
            C2D_DrawText(&texts[5], C2D_WithColor, 4, 154, 0, 0.5f, 0.5f, white);
        }
    }
    else if (getMode() == 1) // buttons
    {
        checkButtons(n3ds);
        C2D_DrawText(&texts[8], C2D_WithColor | C2D_AtBaseline, 2, 236, 0, 0.6f, 0.6f, white); // show return text

        C2D_DrawText(&buttons[0], C2D_WithColor, 330, 112, 0, 0.5f, 0.5f, white); // ABXY, DPAD-UDLR
        C2D_DrawText(&buttons[1], C2D_WithColor, 300, 132, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&buttons[2], C2D_WithColor, 300, 92, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&buttons[3], C2D_WithColor, 270, 112, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&buttons[4], C2D_WithColor, 80, 92, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&buttons[5], C2D_WithColor, 80, 132, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&buttons[6], C2D_WithColor, 50, 112, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&buttons[7], C2D_WithColor, 110, 112, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&buttons[11], C2D_WithColor, 245, 192, 0, 0.5f, 0.5f, white); // START/SELECT
        C2D_DrawText(&buttons[10], C2D_WithColor, 105, 192, 0, 0.5f, 0.5f, white);
        C2D_DrawText(&buttons[8], C2D_WithColor, 55, 52, 0, 0.5f, 0.5f, white); // L/R
        C2D_DrawText(&buttons[9], C2D_WithColor, 295, 52, 0, 0.5f, 0.5f, white);
        if (n3ds) { //enable zl/zr if n3ds is true
            C2D_DrawText(&buttons[12], C2D_WithColor, 125, 52, 0, 0.5f, 0.5f, white); // ZL/ZR
            C2D_DrawText(&buttons[13], C2D_WithColor, 255, 52, 0, 0.5f, 0.5f, white);
        }
    }
    else if (getMode() == 2) // screen test
    {
        rgbsTop();
        C2D_DrawText(&texts[7], C2D_WithColor | C2D_AtBaseline, 2, 236, 0, 0.6f, 0.6f, white);
        C2D_DrawText(&enabled3D, C2D_WithColor | C2D_AtBaseline | C2D_AlignCenter, 202.5f, 120, 0, 1.0f, 1.0f, white);
    } else if (getMode() == 4) { // Circle pad test
        drawLStick(pxx, pyy);
        C2D_DrawText(&texts[7], C2D_WithColor | C2D_AtBaseline, 2, 236, 0, 0.6f, 0.6f, white);
    } else if (getMode() == 6) { // C"Stick" test
        drawCStick();
        C2D_DrawText(&texts[7], C2D_WithColor | C2D_AtBaseline, 2, 236, 0, 0.6f, 0.6f, white);
    }
    else
    {   // not sure what this is tbh.
        C2D_DrawText(&texts[7], C2D_WithColor | C2D_AtBaseline, 2, 236, 0, 0.6f, 0.6f, white);
    }
}

static void sceneRenderTop3D() { // for the screen test, only enabled when 3D is on
    u32 white = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
    if (getMode() == 2) {
        rgbsTop();
        C2D_DrawText(&enabled3D, C2D_WithColor | C2D_AtBaseline | C2D_AlignCenter, 197.5f, 120, 0, 1.0f, 1.0f, white);
    }
}

static void sceneRenderBottom() // render common bottom screen elements
{
    adv_background(0x35, 0x3E, 0x4A);

    if (getMode() == 2) // screen test
    {
        rgbsBtm();
    }
}

int main() // main stuff, this is where it gets messy
{
    //init stuff
    srvInit(); // idk what half of these acronyms stand for, but they are needed
    cfguInit();
    aptInit();
    mcuHwcInit();
    CFGU_GetSystemLanguage(&language); // get system language (lol)
    APT_CheckNew3DS(&n3ds); // enable or disable n3ds features

    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);
    printf("loading...\n");
    sleep(0.1f);
    sceneInit();
    sleep(0.5f);
    gfxExit();

    gfxInitDefault();
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C2D_Prepare();
    u32 clrClear = C2D_Color32(0xFF, 0xD8, 0xB0, 0x68);

    //create screens
    C3D_RenderTarget *top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
    C3D_RenderTarget *top3D = C2D_CreateScreenTarget(GFX_TOP, GFX_RIGHT);
    C3D_RenderTarget *bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

    while (aptMainLoop()) // loops forever (until quit[break])
    {
        // check buttons
        hidScanInput();
        u32 kDown = hidKeysDown();
        u32 kHeld = hidKeysHeld();
        if (getMode() == 0)
        {
            if (kDown & KEY_Y) break; // return to hbl
            if (kDown & KEY_A) setMode(1U); // buttons
            if (kDown & KEY_X) setMode(3U); // touchscreen
            if (kDown & KEY_L) setMode(4U); // stick
            if (kDown & KEY_R && n3ds) setMode(6U); // c-stick
            if (kDown & KEY_B) { // screen check
                gfxSet3D(true);
                setMode(2U);
            }
        }
        else if (kDown & KEY_B)
        {
            // return to main menu
            setMode(0U);
            gfxSet3D(false);
        }

        touchPosition touch; // get touch pos
        hidTouchRead(&touch);

        // render what's needed
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

        if (getMode() == 1 || getMode() == 2) // i think this is to control what the bottom screen shows. it can and will be heavily improved.
        {
            sceneRenderBottom();
        } else if (getMode() == 0) {
            touchPosition tc;
            hidTouchRead(&tc);
            sceneRenderBottom();
            m_useColor(0x48, 0x54, 0x63);
            m_rect(5, 5, 315, 30);
            //m_rect(5, 35, 315, 60);
            u32 white = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
            C2D_DrawText(&texts[9], C2D_WithColor | C2D_AtBaseline | C2D_AlignCenter, 160, 23, 0, 0.5f, 0.5f, white);
            
            // Accessibility


            if(touchWithin(tc.px, tc.py, 5, 5, 315, 30)) {
                setMode(5U);
            }
            if(touchWithin(tc.px, tc.py, 5, 35, 315, 60)) {
                //loaded = 7;
            }
        } else if (getMode() == 5) {
            touchPosition tc;
            hidTouchRead(&tc);
            sceneRenderBottom();
            m_useColor(0x48, 0x54, 0x63);
            m_rect(5, 55, 315, 80);
            u32 white = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
            C2D_DrawText(&texts[9], C2D_WithColor | C2D_AtBaseline | C2D_AlignCenter, 160, 73, 0, 0.5f, 0.5f, white);

            if(touchWithin(tc.px, tc.py, 5, 55, 315, 80)) {
			    APT_HardwareResetAsync(); //reboot
            }

            m_rect(5, 85, 315, 110);
            C2D_DrawText(&texts[10], C2D_WithColor | C2D_AtBaseline | C2D_AlignCenter, 160, 103, 0, 0.5f, 0.5f, white);

            if(touchWithin(tc.px, tc.py, 5, 85, 315, 110)) {
                u8 region = 1;
                CFGU_SecureInfoGetRegion(&region);

                if(region == 0) { //JP
                    aptSetChainloader(0x0004001000020000LL, 0);
                } else if (region == 1) { //US
                    aptSetChainloader(0x0004001000020000LL, 0);
                } else { //OTHER
                    aptSetChainloader(0x0004001000020000LL, 0);
                }
                break;
            }
        } else if (getMode() == 4) {
            sceneRenderBottom();
        }
        else if (getMode() == 3)
        {
            adv_background(0x00, 0x00, 0x00);
            if (kHeld & KEY_TOUCH)
            {
                touchPosLines(touch.px, touch.py);
            }
        } else if (getMode() == 7) {
            sceneRenderBottom();
            /*char dest[] = textGetString(StrId_IsNew3DS);

            if (n3ds) {
                strcat(dest,textGetString(StrId_Yes));
                C2D_TextParse(&detailsView[0], mainTextBuf, &dest);
            } else {
                strcat(dest,textGetString(StrId_No));
                C2D_TextParse(&detailsView[0], mainTextBuf, &dest);
            }

            C2D_TextOptimize(&detailsView[0]);
            C2D_DrawText(&detailsView[0], C2D_WithColor, 5, 45, 0, 0.5f, 0.5f, white);*/
        } else {
            sceneRenderBottom();
        }

        C3D_FrameEnd(0);

        u32 reKDown = hidKeysHeld();
        if (reKDown & KEY_B && reKDown & KEY_START && getMode() == 1)
            setMode(0U);
    }
    sceneExit();

    // Deinit libs
    C2D_Fini();
    C3D_Fini();
    mcuHwcExit();
    aptExit();
	srvExit();
    gfxExit();
    cfguExit();
    return 0;
}

void mainMenuSet() {
    setMode(0U);
}