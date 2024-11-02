/**
 * @file osoyoo_mecanum_wheel.cpp
 * @brief
 * @version 0.1
 * @date 2024-10-30
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "mobility_mecanum_wheel.hpp"

#include <Arduino.h>
#include <Servo.h>

namespace MOBILITY
{

MecanumWheel::MecanumWheel()
{
}

MecanumWheel::~MecanumWheel()
{
    this->stop();
}

bool MecanumWheel::setup(IMotorDriver *front_right, //
                         IMotorDriver *front_left,
                         IMotorDriver *rear_right,
                         IMotorDriver *rear_left)
{
    bool result        = true;
    this->_front_right = front_right;
    this->_front_left  = front_left;
    this->_rear_right  = rear_right;
    this->_rear_left   = rear_left;
    this->stop();
    if (this->_front_right == nullptr   //
        || this->_front_left == nullptr //
        || this->_rear_right == nullptr //
        || this->_rear_left == nullptr) {
        result = false;
    }
    return result;
}

bool MecanumWheel::heartbeat()
{
    if (true == this->_flag_heartbeat) {
#if 0
        static int speed_fr = 0;
        static int speed_fl = 0;
        static int speed_rr = 0;
        static int speed_rl = 0;
#endif

        this->_front_right->speed(this->_request_speed_fr);
        this->_front_left->speed(this->_request_speed_fl);
        this->_rear_right->speed(this->_request_speed_rr);
        this->_rear_left->speed(this->_request_speed_rl);
    }
    return true;
}
void MecanumWheel::giving_instructions(ORDER_STATE order, int speed)
{
    switch (order) {
        case ORDER_STATE::GO_NORTH:
            this->go_north(speed);
            break;
        case ORDER_STATE::GO_NORTHEAST:
            this->go_northeast(speed);
            break;
        case ORDER_STATE::GO_EAST:
            this->go_east(speed);
            break;
        case ORDER_STATE::GO_SOUTHEAST:
            this->go_southeast(speed);
            break;
        case ORDER_STATE::GO_SOUTH:
            this->go_south(speed);
            break;
        case ORDER_STATE::GO_SOUTHWEST:
            this->go_southwest(speed);
            break;
        case ORDER_STATE::GO_WEST:
            this->go_west(speed);
            break;
        case ORDER_STATE::GO_NORTHWEST:
            this->go_northwest(speed);
            break;
        case ORDER_STATE::CLOCKWISE:
            this->clockwise(speed);
            break;
        case ORDER_STATE::ANTICLOCKWISE:
            this->anticlockwise(speed);
            break;
        case ORDER_STATE::STOP:
        default:
            this->stop();
            break;
    }
}

/*motor control*/
void MecanumWheel::go_north(int speed)
{
    this->_speed            = speed;
    this->_request_speed_fr = speed;
    this->_request_speed_fl = speed;
    this->_request_speed_rr = speed;
    this->_request_speed_rl = speed;
    this->_order            = ORDER_STATE::GO_NORTH;
    if (false == this->_flag_heartbeat) {
        this->_front_right->move(this->_request_speed_fr);
        this->_front_left->move(this->_request_speed_fl);
        this->_rear_right->move(this->_request_speed_rr);
        this->_rear_left->move(this->_request_speed_rl);
    }
}
void MecanumWheel::go_northeast(int speed)
{
    this->_speed            = speed;
    this->_request_speed_fr = 0;
    this->_request_speed_fl = speed;
    this->_request_speed_rr = 0;
    this->_request_speed_rl = speed;
    this->_order            = ORDER_STATE::GO_NORTHEAST;
    if (false == this->_flag_heartbeat) {
        this->_front_right->move(this->_request_speed_fr);
        this->_front_left->move(this->_request_speed_fl);
        this->_rear_right->move(this->_request_speed_rr);
        this->_rear_left->move(this->_request_speed_rl);
    }
}
void MecanumWheel::go_east(int speed)
{
    this->_speed            = speed;
    this->_request_speed_fr = -speed;
    this->_request_speed_fl = speed;
    this->_request_speed_rr = speed;
    this->_request_speed_rl = -speed;
    this->_order            = ORDER_STATE::GO_EAST;
    if (false == this->_flag_heartbeat) {
        this->_front_right->move(this->_request_speed_fr);
        this->_front_left->move(this->_request_speed_fl);
        this->_rear_right->move(this->_request_speed_rr);
        this->_rear_left->move(this->_request_speed_rl);
    }
}
void MecanumWheel::go_southeast(int speed)
{
    this->_speed            = speed;
    this->_request_speed_fr = 0;
    this->_request_speed_fl = -speed;
    this->_request_speed_rr = 0;
    this->_request_speed_rl = -speed;
    this->_order            = ORDER_STATE::GO_SOUTHEAST;
    if (false == this->_flag_heartbeat) {
        this->_front_right->move(this->_request_speed_fr);
        this->_front_left->move(this->_request_speed_fl);
        this->_rear_right->move(this->_request_speed_rr);
        this->_rear_left->move(this->_request_speed_rl);
    }
}
void MecanumWheel::go_south(int speed)
{
    this->_speed            = speed;
    this->_request_speed_fr = -speed;
    this->_request_speed_fl = -speed;
    this->_request_speed_rr = -speed;
    this->_request_speed_rl = -speed;
    this->_order            = ORDER_STATE::GO_SOUTH;
    if (false == this->_flag_heartbeat) {
        this->_front_right->move(this->_request_speed_fr);
        this->_front_left->move(this->_request_speed_fl);
        this->_rear_right->move(this->_request_speed_rr);
        this->_rear_left->move(this->_request_speed_rl);
    }
}
void MecanumWheel::go_southwest(int speed)
{
    this->_speed            = speed;
    this->_request_speed_fr = -speed;
    this->_request_speed_fl = 0;
    this->_request_speed_rr = -speed;
    this->_request_speed_rl = 0;
    this->_order            = ORDER_STATE::GO_SOUTHWEST;
    if (false == this->_flag_heartbeat) {
        this->_front_right->move(this->_request_speed_fr);
        this->_front_left->move(this->_request_speed_fl);
        this->_rear_right->move(this->_request_speed_rr);
        this->_rear_left->move(this->_request_speed_rl);
    }
}
void MecanumWheel::go_west(int speed)
{
    this->_speed            = speed;
    this->_request_speed_fr = speed;
    this->_request_speed_fl = -speed;
    this->_request_speed_rr = -speed;
    this->_request_speed_rl = speed;
    this->_order            = ORDER_STATE::GO_WEST;
    if (false == this->_flag_heartbeat) {
        this->_front_right->move(this->_request_speed_fr);
        this->_front_left->move(this->_request_speed_fl);
        this->_rear_right->move(this->_request_speed_rr);
        this->_rear_left->move(this->_request_speed_rl);
    }
}
void MecanumWheel::go_northwest(int speed)
{
    this->_speed            = speed;
    this->_request_speed_fr = speed;
    this->_request_speed_fl = 0;
    this->_request_speed_rr = speed;
    this->_request_speed_rl = 0;
    this->_order            = ORDER_STATE::GO_NORTHWEST;
    if (false == this->_flag_heartbeat) {
        this->_front_right->move(this->_request_speed_fr);
        this->_front_left->move(this->_request_speed_fl);
        this->_rear_right->move(this->_request_speed_rr);
        this->_rear_left->move(this->_request_speed_rl);
    }
}
void MecanumWheel::clockwise(int speed)
{
    this->_speed            = speed;
    this->_request_speed_fr = -speed;
    this->_request_speed_fl = speed;
    this->_request_speed_rr = -speed;
    this->_request_speed_rl = speed;
    this->_order            = ORDER_STATE::CLOCKWISE;
    if (false == this->_flag_heartbeat) {
        this->_front_right->move(this->_request_speed_fr);
        this->_front_left->move(this->_request_speed_fl);
        this->_rear_right->move(this->_request_speed_rr);
        this->_rear_left->move(this->_request_speed_rl);
    }
}
void MecanumWheel::anticlockwise(int speed)
{
    this->_speed            = speed;
    this->_request_speed_fr = speed;
    this->_request_speed_fl = -speed;
    this->_request_speed_rr = speed;
    this->_request_speed_rl = -speed;
    this->_order            = ORDER_STATE::ANTICLOCKWISE;
    if (false == this->_flag_heartbeat) {
        this->_front_right->move(this->_request_speed_fr);
        this->_front_left->move(this->_request_speed_fl);
        this->_rear_right->move(this->_request_speed_rr);
        this->_rear_left->move(this->_request_speed_rl);
    }
}
void MecanumWheel::stop()
{
    this->_speed            = 0;
    this->_request_speed_fr = 0;
    this->_request_speed_fl = 0;
    this->_request_speed_rr = 0;
    this->_request_speed_rl = 0;
    this->_order            = ORDER_STATE::STOP;
    if (false == this->_flag_heartbeat) {
        this->_front_right->speed(this->_request_speed_fr);
        this->_front_left->speed(this->_request_speed_fl);
        this->_rear_right->speed(this->_request_speed_rr);
        this->_rear_left->speed(this->_request_speed_rl);
    }
}

} // namespace MOBILITY
