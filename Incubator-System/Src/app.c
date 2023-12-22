/*
 * app.c
 *
 *  Created on: Sep 19, 2023
 *      Author: GTX
 */


#include "app.h"

int N=0 ;
char Exit_Data;
uint8 buffer[3];
uint8 MaxTemp;
uint8 MinTemp;
uint8_t Automated =1;



UART_Config Exit={
		.BaudRate =9600,
		.HwFlowCtl=UART_HwFlowCtl_NONE,
		.PEIE_IRQ_Enable=0,
		.P_IRQ_CallBack= EXIT_CALLBACK,
		.Parity=UART_Parity__NONE,
		.Payload_Length= UART_Payload_Length_8B,
		.RXNEIE_IRQ_Enable=1,
		.StopBits=UART_StopBits__1,
		.TCIE_IRQ_Enable=0,
		.TXEIE_IRQ_Enable=0,
		.USART_Mode =UART_MODE_TX_RX,
		.USARTx= USART2
};

TIMER_t PWM2={
		.TIMERx= TIM2,
		.CLOCK=8000000,
		.FREQUENCY=600
};


GPIO_PinConfig_t lamp ={
		.GPIO_MODE= GPIO_OUTPUT_PUSHPULL_MODE,
		.GPIO_Output_Speed=GPIO_SPEED_2M,
		.GPIO_PinNumber= 12,
		.GPIO_Port=GPIOB
};

chr_lcd_4bit_t lcd = {
		.lcd_en.GPIO_Port=GPIOB,
		.lcd_en.GPIO_PinNumber = 7 ,
		.lcd_en.GPIO_Output_Speed=GPIO_SPEED_2M,
		.lcd_en.GPIO_MODE =GPIO_OUTPUT_PUSHPULL_MODE,

		.lcd_rs.GPIO_Port=GPIOB,
		.lcd_rs.GPIO_PinNumber = 8 ,
		.lcd_rs.GPIO_Output_Speed=GPIO_SPEED_2M,
		.lcd_rs.GPIO_MODE =GPIO_OUTPUT_PUSHPULL_MODE,

		.lcd_data[0].GPIO_Port=GPIOB,
		.lcd_data[0].GPIO_PinNumber = 3,
		.lcd_data[0].GPIO_Output_Speed=GPIO_SPEED_2M,
		.lcd_data[0].GPIO_MODE =GPIO_OUTPUT_PUSHPULL_MODE,

		.lcd_data[1].GPIO_Port=GPIOB,
		.lcd_data[1].GPIO_PinNumber = 4,
		.lcd_data[1].GPIO_Output_Speed=GPIO_SPEED_2M,
		.lcd_data[1].GPIO_MODE =GPIO_OUTPUT_PUSHPULL_MODE,

		.lcd_data[2].GPIO_Port=GPIOB,
		.lcd_data[2].GPIO_PinNumber = 5,
		.lcd_data[2].GPIO_Output_Speed=GPIO_SPEED_2M,
		.lcd_data[2].GPIO_MODE =GPIO_OUTPUT_PUSHPULL_MODE,

		.lcd_data[3].GPIO_Port=GPIOB,
		.lcd_data[3].GPIO_PinNumber = 6,
		.lcd_data[3].GPIO_Output_Speed=GPIO_SPEED_2M,
		.lcd_data[3].GPIO_MODE =GPIO_OUTPUT_PUSHPULL_MODE

};

uint16_t GetTemp(){
	uint16_t adc;
	adc = MCAL_ADC_READ(ADC1,0);
	adc /= (1867.0/150.0);
	return adc;

}

void SendFrame (USART_TypeDef * uart, char str []){
	uint32_t size =strlen(str);
	for (int i = 0; i < size; i++) {
		MCAL_UART_SendData(uart,(str+i), 1);
		MCAL_UART_WAIT_TC(uart);
	}
}

void NumToStr(uint16_t number ,char *str){
	sprintf(str,"%d",number);
}
void PrintTemp(){
	uint16 Temp=GetTemp();
	uint8 str[]={0,0,0};
	NumToStr(Temp,str);
	lcd_4bit_send_string_pos(&lcd, 3, 1, str);
	lcd_4bit_send_string(&lcd, "  ");
}


void Automatic(uint32_t min , uint32_t max){
	MaxTemp=max;
	MinTemp=min;
	Automated=1;
}
void Manual (uint32_t X ,uint32_t fan_speed){
	Automated=0;
	PWM(&PWM2,2,(fan_speed)*10);
	gpio_pin_write_logic(&lamp, X);
}


char val[3]={0,0,0};
void EXIT_CALLBACK (){

	Exit_Data=USART2->DR;
	MCAL_UART_SendData(&Exit, &Exit_Data, 1);
	buffer[N]= Exit_Data;
	N++;
	if (N==3) {
		buffer[1]-='0';
		buffer[2]-='0';
		N=0;
		if(buffer[0]=='A')
			Automatic(buffer[1]*10,buffer[2]*10);
		else if(buffer[0]=='M')
			Manual(buffer[1],buffer[2]);

		else if(buffer[0]=='T') {
			NumToStr(GetTemp(),&val);
			SendFrame(&Exit, &val);
		}

	}

}
