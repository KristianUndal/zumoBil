#ifndef __CALIBRATE_SENSORS__
#define __CALIBRATE_SENSORS__

extern Zumo32U4LineSensors lineSensors;
extern Zumo32U4Motors motors;

void initSensors();

void spinAndCalibrate();


//eksempel på bruk:
/*
void setup(){
  initSensors();
  
  //legg til getSingleDebouncedPress 
  spinAndCalibrate();

}
*/

#endif