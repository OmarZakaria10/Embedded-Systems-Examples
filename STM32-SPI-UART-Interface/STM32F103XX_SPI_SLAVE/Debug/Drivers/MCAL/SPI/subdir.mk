################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/MCAL/SPI/SPI.c 

OBJS += \
./Drivers/MCAL/SPI/SPI.o 

C_DEPS += \
./Drivers/MCAL/SPI/SPI.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MCAL/SPI/SPI.o: ../Drivers/MCAL/SPI/SPI.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_SLAVE/Drivers/ECU/LCD" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_SLAVE/Drivers/ECU/EEPROM" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_SLAVE/Drivers/MCAL/TIMER" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_SLAVE/Drivers/MCAL/I2C" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_SLAVE/Drivers/MCAL/SPI" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_SLAVE/Drivers/MCAL/USART" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_SLAVE/Drivers/MCAL/RCC" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_SLAVE/Drivers/MCAL/USART" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_SLAVE/Drivers/MCAL/EXTI" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_SLAVE/Drivers" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_SLAVE/Drivers/ECU/KEYPAD" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_SLAVE/Drivers/ECU" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_SLAVE/Drivers/ECU/KEYPAD" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_SLAVE/Drivers/MCAL" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_SLAVE/Drivers/MCAL/GPIO" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/MCAL/SPI/SPI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

