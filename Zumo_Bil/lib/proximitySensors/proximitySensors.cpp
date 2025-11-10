#include <Arduino.h>
#include <Zumo32U4.h>
#include "proximitySensors.h"

#define STOP_THRESHOLD 3
#define RELEASE_THRESHOLD 2
#define DEFAULT_LEFRT_SPEED 100
#define DEFAULT_RIGHT_SPEED 100

extern Zumo32U4Motors motors;
Zumo32U4ProximitySensors prox;

int currentLeftSpeed = DEFAULT_LEFRT_SPEED;
int currentRightSpeed = DEFAULT_RIGHT_SPEED;
bool isStopped = false;

// Initialize proximity sensor
void initObstacleModule() {
    prox.initFrontSensor();
}

// Read front proximity sensors and return sum of left and right hits
static uint8_t readFrontProximitySum() {
  prox.read();
  uint8_t leftHits  = prox.countsFrontWithLeftLeds();
  uint8_t rightHits = prox.countsFrontWithRightLeds();
  return (uint8_t)(leftHits + rightHits);
}

void setDesiredSpeeds(int leftSpeed, int rightSpeed) {
    currentLeftSpeed = leftSpeed;
    currentRightSpeed = rightSpeed;
}

static void startMotorsNow(int leftSpeed, int rightSpeed) {
    motors.setSpeeds(leftSpeed, rightSpeed);
}

static void stopMotorsNow() {
    motors.setSpeeds(0, 0);
}

// Decide whether to stop or start motors based on proximity sensor readings
static bool shouldBeStopped(uint8_t proxSum, bool currentlyStopped) {
    if (!currentlyStopped) {
        return proxSum >= STOP_THRESHOLD;
    }
    else {
        return (proxSum >= RELEASE_THRESHOLD);
    }
}

void updateObstacle() {
    uint8_t proxSum = readFrontProximitySum();
    bool mustStop = shouldBeStopped(proxSum, isStopped);

    if (mustStop && !isStopped) {
        stopMotorsNow();
        isStopped = true;
    }
    else if (!mustStop && isStopped){
        startMotorsNow(currentLeftSpeed, currentRightSpeed);
        isStopped = false;
    }
    else if (!mustStop && !isStopped) {
        startMotorsNow(currentLeftSpeed, currentRightSpeed);
    }
}

