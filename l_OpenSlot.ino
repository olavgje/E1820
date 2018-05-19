/*
This program returns what slot that is an open slot.
*/


int openSlot() {
  int openCharger;
  if (analogRead(7) < 100) { openCharger = 2; }
  if (analogRead(8) < 100) { openCharger = 3; }
  if (analogRead(9) < 100) { openCharger = 4; }
  if (analogRead(10) < 100) { openCharger = 5; }

  if ((analogRead(7) > 100) && (analogRead(8) > 100) && (analogRead(9) > 100) && (analogRead(10) > 100)){
    openCharger = 6; 
  }
    
  return openCharger;
}

