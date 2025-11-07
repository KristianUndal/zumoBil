#include <Arduino.h>

unsigned long elapsedTime = 0;

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
  elapsedTime = millis();
<<<<<<< Updated upstream
}

// put function definitions here:hei 
int myFunction(int x, int y) {
  return x + y;
}
=======
  
}

// put function definitions here:
>>>>>>> Stashed changes
