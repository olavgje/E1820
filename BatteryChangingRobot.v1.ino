#include <Servo.h>
Servo servo1; Servo servo2;
  
  // Define pins for DRONE POSITIONING SENSORS
  int dronePosSens1 = digitalRead(1);
  int dronePosSens2 = digitalRead(2);
  int dronePosSens3 = digitalRead(3);
  int dronePosSens4 = digitalRead(4);
  // Defines pin for LOCKING OF THE DRONE
  int droneLock = 1; // USIKKER
  // Defines pins for MOVING THE BATTERYGRIPER
  int batGrip = 6;
  // Defines pins for LIMITSWITCH FOR BATTERYGRIPER
  int limSwitchBatGrip = 7;
  // Defines pins for SENSING THE BATTERY in the BATTERYGRIPER
  int batGripSens = 8;
  // Defines pins for LOCKING OF THE BATTERY in the BATTERYGRIPER
  int batLock = 2; // USIKKER
  // Defines pins for MOVING THE BATTERYMAGAZINE
  int batMag = 10;
  // Defines LIMITSWITCH FOR BATTERYMAGAZINE
  int limSwitchBatMag = 12; 
  // Defines BATTERYSTATUS in the BATTERYMAGAZINE
  int batStat1 = analogRead(3);
  int batStat2 = analogRead(4);
  int batStat3 = analogRead(5);
  int batStat4 = analogRead(6);
  int batStat5 = analogRead(7);
  
  // Defines a variable thats eather HIGH (drone in position) or LOW (drone not in position)
  int dronePos;
  int rdy2go;


void setup() {
  pinMode(droneLock, OUTPUT);
  pinMode(batLock, OUTPUT);
  servo1.attach(14); //analog pin 0
  servo2.attach(15); //analog pin 1

  // Progam that calibrate the rigg for positioning the batterygripper and batterymagazine

}

void loop() {
  checkForDrone();
  checkBatteryStatus();
  Lock();

  
}



void checkForDrone() {
  if (dronePosSens1 == HIGH && dronePosSens2 == HIGH && dronePosSens3 == HIGH && dronePosSens4 == HIGH) {
    dronePos = HIGH;
  }
  else {
      dronePos = LOW;
  }
}

void checkBatteryStatus() {
  // Read sensors
}

void Lock() {
    if (dronePos == LOW || (dronePos == HIGH && rdy2go == HIGH)) {
      servo1.write(0);
    }
    else if (rdy2go == LOW && dronePos == HIGH) {
      servo1.write(40);
    }
    
    

}




