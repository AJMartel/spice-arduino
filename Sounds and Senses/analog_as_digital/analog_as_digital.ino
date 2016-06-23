/*
  Analog as Digital
   Use analog inputs as digital buttons to control an LED
 */

#include <Pinball.h>

// Sensor pin and variables
int piezo_pin = A0; // pin that we connect the piezo to
int piezo_val = 0; // value read from piezo sensor
int piezo_min = 5; // bottom of range
int piezo_max = 800; // top of range

// LED pin
int greenled_pin = 2; 

void setup(){

  pinMode(greenled_pin, OUTPUT);     
  // note that analog inputs do not require pin mode settings
 

  
  //Serial monitor
  Serial.begin(9600);
  
  
}

void loop(){
  
// Here we read in the sensors on the analog pins using analogRead
// Using the stopwatch 
  if (piezo_delay.time() > piezo_delaytime ){
    piezo_val = analogRead(piezo_pin);
    piezo_delay.start();
  }
  
  // map the sensor range to a range of four cases (case 0 being one of them)
  int range = map(piezo_val, piezo_max, piezo_min, 0, 2);

  // do something different depending on the range value:
  switch (range) {
  case 0:    // hard knock, turn on green LEDs
    Serial.print(piezo_val);
    Serial.print(" ");
    Serial.println("hard knock");
    digitalWrite(greenled_pin, 1);
    digitalWrite(redled_pin, 1);
    break;
    
  case 1:    // light knock, turn on red LED
    Serial.print(piezo_val);
    Serial.print(" ");
    Serial.println("light knock");
    digitalWrite(greenled_pin, 0); 
    digitalWrite(redled_pin, 1);
    break;

  case 2:    // no reading, keep LEDs off and don't print to SerialMonitor
    digitalWrite(greenled_pin, 0); 
    digitalWrite(redled_pin, 0);
    break;
  } 


}

