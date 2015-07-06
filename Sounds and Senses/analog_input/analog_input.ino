/*
  Analog Input
 Demonstrates analog input by reading analog sensors on pins A0, A1, and A2
 */

int sensorValue0 = 0; //value read from proximity sensor
int sensorValue1 = 0; //value read from piezo sensor
int sensorValue2 = 0; //value read from force sensitive resistor

void setup(){
  //Serial monitor
  Serial.begin(9600);
  // note that analog inputs do not require pin mode settings
  
}

void loop(){
  
// Here we read in the sensors on the analog pins using analogRead
  sensorValue0 = analogRead(A0);
  sensorValue1 = analogRead(A1);
  sensorValue2 = analogRead(A2);
  
// Use the Serial Monitor to watch each sensor at once
  Serial.print(sensorValue0);
  Serial.print(" "); // leaves a blank space
  Serial.print(sensorValue1);
  Serial.print(" "); // leaves a blank space
  Serial.println(sensorValue2); // makes a new line
  
}

