// C++ code
//
void setup(){
}

void loop(){
  for(int thisnote = 1000; thisnote < 1200; thisnote += 20){
    int duration = 500;
    tone(8, thisnote, duration);
    int pause = duration * 1.3;
    delay(pause);   
    noTone(8);
  }
}