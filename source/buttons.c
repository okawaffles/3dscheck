#include <citro2d.h>
#include <3ds.h>
#include "mochalibs.h"

void checkButtons(bool n3ds)
{
    hidScanInput();
    u32 keys = hidKeysHeld();

    if (keys & KEY_A){m_useColor(0x00, 0xFF, 0x00);} else {m_useColor(0xFF, 0x00, 0x00);}
    m_rect(325, 110, 355, 130);
    if (keys & KEY_Y){m_useColor(0x00, 0xFF, 0x00);} else {m_useColor(0xFF, 0x00, 0x00);}
    m_rect(265, 110, 295, 130);
    if (keys & KEY_X){m_useColor(0x00, 0xFF, 0x00);} else {m_useColor(0xFF, 0x00, 0x00);}
    m_rect(295, 90, 325, 110);
    if (keys & KEY_B){m_useColor(0x00, 0xFF, 0x00);} else {m_useColor(0xFF, 0x00, 0x00);}
    m_rect(295, 130, 325, 150);

    if (keys & KEY_DRIGHT){m_useColor(0x00, 0xFF, 0x00);} else {m_useColor(0xFF, 0x00, 0x00);}
    m_rect(105, 110, 135, 130);
    if (keys & KEY_DLEFT){m_useColor(0x00, 0xFF, 0x00);} else {m_useColor(0xFF, 0x00, 0x00);}
    m_rect(45, 110, 75, 130);
    if (keys & KEY_DUP){m_useColor(0x00, 0xFF, 0x00);} else {m_useColor(0xFF, 0x00, 0x00);}
    m_rect(75, 90, 105, 110);
    if (keys & KEY_DDOWN){m_useColor(0x00, 0xFF, 0x00);} else {m_useColor(0xFF, 0x00, 0x00);}
    m_rect(75, 130, 105, 150);

    if (keys & KEY_START){m_useColor(0x00, 0xFF, 0x00);} else {m_useColor(0xFF, 0x00, 0x00);}
    m_rect(100, 190, 160, 210);
    if (keys & KEY_SELECT){m_useColor(0x00, 0xFF, 0x00);} else {m_useColor(0xFF, 0x00, 0x00);}
    m_rect(240, 190, 300, 210);

    if (keys & KEY_L){m_useColor(0x00, 0xFF, 0x00);} else {m_useColor(0xFF, 0x00, 0x00);}
    m_rect(50, 50, 110, 70);
    if (keys & KEY_R){m_useColor(0x00, 0xFF, 0x00);} else {m_useColor(0xFF, 0x00, 0x00);}
    m_rect(290, 50, 350, 70);

    if (n3ds) {
        if (keys & KEY_ZL){m_useColor(0x00, 0xFF, 0x00);} else {m_useColor(0xFF, 0x00, 0x00);}
        m_rect(120, 50, 150, 70);
        if (keys & KEY_ZR){m_useColor(0x00, 0xFF, 0x00);} else {m_useColor(0xFF, 0x00, 0x00);}
        m_rect(250, 50, 280, 70);
    }
}