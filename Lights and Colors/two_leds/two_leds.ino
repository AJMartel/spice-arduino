#include <Pinball.h>

int leda = 12;
int ledb = 11;

int ontimea = 500;
int ontimeb = 500;

void setup() {
  
  pinMode(leda, OUTPUT);
  pinMode(ledb, OUTPUT);

}


void loop() {

  digitalWrite(leda, 1);
  delay(ontimea);
  digitalWrite(leda, 0);
  delay(ontimea);  

  digitalWrite(ledb, 1);
  delay(ontimeb);
  digitalWrite(ledb, 0);
  delay(ontimeb);  

}

