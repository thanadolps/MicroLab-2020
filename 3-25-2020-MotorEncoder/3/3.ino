volatile long count = 0;

const int B_PIN = 4;

void setup()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  
  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(2), countIt, RISING);
}

void countIt() {
  count += digitalRead(B_PIN) ? -1 : 1;
}

void loop()
{
  Serial.println(count);
  delay(100);
}