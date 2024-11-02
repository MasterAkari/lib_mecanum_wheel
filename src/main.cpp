/**
 * @file main.cpp
 * @brief
 * @version 0.1
 * @date 2024-10-30
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "driver/l298_motor.hpp"
#include "mecanum_wheel_robot.hpp"

#include <Arduino.h>

MecanumWheelRobot my_car;

void test_move_00()
{
    Serial.println("* test_move_00");
    int SPEED            = 150;
    int DELAY_TIMES      = 500;
    int DELAY_TIMES_SPAN = 5000;

    Serial.println("  * go_north");
    my_car.go_north(SPEED);
    delay(DELAY_TIMES);
    my_car.stop();
    delay(DELAY_TIMES_SPAN);

    Serial.println("  * go_south");
    my_car.go_south(SPEED);
    delay(DELAY_TIMES);
    my_car.stop();
    delay(DELAY_TIMES_SPAN);
}

void test_move_01()
{
    Serial.println("* test_move_01");
    int SPEED            = 150;
    int DELAY_TIMES      = 500;
    int DELAY_TIMES_SPAN = 2000;

    Serial.println("  * go_north");
    my_car.go_north(SPEED);
    delay(DELAY_TIMES);
    my_car.stop();
    delay(DELAY_TIMES_SPAN);

    Serial.println("  * go_south");
    my_car.go_south(SPEED);
    delay(DELAY_TIMES);
    my_car.stop();
    delay(DELAY_TIMES_SPAN);

    Serial.println("  * go_east");
    my_car.go_east(SPEED);
    delay(DELAY_TIMES);
    my_car.stop();
    delay(DELAY_TIMES_SPAN);

    Serial.println("  * go_west");
    my_car.go_west(SPEED);
    delay(DELAY_TIMES);
    my_car.stop();
    delay(DELAY_TIMES_SPAN);

    Serial.println("  * go_northeast");
    my_car.go_northeast(SPEED);
    delay(DELAY_TIMES);
    my_car.stop();
    delay(DELAY_TIMES_SPAN);

    Serial.println("  * go_southwest");
    my_car.go_southwest(SPEED);
    delay(DELAY_TIMES);
    my_car.stop();
    delay(DELAY_TIMES_SPAN);

    Serial.println("  * go_northwest");
    my_car.go_northwest(SPEED);
    delay(DELAY_TIMES);
    my_car.stop();
    delay(DELAY_TIMES_SPAN);

    Serial.println("  * go_southeast");
    my_car.go_southeast(SPEED);
    delay(DELAY_TIMES);
    my_car.stop();
    delay(DELAY_TIMES_SPAN);

    Serial.println("  * clockwise");
    my_car.clockwise(SPEED);
    delay(DELAY_TIMES);
    my_car.stop();
    delay(DELAY_TIMES_SPAN);

    Serial.println("  * anticlockwise");
    my_car.anticlockwise(SPEED);
    delay(DELAY_TIMES);
    my_car.stop();
    delay(DELAY_TIMES_SPAN);
}

void test_move_02()
{
    Serial.println("* test_move_02");
}

///////////////////////////////////////////////////////////////////////////////

void setup()
{
    // Setting up the Mecanum Wheel Robot
    int scan_loop_times           = 4;
    unsigned long serial_baudrate = 115200;

    // Setting up the serial port
    Serial.begin(serial_baudrate);
    while (!Serial) {
        delay(1000);
    }

    // Robot initialization
    my_car.set_scan_loop_times(scan_loop_times);
    bool result = my_car.begin();
    while (false == result) {
        Serial.println("[ERROR] Initialization failed. Mecanum Wheel Robot.");
        delay(1000 * 5);
    }

    // Test
    Serial.println("########################################");
    Serial.println("Hello, Mecanum Wheel Robot!");

    test_move_00();
    test_move_01();
    test_move_02();

    Serial.println("Bye, Mecanum Wheel!");
    Serial.println("########################################");
}

void loop()
{
    my_car.heartbeat();
}
