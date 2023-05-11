
#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/*************************************************************************************************************
 * 													Macros
 ************************************************************************************************************/
#define UART_TIMEOUT					 100000
#define DEVICE_NUM						 2		/* Number of devices communicating via UART */
#define DEVICE_A						 0		/* Index of first device					*/
/*************************************************************************************************************
 * 											User-defined data types
 ************************************************************************************************************/

/* Device type in UART communication options */
typedef enum
{
	UART_TRANSMITTER= 1,
	UART_RECEIVER	   ,
	UART_TRANSCEIVER
}en_UART_Device_t;

/* UART Mode Select options */
typedef enum
{
	UART_SYNCHRONOUS =1,
	UART_ASYNCHRONOUS  
}en_UARTmode_t;

/* UART frame data size options */
typedef enum
{
	UART_5_DATA_BITS = 1,
	UART_6_DATA_BITS	,
	UART_7_DATA_BITS	,
	UART_8_DATA_BITS	,
	UART_9_DATA_BITS 
}en_UART_FrameData_t;

/* UART Frame parity options */
typedef enum
{
	UART_PARITY_DISABLED = 1,
	UART_EVEN_PARITY		,
	UART_ODD_PARITY			
}en_UARTparity_t;

/* UART Frame stop bits options */
typedef enum
{
	ONE_STOP_BIT = 1,
	TWO_STOP_BITS
}en_UARTstopBits_t;

/* UART Speed Options */
typedef enum
{
	UART_NORMAL_SPEED = 1,
	UART_DOUBLE_SPEED
}en_UARTspeed_t;

/* UART Baud Rate options */
typedef enum
{
	BAUD_RATE_2400 = 2400 ,
	BAUD_RATE_4800 = 4800 ,
	BAUD_RATE_9600 = 9600 ,
	BAUD_RATE_14400= 14400
}en_UART_BaudRate_t;


typedef struct
{
	en_UART_Device_t	UART_DEVICE_TYPE	   ;		   
	en_UARTmode_t	    UART_MODE			   ;		   
	en_UART_BaudRate_t  UART_BAUD_RATE		   ;		   
	en_UART_FrameData_t UART_DATA_BITS		   ;		   
	en_UARTparity_t	    UART_PARITY			   ;		   
	en_UARTstopBits_t   UART_STOP_BITS		   ;		   
	en_UARTspeed_t	    UART_SPEED			   ;		   
	en_State_t			UART_RX_COMP_INT	   ;		   
	en_State_t			UART_TX_COMP_INT	   ;		   
	en_State_t			UART_DATA_REG_EMPTY_INT;		   
	en_State_t			MULTI_PROCESSOR_COMM   ;		   
}st_UART_config_t;



#endif /* UART_PRIVATE_H_ */