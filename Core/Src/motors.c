#include "motors.h"


void motors_init(){
	HAL_TIM_Base_Start_IT(&htim16);
	HAL_TIM_Base_Start_IT(&htim17);
	HAL_TIM_PWM_Start(&htim16, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim17, TIM_CHANNEL_1);
	__HAL_TIM_SetCompare(&htim17, TIM_CHANNEL_1, 0);
	__HAL_TIM_SetCompare(&htim16, TIM_CHANNEL_1, 0);
}

void set_speed(volatile uint8_t *state){
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


void go(volatile uint8_t *state)
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
	__HAL_TIM_SetCompare(&htim16, TIM_CHANNEL_1, 0);
	__HAL_TIM_SetCompare(&htim17, TIM_CHANNEL_1, 0);

}


void turn_right()
{
	HAL_GPIO_WritePin(AIN2_SILNIK_GPIO_Port, AIN2_SILNIK_Pin, 1);
	HAL_GPIO_WritePin(AIN1_SILNIK_GPIO_Port, AIN1_SILNIK_Pin, 0);


	HAL_GPIO_WritePin(BIN2_SILNIK_GPIO_Port, BIN2_SILNIK_Pin, 1);
	HAL_GPIO_WritePin(BIN1_SILNIK_GPIO_Port, BIN1_SILNIK_Pin, 0);
	__HAL_TIM_SetCompare(&htim16, TIM_CHANNEL_1, TURNING_SPEED);
	__HAL_TIM_SetCompare(&htim17, TIM_CHANNEL_1, TURNING_SPEED);

}

void turn_left()
{
	HAL_GPIO_WritePin(AIN2_SILNIK_GPIO_Port, AIN2_SILNIK_Pin, 0);
	HAL_GPIO_WritePin(AIN1_SILNIK_GPIO_Port, AIN1_SILNIK_Pin, 1);


	HAL_GPIO_WritePin(BIN2_SILNIK_GPIO_Port, BIN2_SILNIK_Pin, 0);
	HAL_GPIO_WritePin(BIN1_SILNIK_GPIO_Port, BIN1_SILNIK_Pin, 1);
	__HAL_TIM_SetCompare(&htim16, TIM_CHANNEL_1, TURNING_SPEED);
	__HAL_TIM_SetCompare(&htim17, TIM_CHANNEL_1, TURNING_SPEED);


}

uint8_t find_min_dist_index(float *tab){
	uint8_t min_index = 0;
	for (uint8_t i 	= 0; i < 3; ++i) {
		if(tab[i] < tab[min_index]){
			min_index = i;
		}
	}
	return min_index;
}

uint8_t find_max_dist_index(float *tab){
	uint8_t max_index = 0;
	for (uint8_t i 	= 0; i < 3; ++i) {
		if(tab[i] > tab[max_index]){
			max_index = i;
		}
	}
	return max_index;
}


void control(volatile uint8_t *state,float *tab){
	uint8_t min_dist_index;
	uint8_t max_dist_index;
	if(tab[0] > SECURE_DISTANCE && tab[1] > SECURE_DISTANCE && tab[2] > SECURE_DISTANCE ){
		go(state);
	}else{
		min_dist_index = find_min_dist_index(tab);
		if(min_dist_index == FRONT_ULTRASOUND){
			max_dist_index = find_max_dist_index(tab);
			if(max_dist_index == LEFT_ULTRASOUND){
				turn_left();
			}
			if(max_dist_index == RIGHT_ULTRASOUND){
				turn_right();
			}
		}else if(min_dist_index == LEFT_ULTRASOUND){
			turn_right();
		}else if(min_dist_index == RIGHT_ULTRASOUND){
			turn_left();
		}
	}
}
