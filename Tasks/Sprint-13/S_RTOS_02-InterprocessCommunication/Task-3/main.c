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
	
#define PRI_3                 3
#define PRI_2                 2
#define PRI_1                 1

#define BTN_1_PORT						PORT_0
#define BTN_1_PIN							PIN0
#define BTN_2_PORT						PORT_0
#define BTN_2_PIN							PIN1
#define BTN_READ_PERIDOICITY	10 
#define BTN_DEBOUNCE_DELAY		100
#define BTN_NOT_PRESSED				0
#define BTN_PRESSED						1

#define SERIAL_TASK_PERIODICITY 100

#define SERIAL_STR_MAX_SIZE		50
#define CONSUMER_QUEUE_LENGTH 10
/*
 * Configure the processor for use with the Keil demo board.  This is very
 * minimal as most of the setup is managed by the settings in the project
 * file.
 */
static void prvSetupHardware( void );

/* Task Prototypes */
static void Button1_Task(void* parameters);
static void Button2_Task(void* parameters);
static void PeriodicSerial_Task(void* parameters);
static void Consumer_Task(void* parameters);

/* Global Variables */
static TaskHandle_t Button1Task_Handler  = NULL;
static TaskHandle_t Button2Task_Handler  = NULL;
static TaskHandle_t SerialTask_Handler   = NULL;
static TaskHandle_t ConsumerTask_Handler = NULL;

static QueueHandle_t gl_consumer_queue;

/*-----------------------------------------------------------*/
/*
 * Application entry point:
 * Starts all the other tasks, then starts the scheduler. 
 */
int main( void )
{
	volatile int waterMark = 0;
	/* Setup the hardware for use with the Keil demo board. */
	prvSetupHardware();
	
	gl_consumer_queue = xQueueCreate(CONSUMER_QUEUE_LENGTH, sizeof(char*));
	
  /* Create Tasks here */
	xTaskCreate(Button1_Task				, "Button1 Task"		, configMINIMAL_STACK_SIZE, NULL, PRI_3, &Button1Task_Handler );
	xTaskCreate(Button2_Task				, "Button2 Task"		, configMINIMAL_STACK_SIZE, NULL, PRI_3, &Button2Task_Handler );	
	xTaskCreate(PeriodicSerial_Task , "Periodic Serial" , configMINIMAL_STACK_SIZE, NULL, PRI_2, &SerialTask_Handler  );
	xTaskCreate(Consumer_Task				, "Consumer Task"		, configMINIMAL_STACK_SIZE, NULL, PRI_1, &ConsumerTask_Handler);	
	
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
static void Button1_Task(void* parameters)
{
	UBaseType_t ux_btn_state = BTN_NOT_PRESSED;
	static const char* ptr_char_rising_edge_msg = "Button 1 Rising Edge\n";
	static const char* ptr_char_falling_edge_msg = "Button 1 Falling Edge\n";
	
	for(;;)
	{
		ux_btn_state = GPIO_read(BTN_1_PORT, BTN_1_PIN);
		
		if(BTN_PRESSED == ux_btn_state)
		{
			/* Append the consumer task's message queue */
			xQueueSend(gl_consumer_queue, (void*)&ptr_char_rising_edge_msg, portMAX_DELAY);
			
			/* Debounce */
			vTaskDelay(BTN_DEBOUNCE_DELAY);	

			while(BTN_PRESSED == GPIO_read(BTN_1_PORT, BTN_1_PIN))
			{
				vTaskDelay(BTN_READ_PERIDOICITY);
			}
			
			/* Append event to consumer task queue */
			xQueueSend(gl_consumer_queue, (void*)&ptr_char_falling_edge_msg, portMAX_DELAY);
		}
		else 
		{
			vTaskDelay(BTN_READ_PERIDOICITY);			
		}	
	}
}


static void Button2_Task(void* parameters)
{
	UBaseType_t ux_btn_state = BTN_NOT_PRESSED;
	static const char* ptr_char_rising_edge_msg = "Button 2 Rising Edge\n";
	static const char* ptr_char_falling_edge_msg = "Button 2 Falling Edge\n";
	
	for(;;)
	{
		ux_btn_state = GPIO_read(BTN_2_PORT, BTN_2_PIN);
		
		if(BTN_PRESSED == ux_btn_state)
		{
			/* Append the consumer task's message queue */
			xQueueSend(gl_consumer_queue, (void*)&ptr_char_rising_edge_msg, portMAX_DELAY);
			
			/* Debounce */
			vTaskDelay(BTN_DEBOUNCE_DELAY);	

			while(BTN_PRESSED == GPIO_read(BTN_2_PORT, BTN_2_PIN))
			{
				vTaskDelay(BTN_READ_PERIDOICITY);
			}
			
			/* Append event to consumer task queue */
			xQueueSend(gl_consumer_queue, (void*)&ptr_char_falling_edge_msg, portMAX_DELAY);
		}
		else 
		{
			vTaskDelay(BTN_READ_PERIDOICITY);			
		}
	}
}


static void PeriodicSerial_Task(void* parameters)
{
	static const char* ptr_char_periodic_string = "Periodic String\n";
	
	for(;;)
	{
		/* Append the periodic message to the queue */
		xQueueSend(gl_consumer_queue, (void*)&ptr_char_periodic_string, portMAX_DELAY);
		
		vTaskDelay(SERIAL_TASK_PERIODICITY);
	}
}


static void Consumer_Task(void* parameters)
{
	static UBaseType_t lo_ux_queue_state;
	static const char* lo_ptr_char_queue_element;
	
	for(;;)
	{
		/* Receive a message from the queue */
		lo_ux_queue_state = xQueueReceive(gl_consumer_queue, (void*)&lo_ptr_char_queue_element, portMAX_DELAY);
		
		if(pdTRUE == lo_ux_queue_state)
		{
			//if(NULL != lo_ptr_char_queue_element)
			while(pdFALSE == vSerialPutString((const signed char*)lo_ptr_char_queue_element, SERIAL_STR_MAX_SIZE));
			//queue_length = uxQueueMessagesWaiting(gl_consumer_queue);
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


