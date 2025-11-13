#ifndef __LINE_FOLLOWING__
#define __LINE_FOLLOWING__

#include <Arduino.h>
#include <Zumo32U4.h>

extern Zumo32U4LineSensors lineSensors;
extern Zumo32U4Motors motors;

// Håndterer all linjefølging
void adjustDirection(int max_speed);

#endif