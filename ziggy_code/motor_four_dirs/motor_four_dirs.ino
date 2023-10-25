#define LEFT_MOTOR_IN1 9
#define LEFT_MOTOR_IN2 10
#define RIGHT_MOTOR_IN1 5
#define RIGHT_MOTOR_IN2 6

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

  pinMode(LEFT_MOTOR_IN1, OUTPUT);
  pinMode(LEFT_MOTOR_IN2, OUTPUT);
  pinMode(RIGHT_MOTOR_IN1, OUTPUT);
  pinMode(RIGHT_MOTOR_IN2, OUTPUT);
}

void loop() {
  // forward
  digitalWrite(LEFT_MOTOR_IN1, LOW);
  digitalWrite(RIGHT_MOTOR_IN1, LOW);

  // full speed
  analogWrite(LEFT_MOTOR_IN2, 255);
  analogWrite(RIGHT_MOTOR_IN2, 255);

  // forward for 2 seconds
  delay(2000);

  // stop
  digitalWrite(LEFT_MOTOR_IN2, LOW);
  digitalWrite(RIGHT_MOTOR_IN2, LOW);

  delay(1000);


  // backward
  // full speed
  analogWrite(LEFT_MOTOR_IN1, 255);
  analogWrite(RIGHT_MOTOR_IN1, 255);

  // backward for 2 seconds
  delay(2000);

  // stop
  digitalWrite(LEFT_MOTOR_IN1, LOW);
  digitalWrite(RIGHT_MOTOR_IN1, LOW);

  delay(1000);


  // turn left and forward
  // full speed
  analogWrite(LEFT_MOTOR_IN2, 255);
  delay(500);
  analogWrite(LEFT_MOTOR_IN2, 255);
  analogWrite(RIGHT_MOTOR_IN2, 255);

  // forward for 2 seconds
  delay(2000);

  // stop
  digitalWrite(LEFT_MOTOR_IN2, LOW);
  digitalWrite(RIGHT_MOTOR_IN2, LOW);

  delay(1000);


  // turn right and forward
  // full speed
  analogWrite(RIGHT_MOTOR_IN2, 255);
  delay(500);
  analogWrite(LEFT_MOTOR_IN2, 255);
  analogWrite(RIGHT_MOTOR_IN2, 255);

  // forward for 2 seconds
  delay(2000);

  // stop
  digitalWrite(LEFT_MOTOR_IN2, LOW);
  digitalWrite(RIGHT_MOTOR_IN2, LOW);

  delay(1000);
}
