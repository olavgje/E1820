/* 
This function uses input for locking/opening the griper. 

Descrition for input:
inGriper:     LOW - Battery in griper              / HIGH - No battery in griper
lockBattery:  HIGH - Lock battery in griper        / LOW - Release battery from griper
          
*/ 

void griperLock(int inGriper, int lockBattery) {

  if (inGriper == LOW && lockBattery == HIGH){
    gripLeft.write(95);
    gripRight.write(48);
  }
  else {
    gripLeft.write(0);
    gripRight.write(160);
  }  
}
