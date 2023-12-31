/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */


#include "app.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

uint16_t ADC_Value;
char STR[3];

int main(void)
{

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
	MCAL_ADC_INIT(ADC1);
	MCAL_UART_Init(&Exit);
	lcd_4bit_intialize(&lcd);
	gpio_pin_intialize(&lamp);

	uint16 Temp=GetTemp();

	PWM(&PWM2, 2, 0);

	while (1){
		Temp=GetTemp();
		NumToStr(Temp,&STR);
		lcd_4bit_send_string_pos(&lcd, 1, 1, "      ");
		while (Automated){
			uint16 Temp=GetTemp();
			NumToStr(Temp,&STR);
			lcd_4bit_send_string_pos(&lcd, 2, 1, STR);
			if (Temp<MinTemp){
				lcd_4bit_send_string_pos(&lcd, 1, 1, "Cold  ");
				PWM(&PWM2, 2, 0);
				gpio_pin_write_logic(&lamp, 1);
			}
			else if (Temp>MaxTemp){
				lcd_4bit_send_string_pos(&lcd, 1, 1, "Hot   ");
				PWM(&PWM2, 2, 100);
				gpio_pin_write_logic(&lamp, 0);

			}
			else {
				lcd_4bit_send_string_pos(&lcd, 1, 1, "Normal");
				gpio_pin_write_logic(&lamp, 0);
				PWM(&PWM2, 2, 0);
			}




		}
	}
}





















