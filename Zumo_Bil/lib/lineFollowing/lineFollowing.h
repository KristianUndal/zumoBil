#ifndef __LINE_FOLLOWING__
#define __LINE_FOLLOWING__

#include <Arduino.h>
#include <Zumo32U4.h>
#include "calibrateSensors.h"

#include "QTRSensors.h"

extern Zumo32U4LineSensors lineSensors;
extern Zumo32U4Motors motors;

// Egen linjeleser
int readSensors(unsigned int *sensor_values, unsigned char readMode, unsigned char white_line);

// Håndterer all linjefølging
void followLine(int max_speed);

#endif