/* 
This function takes input for controlling the "Griper Robot". 

Descrition for input:

movementDirection:   HIGH - forward / LOW - backward
movementSpeed:       min value: 200 (?) --> fast
                     max value: 2000 (?) --> slow
distance:            distance for travle in MICROmeter (1mm = 1000 micrometer)                 
*/ 

void griperMove(int movementDirection, int movementSpeed, double distance) {
  griperStatus = 0; 
  int loops;
  double numberOfPulses = 10;
    numberOfPulses = (distance / 8) ;
 
  
  for (int i = 0; i <= numberOfPulses; i++) {
    numberOfPulses = (distance / 8) ; // NOT CALIBRATED! 
    
    // Failsafe:
    if ((digitalRead(limSwitchBack) == HIGH) && (digitalRead(limSwitchFront) == HIGH)) {
    // Moveing the griper:
      digitalWrite(dirPin, movementDirection);
      digitalWrite(pulPin, HIGH);
      digitalWrite(pulPin, LOW);
      delayMicroseconds(movementSpeed);
    }
    
    
  }
  
  griperStatus = 1; 
  
}



/* 
void limSwitchState() { 
  
  if (digitalRead(limSwitchBack) == LOW) { limSSBack = LOW; } 
    else { (limSSBack = HIGH); }
  if (digitalRead(limSwitchFront) == LOW) { limSSFront = LOW; } 
    else { (limSSFront = HIGH); }
}

*/
  

