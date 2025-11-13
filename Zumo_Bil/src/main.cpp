#include <Arduino.h>
#include <Zumo32U4.h>
#include "calibrateSensors.h"
#include "lineFollowing.h"

extern int error;
extern int lastError;

void setup(){
  initSensors();
  
  delay(5000);

  spinAndCalibrate();

}
void loop(){
  
  followLine();
}
