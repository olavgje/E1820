
/*
This program is created for discharging a three celled LiPo-battery down to 50% capasity and then stop the draining. 
50% is equal to 3.87V (from fabric)
100% is equal to 4.20V

*/ 

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int relayPin = 13;
int startPin = 8;
int batteryVoltagePin = 5;

void setup() {
  
  Serial.begin(9600);
  lcd.begin(16,2);
 
  pinMode(relayPin, OUTPUT);
  pinMode(startPin, INPUT);
  pinMode(batteryVoltagePin, INPUT);
  
  lcd.print("Trykk start-");
  lcd.setCursor(0,1);
  lcd.print("knappen");

}

void loop() {
  
  int analogVoltage = analogRead(batteryVoltagePin);
  float batteryVoltage = analogVoltage * (5.06 / 1024.0);
  delay(1000);
  digitalWrite(relayPin, HIGH);
  
  if (digitalRead(startPin) == HIGH){
    batteryVoltage = 5;
  }
  if (batteryVoltage >= 3.87) {
    digitalWrite(relayPin, HIGH);
    lcd.clear();
    lcd.print("Celle-spenning:");
    lcd.setCursor(0,1);
    lcd.print(batteryVoltage);
  }
  else {
    digitalWrite(relayPin, LOW);
    lcd.clear();
    lcd.print("Celle-spenning:");
    lcd.setCursor(0,1);
    lcd.print(batteryVoltage);
  }
  
  Serial.println(batteryVoltage);
  

}
