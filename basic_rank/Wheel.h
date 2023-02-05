#ifndef WHEEL_H
#define WHEEL_H

#include "Arudino.h"

class Wheel {
    public:
        Wheel(int pin_number);
        void set_pin(int pin_number);
        void rotate_counterclockwise(int speed);
        void rotate_clockwise(int speed);
        void stop();
        ~Wheel();
    private:
        int pin_number;
}

#endif