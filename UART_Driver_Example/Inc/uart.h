#ifndef UART_H_
#define UART_H_

#include "bit_operations.h"
#include "stm32f446xx.h"

/**
 * @brief Initializes UART2 for transmission and reception.
 *
 * This function performs the following tasks:
 * 1. Enables clock access to GPIOA.
 * 2. Configures PA2 (TX) for alternate function mode.
 * 3. Sets PA2 to UART2 alternate function.
 * 4. Configures PA3 (RX) for alternate function mode.
 * 5. Sets PA3 to UART2 alternate function.
 * 6. Enables clock access to UART2.
 * 7. Configures the baud rate for UART2 assuming an APB1 clock frequency of 45
 * MHz.
 * 8. Enables the UART2 transmitter and receiver.
 * 9. Enables the UART2 module.
 */
void uart2_txrx_init(void);

/**
 * @brief Transmits a single byte of data via UART2.
 *
 * This function performs the following tasks:
 * 1. Waits until the TXE (Transmit Data Register Empty) flag is set.
 * 2. Writes the data byte to the UART2 data register.
 *
 * @param data The byte of data to be transmitted.
 */
void uart2_write(uint8_t data);

/**
 * @brief Receives a single byte of data via UART2.
 *
 * This function performs the following tasks:
 * 1. Waits until the RXNE (Receive Data Register Not Empty) flag is set.
 * 2. Reads the received byte from the UART2 data register.
 *
 * @return The byte of data received.
 */
uint8_t uart2_read(void);

/**
 * @brief Redirects a single character to UART2 for output.
 *
 * This function is used by printf to send characters over UART2.
 *
 * @param ch The character to be transmitted.
 * @return The character that was transmitted.
 */
int __io_putchar(int ch);

#endif /* UART_H_ */
