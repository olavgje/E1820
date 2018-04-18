

// The griper is under the magazine, and without a battery:

void calibrateVar1() {
  
  delay(50);

  while (digitalRead(limSwitchBack) == HIGH) {
    // Moves the griper back:
    digitalWrite(dirPinGriper, HIGH);
    digitalWrite(pulPinGriper, HIGH);
    digitalWrite(pulPinGriper, LOW);   
    delayMicroseconds(300);
  }

  delay(1000);
  
  while (digitalRead(limSwitchLeft) == HIGH) {
    // Moves the magazine to "standby":
    if (((digitalRead(limSwitchUnderMagazine1)) == HIGH) && ((digitalRead(limSwitchUnderMagazine2)) == HIGH)){
      digitalWrite(dirPinMagazine, HIGH);
      digitalWrite(pulPinMagazine, HIGH);
      digitalWrite(pulPinMagazine, LOW);   
      delayMicroseconds(300); 
    }     
  }  

  if (digitalRead(limSwitchBack) == LOW) { 
    // Moves the griper to "standby"
    griperMove(LOW, 33000, 3000, 3000);
  }

}
