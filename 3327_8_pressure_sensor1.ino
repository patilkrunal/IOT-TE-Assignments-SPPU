int LED = 13;
int ForcePin = A1;
int ForceValue = 0;
 
void setup(void) {
  Serial.begin(9600); 
  pinMode(ForcePin, INPUT);
  pinMode(LED, OUTPUT);
}
 
void loop(void) {
  ForceValue = analogRead(ForcePin);
  Serial.println(ForceValue);
 
  analogWrite(LED, ForceValue/2);
 
  delay(100);
}