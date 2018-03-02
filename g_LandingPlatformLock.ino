/*
This function controls the servos on the "LandingPlatform".

Description intput:

int dronePosition     HIGH - Drone in position / LOW - Awaiting drone

Description output:

int droneLocking      HIGH - Drone locked / LOW - Drone 
*/

int droneLock(int dronePosition) {
  int droneLocking;

    if (dronePosition == HIGH){
      delay(500);
      landingPlatformFL.write(0);
      landingPlatformFR.write(180);
      landingPlatformBL.write(0); 
      landingPlatformBR.write(180);
      droneLocking == HIGH;
    }

    else {
      landingPlatformFL.write(90);
      landingPlatformFR.write(90);
      landingPlatformBL.write(90);
      landingPlatformBR.write(90);
      droneLocking == LOW;
    }
  result = droneLocking;
}

