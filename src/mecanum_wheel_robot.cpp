/**
 * @file mecanum_wheel_robot.cpp
 * @brief
 * @version 0.1
 * @date 2024-11-02
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "mecanum_wheel_robot.hpp"

#include <Arduino.h>

MecanumWheelRobot::MecanumWheelRobot()
{
}

MecanumWheelRobot::~MecanumWheelRobot()
{
    this->stop();
}

void MecanumWheelRobot::go_north(int speed)
{
    this->_wheel.go_north(speed);
}
void MecanumWheelRobot::go_northeast(int speed)
{
    this->_wheel.go_northeast(speed);
}
void MecanumWheelRobot::go_east(int speed)
{
    this->_wheel.go_east(speed);
}
void MecanumWheelRobot::go_southeast(int speed)
{
    this->_wheel.go_southeast(speed);
}
void MecanumWheelRobot::go_south(int speed)
{
    this->_wheel.go_south(speed);
}
void MecanumWheelRobot::go_southwest(int speed)
{
    this->_wheel.go_southwest(speed);
}
void MecanumWheelRobot::go_west(int speed)
{
    this->_wheel.go_west(speed);
}
void MecanumWheelRobot::go_northwest(int speed)
{
    this->_wheel.go_northwest(speed);
}
void MecanumWheelRobot::clockwise(int speed)
{
    this->_wheel.clockwise(speed);
}
void MecanumWheelRobot::anticlockwise(int speed)
{
    this->_wheel.anticlockwise(speed);
}
void MecanumWheelRobot::stop()
{
    this->_wheel.stop();
}

void MecanumWheelRobot::set_scan_loop_times(int times)
{
    this->_scan_loop_times = times;
}

bool MecanumWheelRobot::begin()
{
    // head
    int head_servo   = HEAD_SERVO;
    int sensor_tiger = SENSOR_TIGER;
    int sensor_echo  = SENSOR_ECHO;

    this->_flag_initalized = this->_sensor.setup(sensor_tiger, sensor_echo);

    if (true == this->_flag_initalized) {
        this->_flag_initalized = this->_header.setup_servo(head_servo);
    }
    if (true == this->_flag_initalized) {
        this->_flag_initalized = this->_header.setup_sensor(&this->_sensor);
    }
    // wheel
    if (true == this->_flag_initalized) {
        int fr_speed_pin = FR_SPEED_PIN;
        int fr_pin1      = FR_PIN1;
        int fr_pin2      = FR_PIN2;
        int fl_speed_pin = FL_SPEED_PIN;
        int fl_pin1      = FL_PIN1;
        int fl_pin2      = FL_PIN2;
        int rr_speed_pin = RR_SPEED_PIN;
        int rr_pin1      = RR_PIN1;
        int rr_pin2      = RR_PIN2;
        int rl_speed_pin = RL_SPEED_PIN;
        int rl_pin1      = RL_PIN1;
        int rl_pin2      = RL_PIN2;

        this->_front_right.setup(fr_pin1, fr_pin2, fr_speed_pin);
        this->_front_left.setup(fl_pin1, fl_pin2, fl_speed_pin);
        this->_rear_right.setup(rr_pin1, rr_pin2, rr_speed_pin);
        this->_rear_left.setup(rl_pin1, rl_pin2, rl_speed_pin);
        this->_flag_initalized = this->_wheel.setup(&this->_front_right, &this->_front_left, &this->_rear_right, &this->_rear_left);
    }
    return this->_flag_initalized;
}
void MecanumWheelRobot::heartbeat()
{
}
