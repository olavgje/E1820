/*
This function calibrates the rigg.

*/
void calibration(){
  
  // If griper is under magazine, and WITHOUT battery:
  if (((digitalRead(limSwitchUnderMagazine1) == LOW) || (digitalRead(limSwitchUnderMagazine2) == LOW)) && (digitalRead(limSwitchInGriper) == HIGH)) {
    delay(50);
    while (digitalRead(limSwitchBack) == HIGH) {
      // Moveing the griper:
      digitalWrite(dirPinGriper, HIGH);
      digitalWrite(pulPinGriper, HIGH);
      digitalWrite(pulPinGriper, LOW);   
      delayMicroseconds(300);
    }
  }
  delay(1000);
  if (digitalRead(limSwitchBack) == LOW) {
    griperMove(LOW, 350000);
  }


  // If griper is under magazine, and WITH battery:
  if (((digitalRead(limSwitchUnderMagazine1) == LOW) || (digitalRead(limSwitchUnderMagazine2) == LOW)) && (digitalRead(limSwitchInGriper) == LOW)) { 
    // Go back until signal signa in Volt on battery charger
  }


  // If griper is clear from magazine:
  if (((digitalRead(limSwitchUnderMagazine1) == HIGH) && (digitalRead(limSwitchUnderMagazine2) == HIGH)) && (digitalRead(limSwitchInGriper) == LOW)) {
    
  }


}
