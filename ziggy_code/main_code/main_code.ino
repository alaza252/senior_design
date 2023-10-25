// This is the main code for Ziggy

#include <Adafruit_LSM6DSOX.h>
#include <SharpIR.h>

#define LEFT_MOTOR_BWD 10
#define LEFT_MOTOR_FWD 9
#define RIGHT_MOTOR_BWD 6
#define RIGHT_MOTOR_FWD 5

#define FRONT_SENSOR A0
#define FRONT_LIMIT 10
#define TOP_SENSOR A1
#define top_limit 10

Adafruit_LSM6DSOX sox;
SharpIR f_sensor( SharpIR::GP2Y0A21YK0F, FRONT_SENSOR);
SharpIR t_sensor( SharpIR::GP2Y0A21YK0F, TOP_SENSOR);

void forward();
void backward();
void stop();
void left();
void right();

void setup() {
  Serial.begin(115200);
  // Serial.begin(9600);

  while (sox.begin_I2C()) {
    Serial.println("Waiting...");
    delay(2500);
  }
  Serial.println("Success");

  pinMode(LEFT_MOTOR_BWD, OUTPUT);
  pinMode(LEFT_MOTOR_FWD, OUTPUT);
  pinMode(RIGHT_MOTOR_BWD, OUTPUT);
  pinMode(RIGHT_MOTOR_FWD, OUTPUT);
}

void loop() {
  /* Init a new normalized accelerometer sensor event */
  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;


  /* Init distance sensor value */
  int front_dist;
  int top_dist;


  /* Move the mouse in 4 directions */
  stop();

  //forward
  forward();

  // forward for 2 seconds
  delay(2000);

  // stop
  stop();

  delay(1000);

  //backward
  backward();

  // backward for 2 seconds
  delay(2000);

  // stop
  stop();

  delay(1000);

  // turn left 
  left();

  // forward for 2 seconds
  delay(2000);

  // stop
  stop();

  delay(1000);

  // turn right
  right();

  // forward for 2 seconds
  delay(2000);

  // stop
  stop();


  /* Get reading from accelerometer */
  sox.getEvent(&accel, &gyro, &temp);

  /* Display the results (temperature is measured in degrees C) */
  Serial.print("\t\tTemperature ");
  Serial.print(temp.temperature);
  Serial.println(" deg C");

  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("\t\tAccel X: ");
  Serial.print(accel.acceleration.x);
  Serial.print(" \tY: ");
  Serial.print(accel.acceleration.y);
  Serial.print(" \tZ: ");
  Serial.print(accel.acceleration.z);
  Serial.println(" m/s^2 ");

  /* Display the results (rotation is measured in rad/s) */
  Serial.print("\t\tGyro X: ");
  Serial.print(gyro.gyro.x);
  Serial.print(" \tY: ");
  Serial.print(gyro.gyro.y);
  Serial.print(" \tZ: ");
  Serial.print(gyro.gyro.z);
  Serial.println(" radians/s ");
  Serial.println();


  // /* Get IR sensor readings */
  // front_dist = f_sensor.getDistance();
  // top_dist = t_sensor.getDistance();

  // Serial.print("Front distance: ")
  // Serial.println(front_dist);
  // Serial.print("Top distance: ")
  // Serial.println(top_dist)

  delay(1000);
}


void forward() {
  // forward full speed
  analogWrite(LEFT_MOTOR_FWD, 255);
  analogWrite(RIGHT_MOTOR_FWD, 255);
}

void backward() {
  // backward full speed
  analogWrite(LEFT_MOTOR_BWD, 255);
  analogWrite(RIGHT_MOTOR_BWD, 255);
}

void stop() {
  digitalWrite(LEFT_MOTOR_BWD, LOW);
  digitalWrite(RIGHT_MOTOR_BWD, LOW);
  digitalWrite(LEFT_MOTOR_FWD, LOW);
  digitalWrite(RIGHT_MOTOR_FWD, LOW);
}

void left() {
  // turn left
  analogWrite(LEFT_MOTOR_FWD, 255);
  delay(500);

  // forward full speed
  analogWrite(LEFT_MOTOR_FWD, 255);
  analogWrite(RIGHT_MOTOR_FWD, 255);
}

void right() {
  // turn right
  analogWrite(RIGHT_MOTOR_FWD, 255);
  delay(500);

  // forward full speed
  analogWrite(LEFT_MOTOR_FWD, 255);
  analogWrite(RIGHT_MOTOR_FWD, 255);
}
