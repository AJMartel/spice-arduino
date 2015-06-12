/*
  Switch Case
   Use a switch case structure to break analog inputs into ranges
   Use a map function to access the entire range of the speaker
 */

#include <Pinball.h>

int sensorValue0 = 0; //value read from proximity sensor
int sensorValue1 = 0; //value read from piezo sensor
int sensorValue2 = 0; //value read from force sensitive resistor

// Record the minimum values of your sensors below, if needed
int Min0 = 250;
int Min1 = 10;
int Min2 = 10;

int Max0 = 1023;
int Max1 = 1023;
int Max2 = 1023;

int speakerPin = 3; // speaker output pin
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
  
  // map the sensor range to a range of three options:
  int range = map(sensorValue2, Min2, Max2, 0, 3);

  // do something different depending on the 
  // range value:
  switch (range) {
  case 0:    // no squeeze
    Serial.println("no reading");
    speakerVal = 0;
    break;
  case 1:    // gentle squeeze
    Serial.println("gentle");
    speakerVal = 131;
    break;
  case 2:    // moderate squeeze
    Serial.println("moderate");
    speakerVal = 196;
    break;
  case 3:    // forceful squeeze
    Serial.println("forceful");
    speakerVal = 262;
    break;
  } 
  delay(1);        // delay in between reads for stability

  // Use the Serial Monitor to find sensor thresholds
//  Serial.print(sensorValue0);
//  Serial.print(" "); // leaves a blank space
//  Serial.print(sensorValue1);
//  Serial.print(" "); // leaves a blank space
//  Serial.println(sensorValue2); // makes a new line

      
  // Write to speaker with a 100ms tone duration.
  tone(speakerPin,speakerVal,100); 

}

