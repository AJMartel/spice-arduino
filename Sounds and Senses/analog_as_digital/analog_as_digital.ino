/*
  Analog as Digital
   Use analog inputs as digital buttons to control an LED
 */

#include <Pinball.h>

int sensorValue0 = 0; //value read from proximity sensor
int sensorValue1 = 0; //value read from piezo sensor
int sensorValue2 = 0; //value read from force sensitive resistor

// Record the minimum values of your sensors below, plus a little (say, +10)
int Min0 = 210;
int Min1 = 10;
int Min2 = 10;

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
  sensorValue1 = analogRead(A1);
  sensorValue2 = analogRead(A2);
  
  // Use the Serial Monitor to find sensor thresholds
  Serial.print(sensorValue0);
  Serial.print(" "); // leaves a blank space
  Serial.print(sensorValue1);
  Serial.print(" "); // leaves a blank space
  Serial.println(sensorValue2); // makes a new line
 
  // Use the sensor values to control the LED
  if (sensorValue0 > Min0 && sensorValue1 > Min1 || sensorValue2 > Min2){
    digitalWrite(ledpin, 1);
  }
  else {
    digitalWrite(ledpin, 0);
  }  
  
  

  
}

