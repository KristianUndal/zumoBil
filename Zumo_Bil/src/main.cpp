#include <Arduino.h>
#include "battery.h"
#include <Zumo32U4.h>
#include "proximitySensors.h"

// Merged with battery branch

Zumo32U4ProximitySensors prox;
Zumo32U4OLED display;
Zumo32U4Buzzer buzz;

unsigned long elapsedTime = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  displayBatteryPercentage();
  initObstacleModule();
}

void loop() {
  // Elapsed time since start of program
  elapsedTime = millis();

  // Update battery state
  updateBattery();
  updateObstacle();
  delay(25);
}
