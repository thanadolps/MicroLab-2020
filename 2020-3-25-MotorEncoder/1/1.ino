class DcMotor {
private:
  int enableA, enableB, speedPin;
  bool rotation = true;
public:
  DcMotor(int enableA, int enableB, int speedPin) {
  	this->enableA = enableA;
    this->enableB = enableB;
    this->speedPin = speedPin;
    this->rotation = true;
    
    pinMode(enableA, OUTPUT);
    pinMode(enableB, OUTPUT);
    pinMode(speedPin, OUTPUT);
    
    digitalWrite(this->enableA, HIGH);
    digitalWrite(this->enableB, LOW);
  }
  
  void setSpeedPWD(int pwd) {
    boolean new_rotation = pwd > 0;
    
    if(this->rotation != new_rotation) {
      digitalWrite(this->enableA, new_rotation);
      digitalWrite(this->enableB, !new_rotation);
      this->rotation = new_rotation;
    }
    
    analogWrite(this->speedPin, abs(pwd));
  }
};

DcMotor motor (8, 9, 10);

void setup()
{
  Serial.begin(9600);
}

void loop() {
	delay(1000);
}

void serialEvent() {
  int speed = Serial.parseInt();
  Serial.print("Reciving:");
  Serial.println(speed);
  motor.setSpeedPWD(speed);
}