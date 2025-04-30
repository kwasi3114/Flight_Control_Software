//imu code for flight controller
//source: https://randomnerdtutorials.com/esp32-mpu-6050-accelerometer-gyroscope-arduino/

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup() {
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float x_accel = a.acceleration.x;
  float y_accel = a.acceleration.y;
  float z_accel = a.acceleration.z;
  
  float x_rot = g.gyro.x;
  float y_rot = g.gyro.y;
  float z_rot = g.gyro.z;
}