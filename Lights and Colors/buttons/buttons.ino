#include <Pinball.h>

int ledpin = 12;
int buttonpin = 10;


void setup() {
  
  pinMode(ledpin, OUTPUT);
  
  pinMode(buttonpin, INPUT); 
  digitalWrite(buttonpin, 1);

}


void loop() {

  
  if ( digitalRead(buttonpin) == LOW ) {
    digitalWrite(ledpin, 1);
  }
  else {
    digitalWrite(ledpin, 0);
  }
  
}

