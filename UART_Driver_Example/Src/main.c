#include "stm32f4xx.h"
#include "uart.h"
#include <stdint.h>


int main(void)
{
    uart2_txrx_init( );
    printf("Hello, World!\n\r");
}
