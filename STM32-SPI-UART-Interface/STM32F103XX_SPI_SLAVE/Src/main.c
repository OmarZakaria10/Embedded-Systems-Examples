/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><cuart1>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</cuart1></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include "STM32F103C6.h"
#include "GPIO.h"
#include "keypad.h"
#include "lcd.h"
#include "USART.h"
#include "SPI.h"
#include "I2C.h"
#include "TIMER.h"
#include "app.h"


void transmit();
void UART_CALLBACK ();

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


SPI_Config_t spi_slave= {
		.BaudRate_Prescaler=BAUDERATE_PRESCALER_2,
		.CLK_Phase=CLK_PHASE_FIRST,
		.CLK_Polarity=CLK_POLARITY_IDLE_LOW,
		.Communication_Mode=COMMUNICATION_MODE_2LINE_FULL_DUPLEX,
		.Frame_Format=FRAME_FORMAT_MSB_FIRST,
		.Frame_Size=FRAME_SIZE_8BIT,
		.NSS=NSS_HW_SLAVE,
		.SPI_Mode=SPI_MODE_SLAVE,
		.SPIx=SPI1,
		.TXE_INT_EN=0,
		.RXNE_INT_EN=1,
		.ERRI_INT_EN=0,
		.SPI1_IRQ_CallBack=transmit,
		.SPI2_IRQ_CallBack=NULL,

};
UART_Config uart1={
		.BaudRate =9600,
		.HwFlowCtl=UART_HwFlowCtl_NONE,
		.PEIE_IRQ_Enable=0,
		.P_IRQ_CallBack= UART_CALLBACK,
		.Parity=UART_Parity__NONE,
		.Payload_Length= UART_Payload_Length_8B,
		.RXNEIE_IRQ_Enable=0,
		.StopBits=UART_StopBits__1,
		.TCIE_IRQ_Enable=0,
		.TXEIE_IRQ_Enable=0,
		.USART_Mode =UART_MODE_TX_RX,
		.USARTx= USART1
};


uint16 y=0;
uint16 z=0;
uint16 uart1_Data=0;


void transmit(){
	z=SPI1->SPI_DR;
	MCAL_UART_SendData(&uart1, &z, 1);
	//MCAL_SPI_Send_Data(&spi_slave, &z, 1);
}

void UART_CALLBACK (){
	uart1_Data=USART1->DR;
	MCAL_UART_SendData(&uart1, &uart1_Data, 1);

}
GPIO_PinConfig_t pin = {
		.GPIO_MODE=GPIO_OUTPUT_PUSHPULL_MODE,
		.GPIO_Output_Speed=GPIO_SPEED_50M,
		.GPIO_PinNumber=12,
		.GPIO_Port=GPIOB
};


int main(void)
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();

	MCAL_SPI_GPIO_Set_Pins(&spi_slave);
	MCAL_SPI_Init(&spi_slave);
	MCAL_UART_GPIO_Set_Pins(&uart1);
	MCAL_UART_Init(&uart1);
	gpio_pin_intialize(&pin);
	gpio_pin_write_logic(&pin, 0);
	delay_ms(5000);


	while (1){
		//MCAL_SPI_Recieve_Data(&spi_slave, &y, 1);
		//delay_ms(100);
		if(z!=0)gpio_pin_write_logic(&pin, 1);
	}
}


