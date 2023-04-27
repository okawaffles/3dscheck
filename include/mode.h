#pragma once

/**
 * Get the current mode (page) of the app.
 * Returns unsigned int page if argument submode false, or the submode if true
 * @param submode Get the submode id instead of the mode id
 * @returns unsigned int mode/submode
*/
unsigned int getMode(bool submode = false);

/**
 * Set the current mode and submode (page and subpage) of the app.
 * @param mode The mode id to set
 * @param submode (optional; default 0) The submode id to set
*/
void setMode(unsigned int mode, unsigned int submode = 0);