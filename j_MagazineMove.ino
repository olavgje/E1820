/*
This function uses input for controlling the magazine robot. 

Description for input: 
toSlot:   What slot the magazine should move to.

Distances in pulses from different slots:
6-5:  6770      6-5:  6770        
6-4: 13690      5-4:  6920         
6-3: 20600      4-3:  6910          
6-2: 27540      3-2:  6940          
6-1: 34500            6900  
*/

void magazineMove(int toSlot) {
  int movementDirection;
  double numberOfPulses;

  
  delay(50);
  if ((fromSlot - toSlot) > 0) {
    movementDirection = LOW;
  }
  delay(50);

  if ((fromSlot - toSlot) < 0) {
    movementDirection = HIGH;
  }
  delay(50);

  if ((fromSlot - toSlot) == 0) {
    numberOfPulses = 0;
  }
  
  if (fromSlot == 6) {
    movementDirection = LOW;
  }
  delay(50);


  if ((fromSlot == 6 && toSlot == 1) || (fromSlot == 1 && toSlot == 6)) { numberOfPulses = 34500; }   
  if ((fromSlot == 6 && toSlot == 2) || (fromSlot == 2 && toSlot == 6)) { numberOfPulses = 27540; }   
  if ((fromSlot == 6 && toSlot == 3) || (fromSlot == 3 && toSlot == 6)) { numberOfPulses = 20600; }  
  if ((fromSlot == 6 && toSlot == 4) || (fromSlot == 4 && toSlot == 6)) { numberOfPulses = 13690; } 
  if ((fromSlot == 6 && toSlot == 5) || (fromSlot == 5 && toSlot == 6)) { numberOfPulses = 6770; }   
  if ((fromSlot == 5 && toSlot == 1) || (fromSlot == 1 && toSlot == 5)) { numberOfPulses = 27730; }   
  if ((fromSlot == 5 && toSlot == 2) || (fromSlot == 2 && toSlot == 5)) { numberOfPulses = 20770; }   
  if ((fromSlot == 5 && toSlot == 3) || (fromSlot == 3 && toSlot == 5)) { numberOfPulses = 13830; }   
  if ((fromSlot == 5 && toSlot == 4) || (fromSlot == 4 && toSlot == 5)) { numberOfPulses = 6920; }    
  if ((fromSlot == 4 && toSlot == 1) || (fromSlot == 1 && toSlot == 4)) { numberOfPulses = 20800; }   
  if ((fromSlot == 4 && toSlot == 2) || (fromSlot == 2 && toSlot == 4)) { numberOfPulses = 13850; }   
  if ((fromSlot == 4 && toSlot == 3) || (fromSlot == 3 && toSlot == 4)) { numberOfPulses = 6910; }    
  if ((fromSlot == 3 && toSlot == 1) || (fromSlot == 1 && toSlot == 3)) { numberOfPulses = 13830; }   
  if ((fromSlot == 3 && toSlot == 2) || (fromSlot == 2 && toSlot == 3)) { numberOfPulses = 6940; }    
  if ((fromSlot == 2 && toSlot == 1) || (fromSlot == 1 && toSlot == 2)) { numberOfPulses = 6900; }    

  delay(50);

  if (((digitalRead(limSwitchUnderMagazine1)) == HIGH) && ((digitalRead(limSwitchUnderMagazine2)) == HIGH)) {
    for (double i = 0; i <= numberOfPulses; i++) {
      if (((digitalRead(limSwitchLeft) == LOW) && (movementDirection == LOW)) || ((digitalRead(limSwitchRight) == LOW) && (movementDirection == HIGH)) || ((digitalRead(limSwitchLeft) == HIGH) && (digitalRead(limSwitchRight) == HIGH))) {
        digitalWrite(dirPinMagazine, movementDirection);
        digitalWrite(pulPinMagazine, HIGH);
        digitalWrite(pulPinMagazine, LOW);   
        delayMicroseconds(300);
      }
    
      if ((digitalRead(limSwitchLeft) == LOW) && (movementDirection == HIGH)){ 
        delay(50);
        break;
      }
    }
  }
  delay(50);
  
  fromSlot = toSlot;

  if ((digitalRead(limSwitchRight) == LOW)) { 
    calibration(); 
  }
  


}
