#ifndef APPLICATION_H
#define APPLICATION_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Drivers/MCAL/GPIO/GPIO.h"
#include "Drivers/MCAL/USART/USART.h"
#include "Drivers/ECU/LED/led.h"
#include "Drivers/ECU/BUTTON/button.h"
#include "Drivers/ECU/RELAY/relay.h"
#include "Drivers/ECU/MOTOR/dc_motor.h"
#include "Drivers/ECU/7_SEGMENT/7_segment.h"
#include "Drivers/ECU/KEYPAD/keypad.h"
#include "Drivers/ECU/LCD/lcd.h"
#include "Drivers/MCAL/SPI/SPI.h"


extern chr_lcd_4bit_t lcd1;
extern keypad_t keypad1;
extern uint8  input;
extern uint8 * ptr;
extern uint8_t password [5] ;
extern uint8_t user_input [5] ;
extern relay_t relay_1;
extern dc_motor_t motor;
extern led_t RED;
extern pin_config_t pin1;
extern pin_config_t pin2;

void App_Init();

#endif