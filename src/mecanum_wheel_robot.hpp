/**
 * @file mecanum_wheel_robot.hpp
 * @brief
 * @version 0.1
 * @date 2024-11-02
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef MECANUM_WHEEL_ROBOT_HPP
#define MECANUM_WHEEL_ROBOT_HPP

#include "driver/hcsr04_uds.hpp"
#include "driver/l298_motor.hpp"
#include "unit/header_detection.hpp"
#include "unit/mobility_mecanum_wheel.hpp"

class MecanumWheelRobot {
public:
    MecanumWheelRobot();
    ~MecanumWheelRobot();
    bool begin();
    void heartbeat();
    void set_scan_loop_times(int times);

public:
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
    MOBILITY::MecanumWheel _wheel;
    MOBILITY::HeaderDetection _header;

    MOBILITY::L298NMotor _front_right;
    MOBILITY::L298NMotor _front_left;
    MOBILITY::L298NMotor _rear_right;
    MOBILITY::L298NMotor _rear_left;
    MOBILITY::HCSR04_UDS _sensor;

    bool _flag_initalized = false;

private:
    int _scan_loop_times = 2;
};

#endif
