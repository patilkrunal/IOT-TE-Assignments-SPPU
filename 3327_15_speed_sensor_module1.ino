#define pinLed 3
#define pinPot A0

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinPot, INPUT );
  
}

void loop() {
  byte value = analogRead(pinPot)/4;
  analogWrite(pinLed,value);
  delay(10);
}