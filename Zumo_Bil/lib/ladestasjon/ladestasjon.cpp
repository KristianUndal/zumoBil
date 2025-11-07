#include <Arduino.h>
#include <Zumo32u4.h>

//Returnerer summen av alle sensorverdiene
unsigned int sumLinjesensorer(Zumo32U4LineSensors &_linjesensor, int antallSensorer){
    unsigned int linjeVerdier[antallSensorer];

    _linjesensor.read(linjeVerdier);
    int sum = 0;

    for(int i = 0; i < antallSensorer; i++){
        sum += linjeVerdier[i];
    }

    return sum;

}