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
#include "mobility_mecanum_wheel.hpp"

#include <Arduino.h>

MOBILITY::MecanumWheel my_car;
MOBILITY::L298NMotor front_right;
MOBILITY::L298NMotor front_left;
MOBILITY::L298NMotor rear_right;
MOBILITY::L298NMotor rear_left;

void test_move_01()
{
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

void setup()
{
    Serial.begin(115200);
    while (!Serial) {
        delay(1000);
    }

    Serial.println("Hello, Mecanum Wheel!");
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

    Serial.println("Setup motor driver");
    Serial.println("# Front Right : " + String(fr_speed_pin) + " " + String(fr_pin1) + " " + String(fr_pin2));
    front_right.setup(fr_pin1, fr_pin2, fr_speed_pin);
    Serial.println("# Front Left  : " + String(fl_speed_pin) + " " + String(fl_pin1) + " " + String(fl_pin2));
    front_left.setup(fl_pin1, fl_pin2, fl_speed_pin);
    Serial.println("# Rear Right  : " + String(rr_speed_pin) + " " + String(rr_pin1) + " " + String(rr_pin2));
    rear_right.setup(rr_pin1, rr_pin2, rr_speed_pin);
    Serial.println("# Rear Left   : " + String(rl_speed_pin) + " " + String(rl_pin1) + " " + String(rl_pin2));
    rear_left.setup(rl_pin1, rl_pin2, rl_speed_pin);

    Serial.println("########################################");
    Serial.println("Setup mecanum wheel");
    my_car.setup(&front_right, &front_left, &rear_right, &rear_left);

    Serial.println("* Test move 01");
    test_move_01();

    Serial.println("########################################");
}

void loop()
{
    my_car.heartbeat();
}
