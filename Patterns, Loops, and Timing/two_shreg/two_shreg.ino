#include <Pinball.h>

// Connect two 74HC595s' in series
// Connect LEDs with 1k resistors to their outputs

int datapin = 10;     // Data pin
int latchpin = 11;    // Latch pin
int clkpin = 12;      // Clock pin
int numreg = 2;       // Number of shift registers in series

// Declare object named shregs 
Pb_outputs shregs(datapin, clkpin, latchpin, numreg);

byte serdata[2];

Pb_stopwatch mywatch;

int flag, ontime = 250;

void setup() {

 serdata[0] = 0b00000000;
 serdata[1] = 0b00000000; 

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
 
 if (flag == 0) { 
  flag = 7;
 } else {
  flag = flag -1;
 } 
  
}

void changeserdata(int ff) {
  
 if (ff == 0)      { serdata[0] =  0b10000000; serdata[1] = 0b00000001; }
 else if (ff == 1) { serdata[0] =  0b01000000; serdata[1] = 0b00000010; }
 else if (ff == 2) { serdata[0] =  0b00100000; serdata[1] = 0b00000100; }
 else if (ff == 3) { serdata[0] =  0b00010000; serdata[1] = 0b00001000; }
 else if (ff == 4) { serdata[0] =  0b00001000; serdata[1] = 0b00010000; }
 else if (ff == 5) { serdata[0] =  0b00000100; serdata[1] = 0b00100000; } 
 else if (ff == 6) { serdata[0] =  0b00000010; serdata[1] = 0b01000000; }
 else if (ff == 7) { serdata[0] =  0b00000001; serdata[1] = 0b10000000; }

}


