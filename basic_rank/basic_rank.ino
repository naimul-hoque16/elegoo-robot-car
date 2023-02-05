/*
This program represents a very basic rank behavior
performed by a robot.

AIN1 = 7 ; Controls two right motors
BIN1 = 8 ; Controls two left motors

There is a SN74LVC2G14 Dual-Schmitt Trigger Inverters
that invert AIN1 and BIN1 and produces outputs for AIN2 and BIN2
which is why two additional pins are not required.

PWMA and PWMB are used to control the speed of the motors
STANDBY, when set to LOW, turns off all motors.

clockwise moves forward
counter moves backward
*/

#include "Wheel.h"

int STANDBY = 3;
int PWMA = 5;
int PWMB = 6;
int AIN1 = 7;
int BIN1 = 8;

void setup() {
  pinMode(3, OUTPUT);  // Standby Pin, activates motors when set to HIGH
}

void turn_right(Wheel& left_wheels, Wheel& right_wheels, int speed){
  left_wheels.rotate_clockwise(speed);
  right_wheels.stop();
}

void turn_left(Wheel& left_wheels, Wheel& right_wheels, int speed){
  right_wheels.rotate_clockwise(speed);
  left_wheels.stop();
}

void go_forward(Wheel& left_wheels, Wheel& right_wheels, int speed){
  left_wheels.rotate_clockwise(speed);
  right_wheels.rotate_clockwise(speed);
}

void go_backward(Wheel& left_wheels, Wheel& right_wheels, int speed){
  left_wheels.rotate_counterclockwise(speed);
  right_wheels.rotate_counterclockwise(speed);
}

void loop() {
  Wheel right_wheels(AIN1, PWMA);
  Wheel left_wheels(BIN1, PWMB);
  digitalWrite(STANDBY, HIGH);
  go_forward(left_wheels, right_wheels, 50);
  delay(10000);
  turn_right(left_wheels, right_wheels, 50);
  delay(3000);
  go_forward(left_wheels, right_wheels, 50);
  delay(5000);
  turn_left(left_wheels, right_wheels, 50);
  delay(3000);
  digitalWrite(STANDBY, LOW);
  exit(0);
}
