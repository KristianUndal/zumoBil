#include <Arduino.h>
#include <Zumo32U4.h>
#include "proximitySensors.h"



void setup() {
  initObstacleModule();
}

void loop() {
  // Elapsed time since start of program
  elapsedTime = millis();

  // Update battery state
  updateBattery();
 updateObstacle();
 delay(5);
}