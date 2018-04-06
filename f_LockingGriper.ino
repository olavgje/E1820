/* 
This function takes input for locking/opening the griper. 
Descrition for input:
inGriper:     HIGH - Battery in griper              / LOW - No battery in griper
lockBattery:  HIGH - Hold battery in griper         / LOW - Release battery from griper
          
*/ 

void griperLock(int inGriper, int lockBattery) {

  if (inGriper == LOW && lockBattery == HIGH){
    gripLeft.write(95);
    gripRight.write(50);
  }
  else {
    gripLeft.write(0);
    gripRight.write(160);
  }  
}
