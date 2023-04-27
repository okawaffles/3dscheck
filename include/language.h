#pragma once

#include <3ds.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif



typedef enum
{
    StrId_Buttons,
    StrId_Screen,
    StrId_Touchscreen,
    StrId_Return,
    StrId_Stick,
    StrId_CStick,
    StrId_3DSCheck,
    StrId_Back,
    StrId_StartBack,
    StrId_SysOpt,
    StrId_Restart,
    StrId_SysSettings,
    StrId_3DScreenCheck,
    StrId_Version,
    StrId_Language,
    StrId_Tools,
    StrId_CustomChainload,
    StrId_DetailsView,
    StrId_Yes,
    StrId_No,
    StrId_NoWiFi,
    StrId_WiFi,

    StrId_Max,
} StrId;

extern const char* const g_strings[StrId_Max][32];
const StrId langValuesList[32] = {
    StrId_Buttons,
    StrId_Screen,
    StrId_Touchscreen,
    StrId_Return,
    StrId_Stick,
    StrId_CStick,
    StrId_3DSCheck,
    StrId_Back,
    StrId_StartBack,
    StrId_SysOpt,
    StrId_Restart,
    StrId_SysSettings,
    StrId_3DScreenCheck,
    StrId_Version,
    StrId_Language,
    StrId_Tools,
    StrId_CustomChainload,
    StrId_DetailsView,
    StrId_Yes,
    StrId_No,
    StrId_NoWiFi,
    StrId_WiFi,
};

const char *returnBtn(int id);



#ifdef __cplusplus
}
#endif