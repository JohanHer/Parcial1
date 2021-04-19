void ledWrite(int Led){
  shiftOut (2, 4, LSBFIRST, Led);
  shiftOut (8, 10, LSBFIRST, Led);
  digitalWrite(3, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(9, LOW);
}  


void setup(){
   pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
  
   pinMode(8, OUTPUT);
   pinMode(9, OUTPUT);
   pinMode(10, OUTPUT);
  
}

void loop(){
  ledWrite(B11111111);
}