#ifndef BATTERY_H_INCLUDED
#define BATTERY_H_INCLUDED

#include <Arduino.h>
#include <Zumo32U4.h>

// Battery variables
#define FULL_BATTERY 100
#define DRIVE_COST 0.001
#define IDLE_COST 0.1
#define IDLE_TIME 1000

extern unsigned long elapsedTime;

extern volatile double batteryCharge;
extern int batteryPercentage;

void driveBattery();

void idleBattery();

void calculatePercentage();

void updateScreen();

void updateBattery();

#endif // BATTERY_H_INCLUDED