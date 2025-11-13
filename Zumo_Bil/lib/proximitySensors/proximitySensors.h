#ifndef PROXIMITYSENSORS
#define PROXIMITYSENSORS

extern Zumo32U4Motors motors;
extern Zumo32U4ProximitySensors prox;


void initObstacleModule();

void setDesiredSpeeds();

void updateObstacle();

#endif