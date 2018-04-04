/* 
This function takes input for controlling the "Griper Robot". 

Descrition for input:

movementDirection:   LOW - forward / HIGH - backward
distance:            distance for travle in MICROmeter 
constSpeed:          HIGH - constant speed / LOW - speed algorithm
*/ 

void griperMove(int movementDirection, double distance) {
  griperRobotStatus = 0; 
  int pulsSpeed;
  
  long previousMicros = 0;
  
  double numberOfPulses = 10;
  numberOfPulses = ((distance) / 10) ;

 
  
  for (double i = 0; i <= numberOfPulses; 0) {
    numberOfPulses = ((distance) / 10) ; 
     
    if ((i < 3000) || (i > (numberOfPulses - 3000))) {
      pulsSpeed = speedAlgorithm(distance, i); 
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
  
  griperRobotStatus = 1; 
  
}

