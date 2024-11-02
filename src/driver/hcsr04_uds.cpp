/**
 * @file hcsr04_uds.cpp
 * @brief
 * @version 0.1
 * @date 2024-11-02
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "driver/hcsr04_uds.hpp"

#include <Arduino.h>

namespace MOBILITY
{

HCSR04_UDS::HCSR04_UDS()
{
}

HCSR04_UDS ::~HCSR04_UDS()
{
}

bool HCSR04_UDS::setup(int trig_pin, int echo_pin)
{
    bool result = true;

    this->_trig_pin = trig_pin;
    this->_echo_pin = echo_pin;

    // Initialize the digital pin
    pinMode(this->_trig_pin, OUTPUT);
    pinMode(this->_echo_pin, INPUT);

    // Initialize buzzer
    digitalWrite(this->_trig_pin, LOW);

    return result;
}

int HCSR04_UDS::watch()
{
    long echo_distance;

    digitalWrite(this->_trig_pin, LOW);
    delayMicroseconds(5);
    digitalWrite(this->_trig_pin, HIGH);
    delayMicroseconds(15);
    digitalWrite(this->_trig_pin, LOW);

    echo_distance = pulseIn(this->_echo_pin, HIGH);
    echo_distance = echo_distance * 0.01657;

    //how far away is the object in cm
    return round(echo_distance);
}

} // namespace MOBILITY
