#include <Pinball.h>

#include "tunelibrary.h"

//_________________________________________PIN DEFINITIONS_______
// These are the button pins
int button0 = 4, button1 = 5, button2 = 6, button3 = 7;

// Pinball scoreboard
int clkpin = 8, diopin = 9;

//_________________________________________SPECIAL OBJECTS_______

// Define buttons as switches
Pb_switch mysw0(100), mysw1(100), mysw2(100), mysw3(100);

// Declare scoreboard object named myboard
Pb_scoreboard myboard(clkpin, diopin);
//Pb_timedevent scoreboard(changenum);
//int val[] = { 0 };
//int timing[] = { 1000 };

// Use speaker object
Pb_speaker spkr(13);

// Use shift register
Pb_outputs shregs(10, 11, 12, 2); // (datapin, clkpin, latchpin, numreg)

// Use timed events to avoid using delay
Pb_timedevent songlights(lednotes);


//_________________________________________________FLAGS________

// Flags to keep track of button presses and song number
int flag0, flag1, flag2, flag3, num;

//_________________________________________ANALOG SENSORS_______

//There are no analog sensors in a jukebox! But you could add a FSR volume control...

//// Use sensorValue0 to keep track of analog sensor
//int sensorPin0 = A2;
//int sensorValue0 = 0;
//// Record the minimum and maximum values of analog sensor
//int Min0 = 10;
//int Max0 = 1023;

//_____________________________________________SETUP___________

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
  
 // Initial number values
  flag0 = 0; flag1 = 0; flag2 = 0; flag3 = 0; num = 0;

  myboard.showdisplay(num);  
  
  lednotes(0);

}

//____________________________________________THE LOOP___________

void loop() {
  
  // Read all the inputs
  readinputs();
  
  // Figure out what to do based on inputs
  dologic();
  
  // Write to the outputs
  writeoutputs();

}

//____________________________________________INPUT STUFF___________

void readinputs() {

  flag0 = 0; flag1 = 0; flag2 = 0; flag3 = 0;
  
  // Use flags to record which switches have been pushed
  flag0 = mysw0.pushed( digitalRead(button0) );
  flag1 = mysw1.pushed( digitalRead(button1) );
  flag2 = mysw2.pushed( digitalRead(button2) );  
  flag3 = mysw3.pushed( digitalRead(button3) );    
  
}

//____________________________________________LOGIC STUFF___________

void dologic() {
  
  if (flag0 == 1) {   // If switch 0 has been pushed, decrease number
    num = num - 1;
    if (num < 0) {
      num = 0;
    }
  }
  
  
  if (flag2 == 1) {  // If switch 2 has been pushed, increase number
    num = num + 1;
    if (num > 99) {
      num = 99;
    }      
  }
}

//___________________________________________OUTPUT STUFF___________

void writeoutputs() {

  

  // Update the speaker and lights
  spkr.update();
  songlights.update();
  
  // Update the and scoreboard only if needed  
  if ( (flag0 + flag2) > 0 ) {  
    myboard.showdisplay(num);
  }
  
  if (flag1 == 1) {
    playsong(num);                   // Play the correct song
  }
  
  
  if (flag3 == 1) {
      spkr.stop();                   // Pause the song and lights
      songlights.stop();
  }
  
  
}



//___________________________________________SPECIAL FUNCTIONS___________

//void changenum(int ww) {
//
//    myboard.showdisplay(num);
//    
//}  

void playsong(int n) {
 
 if (n == 1) { spkr.start(levelupnotes, leveluptimes, leveluplength); songlights.start(levelupnotes, leveluptimes, leveluplength); } 
 else if (n == 2) { spkr.start(oneupnotes, oneuptimes, oneuplength); songlights.start(oneupnotes, oneuptimes, oneuplength); } 
 else if (n == 3) { spkr.start(gameovernotes, gameovertimes, gameoverlength); songlights.start(gameovernotes, gameovertimes, gameoverlength); } 
 else if (n == 4) { spkr.start(marionotes2, mariotimes2, 61); songlights.start(marionotes2, mariotimes2, 61); }  
 else { spkr.stop(); songlights.stop(); lednotes(0); }
  
}

 // Makes LED light up based on note frequency!
void lednotes(int note) {

 byte serdata[] = { 0b00000000, 0b00000000 } ;
 
 
 if ( note < NOTE_G1) { // do nothing 
 } 
 else if ( note < NOTE_C2 ) { bitWrite(serdata[1], 0, 1); }
 else if ( note < NOTE_DS2 ) { bitWrite(serdata[1], 1, 1); }
 else if ( note < NOTE_FS2 ) { bitWrite(serdata[1], 2, 1); }
 else if ( note < NOTE_B2 ) { bitWrite(serdata[1], 3, 1); }
 else if ( note < NOTE_C3 ) { bitWrite(serdata[1], 4, 1); }
 else if ( note < NOTE_CS3 ) { bitWrite(serdata[1], 5, 1); }
 else if ( note < NOTE_D3 ) { bitWrite(serdata[1], 6, 1); }
 else if ( note < NOTE_DS3 ) { bitWrite(serdata[1], 7, 1); }
 else if ( note < NOTE_E3 ) { bitWrite(serdata[0], 0, 1); }
 else if ( note < NOTE_F3 ) { bitWrite(serdata[0], 1, 1); }
 else if ( note < NOTE_FS3 ) { bitWrite(serdata[0], 2, 1); }
 else if ( note < NOTE_G3 ) { bitWrite(serdata[0], 3, 1); }
 else if ( note < NOTE_A3 ) { bitWrite(serdata[0], 4, 1); }
 else if ( note < NOTE_AS3 ) { bitWrite(serdata[0], 5, 1); }
 else if ( note < NOTE_B3 ) { bitWrite(serdata[0], 6, 1); }
 else  { bitWrite(serdata[0], 7, 1); }
 
 shregs.update(serdata); 
  
}
