/*
Ladestasjon library for Zumo32u4
*/

#ifndef ladestasjon_h
#define ladestasjon_h

#include <Arduino.h>
#include <Zumo32u4.h>

//Returnerer en sum av alle verdiene lest av linjesensoren
unsigned int sumLinjesensorer(Zumo32U4LineSensors &_linjesensor, int antallSensorer);

#endif