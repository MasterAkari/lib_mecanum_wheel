/**
 * @file mobility_mecanum_wheel.hpp
 * @brief
 * @version 0.1
 * @date 2024-10-30
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef mobility_mecanum_wheel_hpp
#define mobility_mecanum_wheel_hpp
#include "driver/i_motor_driver.hpp"

namespace MOBILITY
{
class MecanumWheel {
public:
    MecanumWheel();
    ~MecanumWheel();
    typedef enum
    {
        STOP,
        GO_NORTH,
        GO_NORTHEAST,
        GO_EAST,
        GO_SOUTHEAST,
        GO_SOUTH,
        GO_SOUTHWEST,
        GO_WEST,
        GO_NORTHWEST,
        CLOCKWISE,
        ANTICLOCKWISE
    } ORDER_STATE;

public:
    bool setup(IMotorDriver *front_right, //
               IMotorDriver *front_left,
               IMotorDriver *rear_right,
               IMotorDriver *rear_left);
    bool heartbeat();

public:
    void giving_instructions(ORDER_STATE order, int speed);
    void go_north(int speed);
    void go_northeast(int speed);
    void go_east(int speed);
    void go_southeast(int speed);
    void go_south(int speed);
    void go_southwest(int speed);
    void go_west(int speed);
    void go_northwest(int speed);
    void clockwise(int speed);
    void anticlockwise(int speed);
    void stop();

private:
    int _per_millisecond     = 0;
    int _timeout_millisecond = 1000;
    bool _flag_heartbeat     = false;

    int _speed = 0;

    int _request_time     = 0;
    int _request_speed_fr = 0;
    int _request_speed_fl = 0;
    int _request_speed_rr = 0;
    int _request_speed_rl = 0;

    ORDER_STATE _order         = ORDER_STATE::STOP;
    IMotorDriver *_front_right = nullptr;
    IMotorDriver *_front_left  = nullptr;
    IMotorDriver *_rear_right  = nullptr;
    IMotorDriver *_rear_left   = nullptr;
};
} // namespace MOBILITY
#endif
