
#include "../../../Common/std_types.h"

#include "../uart_private.h"

const st_UART_config_t st_g_UARTconfig[DEVICE_NUM];

st_g_UARTconfig [DEVICE_A] =
{
	/**
	 * Options:
	 *			UART_TRANSMITTER
	 *			UART_RECEIVER
	 *			UART_TRANSCEIVER
	 */
	.UART_DEVICE_TYPE = UART_TRANSCEIVER,
	
	/**
	 * Options:
	 *			UART_SYNCHRONOUS
	 *			UART_ASYNCHRONOUS
	 */
	.UART_MODE = UART_ASYNCHRONOUS,
	
	/**
	 * Options:
	 * 			BAUD_RATE_2400
	 * 			BAUD_RATE_4800
	 * 			BAUD_RATE_9600
	 * 			BAUD_RATE_14400
	 */
	.UART_BAUD_RATE = BAUD_RATE_9600,
	
	/**
	 * Options:
	 * 			UART_5_DATA_BITS
	 *			UART_6_DATA_BITS
	 *			UART_7_DATA_BITS
	 *			UART_8_DATA_BITS
	 *			UART_9_DATA_BITS
	 */
	.UART_DATA_BITS = UART_8_DATA_BITS,
	
	/**
	 * Options:
	 *			UART_PARITY_DISABLED
	 *			UART_EVEN_PARITY
	 *			UART_ODD_PARITY
	 */
	.UART_PARITY = UART_PARITY_DISABLED,
	
	/**
	 * Options:
	 * 			ONE_STOP_BIT
	 * 			TWO_STOP_BITS
	 */
	.UART_STOP_BITS = ONE_STOP_BIT,
	
	/**
	 * Options:
	 * 			UART_NORMAL_SPEED
	 * 			UART_DOUBLE_SPEED
	 */
	.UART_SPEED = UART_NORMAL_SPEED,
	
	/**
	 * Options:
	 * 			ENABLE
	 * 			DISABLE
	 */
	.UART_RX_COMP_INT =	DISABLE,

	/*
	 * Options:
	 * 			ENABLE
	 * 			DISABLE
	 */
	.UART_TX_COMP_INT = DISABLE,

	/**
	 * Options:
	 * 			ENABLE
	 * 			DISABLE
	 */
	.UART_DATA_REG_EMPTY_INT = DISABLE,
	
	/**
	 * Options:
	 * 			ENABLE
	 * 			DISABLE
	 */
	.MULTI_PROCESSOR_COMM = DISABLE
};