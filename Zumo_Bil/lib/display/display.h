#ifndef __DISPLAY__
#define __DISPLAY__

#include <Arduino.h>
#include <Zumo32U4.h>

// Clear screen
void clearScreen();

// Write string to screen
void updateScreen(String str, int line);

#endif