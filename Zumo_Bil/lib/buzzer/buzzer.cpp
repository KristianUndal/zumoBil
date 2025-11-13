#include <Arduino.h>
#include <Zumo32U4.h>
#include "buzzer.h"


void activateBuzzer() {
    buzz.playFrequency(600, 50, 15);
}

void stopSound() {
    buzz.stopPlaying();
}

