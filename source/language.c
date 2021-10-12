#include "language.h"
#include <string.h>

#define STR_JP(_str) [CFG_LANGUAGE_JP] = _str
#define STR_EN(_str) [CFG_LANGUAGE_EN] = _str
#define STR_FR(_str) [CFG_LANGUAGE_FR] = _str

const char* const g_strings[StrId_Max][16] =
{
    [StrId_Buttons] =
    {
        STR_EN("Buttons"),
        STR_JP("ボタン"),
        STR_FR("Botones"),
    },

    [StrId_Screen] =
    {
        STR_EN("Screen"),
        STR_JP("スクリーン"),
        STR_FR("Écran"),
    },

    [StrId_Touchscreen] =
    {
        STR_EN("Touchscreen"),
        STR_JP("タッチ"),
        STR_FR("Écran tactile"),
    },

    [StrId_Return] =
    {
        STR_EN("Return to HBL"),
        STR_JP("ローダへ帰り"),
        STR_FR("Retour à HBL"),
    },

    [StrId_Stick] =
    {
        STR_EN("Stick"),
        STR_JP("スライドパッド"),
        STR_FR("Bloc de cercle"),
    },

    [StrId_CStick] =
    {
        STR_EN("CStick"),
        STR_JP("C パッド"),
        STR_FR("Bâton C"),
    },

    [StrId_3DSCheck] =
    {
        STR_EN("3DSCheck"),
        STR_JP("3DSCheck"),
        STR_FR("3DSVérifier"),
    },

    [StrId_Back] =
    {
        STR_EN("Back"),
        STR_JP("帰る"),
        STR_FR("Retour"),
    },

    [StrId_StartBack] =
    {
        STR_EN("START +  Back"),
        STR_JP("START +  帰る"),
        STR_FR("START +  Retour"),
    },

    [StrId_SysOpt] =
    {
        STR_EN("Sys. Opt."),
        STR_JP("本体設定"),
        STR_FR("Système"),
    },

    [StrId_Restart] =
    {
        STR_EN("Restart"),
        STR_JP("再起動"),
        STR_FR("Redémarrer"),
    },

    [StrId_SysSettings] =
    {
        STR_EN("Open Sys. Settings"),
        STR_JP("本体設定を起動する"),
        STR_FR("Paramètres de Console"),
    },

    [StrId_3DScreenCheck] =
    {
        STR_EN("3D SCREEN TEST"),
        STR_JP("3Dスクリーンテスト"),
        STR_FR("Paramètres de Console"),
    },

    [StrId_Version] =
    {
        STR_EN("EN of v1.3R-EJF"),
        STR_JP("v1.3R-EJFのJP"),
        STR_FR("FR de v1.3R-EJF"),
    },
};