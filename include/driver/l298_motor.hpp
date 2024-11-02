/**
 * @file l298_motor.hpp
 * @brief
 * @version 0.1
 * @date 2024-10-31
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef DC_MOTOR_HPP
#define DC_MOTOR_HPP
#include "i_motor_driver.hpp"

#include <inttypes.h>

namespace MOBILITY
{
class L298NMotor : public MOBILITY::IMotorDriver {
public:
    L298NMotor();
    ~L298NMotor();
    bool setup(uint8_t pin1, uint8_t pin2, uint8_t speed_pin);
    bool invert();
    bool speed(int speed) override;

private:
    uint8_t _pin_a;
    uint8_t _pin_b;
    uint8_t _pin_speed;
    uint8_t _flag_invert;
};
} // namespace MOBILITY
#endif
