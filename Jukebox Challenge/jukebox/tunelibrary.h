//#include <Pinball.h>


int melody1[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4, 0};
int timing1[] = { 250, 125, 125, 250, 250, 250, 250, 250, 10};

int coinnotes[] = {NOTE_DS4, NOTE_GS4, 0};
int cointimes[] = {125, 250, 10};
int coinlength = 3;

int beepboopnotes[] = {0, NOTE_C4, 0, NOTE_G3, 0, NOTE_E4, 0, NOTE_G3, 0, NOTE_C4, 0, NOTE_C3, 0};
int beepbooptimes[] = {200, 200, 400, 200, 300, 200, 400, 200, 300, 200, 400, 200, 1200};
int beepbooplength = 12;

int arpeggionotes[] = {0, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5, 0};
int arpeggiotimes[] = {10, 100, 100, 100, 600, 1000};
int arpeggiolength = 6;

int oneupnotes[] = {0, NOTE_E3, NOTE_G3, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_G4, 0};
int oneuptimes[] = {10, 200, 200, 200, 200, 200, 200, 10};
int oneuplength = 8;

int levelupnotes[] = {0,\
  NOTE_G2, NOTE_C3, NOTE_E3, NOTE_G3, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_E4, 0,\
  NOTE_GS2, NOTE_C3, NOTE_DS3, NOTE_GS3, NOTE_C4, NOTE_DS4, NOTE_GS4, NOTE_DS4, 0,\
  NOTE_AS2, NOTE_D3, NOTE_F3, NOTE_AS3, NOTE_D4, NOTE_F4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_C5, 0}; 

int leveluptimes[] = {125,\
  125, 125, 125, 125, 125, 125, 325, 175, 175,\
  125, 125, 125, 125, 125, 125, 325, 175, 175,\
  125, 125, 125, 125, 125, 125, 325, 125, 125, 125, 925, 825};
  
int leveluplength = 31;

int gameovernotes[] = {0, NOTE_C4, 0, NOTE_G3, 0, NOTE_E3, 0, NOTE_A3, NOTE_B3, NOTE_A3, NOTE_GS3, NOTE_AS3, NOTE_GS3, NOTE_G3, NOTE_F3, NOTE_G3, 0};
int gameovertimes[] = {10, 200, 400, 200, 300, 200, 300, 400, 400, 400, 400, 400, 400, 150, 150, 1200, 1000};
int gameoverlength = 17;

int batmannotes[] = {NOTE_G3, NOTE_G3, NOTE_FS3, NOTE_FS3, NOTE_F3, NOTE_F3, NOTE_FS3, NOTE_FS3, NOTE_G3, 0, NOTE_G3, 0};
int batmantimes[] = {200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 1000, 10};

// A sliding upward tone

int slideupnotes[] = {\
  0, NOTE_C2, NOTE_CS2, NOTE_D2, NOTE_DS2,\
  NOTE_E2,NOTE_F2,NOTE_FS2,NOTE_G2,\
  NOTE_GS2,NOTE_A2,NOTE_AS2,NOTE_B2,\
  NOTE_C3,NOTE_CS3,NOTE_D3,NOTE_DS3,\
  NOTE_E3,NOTE_F3,NOTE_FS3,NOTE_G3,\
  NOTE_GS3,NOTE_A3,NOTE_AS3,NOTE_B3,\
  NOTE_C4,NOTE_CS4,NOTE_D4,NOTE_DS4,\
  NOTE_E4,NOTE_F4,NOTE_FS4,NOTE_G4,\
  NOTE_GS4,NOTE_A4,NOTE_AS4,NOTE_B4,NOTE_C5,0};
  
// A sliding downward tone; use with slidetimes and slidelength

