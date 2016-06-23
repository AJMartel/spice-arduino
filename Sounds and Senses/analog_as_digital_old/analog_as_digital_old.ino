/*
  Analog as Digital
   Use analog inputs as digital buttons to control an LED
 */

#include <Pinball.h>

int sensorValue0 = 0; //value read from piezo sensor

int Min0 = 50; // minimum value of the sensor

int ledpin = 2; 

void setup(){

    pinMode(ledpin, OUTPUT);
  // note that analog inputs do not require pin mode settings
  
  //Serial monitor
  Serial.begin(9600);
  
  
}

void loop(){
  
// Here we read in the sensors on the analog pins using analogRead
  sensorValue0 = analogRead(A0);
  
  // Use the Serial Monitor to find sensor thresholds
  Serial.println(sensorValue0);
  Serial.print(" "); // leaves a blank space
 
  // Use the sensor values to control the LED
  if (sensorValue0 > Min0){
    digitalWrite(ledpin, 1);
  }
  else {
    digitalWrite(ledpin, 0);
  }  
  
  

  
}

