/*
 * app.h
 *
 *  Created on: Sep 19, 2023
 *      Author: 	Omar Zakaria
 */

#ifndef APP_H_
#define APP_H_



#include "STM32F103C6.h"
#include "GPIO.h"
#include "ADC.h"
#include "keypad.h"
#include "lcd.h"
#include "USART.h"
#include "SPI.h"
#include "I2C.h"
#include "TIMERS.h"
#include <string.h>


extern UART_Config Exit;
extern TIMER_t PWM2;
extern GPIO_PinConfig_t lamp;
extern chr_lcd_4bit_t lcd;
extern uint8 MaxTemp;
extern uint8 MinTemp;
extern uint8_t Automated;




void EXIT_CALLBACK ();

void Automatic(uint32_t min , uint32_t max);
void Manual (uint32_t lamp ,uint32_t fan_speed);
uint16_t GetTemp();
void PrintTemp();
void SendFrame (USART_TypeDef * uart,char str []);


#endif
