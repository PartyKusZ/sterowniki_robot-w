#ifndef INC_MOTORS_H_
#define INC_MOTORS_H_

#include "tim.h"
#include "gpio.h"

#define SPEED 80
#define TURNING_SPEED 80
#define SECURE_DISTANCE 15

void motors_init();

void set_speed(volatile uint8_t *state);

void go(volatile uint8_t *state);
void stop();
void turn_right();
void turn_left();
uint8_t find_min_dist_index(float *tab);
uint8_t find_max_dist_index(float *tab);
void control(volatile uint8_t *state,float *tab);

#endif /* INC_MOTORS_H_ */
