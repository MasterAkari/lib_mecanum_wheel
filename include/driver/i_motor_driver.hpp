/**
 * @file i_motor_driver.hpp
 * @brief
 * @version 0.1
 * @date 2024-10-31
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef I_MOTOR_DRIVER_HPP
#define I_MOTOR_DRIVER_HPP

namespace MOBILITY
{
class IMotorDriver {
public:
    virtual ~IMotorDriver()       = default;
    virtual void move(int speed)  = 0;
    virtual void speed(int speed) = 0;
    virtual void forward()        = 0;
    virtual void backward()       = 0;
};
} // namespace MOBILITY

#endif
