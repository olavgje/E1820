

// The griper is clear of the magazine, with a battery:

void calibrateVar4() {
  
  delay(50);
  int noBatterySlot = openSlot();
  int mostChargedBattery = chargedBattery();
  int droneInPosition = dronePos();
  if (droneInPosition == HIGH) {
    delay(500);
    droneLock(LOW); 
  }

  
  while (digitalRead(limSwitchLeft) == HIGH) {
    // Moves the magazine to "standby":
    if (((digitalRead(limSwitchUnderMagazine1)) == HIGH) && ((digitalRead(limSwitchUnderMagazine2)) == HIGH)) {
      digitalWrite(dirPinMagazine, HIGH);
      digitalWrite(pulPinMagazine, HIGH);
      digitalWrite(pulPinMagazine, LOW);   
      delayMicroseconds(300); 
    }    
  } 

  magazineMove(noBatterySlot);

  while (digitalRead(limSwitchUnderMagazine2) == HIGH) {
  // Moves the griper back:
    digitalWrite(dirPinGriper, HIGH);
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
   
} 

