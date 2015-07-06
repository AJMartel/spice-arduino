#include <Pinball.h>

Pb_timedevent dothis(blinkmyled);

int values[] = { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
int timing[] = { 200, 200, 200, 200, 200, 200, 500, 500, 500, 500, 500, 500, 200, 200, 200, 200, 200, 200};  // milliseconds

int buttonpin = 4;
Pb_switch mysw(100);   // Using Pb_switch to debounce

int ledpin = 2;


void setup() {

  pinMode(buttonpin, INPUT);
  digitalWrite(buttonpin, HIGH);
  
  pinMode(ledpin, OUTPUT);
  digitalWrite(ledpin, LOW);
  
}

void loop() {

  dothis.update();      // This needs to be called every loop iteration
  
  if ( mysw.pushed( digitalRead(buttonpin)) ) {
   
    // Start timed sequence if button is pressed
    dothis.start(values, timing, 18);    // Last argument is length of sequence
    // dothis.stop() also exists
  }
  
}

void blinkmyled( int val) {
 
  digitalWrite(ledpin, val);
  
}

