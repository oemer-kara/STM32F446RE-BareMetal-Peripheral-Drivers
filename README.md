# STM32F446RE Bare-Metal Programming

Welcome to the STM32F446RE Bare-Metal Programming repository. This repository contains all the code and resources related to bare-metal firmware development for the STM32F446RE microcontroller. The focus is on building a solid foundation in writing firmware from scratch using embedded C and direct register manipulations, without relying on third-party libraries.

## Table of Contents

1. [Overview](#overview)
2. [Getting Started](#getting-started)
3. [How to Run the Code](#how-to-run-the-code)

## Overview

This repository includes:

- Firmware written in bare-metal embedded C
- Drivers for various peripherals such as ADC, PWM, UART, TIMER, SPI, I2C, and DMA
- Examples of using the ARM-Cortex CMSIS standard
- Techniques for reading and utilizing microcontroller documentation
- Methods for effective debugging and register manipulation

## Getting Started

To get started with this repository, you will need:

- STM32F446RE Nucleo development board
- STM32CubeIDE (free to download)
- Basic knowledge of C programming

## How to Run the Code

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/STM32F446RE-BareMetal-Peripheral-Drivers.git
   cd STM32F446RE-BareMetal-Peripheral-Drivers
   ```

2. **Open STM32CubeIDE**:
   - Import the project by selecting `File > Import > Existing Projects into Workspace`.
   - Browse to the cloned repository and import the project.

3. **Build the Project**:
   - Click on the `Build` button in STM32CubeIDE to compile the code.

4. **Upload to the Board**:
   - Connect your STM32F446RE Nucleo board to your computer.
   - Click on the `Debug` button to upload the firmware to the board.

5. **Run and Test**:
   - Use the debugging tools within STM32CubeIDE to run and test the firmware.
   - Monitor the peripherals and registers to ensure proper functionality.
