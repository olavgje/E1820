
void setup() {
  
// General   
  Serial.begin(9600);
  
// GriperRobot:
  pinMode(pulPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enblPin, OUTPUT);
  pinMode(limSwitchBack, INPUT);
  pinMode(limSwitchFront, INPUT);
  
  digitalWrite(pulPin, LOW);
  digitalWrite(enblPin, LOW);
  digitalWrite(dirPin, LOW);

  digitalWrite(enblPin, HIGH);
  delay(100);
  digitalWrite(enblPin, HIGH);
  
}
