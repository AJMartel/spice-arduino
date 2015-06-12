#include <Pinball.h>

int datapin = 10;     // Data pin
int clkpin = 12;      // Clock pin
int latchpin = 11;    // Latch pin
int numreg = 1;       // Number of shift registers in series

// Declare object named shregs 
Pb_outputs shregs(datapin, clkpin, latchpin, numreg);

byte serdata[1];

Pb_stopwatch mywatch;

int flag, ontime = 500;

void setup() {

 serdata[0] = 0b00000000;

 shregs.update(serdata);   // Shifting out the array
 delay(250);

 flag = 0;
 mywatch.start();

}


void loop() {

 
 if (mywatch.time() > ontime ) {
   
   mywatch.start();
   changeflag();
   changeserdata(flag);
   shregs.update(serdata);
   
 } 
   
}


void changeflag() {
 
  flag = !flag; 
  
}

void changeserdata(int ff) {
  
 if (ff == 0) { serdata[0] = 0b00111100; }
 else if (ff == 1) { serdata[0] = 0b11000011; }

}


