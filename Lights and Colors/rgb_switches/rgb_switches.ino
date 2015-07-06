#include <Pinball.h>

// These are the led pins
int redled = 12;
int greenled = 11;
int blueled = 9;

// These are the button pins
int button1 = 10;
int button2 = 8;
int button3 = 7;

Pb_switch sw1(200);
Pb_switch sw2(200);
Pb_switch sw3(200);

int bluevalue;

void setup() {
  
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(blueled, OUTPUT);  
  
  pinMode(button1, INPUT); 
  digitalWrite(button1, 1);      // This step is important for digital switches
  pinMode(button2, INPUT); 
  digitalWrite(button2, 1);
  pinMode(button3, INPUT); 
  digitalWrite(button3, 1);
  
  makedark();     // THIS IS A NEW USER-DEFINED FUNCTION (SEE BELOW FOR DETAILS)
  
}


void loop() {



  if ( sw1.pushed( digitalRead(button1) ) ) {
    makegreen();    
  }

  if ( sw2.pushed( digitalRead(button2) ) ) {
    makepurple();    
  }

  if ( sw3.pushed( digitalRead(button3) ) ) {
    makered();    
  }

  
}


// NEW FUNCTIONS (NAME THEM ANYTHING YOU WANT)

void makedark() {
 // THIS ONE TURNS OFF EVERYTHING
 digitalWrite(redled, 0);
 digitalWrite(greenled, 0);
 digitalWrite(blueled, 0); 
  
}


void makered() {
 // THIS ONE MAKES RED COLOR
 digitalWrite(redled, 1);
 digitalWrite(greenled, 0);
 digitalWrite(blueled, 0); 
  
}


void makegreen() {
 // THIS ONE MAKES GREEN COLOR
 digitalWrite(redled, 0);
 digitalWrite(greenled, 1);
 digitalWrite(blueled, 0); 
  
}


void makeblue() {
 // THIS ONE MAKES BLUE COLOR
 digitalWrite(redled, 0);
 digitalWrite(greenled, 0);
 digitalWrite(blueled, 1); 
  
}


void makepurple() {
 // THIS ONE MAKES PURPLE
 digitalWrite(redled, 1);
 digitalWrite(greenled, 0);
 digitalWrite(blueled, 1); 
  
}


