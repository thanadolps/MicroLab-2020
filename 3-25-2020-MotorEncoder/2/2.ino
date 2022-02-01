long count = 0;

void setup()
{
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(2), countIt, RISING);
}

void countIt() {
	count++;
}

void loop()
{
  Serial.println(count);
  delay(100);
}