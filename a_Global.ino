#include <Servo.h>
Servo gripLeft; Servo gripRight; 
Servo landingPlatformFL; Servo landingPlatformFR;
Servo landingPlatformBL; Servo landingPlatformBR;

/*
Discription of the program
*/ 

// GriperRobots:
int pulPin = 2;
int dirPin = 3;
int enblPin = 4;
int limSwitchBack = 22;
int limSwitchFront = 23;
int griperStatus;

// Locking-mechanism for the griper:
int limSwitchInGriper = 24;
// analog pin 0
// analog pin 1

// LandingPlatform:
int limSwitchFL = 25;
int limSwitchFR = 26;
int limSwitchBL = 27;
int limSwitchBR = 28;
// analog pin 2
// analog pin 3
// analog pin 4
// analog pin 5

// TESTBRYTER: 
int buttonPin = 53;
