#include <Arduino.h>
#include <Zumo32U4.h>
#include "proximitySensors.h"



void setup() {
  initObstacleModule();
}

void loop() {
 updateObstacle();
 delay(5);
}