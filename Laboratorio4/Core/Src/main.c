/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/

/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

  int contadorDecenas = 1;
  int contadorRGB = 1;
  int modo = 0;
  int estadoateriorsuma = 0;
  int estadoanteriorresta = 0;
  int estadoanteriormodo = 0;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void mododec() {

  int essuma = HAL_GPIO_ReadPin(Boton1_GPIO_Port, Boton1_Pin);
  int esresta = HAL_GPIO_ReadPin(Boton2_GPIO_Port, Boton2_Pin);

//antirebote para los dos botones en el circuito
  HAL_Delay(15);
  if (essuma == 0){
    estadoateriorsuma = 1;
  }
  if (essuma == 1 && estadoateriorsuma == 1){
    contadorDecenas++;

    if (contadorDecenas == 6){
      contadorDecenas = 1;
    }
    estadoateriorsuma = 0;
   HAL_Delay(15);

  }

  if (esresta == 0){
    estadoanteriorresta = 1;
  }
  if (esresta == 1 && estadoanteriorresta == 1){

    if (contadorDecenas == 0){
      contadorDecenas = 6;
    }
    else{
      contadorDecenas--;
    }
    estadoanteriorresta = 0;

    HAL_Delay(15);
  }

//switch case con el contador de decenas
  switch (contadorDecenas){
  case 1:
	  	HAL_GPIO_WritePin(Leddec1_GPIO_Port, Leddec1_Pin, 0);
	  	HAL_GPIO_WritePin(Leddec2_GPIO_Port, Leddec2_Pin, 0);
	  	HAL_GPIO_WritePin(Leddec3_GPIO_Port, Leddec3_Pin, 0);
	  	HAL_GPIO_WritePin(Leddec4_GPIO_Port, Leddec4_Pin, 0);

    break;
  case 2:
	    HAL_GPIO_WritePin(Leddec1_GPIO_Port, Leddec1_Pin, 1);
	    HAL_GPIO_WritePin(Leddec2_GPIO_Port, Leddec2_Pin, 0);
	    HAL_GPIO_WritePin(Leddec3_GPIO_Port, Leddec3_Pin, 0);
	    HAL_GPIO_WritePin(Leddec4_GPIO_Port, Leddec4_Pin, 0);
    break;
  case 3:
	    HAL_GPIO_WritePin(Leddec1_GPIO_Port, Leddec1_Pin, 0);
	    HAL_GPIO_WritePin(Leddec2_GPIO_Port, Leddec2_Pin, 1);
	    HAL_GPIO_WritePin(Leddec3_GPIO_Port, Leddec3_Pin, 0);
	    HAL_GPIO_WritePin(Leddec4_GPIO_Port, Leddec4_Pin, 0);
    break;
  case 4:
	    HAL_GPIO_WritePin(Leddec1_GPIO_Port, Leddec1_Pin, 0);
	    HAL_GPIO_WritePin(Leddec2_GPIO_Port, Leddec2_Pin, 0);
	    HAL_GPIO_WritePin(Leddec3_GPIO_Port, Leddec3_Pin, 1);
	    HAL_GPIO_WritePin(Leddec4_GPIO_Port, Leddec4_Pin, 0);
    break;
  case 5:
	    HAL_GPIO_WritePin(Leddec1_GPIO_Port, Leddec1_Pin, 0);
	    HAL_GPIO_WritePin(Leddec2_GPIO_Port, Leddec2_Pin, 0);
	    HAL_GPIO_WritePin(Leddec3_GPIO_Port, Leddec3_Pin, 0);
	    HAL_GPIO_WritePin(Leddec4_GPIO_Port, Leddec4_Pin, 1);
  }
}

