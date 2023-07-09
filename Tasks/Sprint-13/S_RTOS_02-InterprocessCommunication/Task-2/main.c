/*
 * FreeRTOS Kernel V10.2.0
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* 
	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used.
*/


/*
 * Creates all the demo application tasks, then starts the scheduler.  The WEB
 * documentation provides more details of the demo application tasks.
 * 
 * Main.c also creates a task called "Check".  This only executes every three 
 * seconds but has the highest priority so is guaranteed to get processor time.  
 * Its main function is to check that all the other tasks are still operational.
 * Each task (other than the "flash" tasks) maintains a unique count that is 
 * incremented each time the task successfully completes its function.  Should 
 * any error occur within such a task the count is permanently halted.  The 
 * check task inspects the count of each task to ensure it has changed since
 * the last time the check task executed.  If all the count variables have 
 * changed all the tasks are still executing error free, and the check task
 * toggles the onboard LED.  Should any task contain an error at any time 
 * the LED toggle rate will change from 3 seconds to 500ms.
 *
 */

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
//#include "queue.h"
#include "task.h"
#include "semphr.h"
#include "lpc21xx.h"

/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"


/*-----------------------------------------------------------*/

/* Constants to setup I/O and processor. */
#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )

/* Constants for the ComTest demo application tasks. */
#define mainCOM_TEST_BAUD_RATE	( ( unsigned long ) 115200 )
	
#define PRI_1							1
#define PRI_2							2

#define SERIAL_1_PERIDOICITY	100 
#define SERIAL_2_PERIDOICITY	500 
#define BTN_NOT_PRESSED				0
#define BTN_PRESSED						1

#define HEAVY_LOAD_COUNT					100000
#define SERIAL_STR_REPEAT_COUNT		10
#define SERIAL_STR_SIZE						15
/*
 * Configure the processor for use with the Keil demo board.  This is very
 * minimal as most of the setup is managed by the settings in the project
 * file.
 */
static void prvSetupHardware( void );

/* Task Prototypes */
static void Serial_Task1(void* parameters);
static void Serial_Task2(void* parameters);

/* Global Variables */

SemaphoreHandle_t gl_sem_serial_access;

TaskHandle_t Serial1Task_Handler = NULL;
TaskHandle_t Serial2Task_Handler = NULL;
/*-----------------------------------------------------------*/
/*
 * Application entry point:
 * Starts all the other tasks, then starts the scheduler. 
 */
int main( void )
{
	/* Setup the hardware for use with the Keil demo board. */
	prvSetupHardware();

	gl_sem_serial_access = xSemaphoreCreateBinary();
	
  /* Create Tasks here */
	xTaskCreate(Serial_Task2, "Serial_500", configMINIMAL_STACK_SIZE, NULL, PRI_2, &Serial2Task_Handler);
	xTaskCreate(Serial_Task1, "Serial_100", configMINIMAL_STACK_SIZE, NULL, PRI_1, &Serial1Task_Handler);		
	
	/* Now all the tasks have been started - start the scheduler.

	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used here. */
	vTaskStartScheduler();

	/* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */
	for( ;; );
}
/*-----------------------------------------------------------*/
/* Tasks																										 */
/*-----------------------------------------------------------*/

void Serial_Task1(void* parameters)
{
	static UBaseType_t ux_sem_take;
	static const char* ptr_char_task1_str = "Task 1 string\n\r";
	
	uint8_t lo_u8_counter;
	xSemaphoreGive(gl_sem_serial_access);
	
	for(;;)
	{
		ux_sem_take = xSemaphoreTake(gl_sem_serial_access, portMAX_DELAY);
		if(pdTRUE == ux_sem_take)
		{
			for(lo_u8_counter=0; lo_u8_counter < SERIAL_STR_REPEAT_COUNT; lo_u8_counter++)
			{
				while(pdFALSE == vSerialPutString((const signed char*)ptr_char_task1_str, SERIAL_STR_SIZE));
			}
			
			/* Release the semaphore */
			xSemaphoreGive(gl_sem_serial_access);
			vTaskDelay(SERIAL_1_PERIDOICITY);
		}		
	}
}


void Serial_Task2(void* parameters)
{
	static UBaseType_t ux_sem_take;
	
	static const char* ptr_char_task2_str = "Task 2 string\n\r";
	
	uint8_t lo_u8_write_counter;
	uint32_t lo_u32_count;
	
	for(;;)
	{		
		ux_sem_take = xSemaphoreTake(gl_sem_serial_access, portMAX_DELAY);
		if(pdTRUE == ux_sem_take)
		{
			for(lo_u8_write_counter=0; lo_u8_write_counter < SERIAL_STR_REPEAT_COUNT; lo_u8_write_counter++)
			{
				/* Write string */
				while(pdFALSE == vSerialPutString((const signed char*)ptr_char_task2_str, SERIAL_STR_SIZE));
				
				/* Heavy load simulation */
				for(lo_u32_count=0; lo_u32_count < HEAVY_LOAD_COUNT; lo_u32_count++);
			}
			
			/* Release the semaphore */
			xSemaphoreGive(gl_sem_serial_access);
			vTaskDelay(SERIAL_2_PERIDOICITY);
		}		
	}
}

/* Function to reset timer 1 */
void timer1Reset(void)
{
	T1TCR |= 0x2;
	T1TCR &= ~0x2;
}

/* Function to initialize and start timer 1 */
static void configTimer1(void)
{
	T1PR = 1000;
	T1TCR |= 0x1;
}

static void prvSetupHardware( void )
{
	/* Perform the hardware setup required.  This is minimal as most of the
	setup is managed by the settings in the project file. */

	/* Configure UART */
	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

	/* Configure GPIO */
	GPIO_init();
	
	/* Config trace timer 1 and read T1TC to get current tick */
	configTimer1();

	/* Setup the peripheral bus to be the same as the PLL output. */
	VPBDIV = mainBUS_CLK_FULL;
}
/*-----------------------------------------------------------*/


