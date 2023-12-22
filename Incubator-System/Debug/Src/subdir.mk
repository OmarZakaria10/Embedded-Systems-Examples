################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/app.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/app.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/app.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/app.o: ../Src/app.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/LCD" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/ADC" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/EEPROM" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/TIMERS" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/I2C" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/SPI" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/USART" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/RCC" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/USART" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/EXTI" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/KEYPAD" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/KEYPAD" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/GPIO" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/app.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/main.o: ../Src/main.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/LCD" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/ADC" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/EEPROM" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/TIMERS" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/I2C" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/SPI" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/USART" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/RCC" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/USART" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/EXTI" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/KEYPAD" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/KEYPAD" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/GPIO" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/LCD" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/ADC" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/EEPROM" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/TIMERS" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/I2C" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/SPI" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/USART" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/RCC" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/USART" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/EXTI" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/KEYPAD" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/KEYPAD" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/GPIO" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/LCD" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/ADC" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/EEPROM" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/TIMERS" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/I2C" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/SPI" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/USART" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/RCC" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/USART" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/EXTI" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/KEYPAD" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/ECU/KEYPAD" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL" -I"E:/Git/STM32F103-Arm Cortex M3/STM32F103-Arm-Cortex-M3/Drivers/MCAL/GPIO" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

