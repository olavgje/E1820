/*
This program returns the most charged battery.
Every analog signal from the chargers will have a max voltage = 4,2V.
*/



int chargedBattery() {

int sum2 = 0;
int sum3 = 0;
int sum4 = 0;
int sum5 = 0;

  for (int i = 0; i <= 10 ; i++) {
    int a = analogRead(charger2);
    sum2 = sum2 + a;
  }
  
  for (int i = 0; i <= 10 ; i++) {
    int b = analogRead(charger3);
    sum3 = sum3 + b;
  }

  for (int i = 0; i <= 10 ; i++) {
    int c = analogRead(charger4);
    sum4 = sum4 + c;
  }

  for (int i = 0; i <= 10 ; i++) {
    int d = analogRead(charger5);
    sum5 = sum5 + d;
  }
  
  
  int mostChargedBatterySum = sum2; 
  int mostChargedBattery = 2; 

  if ((sum3) > (mostChargedBatterySum)) { 
    mostChargedBatterySum = sum3;
    mostChargedBattery = 3;
  }
  if ((sum4) > (mostChargedBatterySum)) { 
    mostChargedBatterySum = sum4; 
    mostChargedBattery = 4;
  }
  if ((sum5) > (mostChargedBatterySum)) {
    mostChargedBatterySum = sum5; 
    mostChargedBattery = 5;
  }

  return mostChargedBattery;
}


