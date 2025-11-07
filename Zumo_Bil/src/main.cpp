#include <Arduino.h>
#include <Zumo32u4.h>
#include <ladestasjon.h>

Zumo32U4LineSensors linjesensor;
Zumo32U4Motors motors;
Zumo32U4ButtonA knappA;
Zumo32U4Buzzer buzzer;


void setup() {
  // put your setup code here, to run once:
  linjesensor.initFiveSensors();
  Serial.begin(9600);

  knappA.waitForPress();
  Serial.println("######################");

  delay(1000);
  for(uint16_t i = 0; i < 120; i++)
  {
    if (i > 30 && i <= 90)
    {
      motors.setSpeeds(-200, 200);
    }
    else
    {
      motors.setSpeeds(200, -200);
    }

    linjesensor.calibrate();
  }
  motors.setSpeeds(0, 0);
}

void loop() {
  //Serial.println("PingPingPing");

  //Serial.println(paMarkering(linjesensor, 5));
  switch (paMarkering(linjesensor, 5))
  {
    case INGEN:
      //buzzer.stopPlaying();
      break;

    case LADESTASJON:
      buzzer.play("C");
      break;

    case SAKTE:
      buzzer.play("g");
      break;

    case LYSKRYSS:
      buzzer.play(">c");
      break;
 
    default:
      //buzzer.stopPlaying();
      break;
 }

}