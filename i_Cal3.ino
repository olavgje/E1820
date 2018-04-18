

// The griper is clear of the magazine, and without a battery:

void calibrateVar3() {
  
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
  
  delay(500);
  if (digitalRead(limSwitchBack) == LOW) {
    // Moves the griper to "standby"
    griperMove(LOW, 33000, 3000, 3000);
  }
  
}
