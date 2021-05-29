/* Some hardware and accelerometer code reused from a circuit by ShawnHymel*/



//Declare LEDS to pins
#define L1 9
#define L2 8
#define L3 7
#define L4 6
#define L5 5
#define L6 4
#define L7 3

const int x_pin = A0;

int calibrated = 512;
// Volts per G-Force
const float sensitivity = 0.206;
void cal ();

void setup() {
  analogReference(EXTERNAL);
  Serial.begin(9600);
  //Set up button for interrupt
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), cal, FALLING);
  
  //Set up LED pins
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
  pinMode(L7, OUTPUT);
}

void loop() {

  float x;
  Serial.println(analogRead(x_pin));
  // Read pins and convert to G
  x = (analogRead(x_pin) - calibrated)*3.3/(sensitivity*1023);

  // Display acceleration
  Serial.print("x: ");
  Serial.print(x);

  digitalWrite(L1, LOW); 
  digitalWrite(L2, LOW); 
  digitalWrite(L3, LOW); 
  digitalWrite(L4, LOW); 
  digitalWrite(L5, LOW); 
  digitalWrite(L6, LOW); 
  digitalWrite(L7, LOW); 
  
  if (x>-0.2 && x<0.2){
  digitalWrite(L4, HIGH);   
  }
  else if (x>0.8){
    digitalWrite(L6, HIGH);
    digitalWrite(L7, HIGH);
  }
  else if (x<-0.8){
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH); 
  }
  else if (x>-0.2 && x>-0.8){
  digitalWrite(L3, HIGH);   
  }
  else if (x>0.2 && x<0.8){
  digitalWrite(L5, HIGH);   
  }

  delay(100);
}

void cal(){
calibrated = analogRead(x_pin);
}