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
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/LCD" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/ADC" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/EEPROM" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/TIMERS" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/I2C" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/SPI" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/USART" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/RCC" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/USART" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/EXTI" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/KEYPAD" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/KEYPAD" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/GPIO" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/MCAL/SPI/SPI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

