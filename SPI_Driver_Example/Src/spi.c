#include "spi.h"

//PA5 -> CLK
//PA6 -> MISO
//PA7 -> MOSI
//PA9 -> Slave Select

void spi1_gpio_init(void)
{
    // Enable clock access to GPIOA
    SET_BIT(RCC->AHB1ENR, 0);

    // Set PA5, PA6, PA7 mode to alternate function (AF5 for SPI1)
    // PA5: AF5 (MODER[11:10] = 10)
    CLEAR_BIT(GPIOA->MODER, 10);
    SET_BIT(GPIOA->MODER, 11);

    // PA6: AF5 (MODER[13:12] = 10)
    CLEAR_BIT(GPIOA->MODER, 12);
    SET_BIT(GPIOA->MODER, 13);

    // PA7: AF5 (MODER[15:14] = 10)
    CLEAR_BIT(GPIOA->MODER, 14);
    SET_BIT(GPIOA->MODER, 15);

    // Set PA9 as output pin (MODER[19:18] = 01)
    CLEAR_BIT(GPIOA->MODER, 18);
    SET_BIT(GPIOA->MODER, 19);

    // Set PA5, PA6, PA7 Alternate Function to SPI1 (AF5)
    // AF[0] is for pins PA0-PA7 (bits 0-31)
    // PA5: AFRL[23:20] = 0101
    SET_BIT(GPIOA->AFR[0], 20);
    CLEAR_BIT(GPIOA->AFR[0], 21);
    SET_BIT(GPIOA->AFR[0], 22);
    CLEAR_BIT(GPIOA->AFR[0], 23);

    // PA6: AFRL[27:24] = 0101
    SET_BIT(GPIOA->AFR[0], 24);
    CLEAR_BIT(GPIOA->AFR[0], 25);
    SET_BIT(GPIOA->AFR[0], 26);
    CLEAR_BIT(GPIOA->AFR[0], 27);

    // PA7: AFRL[31:28] = 0101
    SET_BIT(GPIOA->AFR[0], 28);
    CLEAR_BIT(GPIOA->AFR[0], 29);
    SET_BIT(GPIOA->AFR[0], 30);
    CLEAR_BIT(GPIOA->AFR[0], 31);
}

void spi1_config(void)
{
    // Enable clock access to SPI1 module
    SET_BIT(RCC->APB2ENR, 12);

    // Set clock to PCLK (BR[2:0] = 011 for PCLK/16)
    SET_BIT(SPI1->CR1, 3);
    CLEAR_BIT(SPI1->CR1, 4);
    CLEAR_BIT(SPI1->CR1, 5);

    // Set clock polarity (CPOL = 1) and phase (CPHA = 1)
    SET_BIT(SPI1->CR1, 0);
    SET_BIT(SPI1->CR1, 1);

    // Enable Full Duplex (BIDIMODE = 0)
    CLEAR_BIT(SPI1->CR1, 10);

    // Set MSB first (LSBFIRST = 0)
    CLEAR_BIT(SPI1->CR1, 7);

    // Set Mode to MASTER (MSTR = 1)
    SET_BIT(SPI1->CR1, 2);

    // Set the data frame format to 8-bit (DFF = 0)
    CLEAR_BIT(SPI1->CR1, 11);

    // Slave Select Management (SSM = 1, SSI = 1)
    SET_BIT(SPI1->CR1, 8);
    SET_BIT(SPI1->CR1, 9);

    // Enable SPI (SPE = 1)
    SET_BIT(SPI1->CR1, 6);
}

void spi1_transmit(uint8_t* data, uint32_t size)
{
    // Check if data is valid
    if(data == NULL || size == 0)
        return;

    for(uint32_t i = 0; i < size; ++i)
    {
        // Wait until TXE (Transmit buffer empty) is set
        while(!CHECK_BIT(SPI1->SR, 1)) {}

        // Write the data to the data register
        SPI1->DR = data[i];
    }

    // Wait until TXE is set to ensure the last byte is transmitted
    while(!CHECK_BIT(SPI1->SR, 1)) {}

    // Wait until the BUSY flag is cleared, indicating the transmission is complete
    while(CHECK_BIT(SPI1->SR, 7)) {}

    // Clear the OVR (Overrun) flag if set
    if(CHECK_BIT(SPI1->SR, SPI_SR_OVR_Pos))
    {
        // Read DR and SR to clear the OVR flag
        (void) SPI1->DR;
        (void) SPI1->SR;
    }
}

void spi1_receive(uint8_t* data, uint32_t size)
{
    while(size--)
    {
        // Transmit dummy data to generate clock pulses for the SPI slave
        SPI1->DR = 0;

        // Wait for RXNE (Receive buffer not empty) flag to be set
        while(!CHECK_BIT(SPI1->SR, SPI_SR_RXNE_Pos)) {}

        // Read the data from the data register
        *data++ = (uint8_t) (SPI1->DR);
    }
}

void cs_enable(void)
{
    CLEAR_BIT(GPIOA->ODR, 9);
}

void cs_disable(void)
{
    SET_BIT(GPIOA->ODR, 9);
}