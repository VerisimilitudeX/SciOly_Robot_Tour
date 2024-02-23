#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_DCMotor *lMotor;
Adafruit_DCMotor *rMotor;

void setup() {
  Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
  lMotor = AFMS.getMotor(4);
  rMotor = AFMS.getMotor(3);
  AFMS.begin();
}

int speed = 0;
void loop() {
  lMotor->setSpeed(speed);
  rMotor->setSpeed(speed);
  speed++;
  if (speed > 255) {
    speed = 0;
  }
  lMotor->run(FORWARD);
  rMotor->run(FORWARD);
}
