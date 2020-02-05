void setup()
{
  DDRD = 0b11111111;
  
}

void loop(){
  PORTD = 0b10000000;
  delay(1000);
  for(int i=0;i<8;i++){  
    PORTD = PORTD>>1;
    delay(1000);
  }
}
