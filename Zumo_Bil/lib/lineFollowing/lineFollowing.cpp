#include "lineFollowing.h"

#define MIDDLE_OF_LINE 2000
#define NUM_SENSORS 5
unsigned int lineSensorValues[NUM_SENSORS]; 

int error;
int lastError = 0;

//endre disse for å tune styringen
#define PROPORTIONAL_CONSTANT 0.25
#define DERIVATIVE_CONSTANT 6

static void readSensors(){
    //tall mellom 0 og 4000
    int position = lineSensors.readLine(lineSensorValues); 
    //tall mellom -2000 og 2000
    error = position - MIDDLE_OF_LINE;
}

static int directionChange(){
    //PID kontrolleringsformel
    int value = PROPORTIONAL_CONSTANT*error + DERIVATIVE_CONSTANT*(error - lastError);
    lastError = error;
    return value;
}

void followLine(int max_speed){
    readSensors();
    int speedDifference = directionChange();

    int leftSpeed = max_speed + speedDifference;
    int rightSpeed = max_speed - speedDifference;

    leftSpeed = constrain(leftSpeed,0,max_speed);
    rightSpeed = constrain(rightSpeed,0,max_speed);
    motors.setSpeeds(leftSpeed, rightSpeed);
}
