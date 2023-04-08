#define MOTOR1_IN1 10
#define MOTOR1_IN2 11
#define MOTOR2_IN1 6
#define MOTOR2_IN2 9

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

  pinMode(MOTOR1_IN1, OUTPUT);
  pinMode(MOTOR1_IN2, OUTPUT);
  pinMode(MOTOR2_IN1, OUTPUT);
  pinMode(MOTOR2_IN2, OUTPUT);9+
}

void loop() {
  // ramp up forward
  digitalWrite(MOTOR1_IN1, LOW);
  digitalWrite(MOTOR2_IN1, LOW);

  for(int i = 0; i < 255; i++) {
    analogWrite(MOTOR1_IN2, i);
    analogWrite(MOTOR2_IN2, i);
    delay(10);
  }

  // full speed for 5000ms (5s)
  delay(5000);

  // ramp down forward
  for(int i = 255; i >= 0; i--) {
    analogWrite(MOTOR1_IN2, i);
    analogWrite(MOTOR2_IN2, i);
    delay(10);
  }

  // ramp up backward
  digitalWrite(MOTOR1_IN2, LOW);
  digitalWrite(MOTOR2_IN2, LOW);

  for(int i = 0; i < 255; i++) {
    analogWrite(MOTOR1_IN1, i);
    analogWrite(MOTOR2_IN1, i);
    delay(10);
  }

  // backwards for 5000ms (5s)
  delay(5000);

  // ramp down backward
  for(int i = 255; i >= 0; i--) {
    analogWrite(MOTOR1_IN1, i);
    analogWrite(MOTOR2_IN1, i);
    delay(10);
  }
}
