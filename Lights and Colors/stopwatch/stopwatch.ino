#include <Pinball.h>

int ledpin = 12;
int buttonpin = 10;

int ledb = 11;
int ontimeb = 500;
int ledbstate = 0;

Pb_stopwatch mywatch;

void setup() {
  
  pinMode(ledpin, OUTPUT);
  pinMode(ledb, OUTPUT);
  
  
  pinMode(buttonpin, INPUT); 
  digitalWrite(buttonpin, 1);

  mywatch.start();
  
  Serial.begin(9600);

}


void loop() {

  
  if ( digitalRead(buttonpin) == LOW ) {
    digitalWrite(ledpin, 1);
  }
  else {
    digitalWrite(ledpin, 0);
  }
  
  if ( mywatch.time() > ontimeb ) {
   
    ledbstate = !ledbstate;
    digitalWrite(ledb, ledbstate);
    mywatch.start();

    Serial.print("led state is ");
    Serial.println(ledbstate);
    
  }
  
}

