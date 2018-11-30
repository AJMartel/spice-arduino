/*

  Smoothing

  Reads repeatedly from an analog input, calculating a running average
  and printing it to the computer.  Keeps ten readings in an array and
  continually averages them.

  The circuit:
    * Analog sensor (potentiometer will do) attached to analog input 0

  modified from http://www.arduino.cc/en/Tutorial/Smoothing
  http://agoering.github.io/spice-pinball/docs/analog-piezo/


*/

#include <Pinball.h>

// LED pins
int greenled_pin = 2; 
int redled_pin = 3;

// Sensor pin and variables
int piezo_pin = A0; // pin that we connect the piezo to
int piezo_val = 0; // value read from piezo sensor
int piezo_min = 5;
int piezo_max = 100;

//Pb_stopwatch piezo_delay;
//int piezo_delaytime = 100; // how long to wait between piezo readings

// Variables for totaling piezo
const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A0;

void setup() {
  
  pinMode(greenled_pin, OUTPUT);     
  pinMode(redled_pin, OUTPUT);  
  // note that analog inputs do not require pin mode settings
  
  // Serial monitor
  Serial.begin(9600);
  
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(piezo_pin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  Serial.println(average);
  
    // map the sensor range to a range of four cases (case 0 being one of them):
  int range = map(average, piezo_max, piezo_min, 0, 3);

  // do something different depending on the range value:
  switch (range) {
  case 0:    // hard knock, turn on both LEDs
    Serial.print(piezo_val);
    Serial.print(" ");
    Serial.println("hard knock");
    digitalWrite(greenled_pin, 1);
    digitalWrite(redled_pin, 1);
    break;
  case 1:    // moderate knock, turn on red LED
    Serial.print(piezo_val);
    Serial.print(" ");
    Serial.println("moderate knock");
    digitalWrite(greenled_pin, 0); 
    digitalWrite(redled_pin, 1);
    break;

  case 2:    // faint knock, turn on green LED
    Serial.print(piezo_val);
    Serial.print(" ");
    Serial.println("faint knock");
    digitalWrite(greenled_pin, 1); 
    digitalWrite(redled_pin, 0);
    
    break;
  case 3:    // no reading, keep LEDs off and don't print to SerialMonitor
    digitalWrite(greenled_pin, 0); 
    digitalWrite(redled_pin, 0);
    break;


  }
  delay(10);        // delay in between reads for stability

}
