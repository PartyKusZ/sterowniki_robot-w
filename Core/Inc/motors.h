/*
 * motors.h
 *
 *  Created on: 3 cze 2023
 *      Author: zuzanna
 */

#ifndef INC_MOTORS_H_
#define INC_MOTORS_H_

#include "tim.h"
#include "gpio.h"

#define SPEED 80

void motors_init();

void set_speed(uint8_t *state);

void go(uint8_t *state);
void stop();
void turn_right();
void turn_left();

#endif /* INC_MOTORS_H_ */
