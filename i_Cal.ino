/*
This function calibrates the rigg.
*/

void calibration(){
  int var = 0;
  delay(50);
  
  // The griper is under the magazine, and without a battery:
  if (((digitalRead(limSwitchUnderMagazine1) == LOW) || (digitalRead(limSwitchUnderMagazine2) == LOW)) && (digitalRead(limSwitchInGriper) == HIGH)) {
    var = 1;
  }
  // The griper is under the magazine, with a battery: 
  if (((digitalRead(limSwitchUnderMagazine1) == LOW) || (digitalRead(limSwitchUnderMagazine2) == LOW)) && (digitalRead(limSwitchInGriper) == LOW)) { 
    var = 2;
  }
  // The griper is clear of the magazine, and without a battery: 
  if (((digitalRead(limSwitchUnderMagazine1) == HIGH) && (digitalRead(limSwitchUnderMagazine2) == HIGH)) && (digitalRead(limSwitchInGriper) == HIGH)) {
    var = 3;
  }
  // The griper is clear of the magazine, with a battery:
  if (((digitalRead(limSwitchUnderMagazine1) == HIGH) && (digitalRead(limSwitchUnderMagazine2) == HIGH)) && (digitalRead(limSwitchInGriper) == LOW)) {
    var = 4;
  }
  delay(50);
  
  
  
  switch(var) {
    case 1: // The griper is under the magazine, and without a battery:
      
      calibrateVar1;
      break;
     
    case 2: // The griper is under the magazine, with a battery:
      
      calibrateVar2;
      break;
    
    case 3: // The griper is clear of the magazine, and without a battery:
    
      calibrateVar3;
      break;
    
    case 4: // The griper is clear of the magazine, with a battery:
    
      calibrateVar4;
      break;
  }
  
}
  

  
  /*
  
  
  
  // If griper is under magazine, and WITHOUT battery:
  if (((digitalRead(limSwitchUnderMagazine1) == LOW) || (digitalRead(limSwitchUnderMagazine2) == LOW)) && (digitalRead(limSwitchInGriper) == HIGH)) {
    delay(50);
    while (digitalRead(limSwitchBack) == HIGH) {
      // Moves the griper back:
      digitalWrite(dirPinGriper, HIGH);
      digitalWrite(pulPinGriper, HIGH);
      digitalWrite(pulPinGriper, LOW);   
      delayMicroseconds(300);
    }
  }
  delay(1000);
  while (digitalRead(limSwitchLeft) == HIGH) {
    // Moves the magazine to "standby":
    digitalWrite(dirPinMagazine, HIGH);
    digitalWrite(pulPinMagazine, HIGH);
    digitalWrite(pulPinMagazine, LOW);   
    delayMicroseconds(300);      
  }
  
  // Moves the griper to "standby"  
  if (digitalRead(limSwitchBack) == LOW) {
    griperMove(LOW, 350000);
  }


  // If griper is under magazine, and WITH battery:
  if (((digitalRead(limSwitchUnderMagazine1) == LOW) || (digitalRead(limSwitchUnderMagazine2) == LOW)) && (digitalRead(limSwitchInGriper) == LOW)) { 
    // Go back until signal signa in Volt on battery charger
  }



  // If griper is clear from magazine, and WITHOUT battery:
  if (((digitalRead(limSwitchUnderMagazine1) == HIGH) && (digitalRead(limSwitchUnderMagazine2) == HIGH)) && (digitalRead(limSwitchInGriper) == HIGH)) {
    while (digitalRead(limSwitchLeft) == HIGH) {
      // Moveing the magazine:
      digitalWrite(dirPinGriper, HIGH);
      digitalWrite(pulPinGriper, HIGH);
      digitalWrite(pulPinGriper, LOW); 
  }

*/

