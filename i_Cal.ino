/*
This function calibrates the rigg.
*/

void calibration(){
  int var = 0;
  delay(50);
  griperLock(LOW, HIGH);
  delay(2000);
  fromSlot = 6;

  
  // The griper is under the magazine, and without a battery:
  if (((digitalRead(limSwitchUnderMagazine1) == LOW) || (digitalRead(limSwitchUnderMagazine2) == LOW)) && (digitalRead(limSwitchInGriper) == HIGH)) {
    griperLock(HIGH, HIGH);
    var = 1;
    
  }
  // The griper is under the magazine, with a battery: 
  if (((digitalRead(limSwitchUnderMagazine1) == LOW) || (digitalRead(limSwitchUnderMagazine2) == LOW)) && (digitalRead(limSwitchInGriper) == LOW)) { 
    var = 2;
  }
  // The griper is clear of the magazine, and without a battery: 
  if (((digitalRead(limSwitchUnderMagazine1) == HIGH) && (digitalRead(limSwitchUnderMagazine2) == HIGH)) && (digitalRead(limSwitchInGriper) == HIGH)) {
    griperLock(HIGH, HIGH);
    var = 3;
  }
  // The griper is clear of the magazine, with a battery:
  if (((digitalRead(limSwitchUnderMagazine1) == HIGH) && (digitalRead(limSwitchUnderMagazine2) == HIGH)) && (digitalRead(limSwitchInGriper) == LOW)) {
    var = 4;
  }
  delay(50);
  
  
  
  switch(var) {
    case 1: // The griper is under the magazine, and without a battery:
      
      calibrateVar1();
      break;
     
    case 2: // The griper is under the magazine, with a battery:
      
      calibrateVar2();
      break;
    
    case 3: // The griper is clear of the magazine, and without a battery:
    
      calibrateVar3();
      break;
    
    case 4: // The griper is clear of the magazine, with a battery:
    
      calibrateVar4();
      break;
  }
 

  
}


