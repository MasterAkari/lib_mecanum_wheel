/**
 * @file header_detection.cpp
 * @brief
 * @version 0.1
 * @date 2024-11-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "unit/header_detection.hpp"

#include <Arduino.h>
namespace MOBILITY
{

HeaderDetection::HeaderDetection()
{
}

HeaderDetection::~HeaderDetection()
{
}
void HeaderDetection::search_angle(int angle)
{
    this->_servo.write(angle);
    delay(500);
}

bool HeaderDetection::setup_servo(int pin)
{
    bool result = true;
    /*init servo*/
    this->search_angle(0);
    this->search_angle(170);
    this->search_angle(90);
    return result;
}

bool HeaderDetection::setup_sensor(IUltrasonicDistanceSensor *sensor)
{
    bool result   = true;
    this->_sensor = sensor;
    if (nullptr == this->_sensor) {
        result = false;
    }
    return result;
}

} // namespace MOBILITY
