/*
 * motors.c
 *
 *  Created on: 3 cze 2023
 *      Author: zuzanna
 */

#include "motors.h"


void motors_init(){
	HAL_TIM_Base_Start_IT(&htim16);
	HAL_TIM_Base_Start_IT(&htim17);
	HAL_TIM_PWM_Start(&htim16, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim17, TIM_CHANNEL_1);
	__HAL_TIM_SetCompare(&htim17, TIM_CHANNEL_1, 0);
	__HAL_TIM_SetCompare(&htim16, TIM_CHANNEL_1, 0);
}

void set_speed(uint8_t *state){
	if(*state == 1){
		uint32_t pwm_val = htim16.Instance->CCR1;
		if(pwm_val < SPEED){
			__HAL_TIM_SetCompare(&htim16, TIM_CHANNEL_1, ++pwm_val);
		}
		pwm_val = htim17.Instance->CCR1;
		if(pwm_val < SPEED){
			__HAL_TIM_SetCompare(&htim17, TIM_CHANNEL_1, ++pwm_val);
		}
		*state = 0;
	}
}


void go(uint8_t *state)
{
	HAL_GPIO_WritePin(AIN2_SILNIK_GPIO_Port, AIN2_SILNIK_Pin, 0);
	HAL_GPIO_WritePin(AIN1_SILNIK_GPIO_Port, AIN1_SILNIK_Pin, 1);

	HAL_GPIO_WritePin(BIN2_SILNIK_GPIO_Port, BIN2_SILNIK_Pin, 1);
	HAL_GPIO_WritePin(BIN1_SILNIK_GPIO_Port, BIN1_SILNIK_Pin, 0);

	set_speed(state);

}



void stop()
{
	HAL_GPIO_WritePin(AIN2_SILNIK_GPIO_Port, AIN2_SILNIK_Pin, 0);
	HAL_GPIO_WritePin(AIN1_SILNIK_GPIO_Port, AIN1_SILNIK_Pin, 0);

	HAL_GPIO_WritePin(BIN2_SILNIK_GPIO_Port, BIN2_SILNIK_Pin, 0);
	HAL_GPIO_WritePin(BIN1_SILNIK_GPIO_Port, BIN1_SILNIK_Pin, 0);

}


void turn_right()
{
	HAL_GPIO_WritePin(AIN2_SILNIK_GPIO_Port, AIN2_SILNIK_Pin, 1);
	HAL_GPIO_WritePin(AIN1_SILNIK_GPIO_Port, AIN1_SILNIK_Pin, 0);


	HAL_GPIO_WritePin(BIN2_SILNIK_GPIO_Port, BIN2_SILNIK_Pin, 1);
	HAL_GPIO_WritePin(BIN1_SILNIK_GPIO_Port, BIN1_SILNIK_Pin, 0);

}

void turn_left()
{
	HAL_GPIO_WritePin(AIN2_SILNIK_GPIO_Port, AIN2_SILNIK_Pin, 0);
	HAL_GPIO_WritePin(AIN1_SILNIK_GPIO_Port, AIN1_SILNIK_Pin, 1);


	HAL_GPIO_WritePin(BIN2_SILNIK_GPIO_Port, BIN2_SILNIK_Pin, 0);
	HAL_GPIO_WritePin(BIN1_SILNIK_GPIO_Port, BIN1_SILNIK_Pin, 1);

}
