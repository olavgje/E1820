#include <Servo.h>
Servo gripRight; Servo gripLeft; 
Servo landingPlatformFL; Servo landingPlatformFR;
Servo landingPlatformBL; Servo landingPlatformBR;

/*
Discription of the program
*/ 

// GriperRobots:
int pulPinGriper = 2;
int dirPinGriper = 3;
int enblPinGriper = 4;
int limSwitchBack = 22;
int limSwitchFront = 23;
int limSwitchUnderMagazine = 31; 
int griperRobotStatus;

// MagazineRobot:
int pulPinMagazine = 5;
int dirPinMagazine = 6;
int enblPinMagazine = 7;
int limSwitchLeft = 24;
int limSwitchRight = 25;

// Locking-mechanism for the griper:
int limSwitchInGriper = 26;
// analog pin 0,1

// LandingPlatform:
int limSwitchFL = 27;
int limSwitchFR = 28;
int limSwitchBL = 29;
int limSwitchBR = 30;
// analog pin 2,3,4,5


// TESTBRYTER: 
int buttonPin = 53;
