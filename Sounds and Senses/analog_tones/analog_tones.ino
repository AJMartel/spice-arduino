/*
  Analog Tones
   Use the values of analog sensors to make tones on a speaker
 */

#include <Pinball.h>

int piezo_pin = A0; // pin that we connect the piezo to
int piezo_val = 0; //value read from piezo sensor
int piezo_thresh = 5; // bottom of range
int piezo_max = 100; // top of range

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
  piezo_val = analogRead(A0);

  // Use the Serial Monitor to find sensor thresholds
  Serial.println(piezo_val);

  // Use the map function to translate piezo values
  // into numbers that work with the tone() function
  speakerVal = map(piezo_val, piezo_thresh, piezo_max, 33, 4186);
      
  // Write to speaker with a 100ms tone duration.
if (piezo_val > piezo_thresh){
  tone(speakerPin,speakerVal,100); 
}
}

