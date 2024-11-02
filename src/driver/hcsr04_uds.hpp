/**
 * @file hcsr04_uds.hpp
 * @brief
 * @version 0.1
 * @date 2024-11-02
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef HCSR04_UDS_HPP
#define HCSR04_UDS_HPP

#include "driver/i_ultrasonic_distance_sensor.hpp"

namespace MOBILITY
{
class HCSR04_UDS : public MOBILITY::IUltrasonicDistanceSensor {
public:
    HCSR04_UDS();
    ~HCSR04_UDS();
    bool setup(int trig_pin, int echo_pin) override;
    int watch() override;

private:
    int _trig_pin = 0;
    int _echo_pin = 0;
};

} // namespace MOBILITY

#endif
