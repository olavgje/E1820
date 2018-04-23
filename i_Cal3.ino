

// The griper is clear of the magazine, and without a battery:

void calibrateVar3() {

  int droneInPosition = dronePos();
  delay(50);
  
  while (digitalRead(limSwitchLeft) == HIGH) {
    // Moves the magazine to "standby":
    if (((digitalRead(limSwitchUnderMagazine1)) == HIGH) && ((digitalRead(limSwitchUnderMagazine2)) == HIGH)) {
      digitalWrite(dirPinMagazine, HIGH);
      digitalWrite(pulPinMagazine, HIGH);
      digitalWrite(pulPinMagazine, LOW);   
      delayMicroseconds(300);  
    }    
  }  

  while (digitalRead(limSwitchBack) == HIGH) {
    // Moves the griper back:
    digitalWrite(dirPinGriper, HIGH);
    digitalWrite(pulPinGriper, HIGH);
    digitalWrite(pulPinGriper, LOW);   
    delayMicroseconds(300);
  }



  int noBatterySlot = openSlot();
  if (noBatterySlot == 6) {
    if (droneInPosition == HIGH) {
      delay(500);
      droneLock(LOW); 
    }
    int mostChargedBattery = chargedBattery();
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
  }


 
   if ((noBatterySlot != 6) &&  (digitalRead(limSwitchBack) == LOW)) { 
    // Moves the griper to "standby"
    griperMove(LOW, 33000, 3000, 3000);
  }

  
}

