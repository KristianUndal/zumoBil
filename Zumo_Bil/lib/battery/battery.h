#ifndef __BATTERY__
#define __BATTERY__

#include <Arduino.h>
#include <Zumo32U4.h>
#include <string>

// Battery variables
#define FULL_BATTERY 100.0
#define DRIVE_COST_ROTATION 1.0
#define IDLE_COST_MINUTE 60.0
#define IDLE_TIME 1000

extern unsigned long elapsedTime;
extern volatile double batteryCharge;
extern int batteryPercentage;

void driveBattery();

void idleBattery();

void displayBatteryPercentage();

void updateScreen(std::string str);

void updateBattery();

#endif // __BATTERY__