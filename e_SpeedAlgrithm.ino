/* 
This function takes input for controlling the "Speed of the robots". 
The stepper motor is rotating 1.8 degrees / step.

Descrition for input:

                
*/ 

int speedAlgorithm(double totalDistance, double i) {
  double numberOfPulses = (totalDistance / 10);
  float RPSspeed;
  int pulsSpeed; 
  
  int A = 100; 
  float k = (3.1415/numberOfPulses);
  int d = 10; // (Min speed) 

  if (i > (numberOfPulses - 3000)) {
    A = 100;
  }

  RPSspeed = A*sin(k*i) + d;
  if (RPSspeed >= 25 ) { RPSspeed = 25 ; }
  
  pulsSpeed = 1000000/(RPSspeed*200);  

    
  return pulsSpeed;

}
