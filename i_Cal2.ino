

// The griper is under the magazine, with a battery:

void calibrateVar2() {
  
  delay(50);
  int noBatterySlot = openSlot();
  int mostChargedBattery = chargedBattery();
  int droneInPosition = dronePos();
  if (droneInPosition == HIGH) {
    delay(500);
    droneLock(LOW); 
  }
  int temp;
  if (noBatterySlot == 6) {
    temp = 1;
  }
  if (noBatterySlot != 6) {
    temp = 2;
  }

  switch(temp) {
    
    case 1: // There is no open batteryslot, so the griper must be under charging station
    
      griperLock(HIGH, HIGH);
      delay(2000);
      
      while (digitalRead(limSwitchBack) == HIGH) {
      // Moves the griper back:
        digitalWrite(dirPinGriper, HIGH);
        digitalWrite(pulPinGriper, HIGH);
        digitalWrite(pulPinGriper, LOW);   
        delayMicroseconds(300);
      }
      while (digitalRead(limSwitchLeft) == HIGH) {
      // Moves the magazine to "standby":
       if (((digitalRead(limSwitchUnderMagazine1)) == HIGH) && ((digitalRead(limSwitchUnderMagazine2)) == HIGH)){
        digitalWrite(dirPinMagazine, HIGH);
        digitalWrite(pulPinMagazine, HIGH);
        digitalWrite(pulPinMagazine, LOW);   
        delayMicroseconds(300); 
        }     
      }
    
      delay(100);
      mostChargedBattery = chargedBattery();
      delay(100);
      magazineMove(mostChargedBattery); 
      delay(100);
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

      
    
    case 2: // There is a open batteryslot, so the griper needs to place the battery in the slot. 

     while ((digitalRead(limSwitchUnderMagazine2) == LOW) || (digitalRead(limSwitchUnderMagazine2) == LOW)) {
      // Moves the griper forward:
        digitalWrite(dirPinGriper, LOW);
        digitalWrite(pulPinGriper, HIGH);
        digitalWrite(pulPinGriper, LOW);   
        delayMicroseconds(300);
     }
     delay(1000);


     for (int n = 0; n < 13400; n++) {
      digitalWrite(dirPinGriper, HIGH);
      digitalWrite(pulPinGriper, HIGH);
      digitalWrite(pulPinGriper, LOW);   
      delayMicroseconds(300);
     }
     



      
      
      griperLock(HIGH, HIGH); // Open griper
      delay(2000);
      
      while (digitalRead(limSwitchBack) == HIGH) {
      // Moves the griper back:
        digitalWrite(dirPinGriper, HIGH);
        digitalWrite(pulPinGriper, HIGH);
        digitalWrite(pulPinGriper, LOW);   
        delayMicroseconds(300);
      }
      while (digitalRead(limSwitchLeft) == HIGH) {
      // Moves the magazine to "standby":
       if (((digitalRead(limSwitchUnderMagazine1)) == HIGH) && ((digitalRead(limSwitchUnderMagazine2)) == HIGH)){
        digitalWrite(dirPinMagazine, HIGH);
        digitalWrite(pulPinMagazine, HIGH);
        digitalWrite(pulPinMagazine, LOW);   
        delayMicroseconds(300); 
        }     
      }
    
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
    }
    


}
  
  /*
   Check for open slot in the magazine
   While the slot == 0 {
     Move griper slowly back
   }
   
   Open griper
   Move griper forward until clear of magazine
   Move griper back until limSwitchBack == LOW
   Move magazine to standby
   Move griper to standby 
  */ 

