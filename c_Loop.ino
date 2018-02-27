void loop() {

  
  if (digitalRead(buttonPin) == HIGH) {
    griperMove(HIGH, 30000); 
    delay(5000);
    griperMove(LOW, 30000);
    delay(5000);
  }
  
 
 
    
}
