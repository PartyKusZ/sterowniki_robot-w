/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MCO_Pin GPIO_PIN_0
#define MCO_GPIO_Port GPIOF
#define ULT2_ECHO_Pin GPIO_PIN_0
#define ULT2_ECHO_GPIO_Port GPIOA
#define VCP_TX_Pin GPIO_PIN_2
#define VCP_TX_GPIO_Port GPIOA
#define VCP_RX_Pin GPIO_PIN_3
#define VCP_RX_GPIO_Port GPIOA
#define BIN2_SILNIK_Pin GPIO_PIN_4
#define BIN2_SILNIK_GPIO_Port GPIOA
#define PWM_SILNIK_2_Pin GPIO_PIN_7
#define PWM_SILNIK_2_GPIO_Port GPIOA
#define ULT3_TRIG_Pin GPIO_PIN_0
#define ULT3_TRIG_GPIO_Port GPIOB
#define ULT1_ECHO_Pin GPIO_PIN_8
#define ULT1_ECHO_GPIO_Port GPIOA
#define ULT2_TRIG_Pin GPIO_PIN_9
#define ULT2_TRIG_GPIO_Port GPIOA
#define ULT1_TRIG_Pin GPIO_PIN_10
#define ULT1_TRIG_GPIO_Port GPIOA
#define BIN1_SILNIK_Pin GPIO_PIN_11
#define BIN1_SILNIK_GPIO_Port GPIOA
#define PWM_SILNIK_1_Pin GPIO_PIN_12
#define PWM_SILNIK_1_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define AIN1_SILNIK_Pin GPIO_PIN_3
#define AIN1_SILNIK_GPIO_Port GPIOB
#define ULT3_ECHO_Pin GPIO_PIN_4
#define ULT3_ECHO_GPIO_Port GPIOB
#define AIN2_SILNIK_Pin GPIO_PIN_5
#define AIN2_SILNIK_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
