#include "control.hpp"
#include <3ds.h>

bool ButtonPressed(u32 keyBit)
{
    hidScanInput();
    u32 kDown = hidKeysDown();
    return (kDown & keyBit);
}

bool ButtonHeld(u32 keyBit)
{
    hidScanInput();
    u32 kHeld = hidKeysDown();
    return (kHeld & keyBit);
}