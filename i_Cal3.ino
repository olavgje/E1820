

// The griper is clear of the magazine, and without a battery:

void calibrateVar3() {
  
  delay(50);
  
  while (digitalRead(limSwitchLeft) == HIGH) {
    // Moves the magazine to "standby":
    digitalWrite(dirPinMagazine, HIGH);
    digitalWrite(pulPinMagazine, HIGH);
    digitalWrite(pulPinMagazine, LOW);   
    delayMicroseconds(300);      
  }  
  
  while (digitalRead(limSwitchBack) == HIGH) {
    // Moves the griper back:
    digitalWrite(dirPinGriper, HIGH);
    digitalWrite(pulPinGriper, HIGH);
    digitalWrite(pulPinGriper, LOW);   
    delayMicroseconds(300);
  }
  
  if (digitalRead(limSwitchBack) == LOW) {
    // Moves the griper to "standby"
    griperMove(LOW, 350000);
  }
  
}
