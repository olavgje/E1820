/*
This function calibrates the rigg.

*/

void calibration(){
  
  if (digitalRead(limSwitchUnderMagazine) == LOW) {
    while (digitalRead(limSwitchBack) == HIGH) {
      griperMove(HIGH, 100, HIGH);
    }
  }
  delay(2000);
  if (digitalRead(limSwitchBack) == LOW) {
    griperMove(LOW, 50, LOW);
    griperMove(LOW, 50, LOW);
    griperMove(LOW, 10000, LOW);
    // 35000 normal
  }


}
