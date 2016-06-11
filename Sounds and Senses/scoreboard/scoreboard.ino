#include <Pinball.h>

// Someone test this yet??

// Pins for scoreboard
int clkpin = 8;
int diopin = 9;

// Declare scoreboard object named myboard
Pb_scoreboard myboard(clkpin, diopin);

// Use timed events to avoid delay
void changenum(int)
Pb_timedevent scoreboard(changenum);
int val[] = { 0 };
int timing[] = { 1000 };

// Use num as flag to keep track of some number
int num;

void setup() {

  // Display 0 with leading zeros  
  myboard.showdisplay(0, true);
  delay(250);
  
  // Blank out display
  myboard.blankdisplay();
  delay(250);

  // Display 0 without leading zeros  
  myboard.showdisplay(0);
  delay(250);  
  
  // Keep track of flags
  num = 0;

  // Start Timed Events
  scoreboard.loopstart(val, timing, 1);

}

void loop() {
  
  // Update the timed event
  scoreboard.update();
     
}

void changenum(int ww) {

    num = num + 1;
    
    if (num > 99) {
      num = 0;
    }
    
    myboard.showdisplay(num);
    
}  
