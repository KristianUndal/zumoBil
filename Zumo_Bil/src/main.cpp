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
  // put your main code here, to run repeatedly:
  elapsedTime = millis();

  updateBattery();
}