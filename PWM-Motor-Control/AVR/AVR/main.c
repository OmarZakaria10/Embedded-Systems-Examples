#include <avr/io.h>
#include <util/twi.h>
#include "avr/interrupt.h"
#include "util/delay.h"
#include "Drivers/MCAL/GPIO/GPIO.h"
#include "Drivers/MCAL/TIMER0/TIMER0.h"
#include "Drivers/MCAL/EXTI/EXTI.h"


#define F_CPU 8000000UL 
void SPEED_UP();
void SPEED_DOWN();
void CHANGE_DIRECTION();

 uint8_t speed = 0;
pin_config_t m0 ={
	.port= PORTD_INDEX,
	.direction=GPIO_DIRECTION_OUTPUT,
	.logic=1,
	.pin =GPIO_PIN0
};
pin_config_t m1 ={
	.port= PORTD_INDEX,
	.direction=GPIO_DIRECTION_OUTPUT,
	.logic=0,
	.pin =GPIO_PIN1
};
TIMER0_t t0 ={
	.CLOCK_SOURCE=TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_64,
	.MODE=TIMER0_MODE_FAST_PWM_NONINVERTING,
	.OCR_INT=0,
};

EXTI_t x0 ={
	.EXTIX =0,
	.TRIGGER= EXTI_RISING_EDGE,
	.P_IRQ_CallBack=SPEED_UP
};

EXTI_t x1 ={
	.EXTIX =1,
	.TRIGGER= EXTI_RISING_EDGE,
	.P_IRQ_CallBack=SPEED_DOWN
};

EXTI_t x2 ={
	.EXTIX =2,
	.TRIGGER= EXTI_RISING_EDGE,
	.P_IRQ_CallBack=CHANGE_DIRECTION
};

void SPEED_UP (){
	if (speed <100)
	{
		speed+=10;
	}
	
}
void SPEED_DOWN (){
		if (speed >0)
		{
			speed-=10;
		}
}
void CHANGE_DIRECTION (){
	gpio_pin_toggle_logic(&m0);
	gpio_pin_toggle_logic(&m1);
}










int main() {

	MCAL_TIMER0_Init(&t0);
	MCAL_TIMER0_DutyCycle(&t0,0);
	MCAL_EXTI_Init(&x0);
	MCAL_EXTI_Init(&x1);
	MCAL_EXTI_Init(&x2);
gpio_pin_intialize(&m0);
gpio_pin_intialize(&m1);
	
	while(1){
		MCAL_TIMER0_DutyCycle(&t0,speed);

	}
	/*
	// Initialize I2C
	_delay_ms(500);
	I2C_Init();
	int i =0;

	while (1) {
		// Send data to the slave
		I2C_SendByte(SLAVE_ADDRESS, i);
		i++;

		// Delay for a while
		_delay_ms(500);
	}
*/
	return 0;
}

