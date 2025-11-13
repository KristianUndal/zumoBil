#ifndef __PROXIMITY__
#define __PROXIMITY__

void initObstacleModule();

// Read front proximity sensors and return sum of left and right hits
uint8_t readFrontProximitySum();

void setDesiredSpeeds(int leftSpeed, int rightSpeed);

void startMotorsNow(int leftSpeed, int rightSpeed);

void stopMotorsNow();

// Decide whether to stop or start motors based on proximity sensor readings
bool shouldBeStopped(uint8_t proxSum, bool currentlyStopped);

void updateObstacle(unsigned long elapsedTime);

#endif

