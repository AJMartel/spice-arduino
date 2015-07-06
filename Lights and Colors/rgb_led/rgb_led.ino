#include <Pinball.h>

// These are the led pins
int blueled = 12;
int greenled = 11;
int redled = 9;

// These are the button pins
int button1 = 10; // blue
int button2 = 8; // green
int button3 = 7; //red

int bluestate = 0;   // FOR BLUE, WE WILL USE STATE
int blueval;

// NEED A BLUE TOGGLE SWITCH FOR THIS

Pb_switch bluesw(200);   // 200 milliseconds


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

  // TURN EVERYTHING OFF AT START
  digitalWrite(redled, 0);
  digitalWrite(greenled, 0);
  digitalWrite(blueled, 0);   

}


void loop() {

 // THIS IS RED CONTROL 
  if ( digitalRead(button3) == LOW ) {
    digitalWrite(redled, 1);
  }
  else {
    digitalWrite(redled, 0);
  }

// THIS IS GREEN CONTROL
  if ( digitalRead(button2) == LOW ) {
    digitalWrite(greenled, 1);
  }
  else {
    digitalWrite(greenled, 0);
  }


// FOR BLUE, WE WILL TRY A TOGGLE SWITCH
  
  blueval = digitalRead(button1);
  
  if ( bluesw.pushed( blueval ) ) {       // CHECKING IF BUTTON POSITION HAS CHANGED
  
    bluestate = !bluestate;
    digitalWrite(blueled, bluestate);
    
  }

  
}

