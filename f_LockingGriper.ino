/* 
This function takes input for locking/opening the griper. 

Descrition for input:

griperStatus:     HIGH - Open griper / LOW - Lock griper
          
*/ 

void griperLock(int batteryChanged) {

  if ((digitalRead(limSwitchInGriper == LOW)) && (batteryChanged == LOW)){
    gripLeft.write(90);
    gripRight.write(80);
    delay(500);
  }
  if (batteryChanged == HIGH)  {
    gripLeft.write(0);
    gripRight.write(180);
    delay(500);
  }  
}