void modoRGB(){
	 int essuma = HAL_GPIO_ReadPin(Boton1_GPIO_Port, Boton1_Pin);
	 int esresta = HAL_GPIO_ReadPin(Boton2_GPIO_Port, Boton2_Pin);

//dos antirebote para los botones en el circuito
  HAL_Delay(15);
  if (essuma == 0){
    estadoateriorsuma = 1;
  }
  if (essuma == 1 && estadoateriorsuma == 1){
    contadorRGB++;

    if (contadorRGB == 8){
      contadorRGB = 7;
    }
    estadoateriorsuma = 0;
    HAL_Delay(15);
  }

  if (esresta == 0){
    estadoanteriorresta = 1;
  }
  if (esresta == 1 && estadoanteriorresta == 1){

    if (contadorRGB == 0){
      contadorRGB = 1;
    }
    else{
      contadorRGB--;
    }
    estadoanteriorresta = 0;
    HAL_Delay(15);
  }

  //switch case con todos los números entre el 0-15
  switch (contadorRGB){
  case 1:
	    HAL_GPIO_WritePin(LedR_GPIO_Port, LedR_Pin, 0);
	    HAL_GPIO_WritePin(LedG_GPIO_Port, LedG_Pin, 0);
	    HAL_GPIO_WritePin(LedB_GPIO_Port, LedB_Pin, 0);

    break;
  case 2:
	    HAL_GPIO_WritePin(LedR_GPIO_Port, LedR_Pin, 1);
	    HAL_GPIO_WritePin(LedG_GPIO_Port, LedG_Pin, 0);
	    HAL_GPIO_WritePin(LedB_GPIO_Port, LedB_Pin, 0);

    break;
  case 3:
	    HAL_GPIO_WritePin(LedR_GPIO_Port, LedR_Pin, 1);
	    HAL_GPIO_WritePin(LedG_GPIO_Port, LedG_Pin, 0);
	    HAL_GPIO_WritePin(LedB_GPIO_Port, LedB_Pin, 1);

    break;
  case 4:
	    HAL_GPIO_WritePin(LedR_GPIO_Port, LedR_Pin, 0);
	    HAL_GPIO_WritePin(LedG_GPIO_Port, LedG_Pin, 0);
	    HAL_GPIO_WritePin(LedB_GPIO_Port, LedB_Pin, 1);

    break;
  case 5:
	    HAL_GPIO_WritePin(LedR_GPIO_Port, LedR_Pin, 0);
	    HAL_GPIO_WritePin(LedG_GPIO_Port, LedG_Pin, 1);
	    HAL_GPIO_WritePin(LedB_GPIO_Port, LedB_Pin, 1);

    break;
  case 6:
	    HAL_GPIO_WritePin(LedR_GPIO_Port, LedR_Pin, 0);
	    HAL_GPIO_WritePin(LedG_GPIO_Port, LedG_Pin, 1);
	    HAL_GPIO_WritePin(LedB_GPIO_Port, LedB_Pin, 0);

    break;
  case 7:
	    HAL_GPIO_WritePin(LedR_GPIO_Port, LedR_Pin, 1);
	    HAL_GPIO_WritePin(LedG_GPIO_Port, LedG_Pin, 1);
	    HAL_GPIO_WritePin(LedB_GPIO_Port, LedB_Pin, 0);

    break;
  }
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Initialize leds */
  BSP_LED_Init(LED2);

  /* Initialize USER push-button, will be used to trigger an interrupt each time it's pressed.*/
  BSP_PB_Init(BUTTON_USER, BUTTON_MODE_EXTI);

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  int esmodo = HAL_GPIO_ReadPin(Boton3_GPIO_Port, Boton3_Pin);
	    HAL_Delay(15);

	  //anti rebote
	    if (esmodo == 1){
	      estadoanteriormodo = 1;
	    }
	    if (esmodo == 0 && estadoanteriormodo == 1){
	      modo++;

	      if (modo == 2){
	        modo = 0;
	      }

	      estadoanteriormodo = 0;
	      HAL_Delay(15);
	    }


	  //Esto es para el cambio sencillo entre ambos modos
	   switch (modo) {
	      case 0:
	        mododec();
		    HAL_GPIO_WritePin(LedModo_GPIO_Port, LedModo_Pin, 0);
		    HAL_GPIO_WritePin(LedR_GPIO_Port, LedR_Pin, 0);
		    HAL_GPIO_WritePin(LedG_GPIO_Port, LedG_Pin, 0);
		    HAL_GPIO_WritePin(LedB_GPIO_Port, LedB_Pin, 0);
	        break;
	      case 1:
	        modoRGB();
		    HAL_GPIO_WritePin(LedModo_GPIO_Port, LedModo_Pin, 1);
		    HAL_GPIO_WritePin(Leddec1_GPIO_Port, Leddec1_Pin, 0);
		    HAL_GPIO_WritePin(Leddec2_GPIO_Port, Leddec2_Pin, 0);
		    HAL_GPIO_WritePin(Leddec3_GPIO_Port, Leddec3_Pin, 0);
		    HAL_GPIO_WritePin(Leddec4_GPIO_Port, Leddec4_Pin, 0);

	        break;
	    }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, Leddec1_Pin|LedB_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LedR_Pin|LedModo_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, Leddec3_Pin|Leddec4_Pin|Leddec2_Pin|LedG_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : Leddec1_Pin LedB_Pin */
  GPIO_InitStruct.Pin = Leddec1_Pin|LedB_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : Boton3_Pin */
  GPIO_InitStruct.Pin = Boton3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(Boton3_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : USART_TX_Pin USART_RX_Pin */
  GPIO_InitStruct.Pin = USART_TX_Pin|USART_RX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : Boton1_Pin */
  GPIO_InitStruct.Pin = Boton1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(Boton1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LedR_Pin LedModo_Pin */
  GPIO_InitStruct.Pin = LedR_Pin|LedModo_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : Boton2_Pin */
  GPIO_InitStruct.Pin = Boton2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(Boton2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : Leddec3_Pin Leddec4_Pin Leddec2_Pin LedG_Pin */
  GPIO_InitStruct.Pin = Leddec3_Pin|Leddec4_Pin|Leddec2_Pin|LedG_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
