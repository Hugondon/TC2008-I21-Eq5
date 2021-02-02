/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
#include <string.h>
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
UART_HandleTypeDef huart1;

osThreadId produceTaskHandle;
osThreadId consumeTaskHandle;
osThreadId menuTaskHandle;
osThreadId despachadorTaskHandle;
osThreadId empacadorTaskHandle;
osThreadId cocineroTaskHandle;
osThreadId cajeroTaskHandle;
osThreadId clienteTaskHandle;
osSemaphoreId binarySem_uartHandle;
osSemaphoreId binarySem_mesa_pedidos_disponibleHandle;
osSemaphoreId binarySem_mesa_hamburguesas_disponibleHandle;
osSemaphoreId binarySem_mesa_ordenes_disponibleHandle;
osSemaphoreId binarySem_mesa_pedidos_ocupadaHandle;
osSemaphoreId binarySem_mesa_hamburguesas_ocupadaHandle;
osSemaphoreId binarySem_mesa_ordenes_ocupadaHandle;
osSemaphoreId binarySem_ordenHandle;
osSemaphoreId binarySem_cocinar_hamburguesasHandle;
osSemaphoreId Sem_lugares_ocupadosHandle;
osSemaphoreId Sem_lugares_disponiblesHandle;
/* USER CODE BEGIN PV */
bool run_first_exercise = false, run_second_exercise = false, run_our_exercise = false;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
void produce(void const * argument);
void consume(void const * argument);
void menu(void const * argument);
void despachador(void const * argument);
void empacador(void const * argument);
void cocinero(void const * argument);
void cajero(void const * argument);
void cliente(void const * argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* definition and creation of binarySem_uart */
  osSemaphoreDef(binarySem_uart);
  binarySem_uartHandle = osSemaphoreCreate(osSemaphore(binarySem_uart), 1);

  /* definition and creation of binarySem_mesa_pedidos_disponible */
  osSemaphoreDef(binarySem_mesa_pedidos_disponible);
  binarySem_mesa_pedidos_disponibleHandle = osSemaphoreCreate(osSemaphore(binarySem_mesa_pedidos_disponible), 1);

  /* definition and creation of binarySem_mesa_hamburguesas_disponible */
  osSemaphoreDef(binarySem_mesa_hamburguesas_disponible);
  binarySem_mesa_hamburguesas_disponibleHandle = osSemaphoreCreate(osSemaphore(binarySem_mesa_hamburguesas_disponible), 1);

  /* definition and creation of binarySem_mesa_ordenes_disponible */
  osSemaphoreDef(binarySem_mesa_ordenes_disponible);
  binarySem_mesa_ordenes_disponibleHandle = osSemaphoreCreate(osSemaphore(binarySem_mesa_ordenes_disponible), 1);

  /* definition and creation of binarySem_mesa_pedidos_ocupada */
  osSemaphoreDef(binarySem_mesa_pedidos_ocupada);
  binarySem_mesa_pedidos_ocupadaHandle = osSemaphoreCreate(osSemaphore(binarySem_mesa_pedidos_ocupada), 1);

  /* definition and creation of binarySem_mesa_hamburguesas_ocupada */
  osSemaphoreDef(binarySem_mesa_hamburguesas_ocupada);
  binarySem_mesa_hamburguesas_ocupadaHandle = osSemaphoreCreate(osSemaphore(binarySem_mesa_hamburguesas_ocupada), 1);

  /* definition and creation of binarySem_mesa_ordenes_ocupada */
  osSemaphoreDef(binarySem_mesa_ordenes_ocupada);
  binarySem_mesa_ordenes_ocupadaHandle = osSemaphoreCreate(osSemaphore(binarySem_mesa_ordenes_ocupada), 1);

  /* definition and creation of binarySem_orden */
  osSemaphoreDef(binarySem_orden);
  binarySem_ordenHandle = osSemaphoreCreate(osSemaphore(binarySem_orden), 1);

  /* definition and creation of binarySem_cocinar_hamburguesas */
  osSemaphoreDef(binarySem_cocinar_hamburguesas);
  binarySem_cocinar_hamburguesasHandle = osSemaphoreCreate(osSemaphore(binarySem_cocinar_hamburguesas), 1);

  /* definition and creation of Sem_lugares_ocupados */
  osSemaphoreDef(Sem_lugares_ocupados);
  Sem_lugares_ocupadosHandle = osSemaphoreCreate(osSemaphore(Sem_lugares_ocupados), 1);

  /* definition and creation of Sem_lugares_disponibles */
  osSemaphoreDef(Sem_lugares_disponibles);
  Sem_lugares_disponiblesHandle = osSemaphoreCreate(osSemaphore(Sem_lugares_disponibles), 2);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  // Ejercicio 7
  osSemaphoreWait(Sem_lugares_ocupadosHandle, osWaitForever);

  // Ejercicio 8
  osSemaphoreWait(binarySem_mesa_pedidos_ocupadaHandle, osWaitForever);
  osSemaphoreWait(binarySem_mesa_hamburguesas_ocupadaHandle, osWaitForever);
  osSemaphoreWait(binarySem_mesa_ordenes_ocupadaHandle, osWaitForever);

  osSemaphoreWait(binarySem_ordenHandle, osWaitForever);
  osSemaphoreWait(binarySem_cocinar_hamburguesasHandle, osWaitForever);

  // Ejercicio propuesto

  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of produceTask */
  osThreadDef(produceTask, produce, osPriorityNormal, 0, 128);
  produceTaskHandle = osThreadCreate(osThread(produceTask), NULL);

  /* definition and creation of consumeTask */
  osThreadDef(consumeTask, consume, osPriorityNormal, 0, 128);
  consumeTaskHandle = osThreadCreate(osThread(consumeTask), NULL);

  /* definition and creation of menuTask */
  osThreadDef(menuTask, menu, osPriorityAboveNormal, 0, 128);
  menuTaskHandle = osThreadCreate(osThread(menuTask), NULL);

  /* definition and creation of despachadorTask */
  osThreadDef(despachadorTask, despachador, osPriorityNormal, 0, 128);
  despachadorTaskHandle = osThreadCreate(osThread(despachadorTask), NULL);

  /* definition and creation of empacadorTask */
  osThreadDef(empacadorTask, empacador, osPriorityNormal, 0, 128);
  empacadorTaskHandle = osThreadCreate(osThread(empacadorTask), NULL);

  /* definition and creation of cocineroTask */
  osThreadDef(cocineroTask, cocinero, osPriorityNormal, 0, 128);
  cocineroTaskHandle = osThreadCreate(osThread(cocineroTask), NULL);

  /* definition and creation of cajeroTask */
  osThreadDef(cajeroTask, cajero, osPriorityNormal, 0, 128);
  cajeroTaskHandle = osThreadCreate(osThread(cajeroTask), NULL);

  /* definition and creation of clienteTask */
  osThreadDef(clienteTask, cliente, osPriorityNormal, 0, 128);
  clienteTaskHandle = osThreadCreate(osThread(clienteTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
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
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_BUILTIN_GPIO_Port, LED_BUILTIN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_EXT7_Pin|LED_EXT6_Pin|LED_EXT5_Pin|LED_EXT4_Pin
                          |LED_EXT1_Pin|LED_EXT0_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_EXT3_GPIO_Port, LED_EXT3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED_BUILTIN_Pin */
  GPIO_InitStruct.Pin = LED_BUILTIN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_BUILTIN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : BTN_EXT0_Pin BTN_EXT1_Pin BTN_EXT2_Pin BTN_EXT3_Pin
                           BTN_EXT4_Pin */
  GPIO_InitStruct.Pin = BTN_EXT0_Pin|BTN_EXT1_Pin|BTN_EXT2_Pin|BTN_EXT3_Pin
                          |BTN_EXT4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_EXT7_Pin LED_EXT6_Pin LED_EXT5_Pin LED_EXT4_Pin
                           LED_EXT1_Pin LED_EXT0_Pin */
  GPIO_InitStruct.Pin = LED_EXT7_Pin|LED_EXT6_Pin|LED_EXT5_Pin|LED_EXT4_Pin
                          |LED_EXT1_Pin|LED_EXT0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : LED_EXT3_Pin */
  GPIO_InitStruct.Pin = LED_EXT3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_EXT3_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED_EXT2_Pin */
  GPIO_InitStruct.Pin = LED_EXT2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(LED_EXT2_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_produce */
/**
  * @brief  Function implementing the produceTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_produce */
void produce(void const * argument)
{
  /* USER CODE BEGIN 5 */
	char *proceso_actual = "Produciendo\r\n";
  /* Infinite loop */
  for(;;)
  {
	  if(run_first_exercise){
		  osSemaphoreWait(Sem_lugares_disponiblesHandle, osWaitForever);			// p(disponibles)

		  // ---------------------------------------------------------------------------------------


		  osSemaphoreWait(binarySem_uartHandle, osWaitForever);				// p(sem)
		  HAL_UART_Transmit(&huart1, (uint8_t *) proceso_actual, strlen(proceso_actual), 1000);
		  osSemaphoreRelease(binarySem_uartHandle);							// v(sem)


		  // ---------------------------------------------------------------------------------------

		  osSemaphoreRelease(Sem_lugares_ocupadosHandle);							// v(ocupados)

		  osDelay(500);
	  }
  }
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_consume */
/**
* @brief Function implementing the consumeTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_consume */
void consume(void const * argument)
{
  /* USER CODE BEGIN consume */
	char *proceso_actual = "Consumiendo\r\n";
  /* Infinite loop */
	  for(;;)
	  {

		  if(run_first_exercise){

			  osSemaphoreWait(Sem_lugares_ocupadosHandle, osWaitForever);					// p(ocupados)
			  osSemaphoreWait(Sem_lugares_ocupadosHandle, osWaitForever);					// p(ocupados)

			  // ---------------------------------------------------------------------------------------


			  osSemaphoreWait(binarySem_uartHandle, osWaitForever);					// p(sem)
			  HAL_UART_Transmit(&huart1, (uint8_t *) proceso_actual, strlen(proceso_actual), 1000);
			  osSemaphoreRelease(binarySem_uartHandle);								// v(sem)


			  // ---------------------------------------------------------------------------------------

			  osSemaphoreRelease(Sem_lugares_disponiblesHandle);							// v(disponibles)
			  osSemaphoreRelease(Sem_lugares_disponiblesHandle);							// v(disponibles)

			  osDelay(500);
		  }
	  }
  /* USER CODE END consume */
}

/* USER CODE BEGIN Header_menu */
/**
* @brief Function implementing the menuTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_menu */
void menu(void const * argument)
{
  /* USER CODE BEGIN menu */
  /* Infinite loop */
  for(;;)
  {
	  if(!HAL_GPIO_ReadPin(BTN_EXT2_GPIO_Port, BTN_EXT2_Pin)){
		  // 1
		  // osSemaphoreRelease(binarySem_ejercicio_sieteHandle);

		  /* Indicadores */
		  HAL_GPIO_TogglePin(LED_EXT0_GPIO_Port, LED_EXT0_Pin);
		  HAL_GPIO_WritePin(LED_EXT1_GPIO_Port, LED_EXT1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_EXT2_GPIO_Port, LED_EXT2_Pin, GPIO_PIN_RESET);

		  /* Banderas */
		  run_first_exercise = !run_first_exercise;
		  run_second_exercise = false;
		  run_our_exercise = false;
	  }
	  if(!HAL_GPIO_ReadPin(BTN_EXT3_GPIO_Port, BTN_EXT3_Pin)){
		  // 2

		  /* Indicadores */
		  HAL_GPIO_WritePin(LED_EXT0_GPIO_Port, LED_EXT0_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_TogglePin(LED_EXT1_GPIO_Port, LED_EXT1_Pin);
		  HAL_GPIO_WritePin(LED_EXT2_GPIO_Port, LED_EXT2_Pin, GPIO_PIN_RESET);

		  /* Banderas */
		  run_first_exercise = false;
		  run_second_exercise = !run_second_exercise;
		  run_our_exercise = false;
	  }
	  if(!HAL_GPIO_ReadPin(BTN_EXT4_GPIO_Port, BTN_EXT4_Pin)){
		  // 3

		  /* Indicadores */
		  HAL_GPIO_WritePin(LED_EXT0_GPIO_Port, LED_EXT0_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(LED_EXT1_GPIO_Port, LED_EXT1_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_TogglePin(LED_EXT2_GPIO_Port, LED_EXT2_Pin);
		  HAL_GPIO_TogglePin(LED_BUILTIN_GPIO_Port, LED_BUILTIN_Pin);
		  /* Banderas */
		  run_first_exercise = false;
		  run_second_exercise = false;
		  run_our_exercise = !run_our_exercise;
	  }
	 osDelay(200);
  }
  /* USER CODE END menu */
}

/* USER CODE BEGIN Header_despachador */
/**
* @brief Function implementing the despachadorTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_despachador */
void despachador(void const * argument)
{
  /* USER CODE BEGIN despachador */
	char *proceso_actual = "Despachando orden\r\n";
  /* Infinite loop */
	  for(;;)
	  {
		  if(run_second_exercise){
			  osSemaphoreWait(binarySem_ordenHandle, osWaitForever);									// p(sem)
			  osSemaphoreWait(binarySem_mesa_ordenes_disponibleHandle, osWaitForever);					// p(sem)

			  // ---------------------------------------------------------------------------------------


			  osSemaphoreWait(binarySem_uartHandle, osWaitForever);					// p(sem)
			  HAL_UART_Transmit(&huart1, (uint8_t *) proceso_actual, strlen(proceso_actual), 1000);
			  osSemaphoreRelease(binarySem_uartHandle);								// v(sem)


			  // ---------------------------------------------------------------------------------------
			  osSemaphoreRelease(binarySem_cocinar_hamburguesasHandle);
			  osSemaphoreRelease(binarySem_mesa_ordenes_ocupadaHandle);
		  }
		  osDelay(200);
	  }
  /* USER CODE END despachador */
}

/* USER CODE BEGIN Header_empacador */
/**
* @brief Function implementing the empacadorTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_empacador */
void empacador(void const * argument)
{
  /* USER CODE BEGIN empacador */
	char *proceso_actual = "Empacador\r\n";
  /* Infinite loop */
	  for(;;)
	  {

		  if(run_second_exercise){

			  osSemaphoreWait(binarySem_mesa_ordenes_ocupadaHandle,osWaitForever);
			  osSemaphoreWait(binarySem_mesa_hamburguesas_ocupadaHandle,osWaitForever);
			  // osSemaphoreWait(binarySem_mesa_ordenes_disponibleHandle,osWaitForever);


			  // ---------------------------------------------------------------------------------------


			  osSemaphoreWait(binarySem_uartHandle, osWaitForever);					// p(sem)
			  HAL_UART_Transmit(&huart1, (uint8_t *) proceso_actual, strlen(proceso_actual), 1000);
			  osSemaphoreRelease(binarySem_uartHandle);								// v(sem)


			  // ---------------------------------------------------------------------------------------

			  osSemaphoreRelease(binarySem_mesa_hamburguesas_disponibleHandle);
			  osSemaphoreRelease(binarySem_mesa_ordenes_disponibleHandle);
			  osSemaphoreRelease(binarySem_mesa_pedidos_ocupadaHandle);

		  }
		  osDelay(200);
	  }
  /* USER CODE END empacador */
}

/* USER CODE BEGIN Header_cocinero */
/**
* @brief Function implementing the cocineroTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_cocinero */
void cocinero(void const * argument)
{
  /* USER CODE BEGIN cocinero */
	char *proceso_actual = "Cocinero\r\n";
  /* Infinite loop */
	  for(;;)
	  {

		  if(run_second_exercise){

			  osSemaphoreWait(binarySem_cocinar_hamburguesasHandle, osWaitForever);
			  osSemaphoreWait(binarySem_mesa_hamburguesas_disponibleHandle, osWaitForever);

			  // ---------------------------------------------------------------------------------------


			  osSemaphoreWait(binarySem_uartHandle, osWaitForever);					// p(sem)
			  HAL_UART_Transmit(&huart1, (uint8_t *) proceso_actual, strlen(proceso_actual), 1000);
			  osSemaphoreRelease(binarySem_uartHandle);								// v(sem)


			  // ---------------------------------------------------------------------------------------

			  osSemaphoreRelease(binarySem_mesa_hamburguesas_ocupadaHandle);

		  }
		  osDelay(200);
	  }
  /* USER CODE END cocinero */
}

/* USER CODE BEGIN Header_cajero */
/**
* @brief Function implementing the cajeroTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_cajero */
void cajero(void const * argument)
{
  /* USER CODE BEGIN cajero */
	char *proceso_actual = "Cajero\r\n";
  /* Infinite loop */
	  for(;;)
	  {

		  if(run_second_exercise){

			  osSemaphoreWait(binarySem_mesa_pedidos_ocupadaHandle, osWaitForever);

			  // ---------------------------------------------------------------------------------------


			  osSemaphoreWait(binarySem_uartHandle, osWaitForever);					// p(sem)
			  HAL_UART_Transmit(&huart1, (uint8_t *) proceso_actual, strlen(proceso_actual), 1000);
			  osSemaphoreRelease(binarySem_uartHandle);								// v(sem)


			  // ---------------------------------------------------------------------------------------

			  osSemaphoreRelease(binarySem_mesa_pedidos_disponibleHandle);

		  }
		  osDelay(200);
	  }
  /* USER CODE END cajero */
}

/* USER CODE BEGIN Header_cliente */
/**
* @brief Function implementing the clienteTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_cliente */
void cliente(void const * argument)
{
  /* USER CODE BEGIN cliente */
	char *proceso_actual = "Pedido del cliente\r\n";
  /* Infinite loop */
	  for(;;)
	  {

		  if(run_second_exercise && !HAL_GPIO_ReadPin(BTN_EXT0_GPIO_Port, BTN_EXT0_Pin)){
				  // ---------------------------------------------------------------------------------------


				  osSemaphoreWait(binarySem_uartHandle, osWaitForever);					// p(sem)
				  HAL_UART_Transmit(&huart1, (uint8_t *) proceso_actual, strlen(proceso_actual), 1000);
				  osSemaphoreRelease(binarySem_uartHandle);								// v(sem)


				  // ---------------------------------------------------------------------------------------

				  osSemaphoreRelease(binarySem_ordenHandle);								// v(sem)
		  }
		  osDelay(200);
	  }
  /* USER CODE END cliente */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
