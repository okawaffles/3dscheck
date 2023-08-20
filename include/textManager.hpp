#pragma once

#include "common.hpp"
#include "language.h"

// text
class AppTextManager
{
private:
    C2D_TextBuf mainBuffer, timeBuffer, buttonsBuffer;
    C2D_Text mainText[64], timeText, buttonsText[16];
public:
    u8 language = 0; // JP is default language
    AppTextManager(u8 systemLanguage);
    ~AppTextManager();
    void DrawText(StrId id, float x, float y, float z = 0.0f, u32 flags = C2D_WithColor, float scaleX = 0.5f, float scaleY = 0.5f, u32 color = Colors_White);
    void DrawButton(unsigned int id, float x, float y, u32 flags, float scaleX, float scaleY, u32 color);
};