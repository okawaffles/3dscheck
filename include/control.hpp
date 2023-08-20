#pragma once

#include <3ds.h>

void UpdateButtons();
bool ButtonPressed(u32 keyBit);
bool ButtonHeld(u32 keyBit);

// touch
void UpdateTouch();
u16 GetTouchX();
u16 GetTouchY();
bool TouchIsWithin(int x1, int y1, int x2, int y2);