/*
This program is used in bachelorthesis "Automatic battery change on 250g drones" E1820 at NTNU in collaboration with FFI.
*/ 

#include <Servo.h>
Servo gripRight; Servo gripLeft; 
Servo landingPlatformFL; Servo landingPlatformFR;
Servo landingPlatformBL; Servo landingPlatformBR;

// GriperRobots:
int pulPinGriper = 2;
int dirPinGriper = 3;
int enblPinGriper = 4;
int limSwitchBack = 22;
int limSwitchFront = 23;
int limSwitchUnderMagazine1 = 31; 
int limSwitchUnderMagazine2 = 32; 
int griperRobotStatus;

// MagazineRobot:
int pulPinMagazine = 5;
int dirPinMagazine = 6;
int enblPinMagazine = 7;
int limSwitchLeft = 29;
int limSwitchRight = 30;

// Locking-mechanism for the griper:
int limSwitchInGriper = 24;
// analog pin 0,1

// LandingPlatform:
int limSwitchFL = 25;
int limSwitchFR = 26;
int limSwitchBL = 40;
int limSwitchBR = 28;
// analog pin 2,3,4,5

// General
int toSlot;
int fromSlot;

int charger1 = 60;            //analog pin 6
int charger2 = 61;            //analog pin 7
int charger3 = 62;            //analog pin 8
int charger4 = 63;            //analog pin 9
int charger5 = 64;            //analog pin 10
