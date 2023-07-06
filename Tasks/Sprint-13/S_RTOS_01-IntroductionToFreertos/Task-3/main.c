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

#include "bit_math.h"

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "lpc21xx.h"

/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"


/*-----------------------------------------------------------*/

/* Constants to setup I/O and processor. */
#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )

/* Constants for the ComTest demo application tasks. */
#define mainCOM_TEST_BAUD_RATE	( ( unsigned long ) 115200 )
	
#define BIT_0									0

#define _2_SECONDS						2000
#define _4_SECONDS						4000

#define LED1_BLINK_DELAY				100 
#define LED2_BLINK_DELAY				400 

#define LED_PORT							PORT_0
#define LED_PIN								PIN1

#define BTN_PORT							PORT_0
#define BTN_PIN								PIN0
#define BTN_READ_PERIDOICITY				10
#define BTN_DEBOUNCE_DELAY					100
#define BTN_NOT_PRESSED						0
#define BTN_PRESSED							1

#define PRI_1									1
#define PRI_2									2

/*
 * Configure the processor for use with the Keil demo board.  This is very
 * minimal as most of the setup is managed by the settings in the project
 * file.
 */
static void prvSetupHardware( void );

/* Task Prototypes */
void Led1_Task(void* parameters);
void Led2_Task(void* parameters);
void ReadButton_Task(void* parameters);

/* Global Variables */
TaskHandle_t Led1Task_Handler = NULL;
TaskHandle_t Led2Task_Handler = NULL;
TaskHandle_t ButtonTask_Handler = NULL;

/*-----------------------------------------------------------*/
/*
 * Application entry point:
 * Starts all the other tasks, then starts the scheduler. 
 */
int main( void )
{
	/* Setup the hardware for use with the Keil demo board. */
	prvSetupHardware();

	
  /* Create Tasks here */
	/*          pvTaskCode      , pcName    ,		usStackDepth  				, pvParameters, uxPriority,  pxCreatedTask */
	xTaskCreate(ReadButton_Task	, "Button"    , configMINIMAL_STACK_SIZE, NULL			, PRI_2			, &ButtonTask_Handler);	
	xTaskCreate(Led1_Task	    , "Led 1 Task", configMINIMAL_STACK_SIZE, NULL				, PRI_1			, &Led1Task_Handler);	
	xTaskCreate(Led2_Task	    , "Led 2 Task", configMINIMAL_STACK_SIZE, NULL				, PRI_1			, &Led2Task_Handler);	

	vTaskSuspend(Led1Task_Handler);
	vTaskSuspend(Led2Task_Handler);
	
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

/**
 * @brief Task that controls an LED to blink
 * 				every 100 milli seconds
 */
void Led1_Task(void* parameters)
{
	pinState_t lo_en_led_state;
	
	for(;;)
	{
		/* Get LED state */
		lo_en_led_state = GPIO_read(LED_PORT, LED_PIN);
		
		/* Toggle LED state */
		TOG_BIT(lo_en_led_state, BIT_0);
		
		/* Write new LED state */
		GPIO_write(LED_PORT, LED_PIN, lo_en_led_state);
		
		vTaskDelay(LED1_BLINK_DELAY);
	}
}

/**
 * @brief Task that controls an LED to blink
 * 			 every 500 milli seconds
 */
void Led2_Task(void* parameters)
{
	pinState_t lo_en_led_state;
	
	for(;;)
	{
		/* Get LED state */
		lo_en_led_state = GPIO_read(LED_PORT, LED_PIN);
		
		/* Toggle LED state */
		TOG_BIT(lo_en_led_state, BIT_0);
		
		/* Write new LED state */
		GPIO_write(LED_PORT, LED_PIN, lo_en_led_state);
		
		vTaskDelay(LED2_BLINK_DELAY);
	}
}

/**
 * @brief Task that controls the blinking
 *		  mode of an LED by push button state 
 */
void ReadButton_Task(void* parameters)
{
	pinState_t lo_en_btn_state;
	volatile uint32_t lo_u32_elapsed_time;
	static UBaseType_t ux_counter;
	
	for(;;)
	{
		lo_en_btn_state = GPIO_read(BTN_PORT, BTN_PIN);
		
		if(BTN_PRESSED == lo_en_btn_state)
		{
			/* Delay for debouncing */
			if(!ux_counter)	vTaskDelay(BTN_DEBOUNCE_DELAY);
			
			ux_counter++;
		}
		else if(ux_counter != 0)
		{
			/* Get elapsed time */
			lo_u32_elapsed_time = (ux_counter * BTN_READ_PERIDOICITY) + BTN_DEBOUNCE_DELAY;
			
			if(lo_u32_elapsed_time < _2_SECONDS) 
			{
				/* Suspend all tasks */
				vTaskSuspend(Led1Task_Handler);
				vTaskSuspend(Led2Task_Handler);
				
				/* Reset the counter */
				ux_counter = 0;
				lo_u32_elapsed_time = 0;
				
				/* Turn the LED off */
				GPIO_write(LED_PORT, LED_PIN, PIN_IS_LOW);
			}
			else if(lo_u32_elapsed_time < _4_SECONDS)
			{
				/* Suspend all other tasks */
				vTaskSuspend(Led1Task_Handler);
				
				/* Reset the counter */
				ux_counter = 0;
				lo_u32_elapsed_time = 0;
				
				/* Resume the task with right blinking mode */
				vTaskResume(Led2Task_Handler);
			}
			else if(lo_u32_elapsed_time > _4_SECONDS)
			{
				/* Suspend all other tasks */
				vTaskSuspend(Led2Task_Handler);
				
				/* Reset the counter */
				ux_counter = 0;
				lo_u32_elapsed_time = 0;
				
				/* Resume the task with right blinking mode */
				vTaskResume(Led1Task_Handler);
			}
		}
		
		vTaskDelay(BTN_READ_PERIDOICITY);
	}
}


/*-----------------------------------------------------------*/

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


