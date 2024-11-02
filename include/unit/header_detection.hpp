/**
 * @file header_detection.hpp
 * @brief
 * @version 0.1
 * @date 2024-11-02
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef HEADER_DETECTION_HPP
#define HEADER_DETECTION_HPP

#include "driver/i_ultrasonic_distance_sensor.hpp"

#include <Servo.h>

namespace MOBILITY
{
class HeaderDetection {
public:
    HeaderDetection();
    ~HeaderDetection();

public:
    bool setup_servo(int pin);
    bool setup_sensor(IUltrasonicDistanceSensor *sensor);

    void search_angle(int angle);

private:
    Servo _servo;
    IUltrasonicDistanceSensor *_sensor;
};

} // namespace MOBILITY

#endif
