int clk_pin=13;
int latch_pin=10;
int data_pin=11;
int num=1;
int digitArray[16]={
  0b00111111, //0
    0b00000110, //1
    0b01011011, //2
    0b01001111, //3
    0b01100110, //4
    0b01101101, //5
    0b01111101, //6
    0b00000111, //7
    0b01111111, //8
    0b01101111, //9
    0b01110111, //A
    0b01111100, //B
    0b00111001, //C
    0b01011110, //D
    0b01111001, //E
    0b01110001  //F
};
int x=0;
void setLed(uint8_t _state){
  digitalWrite(latch_pin,LOW);
  for(int i=0;i<8;i++){
    digitalWrite(data_pin, (_state>>(7-i))&0x01);
    digitalWrite(clk_pin,HIGH);
    digitalWrite(clk_pin,LOW);
  }
  digitalWrite(latch_pin,HIGH);
}
void setup()
{
  Serial.begin(9600);
  pinMode(clk_pin,OUTPUT);
  pinMode(latch_pin,OUTPUT);
  pinMode(data_pin,OUTPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  
}

void loop()
{
  if(digitalRead(5)==0){
    x = (x+1)%16;
    Serial.println(x);
  setLed(digitArray[x]);
    while(digitalRead(5)==0){delay(10);}
  }
  if(digitalRead(4)==0){
    x = abs(x-1) % 16;
    Serial.println(x);
  setLed(digitArray[x]);
    while(digitalRead(4)==0){delay(10);}
  }
  delay(100);
}
