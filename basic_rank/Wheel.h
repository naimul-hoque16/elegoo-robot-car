/*
This class is responsible for controlling two sets of wheels
on a robot.

NOTE: This is not to control individual wheels. The way the Elegoo robots are designed,
it only allows for controlling two sets of wheels on the same side, not individually.
*/
#ifndef WHEEL_H
#define WHEEL_H

#include "Arudino.h"

class Wheel {
    public:
        Wheel(int motor_pin, int pwm_pin);
        void set_motor_pin(int motor_pin);
        void set_pwm_pin(int pwm_pin);
        void rotate_counterclockwise(int speed);
        void rotate_clockwise(int speed);
        void stop();
        ~Wheel();
    private:
        int motor_pin;
        int pwm_pin;
}

#endif