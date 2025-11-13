#include "lineFollowing.h"

#ifndef BASE_SPEED
#define BASE_SPEED 100
#endif

#define MIDDLE_OF_LINE 2000
#define NUM_SENSORS 5

unsigned int lineSensorValues[NUM_SENSORS]; 

int error;
int lastError = 0;

//endre disse for å tune styringen
#define PROPORTIONAL_CONSTANT 1/10
#define DERIVATIVE_CONSTANT 60

static void readSensors(){
    int position = lineSensors.readLine(lineSensorValues);
    error = position - MIDDLE_OF_LINE;
}

static int directionChange(){
    readSensors();
    //PID kontrolleringsformel
    int value = PROPORTIONAL_CONSTANT*error + DERIVATIVE_CONSTANT*(error - lastError);
    lastError = error;
    return value;
}

void adjustDirection(int max_speed){
    int newLeft = max_speed + directionChange();
    int newRight = max_speed - directionChange();

    int leftSpeed = constrain(newLeft, 0, max_speed);
    int rightSpeed = constrain(newRight, 0, max_speed);

    motors.setSpeeds(leftSpeed, rightSpeed);
}