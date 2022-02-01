#define clk_pin 6
#define latch_pin 4
#define data_pin 5
#define vari A0
bool toggle;
int count=0;
int timer;
int hold=0;
void setLED(uint16_t x) {
  digitalWrite(latch_pin,LOW);
  for(int i=0;i<16;i++){   
    digitalWrite(data_pin,(x>>(15-i) & 0x0001));
    
    digitalWrite(clk_pin,HIGH);
    digitalWrite(clk_pin,LOW);
  }
  digitalWrite(latch_pin,HIGH);
}

void setup() {
  pinMode(clk_pin,OUTPUT);
  pinMode(latch_pin,OUTPUT);
  pinMode(data_pin,OUTPUT);
  
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(vari,INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(8)==1)
    hold=2;
  if(digitalRead(9)==1)
    hold=1;
  
  timer=analogRead(vari);
  Serial.print(timer);
  Serial.println();
  switch(hold){
    case 1:{for(int i=0;i<16;i++){
    			setLED(0b0000000000000001<<i);
      			delay(timer);
      			if(digitalRead(8)==1){
        			hold=2;
        			break;
      			}
    		}
           break;}
    case 2:{for(int i=0;i<16;i++){
    			setLED(0b1000000000000000>>i);
      			delay(timer);
      			if(digitalRead(9)==1){
        			hold=1;
        			break;
      			}
    }
           break;}
  }
}
