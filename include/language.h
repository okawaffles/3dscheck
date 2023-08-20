/*

most of this file is copied over from 3DSCheck (old) 1.4

*/


#pragma once

#include <3ds.h>
#include <citro2d.h>
#include <string.h>


// pretty sure this is required for it to compile correctly. 
#ifdef __cplusplus

extern "C" {
#endif


typedef enum
{
    StrId_3DSCheck,
    StrId_Authors,
    StrId_Screens_2DS,
    StrId_Screens_3DS,
    StrId_Buttons,
    StrId_Touchscreen,
    StrId_SlidePad,

    // keep this in for some reason, i dont remember how this works, i just know it does.
    StrId_Max
} StrId;

extern const char* const g_strings[StrId_Max][64];
const StrId langValuesList[64] = {
    StrId_3DSCheck,
    StrId_Authors,
    StrId_Screens_2DS,
    StrId_Screens_3DS,
    StrId_Buttons,
    StrId_Touchscreen,
    StrId_SlidePad,
};

// buttons for button check
const char *returnBtn(int id);


// function to get from language.c/h
// from homebrew launcher code, thx fincs (?)
const char* textGetString(StrId id, u8 language);

#ifdef __cplusplus
}
#endif