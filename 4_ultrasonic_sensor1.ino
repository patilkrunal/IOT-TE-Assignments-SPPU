// Ultrasonic sensor

const int pingPin = 7;
const int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  long duration, cm;
  // The Ping is triggered by a HIGH pulse of 2 or more microsecond
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse
  
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delay(200);
  digitalWrite(pingPin, HIGH);
  delay(500);
  digitalWrite(pingPin, LOW);
  
  // The same pin is used to read the signal from the PING; a
  // pulse whose duration is the time (in microseconds) from the 
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  
  cm = duration/29/2;
  
  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  if(cm < 100) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(10);
}