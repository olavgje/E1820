void loop() { 

  // Move the magazine to an open slot.
  delay(100);
  int moveToSlot = openSlot(); 
  if ((moveToSlot != toSlot) || (fromSlot == 6)){
    magazineMove(moveToSlot);
    toSlot = moveToSlot;
  }

  // Lock drone, and place griper under the drone
  int droneInPosition = dronePos();
  if (droneInPosition == HIGH) {
    delay(500);
    droneLock(LOW);
    griperMove(LOW, 14850, 3000, 3000);
    delay(100);
    int inGriper = digitalRead(limSwitchInGriper);
    delay(100);
    int var;
    if (inGriper == LOW) { var = 0; }
    if (inGriper == HIGH) { var = 1; }

    switch(var) {
      case 0: 
        griperLock(inGriper, HIGH);
        delay(100);
        griperMove(HIGH, 32350, 8000, 13000);
        delay(100);
        griperLock(inGriper, LOW);
        delay(100);
        griperMove(HIGH, 15500, 3000, 3000); 
        
        int mostChargedBattery;
        mostChargedBattery = chargedBattery();
        magazineMove(mostChargedBattery); 
        griperMove(LOW, 15500, 3000, 3000);
        delay(100);
        // Griper is under the magazine, ready to pick up a battery. 

        griperLock(LOW, HIGH);
        delay(100);
        griperMove(LOW, 32350, 13000, 8000);
        delay(100);
        griperLock(LOW, LOW);
        delay(100);
        griperMove(HIGH, 14850, 3000, 3000);    
        // Griper is in standby position
        
        droneLock(HIGH); 
        droneInPosition = dronePos();
        while (droneInPosition == HIGH) {
          droneInPosition = dronePos();
          delay(500);
        }
        break;


      case 1:
        droneLock(HIGH);
        calibration();
        break;
    }
      
  }

}

