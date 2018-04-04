
/* 
This function takes input for locking/opening the griper. 

Descrition for input:

griperStatus:     HIGH - Open griper / LOW - Lock griper
          
*/ 


void griperLockOrOpen(int griperStatus) {
  if (griperStatus == HIGH){
    gripLeft.write(0);
    gripRight.write(180);
    delay(500);
  }
  if (griperStatus == LOW){
    gripLeft.write(100);
    gripRight.write(80);
    delay(500);
  }
  
}

