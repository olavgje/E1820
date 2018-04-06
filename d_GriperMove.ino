/* 
This function takes input for controlling the "Griper Robot". 

Descrition for input:

movementDirection:   LOW - forward / HIGH - backward
distance:            distance for total travle in MICROmeter 
softStartDistance:   distance for soft start in ??
softEndDistance:     distance for soft end in ?? 

*/ 

void griperMove(int movementDirection, double totalDistance, double softStartDistance, double softEndDistance ) {
  int pulsSpeed;
  
  long previousMicros = 0;
  
  double numberOfPulses = 10;
  numberOfPulses = ((totalDistance) / 10) ;

 
  
  for (double i = 0; i <= numberOfPulses; 0) {
    numberOfPulses = ((totalDistance) / 10) ; 
     
    if ((i < softStartDistance) || (i > (numberOfPulses - softEndDistance))) {
      pulsSpeed = speedAlgorithm(totalDistance, i); 
    }

    
    unsigned long currentMicros = micros();
    if ((currentMicros - previousMicros) > pulsSpeed) {
      previousMicros = currentMicros;
      i = i+1;
    
      // Failsafe:
      
      if (((digitalRead(limSwitchBack) == LOW) && (movementDirection == LOW)) || ((digitalRead(limSwitchFront) == LOW) && (movementDirection == HIGH)) || ((digitalRead(limSwitchBack) == HIGH) && (digitalRead(limSwitchFront) == HIGH)))  { 
        // Moveing the griper:
        digitalWrite(dirPinGriper, movementDirection);
        digitalWrite(pulPinGriper, HIGH);
        digitalWrite(pulPinGriper, LOW);      
      }
      if ((digitalRead(limSwitchBack) == LOW) && (movementDirection == HIGH)){ 
        delay(50);
        break; 
      }
    
    
    }
    
    
  }
  
  
}


  

