//Tests for the distance sensors

#include <SharpIR.h>

#define LEFT_MOTOR_IN1 9
#define LEFT_MOTOR_IN2 10
#define RIGHT_MOTOR_IN1 5
#define RIGHT_MOTOR_IN2 6

#define FRONT_SENSOR A0
#define FRONT_LIMIT 600
#define SENSOR_2 A1
#define top_limit 300

// GP2Y0A21YK0F sensor

SharpIR sensor( SharpIR::GP2Y0A21YK0F, A0);


void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

  pinMode(LEFT_MOTOR_IN1, OUTPUT);
  pinMode(LEFT_MOTOR_IN2, OUTPUT);
  pinMode(RIGHT_MOTOR_IN1, OUTPUT);
  pinMode(RIGHT_MOTOR_IN2, OUTPUT);
}

void loop() {
  digitalWrite(LEFT_MOTOR_IN1, LOW);
  digitalWrite(RIGHT_MOTOR_IN1, LOW);
  digitalWrite(LEFT_MOTOR_IN2, LOW);
  digitalWrite(RIGHT_MOTOR_IN2, LOW);

  int test_dist = sensor.getDistance();

  Serial.println(test_dist);
  
  // int front_dist;
  // int top_dist;
  // front_dist = analogRead(FRONT_SENSOR);
  // top_dist = analogRead(A1);
  // Serial.print("Front distance: ");
  // Serial.println(front_dist);
  // Serial.print("Top distance: ");
  // Serial.println(top_dist);

  // digitalWrite(LEFT_MOTOR_IN1, LOW);
  // digitalWrite(RIGHT_MOTOR_IN1, LOW);

  // analogWrite(LEFT_MOTOR_IN2, 255);
  // analogWrite(RIGHT_MOTOR_IN2, 255);
  
  // if (front_dist > 600) {
  //   digitalWrite(LEFT_MOTOR_IN2, LOW);
  //   digitalWrite(RIGHT_MOTOR_IN2, LOW);
  // }

  // if (top_dist < 300) {
  //   digitalWrite(LEFT_MOTOR_IN2, LOW);
  //   digitalWrite(RIGHT_MOTOR_IN2, LOW);
  // }

  // else {
  //   analogWrite(LEFT_MOTOR_IN2, 255);
  //   analogWrite(RIGHT_MOTOR_IN2, 255);
  // }

  delay(1000);
}
