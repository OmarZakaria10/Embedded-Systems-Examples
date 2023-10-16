################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Drivers/MCAL/USART/subdir.mk
-include Drivers/MCAL/TIMER/subdir.mk
-include Drivers/MCAL/SPI/subdir.mk
-include Drivers/MCAL/RCC/subdir.mk
-include Drivers/MCAL/I2C/subdir.mk
-include Drivers/MCAL/GPIO/subdir.mk
-include Drivers/MCAL/EXTI/subdir.mk
-include Drivers/ECU/LCD/subdir.mk
-include Drivers/ECU/KEYPAD/subdir.mk
-include Drivers/ECU/EEPROM/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32F103XX_SPI_SLAVE.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32F103XX_SPI_SLAVE.list \

OBJCOPY_BIN += \
STM32F103XX_SPI_SLAVE.bin \


# All Target
all: STM32F103XX_SPI_SLAVE.elf secondary-outputs

# Tool invocations
STM32F103XX_SPI_SLAVE.elf: $(OBJS) $(USER_OBJS) C:\Users\GTX\STM32CubeIDE\STM32F103XX_SPI_SLAVE\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc  -gdwarf-2 -o "STM32F103XX_SPI_SLAVE.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\GTX\STM32CubeIDE\STM32F103XX_SPI_SLAVE\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="STM32F103XX_SPI_SLAVE.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32F103XX_SPI_SLAVE.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32F103XX_SPI_SLAVE.list"
	@echo 'Finished building: $@'
	@echo ' '

STM32F103XX_SPI_SLAVE.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "STM32F103XX_SPI_SLAVE.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
