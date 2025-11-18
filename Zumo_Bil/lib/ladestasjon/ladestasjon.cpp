#include "ladestasjon.h"

unsigned long kontaktMedVeimarkering = 0;  //Tidspunktet bilen først merker en veimarkering



veimarkering paMarkering(Zumo32U4LineSensors &_linjesensor, int antallSensorer, unsigned int forsinkelse, unsigned int grenseverdi){
    unsigned int linjeVerdier[antallSensorer];
    _linjesensor.read(linjeVerdier);

    unsigned long tidspunkt = millis();
 
    byte overGrense = 0;

    //Lagrer en 1 i hhv. andre og første bitplassering om avlesningene er over grenseverdien.
    //Venstre sensor over verdi: 10, høyre sensor over: 01, begge over: 11, ingen over: 00
    overGrense |= (linjeVerdier[0] > grenseverdi ? 1 : 0) << 1;
    overGrense |= (linjeVerdier[antallSensorer - 1] > grenseverdi ? 1 : 0);


    //Dersom vi ikke leser noen ting returnerer vi. Da slipper vi å oppdatere kontaktvariablen unødvendig
    if(overGrense == 0){
        return INGEN;
    }

    //Vi oppdaterer kun første kontakt variabelen dersom det er gått mer enn en halvt sekund siden sist avlesing.
    //Da har det gått lang nok tid til at vi ikke overskriver variabelen
    if((tidspunkt - kontaktMedVeimarkering) > forsinkelse + 500){
        kontaktMedVeimarkering = tidspunkt;
        return INGEN;
    }
    //Vi legger inn en forsinkelse i tilfelle den ene siden treffer litt før den andre
    else if((tidspunkt - kontaktMedVeimarkering) < forsinkelse){
        return INGEN;
    }

    
    kontaktMedVeimarkering = tidspunkt;
    
    switch (overGrense)
    {
    //Ingen over grenseverdi
    case 0:
        return RASK;
        break;
    
    //Høyre over grenseverdi
    case 1:
        return LADESTASJON;
        break;

    //Venstre over grenseverdi
    case 2:
        return SAKTE;
        break;

    //Begge over grenseverdi
    case 3:
        return LYSKRYSS;
        break;


    //Skal aldri skje
    default:
        return INGEN;
        break;

    }

}


//Returnerer true om linjesensorene møter en linje
bool paKryss(Zumo32U4LineSensors &_linjesensor, int antallSensorer, unsigned int grenseverdi = 3000){
    unsigned int linjeVerdier[antallSensorer];

    _linjesensor.read(linjeVerdier);
    unsigned int sum = 0;

    for(int i = 0; i < antallSensorer; i++){
        sum += linjeVerdier[i];
    }

    return sum > grenseverdi;

}