/*
This function controls the servos on the "LandingPlatform".
Description intput:
int dronePosition     HIGH - Drone in position / LOW - Awaiting drone
Description output:
int droneLocking      HIGH - Drone locked / LOW - Drone 
*/

int droneLock(int landingSensor, int batteryChanged) {
  int droneLocking;

    if ((landingSensor == HIGH) && (batteryChanged == LOW)) {
      delay(500);
      landingPlatformFL.write(50);
      landingPlatformFR.write(80);
      landingPlatformBL.write(50); 
      landingPlatformBR.write(100);
      droneLocking == HIGH;
    }

    else {
      landingPlatformFL.write(95);
      landingPlatformFR.write(35);
      landingPlatformBL.write(18);
      landingPlatformBR.write(135);
      droneLocking == LOW;
    }
  return droneLocking;
}

