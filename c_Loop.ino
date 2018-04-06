void loop() { 
  
  if (digitalRead(limSwitchFront) == LOW) {
    delay(2000);
    magazineMove(3);
    delay(1000);
    griperLock(LOW, HIGH);
    delay(1000);
    griperMove(HIGH, 173000, 70000, 100000);
    delay(500);
    griperLock(LOW, LOW);
    delay(5000);
    griperMove(HIGH, 157000, 30000, 30000); 
    delay(5000);
    griperMove(LOW, 157000, 30000, 30000);
    delay(3000);
    griperLock(LOW, HIGH);
    delay(3000);
    griperMove(LOW, 173000, 70000, 100000);
    
  }
  

}



