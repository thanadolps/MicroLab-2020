void setup()
{
  DDRD = 0b11111111;
  DDRB = 0b00000011;
  PORTD=0b00010000;
}

void loop()
{
  if(digitalRead(8)==1){
    PORTD = PORTD >> 1;
    while(digitalRead(8)==1){delay(100);}
  }
  if(digitalRead(9)==1){
    PORTD = PORTD << 1;
    while(digitalRead(9)==1){delay(100);}
  }
}
