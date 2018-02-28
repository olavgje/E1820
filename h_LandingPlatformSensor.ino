/*
This function controls the sensors on the "LandingPlatform".

Description intput:

int limSwitchFL:      HIGH - Drone in position FL / LOW - Waiting for drone FL
int limSwitchFR:      HIGH - Drone in position FR / LOW - Waiting for drone FR
int limSwitchBL:      HIGH - Drone in position BL / LOW - Waiting for drone BL
int limSwitchBR:      HIGH - Drone in position BR / LOW - Waiting for drone BR

Description output:
int DronePos:         HIGH - Dronearms in position / LOW - Waiting for drone
*/


int DronePosFront;
int DronePosBack;
int DronePos;

if ((digitalRead(limSwitchFL) == HIGH) && (digitalRead(limSwitchFR) == HIGH)) {
  DronePosFront == HIGH;
}

if ((digitalRead(limSwitchBL) == HIGH) && (digitalRead(limSwitchBR) == HIGH)) {
  DronePosBack == HIGH;
}

if ((DronePosFront == HIGH) && (DronePosBack == HIGH) {
  DronePos == HIGH;
  Serial.print("Drone in position!");
}
    
if (DronePos == LOW) {
  Serial.print("Waiting for drone...");
