/*
This program tells where it is an open slot
Every analog signal from the chargers will have a max voltage = 4,2V
*/

/*
GLOBAL
  int charger1 = 60;            //analog pin 6
  int charger2 = 61;            //analog pin 7
  int charger3 = 62;            //analog pin 8
  int charger4 = 63;            //analog pin 9
  int charger5 = 64;            //analog pin 10
SETUP
  pinMode(charger1, INPUT);
  pinMode(charger2, INPUT);
  pinMode(charger3, INPUT);
  pinMode(charger4, INPUT);
  pinMode(charger5, INPUT);
*/

int openSlot() {
  int openCharger;
  if (analogRead(6) == 0) { openCharger = 1; }
  if (analogRead(7) == 0) { openCharger = 2; }
  if (analogRead(8) == 0) { openCharger = 3; }
  if (analogRead(9) == 0) { openCharger = 4; }
  if (analogRead(10) == 0) { openCharger = 5; }
  return openCharger;
}

