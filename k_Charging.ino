/*
This program chooses the most charged battery

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

int chargedBattery() {
  int chosenBattery = 1;
  int previ = 0;
  int chargers[] = { analogRead(charger1), analogRead(charger2), analogRead(charger3), analogRead(charger4), analogRead(charger5) };

  for ( int i = 1; i <= 4; i++) {
    if (chargers[i] > chargers[previ]) {
      previ = i+1;
    }
    delay(50);
  }
  chosenBattery = previ;
  
  return chosenBattery;
}