int slidedownnotes[] = {\
  0, NOTE_C5, NOTE_B4, NOTE_AS4, \
  NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_FS4, \
  NOTE_F4, NOTE_E4, NOTE_DS4, NOTE_D4,\
  NOTE_CS4, NOTE_C4, NOTE_B3, NOTE_AS3,\
  NOTE_A3, NOTE_GS3, NOTE_G3, NOTE_FS3,\
  NOTE_F3, NOTE_E3, NOTE_DS3, NOTE_D3,\
  NOTE_CS3, NOTE_C3, NOTE_B2, NOTE_AS2,\
  NOTE_A2, NOTE_GS2, NOTE_G2, NOTE_FS2,\
  NOTE_F2, NOTE_E2, NOTE_DS2, NOTE_D2,\
  NOTE_CS2, NOTE_C2, 0};
  
int slidetimes[] = {\
  500, 100, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40,\
  40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40,\
  40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 500, 1000};
  
int slidelength = 39;

//
int marionotes2[] = { \
\
  NOTE_C3, NOTE_C4, NOTE_A2, NOTE_A3, NOTE_GS2, NOTE_AS3, 0,\
  NOTE_C3, NOTE_C4, NOTE_A2, NOTE_A3, NOTE_GS1, NOTE_AS3, 0,\
\
  NOTE_G2, NOTE_G3, NOTE_E2, NOTE_E3, NOTE_F2, NOTE_F3, 0,\
  NOTE_G2, NOTE_G3, NOTE_E2, NOTE_E3, NOTE_F2, NOTE_F3, 0,\
\
  NOTE_F3, NOTE_E3, NOTE_DS3, NOTE_D3, 0, NOTE_F3, 0, NOTE_E3, 0,\
  NOTE_AS2, 0, NOTE_A2, 0, NOTE_DS3, 0, NOTE_D3, NOTE_GS3, NOTE_G3, NOTE_FS3, \
  NOTE_C4, NOTE_B3, NOTE_AS3, 0, NOTE_F3, 0, NOTE_CS3, 0, NOTE_C3, 0, NOTE_B2, 0, NOTE_AS2, 0};
  
int mariotimes2[] = { \
\
  200, 200, 200, 200, 200, 200, 1000,           \
  200, 200, 200, 200, 200, 200, 1000,           \
\
  200, 200, 200, 200, 200, 200, 1000,           \
  200, 200, 200, 200, 200, 200, 1000,           \
\
  100, 100, 100, 200, 250, 200, 250, 200, 250,           \
  200, 250, 200, 250, 200, 250, 100, 100, 100, 100, \
  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 3000};


