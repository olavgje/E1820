
void setup() {
  
  droneLock(LOW, LOW);
  griperLock(HIGH, HIGH);
  
// General   
  Serial.begin(9600);
  
// GriperRobot:
  pinMode(pulPinGriper, OUTPUT);
  pinMode(dirPinGriper, OUTPUT);
  pinMode(enblPinGriper, OUTPUT);
  pinMode(limSwitchBack, INPUT);
  pinMode(limSwitchFront, INPUT);
  
  digitalWrite(pulPinGriper, LOW);
  digitalWrite(enblPinGriper, LOW);
  digitalWrite(dirPinGriper, LOW);

  digitalWrite(enblPinGriper, HIGH);
  delay(100);
  digitalWrite(enblPinGriper, HIGH);
  
  pinMode(limSwitchBack, INPUT);
  pinMode(limSwitchFront, INPUT);
  pinMode(limSwitchUnderMagazine1, INPUT);
  pinMode(limSwitchUnderMagazine2, INPUT);

// MagazineRobot: 
  pinMode(pulPinMagazine, OUTPUT);
  pinMode(dirPinMagazine, OUTPUT);
  pinMode(enblPinMagazine, OUTPUT);
  
  digitalWrite(pulPinMagazine, LOW);
  digitalWrite(enblPinMagazine, LOW);
  digitalWrite(dirPinMagazine, LOW);

  digitalWrite(enblPinMagazine, HIGH);
  delay(100);
  digitalWrite(enblPinMagazine, HIGH);  
  
  pinMode(limSwitchLeft, INPUT);
  pinMode(limSwitchRight, INPUT);
  
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
  
  calibration();

}
