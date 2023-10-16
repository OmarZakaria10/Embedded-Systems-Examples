################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/ECU/LCD/lcd.c 

OBJS += \
./Drivers/ECU/LCD/lcd.o 

C_DEPS += \
./Drivers/ECU/LCD/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/ECU/LCD/lcd.o: ../Drivers/ECU/LCD/lcd.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_MASTER/Drivers/ECU/LCD" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_MASTER/Drivers/ECU/EEPROM" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_MASTER/Drivers/MCAL/TIMER" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_MASTER/Drivers/MCAL/I2C" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_MASTER/Drivers/MCAL/SPI" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_MASTER/Drivers/MCAL/USART" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_MASTER/Drivers/MCAL/RCC" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_MASTER/Drivers/MCAL/USART" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_MASTER/Drivers/MCAL/EXTI" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_MASTER/Drivers" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_MASTER/Drivers/ECU/KEYPAD" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_MASTER/Drivers/ECU" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_MASTER/Drivers/ECU/KEYPAD" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_MASTER/Drivers/MCAL" -I"C:/Users/GTX/STM32CubeIDE/STM32F103XX_SPI_MASTER/Drivers/MCAL/GPIO" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/ECU/LCD/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

