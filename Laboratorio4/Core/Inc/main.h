/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f4xx_hal.h"

#include "stm32f4xx_nucleo.h"

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
#define Leddec1_Pin GPIO_PIN_0
#define Leddec1_GPIO_Port GPIOC
#define Boton3_Pin GPIO_PIN_1
#define Boton3_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define Boton1_Pin GPIO_PIN_4
#define Boton1_GPIO_Port GPIOA
#define LedR_Pin GPIO_PIN_7
#define LedR_GPIO_Port GPIOA
#define Boton2_Pin GPIO_PIN_0
#define Boton2_GPIO_Port GPIOB
#define Leddec3_Pin GPIO_PIN_10
#define Leddec3_GPIO_Port GPIOB
#define LedB_Pin GPIO_PIN_7
#define LedB_GPIO_Port GPIOC
#define LedModo_Pin GPIO_PIN_10
#define LedModo_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define Leddec4_Pin GPIO_PIN_3
#define Leddec4_GPIO_Port GPIOB
#define Leddec2_Pin GPIO_PIN_4
#define Leddec2_GPIO_Port GPIOB
#define LedG_Pin GPIO_PIN_6
#define LedG_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
