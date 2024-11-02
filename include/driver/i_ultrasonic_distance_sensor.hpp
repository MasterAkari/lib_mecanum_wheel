/**
 * @file i_ultrasonic_distance_sensor.hpp
 * @brief
 * @version 0.1
 * @date 2024-11-02
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef I_ULTRASONIC_DISTANCE_SENSOR_HPP
#define I_ULTRASONIC_DISTANCE_SENSOR_HPP

namespace MOBILITY
{
class IUltrasonicDistanceSensor {
public:
    virtual ~IUltrasonicDistanceSensor()           = default;
    virtual bool setup(int trig_pin, int echo_pin) = 0;
    virtual int watch()                            = 0;
};

} // namespace MOBILITY

#endif
