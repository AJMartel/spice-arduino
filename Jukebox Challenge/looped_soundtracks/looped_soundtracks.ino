#include <Pinball.h>

#include "mytunes.h"

// These are the button pins
int button0 = 4;
int button1 = 5;
int button2 = 6;
int button3 = 7;

// These flags will keep track of which button has been pressed
int flag0, flag1, flag2, flag3;
int loopstate;

Pb_switch mysw0(100), mysw1(100), mysw2(100), mysw3(100);

Pb_speaker spkr(13);



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

  loopstate = 1;
  spkr.loopstart(marionotes2, mariotimes2, 61);

}


void loop() {

  readinputs();       // Read all the input sensors
  dologic();          // Perform logical operations
  writeoutputs();     // Control all output components
  
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
    if ( (flag0 + flag1 + flag2) > 0 ) {  // If at least one switch has been pushed
  
  if (flag0 == 1) {
    spkr.start(melody1, timing1, 8);   // Last argument is the length of song
  }

  if (flag1 == 1) {
    spkr.start(melody2, timing2, 2);   // Last argument is the length of song
  }
  
  if (flag2 == 1) {
    spkr.start(melody3, timing3, 11);   // Last argument is the length of song
  }  
  
  }
  if (flag3 == 1) {
    if (loopstate == 1) {
      spkr.loopstop();
      loopstate = 0;
    } 
    else {
      spkr.loopstart(marionotes2, mariotimes2, 61);        
      loopstate = 1;
    }
   }
}

void writeoutputs() {

  spkr.update();
  

}

