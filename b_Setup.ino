
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
  
// Locking-mechanism for the griper:
  pinMode(limSwitchInGriper, INPUT);
  gripLeft.attach(54);            //analog pin 0
  gripRight.attach(55);           //analog pin 1

// LandingPlatform: 
  pinMode(limSwitchFL, INPUT);
  pinMode(limSwitchFR, INPUT);
  pinMode(limSwitchBL, INPUT);
  pinMode(limSwitchBR, INPUT);
  landingPlatformFL.attach(56);   //analog pin 2
  landingPlatformFR.attach(57);   //analog pin 3
  landingPlatformBL.attach(58);   //analog pin 4
  landingPlatformBR.attach(59);   //analog pin 5
  
// Testbutton:
  pinMode(buttonPin, INPUT);
}
