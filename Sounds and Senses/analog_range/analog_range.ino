/*
  Analog Range
   Use a switch case structure to switch between cases according to range.
   
 */

#include <Pinball.h>

// Sensor pin and variables
int piezo_pin = A0; // pin that we connect the piezo to
int piezo_val = 0; // value read from piezo sensor
int max_piezo_val = 0; // maximum piezo value read for each pulse
int piezo_min = 5; // bottom of range
int piezo_max = 1023; // top of range

Pb_stopwatch piezo_delay;
int piezo_delaytime = 100; // how long to wait between piezo readings

// LED pins
int greenled_pin = 2; 
int redled_pin = 3;

void setup(){

  pinMode(greenled_pin, OUTPUT);     
  pinMode(redled_pin, OUTPUT);  
  // note that analog inputs do not require pin mode settings
  
  piezo_delay.start();  // Start piezo stopwatch
  
  //Serial monitor
  Serial.begin(9600);
  
  
}

void loop(){
  
// Here we read in the sensors on the analog pins using analogRead
// Using the stopwatch 
//  if (piezo_delay.time() > piezo_delaytime ){
//    piezo_val = analogRead(piezo_pin);
//    piezo_delay.start();
//  }

  // read only the peak signal
  
  piezo_val = analogRead(piezo_pin);
  
  if (piezo_val > max_piezo_val){
    last_piezo_val = piezo_val; // update the maximum value
    piezo_val = analogRead(piezo_pin);
  }
  
  // map the sensor range to a range of four cases (case 0 being one of them)
  int range = map(piezo_val, piezo_max, piezo_min, 0, 2);

  // do something different depending on the range value:
  switch (range) {
  case 0:    // hard knock, turn on red LED
    Serial.print(piezo_val);
    Serial.print(" ");
    Serial.println("hard knock");
    digitalWrite(redled_pin, 1);
    break;
    
  case 1:    // light knock, turn on green LED
    Serial.print(piezo_val);
    Serial.print(" ");
    Serial.println("light knock");
    digitalWrite(greenled_pin, 1);
    break;

  case 2:    // no reading, keep LEDs off and don't print to SerialMonitor
    digitalWrite(greenled_pin, 0); 
    digitalWrite(redled_pin, 0);
    break;
  } 


}

