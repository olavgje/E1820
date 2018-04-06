

// The griper is clear of the magazine, with a battery:

void calibrateVar4() {
  
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
}
