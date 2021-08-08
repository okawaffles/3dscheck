#include "screens.h"
#include "mochalibs.h"

void rgbsTop()
{
    m_useColor(0xFF, 0x00, 0x00); // red squares | TOP
    m_rect(0, 0, 133, 80);
    m_rect(133, 80, 266, 160);
    m_rect(266, 160, 400, 240);
    m_useColor(0x00, 0xFF, 0x00); // green squares
    m_rect(133, 0, 266, 80);
    m_rect(266, 80, 400, 160);
    m_rect(0, 160, 133, 240);
    m_useColor(0x00, 0x00, 0xFF); // blue squares
    m_rect(266, 0, 400, 80);
    m_rect(0, 80, 133, 160);
    m_rect(133, 160, 266, 240);
}
void rgbsBtm()
{
    m_useColor(0xFF, 0x00, 0x00); // red squares | BOTTOM
    m_rect(0, 0, 106, 80);
    m_rect(106, 80, 212, 160);
    m_rect(212, 107, 320, 240);
    m_useColor(0x00, 0xFF, 0x00); // green squares
    m_rect(106, 0, 212, 80);
    m_rect(212, 80, 320, 160);
    m_rect(0, 160, 106, 240);
    m_useColor(0x00, 0x00, 0xFF); // blue squares
    m_rect(212, 0, 320, 80);
    m_rect(0, 80, 106, 160);
    m_rect(106, 160, 212, 240);
}