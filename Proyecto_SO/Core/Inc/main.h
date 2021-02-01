/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
#define LED_BUILTIN_Pin GPIO_PIN_13
#define LED_BUILTIN_GPIO_Port GPIOC
#define BTN_EXT0_Pin GPIO_PIN_0
#define BTN_EXT0_GPIO_Port GPIOA
#define BTN_EXT1_Pin GPIO_PIN_1
#define BTN_EXT1_GPIO_Port GPIOA
#define BTN_EXT2_Pin GPIO_PIN_2
#define BTN_EXT2_GPIO_Port GPIOA
#define BTN_EXT3_Pin GPIO_PIN_3
#define BTN_EXT3_GPIO_Port GPIOA
#define BTN_EXT4_Pin GPIO_PIN_4
#define BTN_EXT4_GPIO_Port GPIOA
#define LED_EXT7_Pin GPIO_PIN_12
#define LED_EXT7_GPIO_Port GPIOB
#define LED_EXT6_Pin GPIO_PIN_13
#define LED_EXT6_GPIO_Port GPIOB
#define LED_EXT5_Pin GPIO_PIN_14
#define LED_EXT5_GPIO_Port GPIOB
#define LED_EXT4_Pin GPIO_PIN_15
#define LED_EXT4_GPIO_Port GPIOB
#define LED_EXT3_Pin GPIO_PIN_8
#define LED_EXT3_GPIO_Port GPIOA
#define LED_EXT2_Pin GPIO_PIN_7
#define LED_EXT2_GPIO_Port GPIOB
#define LED_EXT1_Pin GPIO_PIN_8
#define LED_EXT1_GPIO_Port GPIOB
#define LED_EXT0_Pin GPIO_PIN_9
#define LED_EXT0_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
