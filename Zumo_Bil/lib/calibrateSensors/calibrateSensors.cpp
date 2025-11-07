#include <Arduino.h>
#include <Zumo32U4.h>
#include "calibrateSensors.h"

Zumo32U4LineSensors lineSensors;
Zumo32U4Motors motors;

void initSensors(){
    lineSensors.initFiveSensors();
}

void spinAndCalibrate(){
    for(int i=0; i<120; i++){
        if(i>30 && i<=90){
            motors.setSpeeds(200, -200);
        }
        else{
            motors.setSpeeds(-200, 200);
        }
        
        lineSensors.calibrate();
        delay(10);
    }
    motors.setSpeeds(0,0);
}
