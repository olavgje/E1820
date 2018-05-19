/* 
This function uses input for controlling the speed of the robot as a sin-curve with limitations for max and min speed.

Descrition for inputs:

totalDistance:  Distance for total travle in A times 100 millimeter, 140mm = 14 000
i:              Number of run-through from function "d_GriperMove".
                
*/ 

int speedAlgorithm(double totalDistance, double i) {
  double numberOfPulses = (totalDistance);
  float RPSspeed;
  int pulsSpeed; 
  
  int A = 50; 
  float k = (3.1415/numberOfPulses);
  int d = 10; // (Min speed) 

  RPSspeed = A*sin(k*i) + d;
  if (RPSspeed >= 25 ) { RPSspeed = 25 ; }
  
  pulsSpeed = 1000000/(RPSspeed*200);  
 
  return pulsSpeed;

}
