#include <avr/io.h>
#include <util/twi.h>
#include <stdio.h>
#include <stdlib.h>
#include "avr/interrupt.h"
#include "util/delay.h"
#include "Drivers/MCAL/I2C/I2C.h"
#include "Drivers/MCAL/USART/USART.h"
#include "Drivers/MCAL/TIMER0/TIMER0.h"
#include "Drivers/MCAL/ADC/ADC.h"
#include "Drivers/MCAL/EXTI/EXTI.h"
#include "Drivers/MCAL/GPIO/GPIO.h"

#define F_CPU 8000000UL 
uint8 ch ;
uint8_t ADC_Value;
uint8 speed;

uint8 str[3] ;
void Receive (void);
void SendA (void);
void SendZ (void);

EXTI_t x0 ={
	.EXTIX =0,
	.TRIGGER= EXTI_RISING_EDGE,
	.P_IRQ_CallBack=SendA
};

EXTI_t x1 ={
	.EXTIX =1,
	.TRIGGER= EXTI_RISING_EDGE,
	.P_IRQ_CallBack=SendZ
};

TIMER0_t t0 ={
	.CLOCK_SOURCE=TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_64,
	.MODE=TIMER0_MODE_FAST_PWM_NONINVERTING,
	.OCR_INT=0,
};
ADC_t adc= {
	.ADC_ADJ=ADC_LEFT_ADJUSTMENT,
	.ADC_AUTO_TRIGGER_EN=0,
	.ADC_INT_EN=0,
	.ADC_INT_HANDLER=NULL,
	.ADC_PRESCALE=ADC_PRESCALE_8,
	.ADC_REF=INTERNAL_2_56,
	.ADC_RESOLUTION=ADC_8BIT_MODE,
	.ADC_TRIGGER=0
};

USART_Config_t uart ={
	.USART_Baudrate=USART_BAUD_RATE_9600,
	.USART_DATA=USART_8_DATA_BITS,
	.USART_PARITY=USART_NO_PARITY,
	.USART_RX_EN=1,
	.USART_TX_EN=1,
	.USART_STOP=USART_1_STOP_BIT,
	.USART_RXCIE_INT_EN=1,
	.UART_RXCIE_InterruptHandler=Receive
};

pin_config_t led ={
	.port =PORTA_INDEX,
	.logic=0,
	.pin=7,
	.direction=GPIO_DIRECTION_OUTPUT
};

void Receive (void){
	ch =UDR;
	switch (ch){
		case '1':
		gpio_pin_write_logic(&led,1);
		break;
		
		case '0':
		gpio_pin_write_logic(&led,0);
		break;
		
		case 'h':
		speed+=10;
		break;
		
		case 'l':
		speed -=10;
		break;
		
		default:
		break;
	}

}
void SendA (void){
	USART_SendByteBlocking('A');
}
void SendZ (void){
	USART_SendByteBlocking('Z');
}

int main() {
	
	MCAL_EXTI_Init(&x0);
	MCAL_EXTI_Init(&x1);
	gpio_pin_intialize(&led);
	USART_Init(&uart);
	MCAL_TIMER0_Init(&t0);
	MCAL_ADC_Init(&adc);
	
	
	
	while(1){
		MCAL_ADC_StartConversion(ADC0);
		if (ADC_Value !=MCAL_ADC_GetResult(&adc))
		{
			ADC_Value =MCAL_ADC_GetResult(&adc);
			sprintf(str, "%d", ADC_Value);
			USART_SendStringBlocking("\rTemp Is= ",10);
			USART_SendStringBlocking(str,3);
			
		}
		MCAL_TIMER0_DutyCycle(&t0,speed);

	}

	return 0;
}

