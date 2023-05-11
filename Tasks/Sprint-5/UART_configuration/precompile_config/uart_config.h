
#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/*************************************************************************************************************
 * 													Macros
 ************************************************************************************************************/
/**
 * Options:
 *			UART_TRANSMITTER
 *			UART_RECEIVER
 *			UART_TRANSCEIVER
 */
#define UART_DEVICE_TYPE			UART_TRANSCEIVER

/**
 * Options:
 *			UART_SYNCHRONOUS
 *			UART_ASYNCHRONOUS
 */
#define UART_MODE					UART_ASYNCHRONOUS

/**
 * Options:
 * 			BAUD_RATE_2400
 * 			BAUD_RATE_4800
 * 			BAUD_RATE_9600
 * 			BAUD_RATE_14400
 */
#define UART_BAUD_RATE              BAUD_RATE_9600

/**
 * Options:
 * 			UART_5_DATA_BITS
 *			UART_6_DATA_BITS
 *			UART_7_DATA_BITS
 *			UART_8_DATA_BITS
 *			UART_9_DATA_BITS
 */
#define UART_CHAR_SIZE				UART_8_DATA_BITS

/**
 * Options:
 *			UART_PARITY_DISABLED
 *			UART_EVEN_PARITY
 *			UART_ODD_PARITY
 */
#define UART_PARITY					UART_PARITY_DISABLED

/**
 * Options:
 * 			ONE_STOP_BIT
 * 			TWO_STOP_BITS
 */
#define UART_STOP_BITS				ONE_STOP_BIT

/**
 * Options:
 * 			UART_NORMAL_SPEED
 * 			UART_DOUBLE_SPEED
 */
#define UART_SPEED					UART_NORMAL_SPEED

/**
 * Options:
 * 			ENABLE
 * 			DISABLE
 */
#define UART_RX_COMP_INT			DISABLE

/**
 * Options:
 * 			ENABLE
 * 			DISABLE
 */
#define UART_TX_COMP_INT			DISABLE

/**
 * Options:
 * 			ENABLE
 * 			DISABLE
 */
#define UART_DATA_REG_EMPTY_INT		DISABLE

/**
 * Options:
 * 			ENABLE
 * 			DISABLE
 */
#define MULTI_PROCESSOR_COMM		DISABLE





#endif /* UART_CONFIG_H_ */