#include <IRremote.h>

int IR_Recv_PIN = 2;   //IR Receiver Pin 3

IRrecv irrecv(IR_Recv_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);  //starts serial communication
  irrecv.enableIRIn(); // Starts the receiver
}

void loop(){
  //decodes the infrared input
  if (irrecv.decode(&results)){
    Serial.println(results.value, HEX);
    //switch case to use the selected remote control button
    switch (results.value){
      case 0xFD08F7: //when you press the 1 button
        analogWrite(13, 255);
        break;
      
      case 0xFD8877: //when you press the 2 button
        analogWrite(13, 0);     // red dot is off
        break;
    }
    irrecv.resume(); // Receives the next value from the button you press
  }
  delay(10);
}