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
int flag = 0;                  // WE WILL USE THIS FLAG TO KEEP TRACK OF WHERE WE ARE


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
    changenext();
  }

  if ( sw2.pushed( digitalRead(button2) ) ) {
    makedark();    
    flag = 0;
  }

  if ( sw3.pushed( digitalRead(button3) ) ) {
    changeback();    
  }

  
}

void resetpattern() {
  
 if (flag == 0) {flag = 1; makecyan(); }
 else if (flag == 1) {flag = 2; makeyellow(); }
 else if (flag == 2) {flag = 3; makegreen(); } 
 else if (flag == 3) {flag = 4; makecyan(); }  
 else if (flag == 4) {flag = 5; makeblue(); }   
 else if (flag == 5) {flag = 6; makepurple(); }
 else if (flag == 6) {flag = 1; makered(); }
  
}

void changenext() {
  
 if (flag == 0) {flag = 1; makered(); }
 else if (flag == 1) {flag = 2; makeyellow(); }
 else if (flag == 2) {flag = 3; makegreen(); } 
 else if (flag == 3) {flag = 4; makecyan(); }  
 else if (flag == 4) {flag = 5; makeblue(); }   
 else if (flag == 5) {flag = 6; makepurple(); }
 else if (flag == 6) {flag = 1; makered(); }
  
}


void changeback() {
  
 if (flag == 0) {flag = 6; makepurple(); }
 else if (flag == 6) {flag = 5; makeblue(); }
 else if (flag == 5) {flag = 4; makecyan(); }
 else if (flag == 4) {flag = 3; makegreen(); } 
 else if (flag == 3) {flag = 2; makeyellow(); }  
 else if (flag == 2) {flag = 1; makered(); }   
 else if (flag == 1) {flag = 6; makepurple(); }   
}


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

void makecyan() {
 // THIS ONE MAKES CYAN
 digitalWrite(redled, 0);
 digitalWrite(greenled, 1);
 digitalWrite(blueled, 1); 
  
}

void makeyellow() {
 // THIS ONE MAKES yellow
 digitalWrite(redled, 1);
 digitalWrite(greenled, 1);
 digitalWrite(blueled, 0); 
  
}
