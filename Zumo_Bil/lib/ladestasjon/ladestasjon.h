/*
Ladestasjon library for Zumo32u4
*/

#ifndef ladestasjon_h
#define ladestasjon_h

#include <Arduino.h>
#include <Zumo32u4.h>

enum veimarkering{
    INGEN,
    LADESTASJON,
    SAKTE,
    LYSKRYSS
};


//Returnerer hvilken veimarkering bilen står på. Typer: INGEN, LADESTASJON, SAKTE, LYSKRYSS
veimarkering paMarkering(Zumo32U4LineSensors &_linjesensor, int antallSensorer, unsigned int forsinkelse = 100, unsigned int grenseverdi = 400);

//Returnerer om linjesensoren står ovenfor et kryss eller ikke
bool paKryss(Zumo32U4LineSensors &_linjesensor, int antallSensorer, unsigned int grenseverdi = 3000);

#endif