#include <Pinball.h>

// These are the button pins
int button0 = 4;
int button1 = 5;
int button2 = 6;
int button3 = 7;

// Flags to keep track of button presses
int flag0, flag1, flag2, flag3;

// Define buttons as switches
Pb_switch mysw0(100), mysw1(100), mysw2(100), mysw3(100);

// Pinball scoreboard
int clkpin = 8;
int diopin = 9;

// Declare scoreboard object named myboard
Pb_scoreboard myboard(clkpin, diopin);

// Use timed events to avoid using delay
Pb_timedevent scoreboard(changenum);
int val[] = { 0 };
int timing[] = { 250 };

// Use num as flag to keep track of some number
int num, num2;

void setup() {
  
  // This step is important for digital switches
  pinMode(button0, INPUT); 
  digitalWrite(button0, 1);
  pinMode(button1, INPUT); 
  digitalWrite(button1, 1);     
  pinMode(button2, INPUT); 
  digitalWrite(button2, 1);
  pinMode(button3, INPUT); 
  digitalWrite(button3, 1);
  
  flag0 = 0; flag1 = 0; flag2 = 0; flag3 = 0;

// Put decimal partition at location 1
  myboard.setpartition(1);
  myboard.blankpredisplay();
  myboard.blankpostdisplay(); 
  
  // Initial number flag values
  num = 0;
  num2 = 5;
  
  scoreboard.loopstart(val, timing, 1);

}

void loop() {
  
  // Read all the inputs
  readinputs();
  
  // Figure out what to do based on inputs
  dologic();
  
  // Write to the outputs
  writeoutputs();

}

void readinputs() {

  flag0 = 0; flag1 = 0; flag2 = 0; flag3 = 0;
  
  // Use flags to record which switches have been pushed
  flag0 = mysw0.pushed( digitalRead(button0) );
  flag1 = mysw1.pushed( digitalRead(button1) );
  flag2 = mysw2.pushed( digitalRead(button2) );  
  flag3 = mysw3.pushed( digitalRead(button3) );    
  
}

void dologic(){
    
    if (flag0 + flag1 + flag2 + flag3 > 0){
    // At least one button has been pressed
      if (num < 1000){

        if (flag0 == 1){
          num = num + 1;
        }
        if (flag1 == 1){
          num = num + 10;
        }
        if (flag2 == 1){
          num = num + 100;
        }
        if (flag3 == 1){
          if (num2 > 0){
          num2 = num2 - 1;
          }
          else{
            num2 = 0;
          }
        }
      }
      else{num = 0;}
    }
    else{
    // Don't do anything if there's nothing to do!
  }
}

void writeoutputs() {
  
  // Update the scoreboard
  scoreboard.update();    
}
  
void changenum(int ww) {

    myboard.postdisplay(num);
    myboard.predisplay(num2);
    
}  

