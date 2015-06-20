#include <Pinball.h>

Pb_timedevent dothis(shiftpattern);

int values[] = {8, 9, 3, 2, 1, 0};
int timing[] = {250, 250, 100, 100, 100, 100};  // milliseconds

int val2[] = {0, 1, 2, 3, 4, 5, 6, 7};
int tim2[] = {250, 250, 250, 250, 250, 250, 250, 250};

int buttonpin = 4;
Pb_switch mysw(50);   // Using Pb_switch to debounce


int datapin = 10;     // Data pin
int latchpin = 11;    // Latch pin
int clkpin = 12;      // Clock pin
int numreg = 2;       // Number of shift registers in series

// Declare object named shregs 
Pb_outputs shregs(datapin, clkpin, latchpin, numreg);

byte serdata[2];


void setup() {

  pinMode(buttonpin, INPUT);
  digitalWrite(buttonpin, HIGH);
  
  serdata[0] = 0b00000000;
  serdata[1] = 0b00000000;

  shregs.update(serdata);   // Shifting out the array  
  
  dothis.loopstart(val2, tim2, 8);
  // dothis.loopstop() is also defined
}

void loop() {

  dothis.update();      // This needs to be called every loop iteration
  
  if ( mysw.pushed( digitalRead(buttonpin)) ) {
   
    // Start timed sequence if button is pressed
    dothis.start(values, timing, 6);    // Last argument is length of sequence
    // dothis.stop() also exists
  }
  
}

void shiftpattern(int ff) {
  
 if (ff == 0)      { serdata[0] =  0b10000000; serdata[1] = 0b00000001; }
 else if (ff == 1) { serdata[0] =  0b01000000; serdata[1] = 0b00000010; }
 else if (ff == 2) { serdata[0] =  0b00100000; serdata[1] = 0b00000100; }
 else if (ff == 3) { serdata[0] =  0b00010000; serdata[1] = 0b00001000; }
 else if (ff == 4) { serdata[0] =  0b00001000; serdata[1] = 0b00010000; }
 else if (ff == 5) { serdata[0] =  0b00000100; serdata[1] = 0b00100000; } 
 else if (ff == 6) { serdata[0] =  0b00000010; serdata[1] = 0b01000000; }
 else if (ff == 7) { serdata[0] =  0b00000001; serdata[1] = 0b10000000; }
 else if (ff == 8) { serdata[0] =  0b11110000; serdata[1] = 0b00001111; } 
 else if (ff == 9) { serdata[0] =  0b00001111; serdata[1] = 0b11110000; }

 shregs.update(serdata);

}

