/* 
This function takes input for controlling the "Griper Robot". 

Descrition for input:

movementDirection:   HIGH - forward / LOW - backward
distance:            distance for travle in mm                
*/ 

void griperMove(int movementDirection, double distance) {
  griperStatus = 0; 
  int pulsSpeed;
  
  long previousMicros = 0;
  
  double numberOfPulses = 10;
  numberOfPulses = ((distance) / 10) ;

 
  
  for (double i = 0; i <= numberOfPulses; 0) {
    numberOfPulses = ((distance) / 10) ; 
      
    // SpeedAlgorithm:
    if ((i < 3000) || (i > (numberOfPulses - 3000))) {
    pulsSpeed = speedAlgorithm(distance, i); 
    }
    
    unsigned long currentMicros = micros();
    if ((currentMicros - previousMicros) > pulsSpeed) {
      previousMicros = currentMicros;
      i = i+1;
    
      // Failsafe:
      if ((digitalRead(limSwitchBack) == HIGH) && (digitalRead(limSwitchFront) == HIGH)) {
         
        // Moveing the griper:
        digitalWrite(dirPin, movementDirection);
        digitalWrite(pulPin, HIGH);
        digitalWrite(pulPin, LOW);      
    }
    
    }
    
    
  }
  
  griperStatus = 1; 
  
}


  

