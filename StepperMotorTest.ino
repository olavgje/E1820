int pulPin = 10;
int dirPin = 11;
int enblPin = 12;
int ledPin = 13;
int limSwitchBack = 51;
int limSwitchFront = 50;



int loopsF = 0;
int loopsB = 0;
int stepDelay = 300; //microseconds
int limSS;
int prevSS;

void setup() {
  // put your setup code here, to run once:
  pinMode(pulPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enblPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(limSwitchBack, INPUT);
  pinMode(limSwitchFront, INPUT);
  
  digitalWrite(pulPin, LOW);
  digitalWrite(ledPin, LOW);
  digitalWrite(enblPin, LOW);
  digitalWrite(dirPin, LOW);
  
  
  digitalWrite(enblPin, HIGH);
  delay(100);
  digitalWrite(enblPin, HIGH);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  prevSS = limSS;
  limSwitchState();
  if (limSS == LOW) {
    if (prevSS != limSS) {
     delay(500);
     loopsF = 0;
    } 
    stepperForward();
//    loopsF = loopsF+1;
//    Serial.println(loopsF);
  }
  if (limSS == HIGH) {
    if (prevSS != limSS) {
     delay(500);
    } 
    stepperBack();
  }
  
}

void stepperForward() {
  digitalWrite(dirPin, HIGH);
  digitalWrite(pulPin, HIGH);
  digitalWrite(pulPin, LOW);
  
  delayMicroseconds(stepDelay);
}

void stepperBack() {
  digitalWrite(dirPin, LOW);
  digitalWrite(pulPin, HIGH);
  digitalWrite(pulPin, LOW);
  
  delayMicroseconds(stepDelay);
}

void limSwitchState() {
  if (digitalRead(limSwitchBack) == LOW) {
    limSS = LOW;
  }
  if (digitalRead(limSwitchFront) == LOW) {
    limSS = HIGH;
  }
}
 
