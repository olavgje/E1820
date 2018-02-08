void setup() {
  // Define pins for DRONE POSITIONING SENSORS
  #define DronePosSens1 = digitalRead(1);
  #define DronePosSens2 = digitalRead(2);
  #define DronePosSens3 = digitalRead(3);
  #define DronePosSens4 = digitalRead(4);
  // Defines pins for LOCKING OF THE DRONE
  #define DroneLock1 = 5;
  #define DroneLock2 = 6;
  #define DroneLock3 = 7;
  #define DroneLock4 = 8;
  // Defines pins for MOVING THE BATTERYGRIPER
  #define BatGrip = analogWrite(1);
  // Defines pins for LIMITSWITCH FOR BATTERYGRIPER
  #define LimSwitchBatGrip = 9;
  // Defines pins for SENSING THE BATTERY in the BATTERYGRIPER
  #define BatGripSens = 10;
  // Defines pins for LOCKING OF THE BATTERY in the BATTERYGRIPER
  #define BatLock = 11;
  // Defines pins for MOVING THE BATTERYMAGAZINE
  #define BatMag = analogWrite(2);
  // Defines LIMITSWITCH FOR BATTERYMAGAZINE
  #define LimSwitchBatMag = 12; 
  // Defines BATTERYSTATUS in the BATTERYMAGAZINE
  #define BatStat1 = analogRead(3);
  #define BatStat1 = analogRead(4);
  #define BatStat1 = analogRead(5);
  #define BatStat1 = analogRead(6);
  #define BatStat1 = analogRead(7);
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
