#ifndef __BATTERY__
#define __BATTERY__

#include <Arduino.h>

extern Zumo32U4Encoders encoders;

// Battery variables
// Maximal battery level
#define FULL_BATTERY 100.0
// Battery cost of driving, percentage per wheel rotation
#define DRIVE_COST_ROTATION 5.0
// Battery cost of running, percentage per minute
#define IDLE_COST_MINUTE 60.0
// Idle cost time interval, 1 second
#define IDLE_TIME 1000

// Elapsed time since start of program, global variable
extern unsigned long elapsedTime;
// Current battery charge, global variable
extern volatile double batteryCharge;
// Current battery charge converted to in 0-100, global variable
extern int batteryPercentage;

// Subtract battery charge cost of driving
void driveBattery();

// Subtract battery charge cost of idle
void idleBattery();

// Calculate percentage from batteryCharge, and write to screen
void displayBatteryPercentage();

// Runs all functions above to update battery state and display
void updateBattery();

#endif // __BATTERY__