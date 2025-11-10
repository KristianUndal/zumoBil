#include "battery.h"

// ZUMO library functions
Zumo32U4OLED display;
Zumo32U4Encoders encoders;

// Set battery charge to full at start of program
volatile double batteryCharge = FULL_BATTERY;
// Set battery percentage to full at start of program
int batteryPercentage = 100;

// Last time of idleBattery() update
unsigned long lastIdleUpdate = 0;

// Update battery charge when wheel encoders move, interrupts loop()
void driveBattery() {
    int leftEncoder = encoders.getCountsAndResetLeft();
    int rightEncoder = encoders.getCountsAndResetRight();
    
    int encodersCount = abs(leftEncoder) + abs(rightEncoder);
    batteryCharge -= encodersCount * DRIVE_COST_ROTATION/900;
}

// Update battery charge based on elapsed time
void idleBattery() {
    // Subtracts IDLE_COST from batteryCharge if IDLE_TIME has passed since last update.
    if (elapsedTime > (lastIdleUpdate + IDLE_TIME)) {
        lastIdleUpdate = elapsedTime;
        batteryCharge -= IDLE_COST_MINUTE/60;
    }
}

void displayBatteryPercentage() {
    // Calculate percentage from current charge and fullBattery value
    int newPercentage = round(100*batteryCharge/FULL_BATTERY);
    // If percentage has changed, update value and screen
    if (batteryPercentage != newPercentage) {
        batteryPercentage = newPercentage;
        batteryString = String(batteryPercentage) + "%";
        
        // Update screen
        updateScreen(batteryString);
    }
}

void updateScreen(std::string str) {
    // Clear the screen
    display.clear();
    
    // Print a batteryCPercentage to screen
    display.print(String(str));
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