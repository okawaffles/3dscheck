#include "control.hpp"
#include <stdio.h>
#include <3ds.h>

u32 kDown;
u32 kHeld;
touchPosition t;

void UpdateButtons()
{
    hidScanInput();
    kDown = hidKeysDown();
    kHeld = hidKeysHeld();
}

bool ButtonPressed(u32 keyBit)
{
    return (kDown & keyBit);
}

bool ButtonHeld(u32 keyBit)
{
    return (kHeld & keyBit);
}


void UpdateTouch()
{
    hidTouchRead(&t);
}

u16 GetTouchX()
{
    return t.px;
}

u16 GetTouchY()
{
    return t.py;
}

bool TouchIsWithin(int x1, int y1, int x2, int y2)
{
    return (t.px >= x1 && t.px <= x2 && t.py >= y1 && t.py <= y2);
}