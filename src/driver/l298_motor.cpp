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
    bool result = true;

    this->_pin_a     = pin1;
    this->_pin_b     = pin2;
    this->_pin_speed = speed_pin;

    pinMode(this->_pin_a, OUTPUT);
    pinMode(this->_pin_b, OUTPUT);
    pinMode(this->_pin_speed, OUTPUT);

    digitalWrite(this->_pin_a, HIGH);
    digitalWrite(this->_pin_b, HIGH);
    this->_direction = NOT_SET;

    this->speed(0);
    return result;
}

void L298NMotor::speed(int speed)
{
    analogWrite(this->_pin_speed, abs(speed));
}

void L298NMotor::forward()
{
    if (FORWARD == this->_direction) {
        return;
    }
    if (true == this->_flag_invert) {
        digitalWrite(this->_pin_a, LOW);
        digitalWrite(this->_pin_b, HIGH);
    } else {
        digitalWrite(this->_pin_a, HIGH);
        digitalWrite(this->_pin_b, LOW);
    }
    this->_direction = FORWARD;
}

void L298NMotor::backward()
{
    if (BACKWARD == this->_direction) {
        return;
    }
    if (true == this->_flag_invert) {
        digitalWrite(this->_pin_a, HIGH);
        digitalWrite(this->_pin_b, LOW);
    } else {
        digitalWrite(this->_pin_a, LOW);
        digitalWrite(this->_pin_b, HIGH);
    }
    this->_direction = BACKWARD;
}

void L298NMotor::move(int speed)
{
    int set_speed = abs(speed);
    if (speed == 0) {
        // stop
        this->speed(0);
    } else if (speed < 0) {
        // backward
        this->backward();
        this->speed(set_speed);
    } else {
        // forward
        this->forward();
        this->speed(set_speed);
    }
}

bool L298NMotor::invert()
{
    this->_flag_invert = !this->_flag_invert;
    this->_direction   = NOT_SET;
    return this->_flag_invert;
}

} // namespace MOBILITY
