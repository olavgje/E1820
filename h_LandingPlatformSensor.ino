/*
This function controls the sensors on the "LandingPlatform".

Description intput:

int limSwitchFL:      HIGH - Waiting for drone FL / LOW - Drone in position FL
int limSwitchFR:      HIGH - Waiting for drone FR / LOW - Drone in position FR
int limSwitchBL:      HIGH - Waiting for drone BL / LOW - Drone in position BL
int limSwitchBR:      HIGH - Waiting for drone BR / LOW - Drone in position BR

Description output:
int dronePosition:    HIGH - Dronearms in position / LOW - Waiting for drone
*/

int dronePos(){
  int dronePosition;
  
  if((digitalRead(limSwitchFL) == LOW) && (digitalRead(limSwitchFR) == LOW) && (digitalRead(limSwitchBL) == LOW) && (digitalRead(limSwitchBR) == LOW)) {
    dronePosition == HIGH;
    Serial.print("Drone in position!");
  }
  else {
    dronePosition == LOW;
    Serial.print("Awaiting drone...");
  }
}

