const int potPin = A0;
const int clockwise = 13;
const int anticlockwise = 12;
const int pin1 = 11;
const int pin2 = 10;

int potValue = 0;
int motorValue = 0;
int state = 0;
//int anticlockwisestate = 0;


void setup() {
  pinMode (clockwise, INPUT_PULLUP);
  pinMode (anticlockwise, INPUT_PULLUP);
  pinMode (pin1 , OUTPUT);
  pinMode (pin2 , OUTPUT);
}

void loop() {
  potValue = analogRead(potPin);
  motorValue = map(potValue , 0 , 1023 , 0, 255);
  state = digitalRead(clockwise);
  //anticlockwisestate = digitalRead(anticlockwise);

  if (state == LOW) {
    analogWrite(pin1, motorValue);
    digitalWrite(pin2 , LOW);
  }
  else if (state == HIGH)
  {
    analogWrite(pin2, motorValue);
    digitalWrite(pin1 , HIGH);
  }
  else
  {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
  }
}
