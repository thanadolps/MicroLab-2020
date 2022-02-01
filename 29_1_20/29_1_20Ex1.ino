#define clk_pin_1 6
#define latch_pin_1 4
#define data_pin_1 5
#define clk_pin_2 11
#define latch_pin_2 9
#define data_pin_2 10
bool toggle;
void setup()
{
  pinMode(clk_pin_1,OUTPUT);
  pinMode(latch_pin_1,OUTPUT);
  pinMode(data_pin_1,OUTPUT);
  pinMode(clk_pin_2,OUTPUT);
  pinMode(latch_pin_2,OUTPUT);
  pinMode(data_pin_2,OUTPUT);
}

void loop()
{
  digitalWrite(latch_pin_1,LOW);
  digitalWrite(latch_pin_2,LOW);
  for(int i=0;i<8;i++){
    digitalWrite(data_pin_1,toggle);
    digitalWrite(clk_pin_1,HIGH);
    digitalWrite(clk_pin_1,LOW);

    digitalWrite(data_pin_2,toggle);
    digitalWrite(clk_pin_2,HIGH);
    digitalWrite(clk_pin_2,LOW);
    toggle=!toggle;
  }

  digitalWrite(latch_pin_1,HIGH);
  digitalWrite(latch_pin_2,HIGH);
  toggle=!toggle;
  delay(1000);
}
