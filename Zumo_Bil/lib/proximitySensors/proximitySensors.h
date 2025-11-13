#ifndef PROXIMITYSENSORS
#define PROXIMITYSENSORS

extern Zumo32U4Motors motors;
extern Zumo32U4ProximitySensors prox;

extern unsigned long elapsedTime;

void initObstacleModule();

void setDesiredSpeeds();

void updateObstacle();

#endif