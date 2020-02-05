int t=0;
int timer;
void setup()
{
  DDRD = 0b11111111;
  DDRB = 0b00000011;
  pinMode(A0,INPUT);
}

void loop()
{
  if(digitalRead(8)==1){
    t=1;
    while(digitalRead(8)==1){delay(100);}
  }
  if(digitalRead(9)==1){
    t=2;
    while(digitalRead(9)==1){delay(100);}
  }
  timer = analogRead(A0);
  
  switch(t){
    case 1: PORTD = 0b10000000;
        for(int i=0;i<8;i++){
            PORTD = PORTD >> 1;
              delay(timer);
        }
        break;
    case 2: PORTD = 0b00000001;
        for(int i=0;i<8;i++){
              PORTD = PORTD << 1;
              delay(timer);
        }
        break;
  }
}
