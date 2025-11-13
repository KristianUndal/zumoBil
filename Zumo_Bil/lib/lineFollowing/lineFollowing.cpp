#include "lineFollowing.h"

#define MIDDLE_OF_LINE 2000
#define BASE_SPEED 400
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

void followLine(){
    readSensors();
    int speedDifference = directionChange();

    int leftSpeed = BASE_SPEED + speedDifference;
    int rightSpeed = BASE_SPEED - speedDifference;

    leftSpeed = constrain(leftSpeed,0,BASE_SPEED);
    rightSpeed = constrain(rightSpeed,0,BASE_SPEED);
    motors.setSpeeds(leftSpeed, rightSpeed);
}
