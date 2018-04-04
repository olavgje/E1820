/* 
This function takes input for controlling the "Speed of the robots". 
The stepper motor is rotating 1.8 degrees / step.

Descrition for input:

                
*/ 

int speedAlgorithm(double distance, double i) {
  double numberOfPulses = (distance / 10);
  float RPSspeed;
  int pulsSpeed; 
  
  int A = 300; 
  float k = (3.1415/numberOfPulses);
  int d = 8; // (Min speed) 

  RPSspeed = A*sin(k*i) + d;
  if (RPSspeed >= 25 ) { RPSspeed = 25 ; }
  pulsSpeed = 1000000/(RPSspeed*200);  
    
  return pulsSpeed;

}
