#include <Pinball.h>

int ledpin = 12;
int ontime = 500;

void setup() {
  
  pinMode(ledpin, OUTPUT);

}


void loop() {

  digitalWrite(ledpin, 1);
  delay(ontime);
  digitalWrite(ledpin, 0);
  delay(ontime);  

}

