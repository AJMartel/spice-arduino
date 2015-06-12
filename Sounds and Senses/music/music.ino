#include <Pinball.h>

// These are the button pins
int button0 = 4;
int button1 = 5;
int button2 = 6;

// These flags will keep track of which button has been pressed
int flag0, flag1, flag2;

Pb_switch mysw0(100), mysw1(100), mysw2(100);

Pb_speaker spkr(3);

// Check notes.h in library folder for note definitions
int melody1[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
// Timings in milliseconds
int timing1[] = { 250, 125, 125, 250, 250, 250, 250, 250};

int melody2[] = {NOTE_DS4, NOTE_GS4};
int timing2[] = {125, 250};

int melody3[] = {NOTE_G3, NOTE_G3, NOTE_FS3, NOTE_FS3, NOTE_F3, NOTE_F3, NOTE_FS3, NOTE_FS3, NOTE_G3, 0, NOTE_G3};
int timing3[] = {200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 1000};

void setup() {
   // This step is important for digital switches
  pinMode(button0, INPUT); 
  digitalWrite(button0, 1);
  pinMode(button1, INPUT); 
  digitalWrite(button1, 1);     
  pinMode(button2, INPUT); 
  digitalWrite(button2, 1);
  
  flag0 = 0; flag1 = 0; flag2 = 0;

}


void loop() {

  readinputs();       // Read all the input sensors
//  dologic();          // Perform logical operations
  writeoutputs();     // Control all output components
  
}


void readinputs() {

  flag0 = 0; flag1 = 0; flag2 = 0;
  
  // Use flags to record which switches have been pushed
  flag0 = mysw0.pushed( digitalRead(button0) );
  flag1 = mysw1.pushed( digitalRead(button1) );
  flag2 = mysw2.pushed( digitalRead(button2) );  
  
}

void dologic(){
}

void writeoutputs() {

  spkr.update();
  
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
}

