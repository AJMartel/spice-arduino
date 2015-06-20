/*
  Analog Tones
   Use the values of analog sensors to make tones on a speaker
 */

#include <Pinball.h>

int sensorValue0 = 0; //value read from proximity sensor
int sensorValue1 = 0; //value read from piezo sensor
int sensorValue2 = 0; //value read from force sensitive resistor

// Record the minimum values of your sensors below, if needed
int Min0 = 250;
int Min1 = 10;
int Min2 = 10;

int speakerPin = 13; // speaker output pin
int speakerVal = 0; // initial value output to speaker

void setup(){

  pinMode(speakerPin, OUTPUT);  
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


  // Use the sensor values to produce a value to send to the speaker
//  speakerVal = (sensorValue0+sensorValue1+sensorValue2)/3;
  speakerVal = (sensorValue0+sensorValue1+sensorValue2);      
      
  // Write to speaker with a 100ms tone duration.
  tone(speakerPin,speakerVal,100); 

}

