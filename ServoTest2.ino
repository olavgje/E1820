#include <Servo.h>
// Make code in Servo.h available to this sketch  
  
Servo servo1; Servo servo2; 
int limSwitchPin = 2;
int limSwitchState;

void setup() {

  pinMode(1,OUTPUT);
  pinMode(2,INPUT);
  servo1.attach(14); //analog pin 0
  //servo1.setMaximumPulse(2000);
  //servo1.setMinimumPulse(700);

  servo2.attach(15); //analog pin 1
  Serial.begin(9600);
  Serial.println("Ready");

}

void loop()   { 
  limSwitchState = digitalRead(limSwitchPin);
  if (limSwitchState == HIGH) { 
    delay(500);
    servo1.write(0);
    servo2.write(180);
  }
  
  if (limSwitchState == LOW) {  
    delay(500);
    servo1.write(90);
    servo2.write(90);
  }

  Serial.println(digitalRead(limSwitchPin));
 
}
