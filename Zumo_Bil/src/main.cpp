#include <Arduino.h>
#include "battery.h"
#include "proximitySensors.h"
#include "display.h"

int leftEncoderCount = 0;
int rightEncoderCount = 0;

// ZUMO objects
Zumo32U4Encoders encoders;

unsigned long elapsedTime = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  displayBatteryPercentage();
}

void loop() {
  // Elapsed time since start of program
  elapsedTime = millis();
  leftEncoderCount = encoders.getCountsAndResetRight();
  rightEncoderCount =  encoders.getCountsAndResetLeft();

  // Update battery state
  updateBattery();
  writeToScreen(String(elapsedTime), 1);
}