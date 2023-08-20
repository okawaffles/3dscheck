#include "textManager.hpp"

AppTextManager::AppTextManager(u8 systemLanguage)
{
    // initialize everything
    // debug
    printf("(ATM) init...\n");

    // prep the buffers
    this->mainBuffer = C2D_TextBufNew(4096);
    this->timeBuffer = C2D_TextBufNew(4096);
    this->buttonsBuffer = C2D_TextBufNew(4096);
    this->language = systemLanguage;

    // get all texts into the buffers
    // update as we add more
    for (size_t i = 0; i < StrId_Max; i++) {
        C2D_TextParse(&this->mainText[i], this->mainBuffer, textGetString( langValuesList[i], language ));

        // optimize it, not that it matters but it's good practice
        C2D_TextOptimize(&mainText[i]);
    }

    // buttons
    for (size_t i = 0; i < 14; i++)
    {
        C2D_TextParse(&buttonsText[i], buttonsBuffer, returnBtn(i));
        C2D_TextOptimize(&buttonsText[i]);
    }

    printf("(ATM) OK!\n");
}

AppTextManager::~AppTextManager()
{
    // destroy everything
    // delete the text buffers
    C2D_TextBufDelete(mainBuffer);
    C2D_TextBufDelete(timeBuffer);
    C2D_TextBufDelete(buttonsBuffer);
}

// draw a text
// 0.5f is default scaling.
void AppTextManager::DrawText(StrId id, float x, float y, u32 flags, float scaleX, float scaleY, u32 color)
{
    // draw string
    C2D_DrawText(&this->mainText[id], flags, x, y, 0, scaleX, scaleY, color);
}

// button-specific function
// 0.5f is default scaling
void AppTextManager::DrawButton(unsigned int id, float x, float y, u32 flags, float scaleX, float scaleY, u32 color)
{
    // get the button and draw it
    C2D_DrawText(&this->buttonsText[id], flags, x, y, 0, scaleX, scaleY, color);
}