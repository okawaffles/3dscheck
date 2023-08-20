#pragma once

#include "common.hpp"
#include "graphics.hpp"
#include "language.h"
#include "textManager.hpp"

// controls which function is shown
enum
{
    MAIN_MENU = 0,
    SCREEN_CHECK_3D = 1,
    SCREEN_CHECK_2D = 2,
    BUTTONS_CHECK = 3,
    SLIDEPAD_CHECK = 4,
    SOUND_CHECK = 5,
    SENSOR_CHECK = 6
};

// self explanatory functions
unsigned int GetCurrentFunction();
void SetCurrentFunction(unsigned int function);

// function to draw the main menu
void DrawMenu(u8 model, AppTextManager *ATM);
void DrawMenuBottom(u8 model, AppTextManager *ATM);