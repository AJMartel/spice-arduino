
#include <Pinball.h>

//Pb_stopwatch mywatch;
Pb_timedevent dothis(changeserdata);
int values[] = {0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,8};
int timing[] = {70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70};

int clkpin = 12;      // Clock pin
int latchpin = 13;    // Latch pin
int datapin = 11;     // Data pin
int numreg = 2;       // Number of shift registers in series

Pb_outputs shregs(datapin, clkpin, latchpin, numreg);
byte serdata[2];
int flag, ontime = 70;

int l1=2;
int l2=3;
int l3=4;


// Declare scoreboard object named disp 
Pb_display disp(10, 8, 9);


Pb_switch bsw0(100), bsw1(100), bsw2(100), bsw3(100), bsw4(100);

int buttonpin =14;
int buttonpin1=15;
int buttonpin2=16;
int buttonpin3=17;
int buttonpin4=18;

int num = 0, oldnum = 0, lives = 3;






void setup() {

   //Serial.begin(9600);
  // Write a 0 to the display.
 disp.print_number(0);
 
  pinMode(buttonpin, INPUT);
  digitalWrite(buttonpin, HIGH);
  
  pinMode(buttonpin1, INPUT);
  digitalWrite(buttonpin1, HIGH);
  
  pinMode(buttonpin2, INPUT);
  digitalWrite(buttonpin2, HIGH);
  
  pinMode(buttonpin3, INPUT);
  digitalWrite(buttonpin3, HIGH);
  
  pinMode(buttonpin4, INPUT);
   digitalWrite(buttonpin4, HIGH);
 
   
 serdata[0] = 0b00000000;
 serdata[1] = 0b00000000; 

 shregs.update(serdata);   // Shifting out the array
 //delay(250);

 flag = 0;
 //mywatch.start();
pinMode(l1, OUTPUT);
pinMode(l2, OUTPUT);
pinMode(l3, OUTPUT);
digitalWrite(l1, 1);
digitalWrite(l2, 1);
digitalWrite(l3, 1);
 }


void loop() {
 // Serial.println(analogRead(A0));
  //Serial.println(lives);
  dothis.update();
  
 if( num < 0 ){
   num = 0;
 }
 
 if( num > 99 ){
   num = 99;
 }
if( lives == 2){digitalWrite(l1, 0);}
if( lives == 1){digitalWrite(l2, 0);}
if( lives == 0){digitalWrite(l3, 0);}
if( lives <= 0 ){
  dothis.start(values,timing,41);
  delay(5000);
  num = 0;
  lives = 3;
} 
 
 writescore();
 
 
   if (bsw0.pushed( digitalRead(buttonpin)) ) {
    
    num = num + 5;
    dothis.start(values,timing,41);
  }
    
    if (bsw1.pushed( digitalRead(buttonpin1)) ) {
     num = num + 5;
     dothis.start(values,timing,41);
    }


    if (bsw2.pushed( digitalRead(buttonpin2)) ) {  
          num = num + 5;
          dothis.start(values,timing,41);
    }
      
      if (bsw3.pushed( digitalRead(buttonpin3)) ) {
        num = num + 5;
        dothis.start(values,timing,41);
      }
      
      if (bsw4.pushed( digitalRead(buttonpin4)) ) {
        lives = lives - 1;
        num = num - 5;
   }
  
 }
 
  
  void writescore() {
 
  if (oldnum != num ) {
     disp.print_number(num);
    oldnum = num;
  }
   
}


void changeflag() {

 if (flag < 7) { 
  flag = flag + 1;
 }
  else {
  flag = 0;
  }
  
}
void changeserdata(int ff) {
  
 if (ff == 0)      { serdata[0] =  0b00000001; serdata[1] = 0b00000001; }
 else if (ff == 1) { serdata[0] =  0b00000010; serdata[1] = 0b00000010; }
 else if (ff == 2) { serdata[0] =  0b00000100; serdata[1] = 0b00000100; }
 else if (ff == 3) { serdata[0] =  0b00001000; serdata[1] = 0b00001000; }
 else if (ff == 4) { serdata[0] =  0b00010000; serdata[1] = 0b00010000; }
 else if (ff == 5) { serdata[0] =  0b00100000; serdata[1] = 0b00100000; } 
 else if (ff == 6) { serdata[0] =  0b01000000; serdata[1] = 0b01000000; }
 else if (ff == 7) { serdata[0] =  0b10000000; serdata[1] = 0b10000000; }
 else if (ff == 8) { serdata[0] =  0b00000000; serdata[1] = 0b00000000; }
shregs.update(serdata);
}






