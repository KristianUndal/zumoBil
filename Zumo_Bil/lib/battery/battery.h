#ifndef BATTERY_H_INCLUDED
#define BATTERY_H_INCLUDED

// Battery variables
#define fullBattery 100 000

extern int batteryCharge;
extern int batteryPercentage;

void driveBattery();

void idleBattery();

void calculatePercentage();

void updateScreen();

// Runs all functions above to update battery state and display
void updateBattery();

#endif // BATTERY_H_INCLUDED