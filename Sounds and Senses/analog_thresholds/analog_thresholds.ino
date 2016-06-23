/*
  Analog Thresholds
   Use an analog input with a set threshold to control an LED
 */

#include <Pinball.h>

int piezo_pin = A0; //pin that we connect the piezo to
int piezo_val = 0; //value read from piezo sensor
int piezo_thresh = 800; // minimum value of the sensor for which the LED will light

int led_pin = 2; 

void setup(){

    pinMode(led_pin, OUTPUT);
  // note that analog inputs do not require pin mode settings
  
  //Serial monitor
  Serial.begin(9600);
  
  
}

void loop(){
  
// Here we read in the sensors on the analog pins using analogRead
  piezo_val = analogRead(piezo_pin);
  
  // Use the Serial Monitor to find sensor thresholds
  Serial.println(piezo_val);
 
  // Use the sensor values to control the LED
  if (piezo_val > piezo_thresh){
    digitalWrite(led_pin, 1);
  }
  else {
    digitalWrite(led_pin, 0);
  }  
  
  

  
}

