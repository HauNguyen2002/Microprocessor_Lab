/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
void sec(int co,int st,int min)
{
	if(co>0&&co<=50)
		{
			if(st==1)
			{
				if(min!=0)
				{
					if(min<55)
						{
							HAL_GPIO_TogglePin(led_11_GPIO_Port, led_11_Pin);
						}
					HAL_GPIO_WritePin(led_0_GPIO_Port, led_0_Pin,SET);
				}
			}
		}
		else if (co>50 &&co<=100)
		{
			if(st==1)
			{
				if(min>4)
				{
					HAL_GPIO_TogglePin(led_0_GPIO_Port, led_0_Pin);
				}
				if(min!=5)
				{
					HAL_GPIO_WritePin(led_1_GPIO_Port, led_1_Pin, SET);
				}
			}
		}
		else if (co>100 &&co<=150)
		{
			if(st==1)
			{
				if(min<5 || min>9)
				{
					HAL_GPIO_TogglePin(led_1_GPIO_Port, led_1_Pin);
				}
				if(min!=10)
				{
					HAL_GPIO_WritePin(led_2_GPIO_Port, led_2_Pin,SET);
				}
			}
		}
		else if (co>150 &&co<=200)
		{
			if(st==1)
			{
				if(min<10||min>14)
				{
					HAL_GPIO_TogglePin(led_2_GPIO_Port, led_2_Pin);
				}
				if(min!=15)
				{
				HAL_GPIO_WritePin(led_3_GPIO_Port, led_3_Pin,SET);
				}
			}
		}
		else if (co>200 &&co<=250)
		{
			if(st==1)
			{
				if(min<15||min>19)
				{
					HAL_GPIO_TogglePin(led_3_GPIO_Port, led_3_Pin);
				}
				if(min!=20)
				{
				HAL_GPIO_WritePin(led_4_GPIO_Port, led_4_Pin,SET);
				}
			}
		}
		else if (co>250 &&co<=300)
		{
			if(st==1)
			{
				if(min<20||min>24)
				{
					HAL_GPIO_TogglePin(led_4_GPIO_Port, led_4_Pin);
				}
				if(min!=25)
				{
				HAL_GPIO_WritePin(led_5_GPIO_Port, led_5_Pin,SET);
				}
			}
		}
		else if (co>300 &&co<=350)
		{
			if(st==1)
			{
				if(min<25||min>29)
				{
					HAL_GPIO_TogglePin(led_5_GPIO_Port, led_5_Pin);
				}
				if(min!=30)
				{
				HAL_GPIO_WritePin(led_6_GPIO_Port, led_6_Pin,SET);
				}
			}
		}
		else if (co>350 &&co<=400)
		{
			if(st==1)
			{
				if(min<30||min>34)
				{
					HAL_GPIO_TogglePin(led_6_GPIO_Port, led_6_Pin);
				}
				if(min!=35)
				{
				HAL_GPIO_WritePin(led_7_GPIO_Port, led_7_Pin,SET);
				}
			}
		}
		else if (co>400 &&co<=450)
		{
			if(st==1)
			{
				if(min<36||min>40)
				{
					HAL_GPIO_TogglePin(led_7_GPIO_Port, led_7_Pin);
				}
				if(min!=41)
				{
				HAL_GPIO_WritePin(led_8_GPIO_Port, led_8_Pin,SET);
				}
			}
		}
		else if (co>450 &&co<=500)
		{
			if(st==1)
			{
				if(min<41||min>45)
				{
					HAL_GPIO_TogglePin(led_8_GPIO_Port, led_8_Pin);
				}
				if(min!=46)
				{
				HAL_GPIO_WritePin(led_9_GPIO_Port, led_9_Pin,SET);
				}
			}
		}
		else if (co>500 &&co<=550)
		{
			if(st==1)
			{
				if(min<46||min>50)
				{
					HAL_GPIO_TogglePin(led_9_GPIO_Port, led_9_Pin);
				}
				if(min!=51)
				{
				HAL_GPIO_WritePin(led_10_GPIO_Port, led_10_Pin,SET);
				}
			}
		}
		else if (co>550 &&co<=600)
		{
			if(st==1)
			{
				if(min<51||min>55)
				{
					HAL_GPIO_TogglePin(led_10_GPIO_Port, led_10_Pin);
				}
				if(min!=56)
				{
					HAL_GPIO_WritePin(led_11_GPIO_Port, led_11_Pin,SET);
				}
			}
		}

}
void min(int min)
{
		switch(min)
		{
		case 0:
			HAL_GPIO_WritePin(GPIOA, led_0_Pin, SET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOA, led_0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, led_1_Pin, SET);
			break;
		case 10:
			HAL_GPIO_WritePin(GPIOA, led_1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, led_2_Pin, SET);
			break;
		case 15:
			HAL_GPIO_WritePin(GPIOA, led_2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, led_3_Pin, SET);
			break;
		case 20:
			HAL_GPIO_WritePin(GPIOA, led_3_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, led_4_Pin, SET);
			break;
		case 25:
			HAL_GPIO_WritePin(GPIOA, led_4_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, led_5_Pin, SET);
			break;
		case 30:
			HAL_GPIO_WritePin(GPIOA, led_5_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, led_6_Pin, SET);
			break;
		case 35:
			HAL_GPIO_WritePin(GPIOA, led_6_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, led_7_Pin, SET);
			break;
		case 40:
			HAL_GPIO_WritePin(GPIOA, led_7_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, led_8_Pin, SET);
			break;
		case 45:
			HAL_GPIO_WritePin(GPIOA, led_8_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, led_9_Pin, SET);
			break;
		case 50:
			HAL_GPIO_WritePin(GPIOA, led_9_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, led_10_Pin, SET);
			break;
		case 55:
			HAL_GPIO_WritePin(GPIOA, led_10_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, led_11_Pin, SET);
			break;
		case 60:
			HAL_GPIO_WritePin(GPIOA, led_11_Pin,RESET);
			HAL_GPIO_WritePin(GPIOA, led_0_Pin, SET);
			break;
		default:
			break;
		}
}
void clearAllClock ()
{
	HAL_GPIO_WritePin(GPIOA, led_0_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, led_1_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, led_2_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, led_3_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, led_4_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, led_5_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, led_6_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, led_7_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, led_8_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, led_9_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, led_10_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, led_11_Pin, RESET);
}
void setNumberOnClock(int num)
{
	switch (num)
	{
	case 0:
		HAL_GPIO_WritePin(GPIOA, led_0_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, led_1_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, led_2_Pin, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, led_3_Pin, SET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOA, led_4_Pin, SET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOA, led_5_Pin, SET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOA, led_6_Pin, SET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOA, led_7_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOA, led_8_Pin, SET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOA, led_9_Pin, SET);
		break;
	case 10:
		HAL_GPIO_WritePin(GPIOA, led_10_Pin, SET);
		break;
	case 11:
		HAL_GPIO_WritePin(GPIOA, led_11_Pin, SET);
		break;
	default:
		break;
	}
}
void clearNumberOnClock(int num)
{
	switch (num)
	{
	case 0:
		HAL_GPIO_WritePin(GPIOA, led_0_Pin, RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, led_1_Pin, RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, led_2_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, led_3_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOA, led_4_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOA, led_5_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOA, led_6_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOA, led_7_Pin, RESET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOA, led_8_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOA, led_9_Pin, RESET);
		break;
	case 10:
		HAL_GPIO_WritePin(GPIOA, led_10_Pin, RESET);
		break;
	case 11:
		HAL_GPIO_WritePin(GPIOA, led_11_Pin, RESET);
		break;
	default:
		break;
	}
}
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
  	  int count=1;
  	  int countmin=0;
  	  int state=0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if (count>600)
	  {
		  count=1;
		  countmin++;
		  if (countmin>60) countmin=0;
	  }
	  (count%50==0)? (state=1):(state=0);
	  sec(count,state,countmin);
	  if(countmin%5==0) min(countmin);
	  count++;
	  HAL_Delay(1);
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
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

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, led_0_Pin|led_1_Pin|led_2_Pin|led_3_Pin
                          |led_4_Pin|led_5_Pin|led_6_Pin|led_7_Pin
                          |led_8_Pin|led_9_Pin|led_10_Pin|led_11_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : led_0_Pin led_1_Pin led_2_Pin led_3_Pin
                           led_4_Pin led_5_Pin led_6_Pin led_7_Pin
                           led_8_Pin led_9_Pin led_10_Pin led_11_Pin */
  GPIO_InitStruct.Pin = led_0_Pin|led_1_Pin|led_2_Pin|led_3_Pin
                          |led_4_Pin|led_5_Pin|led_6_Pin|led_7_Pin
                          |led_8_Pin|led_9_Pin|led_10_Pin|led_11_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

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

#ifdef  USE_FULL_ASSERT
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
