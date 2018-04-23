/* 
This function takes input for controlling the "Griper Robot". 

Descrition for input:

movementDirection:   LOW - forward / HIGH - backward
distance:            distance for total travle in X times 100 millimeter, 140 mm = 14 000 
softStartDistance:   distance for soft start in X times 100 millimeter
softEndDistance:     distance for soft end in X times 100 millimeter 

*/ 

void griperMove(int movementDirection, double totalDistance, double softStartDistance, double softEndDistance ) {
  int pulsSpeed = 250;
  
  long previousMicros = 0;
  
  double numberOfPulses = 10;
  numberOfPulses = (totalDistance);

 
  
  for (double i = 0; i <= numberOfPulses; 0) {
    numberOfPulses = (totalDistance) ; 
    
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

/*
Distances: 
Standby position - drone :   14 850 pulses
Standby position - magazine: 17 500 pulses
Magazine - limitSwitchBack:  15 500 pulses

Standby position - limSwitchUmderMagazine2: 4100 pulses
*/


  

