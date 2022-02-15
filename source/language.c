#include "language.h"
#include <string.h>

#define STR_JP(_str) [CFG_LANGUAGE_JP] = _str
#define STR_EN(_str) [CFG_LANGUAGE_EN] = _str
#define STR_FR(_str) [CFG_LANGUAGE_FR] = _str
#define STR_ES(_str) [CFG_LANGUAGE_ES] = _str

const char* const g_strings[StrId_Max][16] =
{
    [StrId_Buttons] =
    {
        STR_EN(" Buttons"),
        STR_JP(" ボタン"),
        STR_FR(" Boutons"),
        STR_ES(" Botones"),
    },

    [StrId_Screen] =
    {
        STR_EN(" Screen"),
        STR_JP(" スクリーン"),
        STR_FR(" Écran"),
        STR_ES(" Pantalla"),
    },

    [StrId_Touchscreen] =
    {
        STR_EN(" Touchscreen"),
        STR_JP(" タッチ"),
        STR_FR(" Écran tactile"),
        STR_ES(" Pantalla Táctil"),
    },

    [StrId_Return] =
    {
        STR_EN(" Return to HBL"),
        STR_JP(" ローダへ帰り"),
        STR_FR(" Retour à HBL"),
        STR_ES(" Dejar a HBL"),
    },

    [StrId_Stick] =
    {
        STR_EN(" Stick"),
        STR_JP(" スライドパッド"),
        STR_FR(" Bloc de cercle"),
        STR_ES(" Botón deslizante"),
    },

    [StrId_CStick] =
    {
        STR_EN(" CStick"),
        STR_JP(" C パッド"),
        STR_FR(" Bâton C"),
        STR_ES(" Palanca C"),
    },

    [StrId_3DSCheck] =
    {
        STR_EN("3DSCheck"),
        STR_JP("3DSCheck"),
        STR_FR("3DSVérifier"),
        STR_ES("3DSVerificar"),
    },

    [StrId_Back] =
    {
        STR_EN(" Back"),
        STR_JP(" 帰る"),
        STR_FR(" Retour"),
        STR_ES(" Regresar"),
    },

    [StrId_StartBack] =
    {
        STR_EN("START +  Back"),
        STR_JP("START +  帰る"),
        STR_FR("START +  Retour"),
        STR_ES("START +  Regresar"),
    },

    [StrId_SysOpt] =
    {
        STR_EN("System Options"),
        STR_JP("本体設定"),
        STR_FR("Système"),
        STR_ES("Consola"),
    },

    [StrId_Restart] =
    {
        STR_EN("Restart"),
        STR_JP("再起動"),
        STR_FR("Redémarrer"),
        STR_ES("Reiniciar"),
    },

    [StrId_SysSettings] =
    {
        STR_EN("Open System Settings"),
        STR_JP("本体設定を起動する"),
        STR_FR("Paramètres de Console"),
        STR_ES("Configuración de la Consola"),
    },

    [StrId_3DScreenCheck] =
    {
        STR_EN("3D SCREEN TEST"),
        STR_JP("3Dスクリーンテスト"),
        STR_FR("Test de l'écran 3D"),
        STR_ES("Verificación de pantalla 3D"),
    },

    [StrId_Version] =
    {
        STR_EN("EN of v1.5R-EJFS"),
        STR_JP("v1.5R-EJFSのJP"),
        STR_FR("FR de v1.5R-EJFS"),
        STR_ES("ES de v1.5R-EJFS"),
    },

    [StrId_Language] =
    {
        STR_EN("English"),
        STR_JP("日本語"),
        STR_FR("Français"),
        STR_ES("Español"),
    },

    [StrId_Tools] =
    {
        STR_EN("Tools"),
        STR_JP("ツール"),
        STR_FR("Outils"),
        STR_ES("Utilidades"),
    },

    [StrId_CustomChainload] =
    {
        STR_EN("Custom Chainload"),
        STR_JP("カスタムチェインロード"),
        STR_FR("Chargeur personnalisé"),
        STR_ES("Cargador de Personalizado"),
    },
};

/* const char buttons[14];
buttons[0] = "A";
buttons[1] = "B";
buttons[2] = "X";
buttons[3] = "Y";
buttons[4] = "DU";
buttons[5] = "DD";
buttons[6] = "DL";
buttons[7] = "DR";
buttons[8] = "L";
buttons[9] = "R";
buttons[10] = "SELECT";
buttons[11] = "START";
buttons[12] = "ZL";
buttons[13] = "ZR";*/

/*const enum buttons[] = { 'A', 'B', 'X', 'Y', "DU", "DD", "DL", "DR", 'L', 'R', "SELECT", "START", "ZL", "ZR" };

int returnBtn(int id) {
    return(buttons[id]);
}*/