/*
  Analog Input
 Demonstrates analog input by reading analog sensors on pins A0, A1, and A2
 */
 
 //Input IR sensors
int analogIn0 = A0;     
int analogIn1 = A1;
int analogIn2 = A2;

int sensorValue0 = 0; //value read from IR sensor
int sensorValue1 = 0; //value read from piezo sensor
int sensorValue2 = 0; //value read from FSR sensor

void setup(){
  //Serial monitor
  Serial.begin(9600);
  // note that analog inputs do not require pin mode settings
  
}

void loop(){
  
// Here we read in the sensors on the ANALOG IN pins using analogRead
  sensorValue0 = analogRead(analogIn0);
  sensorValue1 = analogRead(analogIn1);
  sensorValue2 = analogRead(analogIn2);
  
// Use the Serial Monitor to watch each sensor at once
  Serial.print(sensorValue0);
  Serial.print(" "); // leaves a blank space
  Serial.print(sensorValue1);
  Serial.print(" "); // leaves a blank space
  Serial.println(sensorValue2); // makes a new line
  
}

