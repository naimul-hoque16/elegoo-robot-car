#include "Arduino.h"
#include "Wheel.h"

Wheel::Wheel(int pin_number){
    pin = pin_number;
    pinMode(pin, INPUT);
}