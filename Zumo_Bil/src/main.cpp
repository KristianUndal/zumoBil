#include <Arduino.h>
#include "battery.h"

#define ENCODER_PIN 8

unsigned long elapsedTime = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  updateScreen();
}

void loop() {
  // Elapsed time since start of program
  elapsedTime = millis();

  // Update battery state
  updateBattery();
}