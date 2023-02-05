#include "Arduino.h"
#include "Wheel.h"

Wheel::Wheel(int m_pin, int p_pin) {
  motor_pin = m_pin;
  pwm_pin = p_pin;
  pinMode(motor_pin, OUTPUT);
  pinMode(pwm_pin, OUTPUT);
}

void Wheel::set_motor_pin(int m_pin) {
  motor_pin = m_pin;
  pinMode(motor_pin, OUTPUT);
}

void Wheel::set_pwm_pin(int p_pin) {
  pwm_pin = p_pin;
  pinMode(pwm_pin, OUTPUT);
}

void Wheel::rotate_clockwise(int speed) {
  digitalWrite(motor_pin, HIGH);
  analogWrite(pwm_pin, speed);
}

void Wheel::rotate_counterclockwise(int speed) {
  digitalWrite(motor_pin, LOW);
  analogWrite(pwm_pin, speed);
}

void Wheel::set_speed(int speed) {
  analogWrite(pwm_pin, speed);
}

void Wheel::stop() {
  set_speed(0);
}

Wheel::~Wheel() {
  set_speed(0);
}