#include "battery.h"
#include <Arduino.h>

#define driveCost 1
#define idleCost 1
#define idleTime 1000

int batteryCharge = fullBattery;
int batteryPercentage = 100;

unsigned long lastIdleUpdate = 0;

// Update battery charge when wheel encoders move, interrupts loop()
void driveBattery() {
    batteryCharge -= driveCost;
}

// Update battery charge based on elapsed time
void idleBattery(unsigned long elapsedTime) {
    if (elapsedTime > lastIdleUpdate + idleTime) {
        lastIdleUpdate = elapsedTime;
        batteryCharge -= idleCost;
    }
}

void calculatePercentage() {
    // Calculate percentage from current charge and fullBattery value
    int newPercentage = round(100*batteryCharge/fullBattery);
    // If percentage has changed, update value and screen
    if (batteryPercentage != newPercentage) {
        batteryPercentage = newPercentage;
        // Update screen
        updateScreen();
    }
}

void updateScreen() {

}


void updateBattery() {
    // Subtracts IDLE_COST from batteryCharge every IDLE_TIME ms
    idleBattery();
    // Subtracts DRIVE_COST from batteryCharge for every encoder pulse
    driveBattery();

    // Stops battery charge from going below zero
    if (batteryCharge < 0) {
        batteryCharge = 0;
    }

    // Update battery percentage on screen
    displayBatteryPercentage();
}