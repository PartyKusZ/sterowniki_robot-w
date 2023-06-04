#include "ultrasound.h"

void init_ultrasound_sensors()
{
	HAL_TIM_IC_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_IC_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);

	HAL_TIM_IC_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_IC_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);

	HAL_TIM_IC_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_IC_Start(&htim3, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
}

void read_distances(float *tab)
{
	uint32_t start;
	uint32_t stop;

	start = HAL_TIM_ReadCapturedValue(&htim1, TIM_CHANNEL_1);
	stop = HAL_TIM_ReadCapturedValue(&htim1, TIM_CHANNEL_2);
	tab[0] = (stop - start) / 58.0f;


	start = HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_1);
	stop = HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_2);
	tab[1]= (stop - start) / 58.0f;


	start = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_1);
	stop = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_2);
	tab[2] = (stop - start) / 58.0f;
}
