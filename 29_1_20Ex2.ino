#define clk_pin 6
#define latch_pin 4
#define data_pin 5
bool toggle;
int count=0;

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
}

void loop() {
  setLED(0b0000000000000001<<count);
  
  if(digitalRead(8)==0){
    count++;
    delay(100);
  }
  if(digitalRead(9)==0){
    count--;
    delay(100);
  }
  
}
