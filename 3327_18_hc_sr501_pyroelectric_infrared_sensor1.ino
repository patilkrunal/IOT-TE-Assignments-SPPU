int LED = 13;
int PIRPin = 12;
int isObstacle = LOW;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(PIRPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  isObstacle = digitalRead(PIRPin);
  if (isObstacle == HIGH)
  {
    digitalWrite(LED, HIGH);
    Serial.println("Obstacle detected!");
  }
  else
  {
    Serial.println("Clear!");
    digitalWrite(LED, LOW);
  }
  delay(100); // Wait for 10 millisecond(s)
}