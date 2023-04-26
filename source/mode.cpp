#include "mode.h"

unsigned int page = 0;
unsigned int subpage = 0;

/**
 * Get the current mode (page) of the app.
 * Returns unsigned int page if argument submode false, or the submode if true
*/
unsigned int getMode(bool submode)
{
    if (subpage)
        return subpage;
    else
        return page;
}


/**
 * Set the current mode and submode (page and subpage) of the app.
*/
void setMode(unsigned int mode, unsigned int submode = 0)
{
    page = mode;
    subpage = subpage;
}