int mariolength2 = 61;
//
//
//int robotonotes[] = { \
//\
//  0, NOTE_A3, NOTE_G3, NOTE_C4, NOTE_B3, NOTE_G3, NOTE_F3,\
//  NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0, NOTE_B3, 0, 0, NOTE_A3, 0,\
//  NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0, NOTE_B3, 0, 0,\
//\
//  NOTE_A3, NOTE_G3, NOTE_C4, NOTE_B3, NOTE_G3, NOTE_F3,\
//  NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0, NOTE_B3, 0, 0, NOTE_A3, 0,\
//  NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0, NOTE_B3, 0, 0,\
//\
//  NOTE_A3, NOTE_G3, NOTE_C4, NOTE_B3, NOTE_G3, NOTE_F3,\
//  NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0, NOTE_B3, 0, 0, NOTE_A3, 0,\
//  NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0, NOTE_B3, 0, 0,\
//\
//  NOTE_A3, NOTE_G3, NOTE_C4, NOTE_B3, NOTE_C4,\
//  NOTE_D4, 0, NOTE_D4, 0, NOTE_D3, 0, NOTE_D3, 0, NOTE_D3, 0, NOTE_D3, 0,\
//  NOTE_D4, 0, NOTE_D4, 0, NOTE_D3, 0, NOTE_D3, 0, NOTE_D3, 0, NOTE_D3, 0,\
//\
//  NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, 0, 0, NOTE_B3, 0, NOTE_C4, 0,\
//  0, 0, NOTE_C4, 0, 0, 0, NOTE_B3, 0, NOTE_C4, 0, 0, 0, NOTE_B3, 0, 0, 0,\
//  NOTE_D4, 0, NOTE_D4, 0, NOTE_D3, 0, NOTE_D3, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
//  NOTE_D4, 0, NOTE_D4, 0, NOTE_D3, 0, NOTE_D3, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
//\
//  NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, 0, 0, NOTE_B3, 0, NOTE_C4, 0,\
//  0, 0, NOTE_C4, 0, 0, 0, NOTE_B3, 0, NOTE_C4, 0, 0, 0, NOTE_B3, 0, 0, 0,\
//  NOTE_D4, 0, NOTE_D4, 0, NOTE_D3, 0, NOTE_D3, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
//  NOTE_D4, 0, NOTE_D4, 0, NOTE_D3, 0, NOTE_D3, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
//0};
//
//int robototimes[] = { \
//\
//  100, 200, 600, 200, 600, 200, 600,\
//  100, 100, 100, 100, 100, 100, 100, 100, 200, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100, 400,\
//\
//  200, 600, 200, 600, 200, 600,\
//  100, 100, 100, 100, 100, 100, 100, 100, 200, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100, 400,\
//\
//  200, 600, 200, 600, 200, 600,\
//  100, 100, 100, 100, 100, 100, 100, 100, 200, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100, 400,\
//\
//  200, 600, 200, 600, 400,\
//  300, 100, 300, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  300, 100, 300, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//100};
//  
//int robotolength = 3*26+18+12+8*16;
//
////400 quarter note, 200 eighth note, 100 sixteenth note
////All vals for first part are 100
//
//int funkynotes[] = {\
//\ 
//  NOTE_C4, 0, NOTE_C4, 0, NOTE_AS3, 0, NOTE_C4, 0, 0, 0, NOTE_G3, 0, 0, 0, NOTE_G3, 0, NOTE_C4, 0, NOTE_F4, 0, NOTE_E4, 0, NOTE_C4, 0,\
//  0,\
//  NOTE_C4, 0, NOTE_C4, 0, NOTE_AS3, 0, NOTE_C4, 0, 0, 0, NOTE_G3, 0, 0, 0, NOTE_G3, 0, NOTE_C4, 0, NOTE_F4, 0, NOTE_E4, 0, NOTE_C4, 0,\
//  0,\
//\
//  NOTE_C3, 0, NOTE_C3, 0, NOTE_C3, 0, NOTE_C3, 0, NOTE_E3, 0, NOTE_E3, 0, NOTE_E3, 0, NOTE_G3, 0, NOTE_G3, 0, NOTE_E4, 0, 0, 0, NOTE_D4, 0, NOTE_C4, 0,\
//  0,\
//\
//  NOTE_C4, 0, NOTE_C4, 0, NOTE_AS3, 0, NOTE_C4, 0, 0, 0, NOTE_G3, 0, 0, 0, NOTE_G3, 0, NOTE_C4, 0, NOTE_F4, 0, NOTE_E4, 0, NOTE_C4, 0,\
//  0,\
//\
//  NOTE_C3, 0, NOTE_C3, 0, NOTE_C3, 0, NOTE_C3, 0, NOTE_E3, 0, NOTE_E3, 0, NOTE_E3, 0, NOTE_G3, 0, NOTE_G3, 0, NOTE_E4, 0, 0, 0, NOTE_D4, 0, NOTE_C4, 0,\
//  0,\
//\
//  NOTE_C4, 0, NOTE_C4, 0, NOTE_AS3, 0, NOTE_C4, 0, 0, 0, NOTE_G3, 0, 0, 0, NOTE_G3, 0, NOTE_C4, 0, NOTE_F4, 0, NOTE_E4, 0, NOTE_C4, 0,\
//  0,\
//\
//  NOTE_C4, 0, NOTE_C4, 0, NOTE_D4, 0, NOTE_D4, 0, NOTE_D4, 0, NOTE_D4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0,\
//  NOTE_B3, 0, NOTE_B3, 0, NOTE_B3, 0, NOTE_B3, 0, NOTE_A3, 0, NOTE_A3, 0, NOTE_A3, 0,\
//\
//  NOTE_G3, 0, NOTE_G3, 0, NOTE_F3, 0, NOTE_G3, 0, 0, 0, NOTE_D3, 0, 0, 0, NOTE_D3, 0, NOTE_G3, 0, NOTE_C4, 0, NOTE_B3, 0, NOTE_G3, 0,\
//  0,\
//\
//  NOTE_D4, 0, 0, 0, NOTE_D4, 0, NOTE_D4, 0, 0, 0, NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, 0, 0, 0, \
//  NOTE_B3, 0, NOTE_B3, 0, NOTE_B3, 0, 0, 0, NOTE_B3,\
//\
//  NOTE_C4, 0, 0, 0, NOTE_C4, 0, NOTE_AS3, 0, NOTE_C4, 0, 0, 0, NOTE_G3, 0, 0, 0, NOTE_G3, 0, NOTE_C4, 0, NOTE_F4, 0, NOTE_E4, 0, NOTE_C4, 0,\
//  0,\
//  NOTE_C4, 0, NOTE_C4, 0, NOTE_AS3, 0, NOTE_C4, 0, 0, 0, NOTE_G3, 0, 0, 0, NOTE_G3, 0, NOTE_C4, 0, NOTE_F4, 0, NOTE_E4, 0, NOTE_C4, 0,\
//  0,\
//\
//  0, 0, NOTE_G3, 0, 0, 0, NOTE_G3, 0, 0, 0, NOTE_F3, 0, 0, 0, NOTE_F3, 0, 0, 0, NOTE_E3, 0, 0, 0, NOTE_E3, 0, 0, 0, 
//  NOTE_D3, NOTE_C3,\
//\
//0};
//  
//int funkytimes[] = {\
//\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  800,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  600,\
//\
//  300, 100, 100, 100, 100, 100, 100, 100, 300, 100, 100, 100, 100, 100, 300, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  200,\
//\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  600,\
//\
//  300, 100, 100, 100, 100, 100, 100, 100, 300, 100, 100, 100, 100, 100, 300, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  200,\
//\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  200,\
//\
//  300, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//\
//  300, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  700,\
//\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 600,\ 
//\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  800,\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  800,\
//\
//  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
//  600, 800,\ 
//\
//3000};
//  
//int funkylength = 50+27+25+27+25+34+24+27+28+52+28+1;
//
//int funkynotes2[] = {0,\
//\
//  NOTE_G2, 0, NOTE_G2, NOTE_G2, 0, NOTE_G3, 0,\
//  NOTE_AS3, 0, NOTE_G3, 0, NOTE_AS3, 0, NOTE_G3, 0,\
//  NOTE_G2, 0, NOTE_G2, NOTE_G2, 0, NOTE_AS3, 0,\
//  NOTE_C4, 0, NOTE_AS3, 0, NOTE_DS4, 0,\
//  NOTE_G2, 0, NOTE_G2, NOTE_G2, 0, NOTE_G3, 0,\
//  NOTE_AS3, 0, NOTE_G3, 0, NOTE_AS3, 0, NOTE_C4, 0,\
//  NOTE_G2, 0, NOTE_G2, NOTE_G2, 0, NOTE_AS3, 0, \
//  NOTE_C4, 0, NOTE_C4, 0, NOTE_DS3, 0,\
//\
//  NOTE_G2, 0, NOTE_G2, NOTE_G2, 0, NOTE_G3, 0,\
//  NOTE_AS3, 0, NOTE_G3, 0, NOTE_AS3, 0, NOTE_G3, 0,\
//  NOTE_G2, 0, NOTE_G2, NOTE_G2, 0, NOTE_AS3, 0,\
//  NOTE_C4, 0, NOTE_AS3, 0, NOTE_DS4, 0,\
//  NOTE_G2, 0, NOTE_G2, NOTE_G2, 0, NOTE_G3, 0,\
//  NOTE_AS3, 0, NOTE_G3, 0, NOTE_AS3, 0, NOTE_C4, 0,\
//\
//  0, NOTE_G4, 0, NOTE_G4, 0, NOTE_F4, 0, NOTE_DS4, 0, NOTE_C4,\
//0};
//
//int funkytimes2[] = {10,\
//\
//  300, 50,  50, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100,\
//  300, 50,  50, 100, 100, 100, 100,\
//  100, 100, 100, 100, 300, 100,\
//  300, 50,  50, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100,\
//  300, 50,  50, 100, 100, 100, 100,\
//  100, 100, 100, 100, 300, 100,\
//\
//  300, 50, 50, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100,\
//  300, 50,  50, 100, 100, 100, 100,\
//  100, 100, 100, 100, 300, 100,\
//  300, 50,  50, 100, 100, 100, 100,\
//  100, 100, 100, 100, 100, 100, 100, 100,\
//\
//  400, 300, 100, 100, 100, 100, 100, 100, 100, 1000,\
//\
//3000};
//
//int funkylength2 = 56*2-13+10+2;
//
////  100, 100, 100, 100, 100, 100, 100, 100,\
////  300, 50, 50, 100, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100,\
////  300, 50, 50, 100, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100,\
////  300, 50, 50, 100, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100,\
//
//\
//
//
////\
////  300, 100, 100, 100, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
////  300, 100, 100, 100, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100,\
////  300, 100, 100, 100, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100, 100, 100,\
////  300, 100, 100, 100, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100,\
////\
////  300, 100, 100, 100, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100,\
////  300, 100, 100, 100, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100,\
////
////  300, 100, 100, 100, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100,\
////
////  300, 100, 100, 100, 100, 100,\
////  100, 100, 100, 100, 100, 100, 100, 100,\
////
////\
//// 
////\
////  NOTE_G1, 0, NOTE_G1, 0, NOTE_G1, 0,\
////  NOTE_G2, 0, NOTE_AS2, 0, NOTE_G2, 0, NOTE_AS2, 0, NOTE_G2, 0,\
////  NOTE_G2, 0, NOTE_G2, 0, NOTE_G2, 0,\
////  NOTE_AS2, 0, NOTE_C3, 0, NOTE_AS2, 0, NOTE_DS3, 0,\
////  NOTE_G2, 0, NOTE_G2, 0, NOTE_G2, 0,\
////  NOTE_G2, 0, NOTE_AS2, 0, NOTE_G2, 0, NOTE_AS2, 0, NOTE_C3, 0,\
////  NOTE_G2, 0, NOTE_G2, 0, NOTE_G2, 0,\
////  NOTE_AS2, 0, NOTE_C3, 0, NOTE_C3, 0, NOTE_DS2, 0,\
////\
////  NOTE_G1, 0, NOTE_G1, 0, NOTE_G1, 0,\
////  NOTE_G2, 0, NOTE_AS2, 0, NOTE_G2, 0, NOTE_AS2, 0, NOTE_G2, 0,\
////  NOTE_G2, 0, NOTE_G2, 0, NOTE_G2, 0,\
////  NOTE_AS2, 0, NOTE_C3, 0, NOTE_AS2, 0, NOTE_DS3, 0,\
////  NOTE_G2, 0, NOTE_G2, 0, NOTE_G2, 0,\
////  NOTE_G2, 0, NOTE_AS2, 0, NOTE_G2, 0, NOTE_AS2, 0, NOTE_C3, 0,\
////  NOTE_G2, 0, NOTE_G2, 0, NOTE_G2, 0,\
////  NOTE_G3, 0, NOTE_G3, 0, NOTE_F3, 0, NOTE_DS3, 0, NOTE_C3, 0};
////  
////  
////  
////  
