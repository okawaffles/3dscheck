#include "language.h"
#include <string.h>
#include <stdio.h>

#define STR_JP(_str) [CFG_LANGUAGE_JP] = _str
#define STR_EN(_str) [CFG_LANGUAGE_EN] = _str
#define STR_FR(_str) [CFG_LANGUAGE_FR] = _str
#define STR_ES(_str) [CFG_LANGUAGE_ES] = _str

const char* const g_strings[StrId_Max][32] =
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
        STR_EN("English (Official)"),
        STR_JP("日本語 (公式)"),
        STR_FR("Français (officieux)"),
        STR_ES("Español (extraoficial)"),
    },

    [StrId_Tools] =
    {
        STR_EN("Tools"),
        STR_JP("ツール"),
        STR_FR("Outils"),
        STR_ES("Utilidades"),
    },

    [StrId_LowBattery] =
    {
        STR_EN("Low Battery!"),
        STR_JP("低いバッテリー!"),
        STR_FR("Batterie faible!"),
        STR_ES("Batería baja!"),
    },

    [StrId_DetailsView] =
    {
        STR_EN("View More Details"),
        STR_JP("StrId_DetailsView_JP"),
        STR_FR("StrId_DetailsView_FR"),
        STR_ES("StrId_DetailsView_ES"),
    },

    [StrId_Yes] =
    {
        STR_EN("Yes"),
        STR_JP("はい"),
        STR_FR("Oui"),
        STR_ES("Sí"),
    },
    [StrId_No] =
    {
        STR_EN("No"),
        STR_JP("いいえ"),
        STR_FR("Non"),
        STR_ES("No"),
    },

    [StrId_WiFi] =
    {
        STR_EN("WiFi Connected"),
        STR_JP("WiFiが付します"),
        STR_FR("FR"),
        STR_ES("ES"),
    },
    [StrId_NoWiFi] =
    {
        STR_EN("No WiFi"),
        STR_JP("WiFiがありません"),
        STR_FR("FR"),
        STR_ES("ES"),
    },

    [StrId_Charging] =
    {
        STR_EN("Charging"),
        STR_JP(""),
        STR_FR("FR"),
        STR_ES("ES"),
    },
};

char *returnBtn(int id) {
    char *buttons[14] = { "A", "B", "X", "Y", "DU", "DD", "DL", "DR", "L", "R", "SELECT", "START", "ZL", "ZR" };

    return buttons[id];
}