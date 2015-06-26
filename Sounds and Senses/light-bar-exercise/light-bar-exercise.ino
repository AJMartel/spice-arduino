#include <Pinball.h>

int shclk = 12;     // Shift registers clock pin
int shlatch = 11;    // Shift registers latch pin
int shdata = 10;     // Shift registers data pin
int numreg = 2;     // Number of shift registers in series

// Declare shift registers object named shregs 
Pb_outputs shregs(shdata, shclk, shlatch, numreg);

byte serdata[2];    // Array for shift register data

int aval;           // Variable for analog sensor value

int apin = A0;      // Analog input sensor pin

int temp; // Logic variable

void setup() {
  
  serdata[0] = 0b00000000; serdata[1] = 0b00000000;
  shregs.update(serdata);
  
}

void loop() {
  
  readinputs();       // Read all the input sensors
  dologic();          // Perform logical operations
  writeoutputs();     // Control all output components
  
}


void readinputs() {
  
  aval = analogRead(apin);  

}

void dologic() {
  
  serdata[0] = 0b00000000; serdata[1] = 0b00000000;
  temp = (aval-60)/57;
  if (temp > 0) {
    if (temp < 9) { bitWrite(serdata[1], temp - 1, 1); }
    else { bitWrite(serdata[0], temp - 9, 1); }
  }

}

void writeoutputs() {

  shregs.update(serdata);  

}
