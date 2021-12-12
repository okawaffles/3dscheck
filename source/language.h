#pragma once

#include <3ds.h>
#include <string.h>

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
    
    StrId_Max,
} StrId;

extern const char* const g_strings[StrId_Max][16];