//--- Definisjoner ---
// Globale definisjoner for batteriet. Fjern kommentar for å omdefinere, ellers standard
//#define FULL_BATTERY //Standard 100.0
//#define DRIVE_COST_ROTATION //Standard 1.0
//#define IDLE_COST_MINUTE //Standard 60.0
//#define IDLE_TIME //Standard 1000

//Maks hastighet for kjøretøyet. Fjern kommentar for å omdefinere, ellers standard
//#define BASE_SPEED //Standard 100

#define KLIKK_I_SVING 909 //Antall klikk i rotary encoder for å svinge av til ladestasjonen

//--- Includes ---
#include <Arduino.h>
#include <Zumo32U4.h>

//Egne biblioteker
#include "battery.h"
#include "calibrateSensors.h"
#include "ladestasjon.h"
#include "lineFollowing.h"
#include "proximitySensors.h"
#include "display.h"
#include "buzzer.h"


//--- Objekter --- 
Zumo32U4LineSensors lineSensors;
Zumo32U4Motors motors;
Zumo32U4ProximitySensors prox;
Zumo32U4ButtonA buttonA;
Zumo32U4Buzzer buzzer;
Zumo32U4OLED display;
Zumo32U4Encoders encoders;

//--- Globale variabler ---
// Generelt
unsigned long elapsedTime = 0; // Millisekunder siden programmets start
int maksHastighet = 100;
int _lastValue = 0;


// Batteri
unsigned long sistBatterimaling = 0;
volatile double batteryCharge = FULL_BATTERY; // Batteri
int batteryPercentage; //Batteri målt i sekunder

// Avstandsmåling
unsigned long sistAvstandsmaling = 0;
bool hinder = false;

// Lading
bool skalLade = false;
unsigned long ladeSvingTid = 0; // Når vi startet å svinge for å kjøre til lading. Stopper linjefølging et øyeblikk for å svinge av veien feilfritt
int antallStegISving = 0;
int ladeGrense = 95;
unsigned long skjermtid = 0;
unsigned long sving = 0;

// Saktesone
bool iSakteSone = false;

void setup() {
  // Vi bruker fem linjesensorer
  lineSensors.initFiveSensors();
  
  initObstacleModule();

  // Venter med kalibrasjon til brukeren trykker knappen 
  writeToScreen("Trykk A for å kalibrere", 0);
  buttonA.waitForButton();
  clearScreen();
  delay(1000); // Venter litt etter brukeren har sluppet knappen. Delay er helt ok i setup for ingenting annet skal skje

  spinAndCalibrate();
  //buzzer.play("MSAAA"); // Varsel om at roboten er ferdig kalibrert
  delay(1500); // Pause for sikkerhets skyld
}

void loop() {
  elapsedTime = millis();

  updateBattery();


  // Avstandssensorkode. 
  hinder = updateObstacle(); // Stopper om kjøretøyet er for nær en hindring


  // All linjefølging håndteres av denne funksjonen. Den deaktiveres et øyeblikk mens vi svinger av veien for 
  // å ikke skape problemer 
  
  if(!hinder){
    followLine(maksHastighet);  
    //distanceAlert();
  }else{
    motors.setSpeeds(0, 0);
  }

  

  // Veimarkeringer 
  switch (paMarkering(lineSensors, 5, 25)) {

  case RASK:
    maksHastighet = 350;
  break;
  
  case LADESTASJON:

    if(skalLade){ // Dersom vi allerede er på vei til en ladestasjon
      while(batteryCharge < ladeGrense){ // Alt vi gjør er å lade. Blokkerende kode er OK
        motors.setSpeeds(0, 0);
        batteryCharge++;
        displayBatteryPercentage();
        delay(200); 
      }

      skalLade = false;

    }else if(batteryCharge < 20){ // Om vi ikke enda er på vei til en ladestasjon oppdaterer vi skalLade og svinger til høyre
      //Ikke ødelegg motoren. Vi hardkoder her for å unngå at den stanser umiddelbart og lader på samme strek

      motors.setSpeeds(0, 0);
      buzzer.play("<C");
      delay(100);

      skalLade = true;
      ladeSvingTid = elapsedTime;
      motors.setSpeeds(250, -100);
      buzzer.play(">C");
      delay(500);
    } 
    break;

  case SAKTE:
    maksHastighet = 100;
    break;


  default:
    break;
  }



}
