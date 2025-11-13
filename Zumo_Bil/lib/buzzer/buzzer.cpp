#include <Arduino.h>
#include <Zumo32U4.h>
#include "buzzer.h"


void activateBuzzer(int frequency, int duration) {
    buzz.playFrequency(frequency, duration);
}