// Basic demo for accelerometer & gyro readings from Adafruit
// LSM6DSOX sensor

#include <Adafruit_LSM6DSOX.h>

Adafruit_LSM6DSOX sox;

void setup(void) {
  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit LSM6DSOX test!");

  while (sox.begin_I2C()) {
    delay(2500);
  }

  Serial.println("Success");

  // if (sox.begin_I2C()) {
  //   Serial.println("I2C Success");
  // }
  // else {
  //   Serial.println("I2C Fail");
  // }
}

void loop() {
  /* Get a new normalized sensor event */
  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;
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

  delay(1000);
}