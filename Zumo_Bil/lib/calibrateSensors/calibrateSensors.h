#ifndef __CALIBRATE_SENSORS__
#define __CALIBRATE_SENSORS__

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