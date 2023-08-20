#include "language.h"
#include <string.h>
#include <stdio.h>

#define LANG_JP(_str) [CFG_LANGUAGE_JP] = _str
#define LANG_EN(_str) [CFG_LANGUAGE_EN] = _str

const char* const g_strings[StrId_Max][64] =
{
    [StrId_3DSCheck] = {
        LANG_JP("3DSCheck 2.0.0 JP"),
        LANG_EN("3DSCheck 2.0.0 EN") // L R DPAD ALCLOCK SMILE ANGRY SAD FACE? SUNNY CLOUD UMBRELLA SNOWMAN
    },
    [StrId_Authors] = {
        LANG_JP("によってokawaffles"),
        LANG_EN("By okawaffles")
    },
    [StrId_Screens_2DS] = {
        LANG_JP(" 画面 (3Dない)"),
        LANG_EN(" Screen (without 3D)")
    },
    [StrId_Screens_3DS] = {
        LANG_JP(" 画面 (3Dがある)"),
        LANG_EN(" Screen (with 3D)")
    },
    [StrId_Buttons] = {
        LANG_JP(" ボタン"),
        LANG_EN(" Buttons")
    },
    [StrId_Touchscreen] = {
        LANG_JP(" タッチスクリーン"),
        LANG_EN(" Touchscreen")
    },
    [StrId_SlidePad] = {
        LANG_JP(" スライドパッド"),
        LANG_EN(" Circle Pad")
    },
};

const char* returnBtn(int id)
{
    const char *buttons[14] = { "", "", "", "", "DU", "DD", "DL", "DR", "", "", "SELECT", "START", "ZL", "ZR" };

    return buttons[id];
}

const char* textGetString(StrId id, u8 language)
{
	const char* str = g_strings[id][language];
	if (!str) str = g_strings[id][CFG_LANGUAGE_EN];
	return str;
}