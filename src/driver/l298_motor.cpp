/**
 * @file l298_motor.cpp
 * @brief
 * @version 0.1
 * @date 2024-10-31
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "driver/l298_motor.hpp"

#include <Arduino.h>

namespace MOBILITY
{

L298NMotor::L298NMotor()
{
}
L298NMotor::~L298NMotor()
{
    this->speed(0);
}

bool L298NMotor::setup(uint8_t pin1, uint8_t pin2, uint8_t speed_pin)
{
    this->_pin_a     = pin1;
    this->_pin_b     = pin2;
    this->_pin_speed = speed_pin;
    pinMode(this->_pin_a, OUTPUT);
    pinMode(this->_pin_b, OUTPUT);
    pinMode(this->_pin_speed, OUTPUT);

    return true;
}

bool L298NMotor::speed(int speed)
{
    bool result   = true;
    int type      = 0;
    int set_speed = abs(speed);
    if (speed == 0) {
        // stop
        type = 0;
    } else if (speed < 0) {
        // back
        type = this->_flag_invert ? 1 : 2;
    } else {
        // forward
        type = this->_flag_invert ? 2 : 1;
    }

    if (type == 1) {
        digitalWrite(this->_pin_a, HIGH);
        digitalWrite(this->_pin_b, LOW);
        analogWrite(this->_pin_speed, set_speed);
    } else if (type == 2) {
        digitalWrite(this->_pin_a, LOW);
        digitalWrite(this->_pin_b, HIGH);
        analogWrite(this->_pin_speed, set_speed);
    } else {
        analogWrite(this->_pin_speed, 0);
    }
    return result;
}
bool L298NMotor::invert()
{
    this->_flag_invert = !this->_flag_invert;
    return this->_flag_invert;
}

} // namespace MOBILITY
