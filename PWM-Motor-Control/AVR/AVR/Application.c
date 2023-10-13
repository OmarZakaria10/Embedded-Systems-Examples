#include "application.h"


uint8  input;
uint8 * ptr;
uint8_t password [5] ={'1','2','3','4'};
uint8_t user_input [5]={} ;

led_t RED = {.port_name = PORTA_INDEX, .pin = GPIO_PIN0, .led_status = GPIO_LOW};

pin_config_t pin1 = {.port=PORTA_INDEX , .pin=GPIO_PIN3 ,.direction= GPIO_DIRECTION_OUTPUT, .logic =GPIO_LOW};
pin_config_t pin2 = {.port=PORTA_INDEX , .pin=GPIO_PIN4 ,.direction= GPIO_DIRECTION_OUTPUT, .logic =GPIO_LOW};


keypad_t keypad1={
	.keypad_row_pins[0].port=PORTB_INDEX ,
	.keypad_row_pins[0].pin=GPIO_PIN0 ,
	.keypad_row_pins[0].direction = GPIO_DIRECTION_OUTPUT ,
	.keypad_row_pins[0].logic =GPIO_LOW,
	.keypad_row_pins[1].port=PORTB_INDEX ,
	.keypad_row_pins[1].pin=GPIO_PIN1 ,
	.keypad_row_pins[1].direction = GPIO_DIRECTION_OUTPUT ,
	.keypad_row_pins[1].logic =GPIO_LOW,
	.keypad_row_pins[2].port=PORTB_INDEX ,
	.keypad_row_pins[2].pin=GPIO_PIN2 ,
	.keypad_row_pins[2].direction = GPIO_DIRECTION_OUTPUT ,
	.keypad_row_pins[2].logic =GPIO_LOW,
	.keypad_row_pins[3].port=PORTB_INDEX ,
	.keypad_row_pins[3].pin=GPIO_PIN3 ,
	.keypad_row_pins[3].direction = GPIO_DIRECTION_OUTPUT ,
	.keypad_row_pins[3].logic =GPIO_LOW,

	.keypad_columns_pins[0].port=PORTB_INDEX ,
	.keypad_columns_pins[0].pin=GPIO_PIN4 ,
	.keypad_columns_pins[0].direction = GPIO_DIRECTION_INPUT ,
	.keypad_columns_pins[0].logic =GPIO_LOW,
	.keypad_columns_pins[1].port=PORTB_INDEX ,
	.keypad_columns_pins[1].pin=GPIO_PIN5 ,
	.keypad_columns_pins[1].direction = GPIO_DIRECTION_INPUT ,
	.keypad_columns_pins[1].logic =GPIO_LOW,
	.keypad_columns_pins[2].port=PORTB_INDEX ,
	.keypad_columns_pins[2].pin=GPIO_PIN6 ,
	.keypad_columns_pins[2].direction = GPIO_DIRECTION_INPUT ,
	.keypad_columns_pins[2].logic =GPIO_LOW,
	.keypad_columns_pins[3].port=PORTB_INDEX ,
	.keypad_columns_pins[3].pin=GPIO_PIN7 ,
	.keypad_columns_pins[3].direction = GPIO_DIRECTION_INPUT ,
	.keypad_columns_pins[3].logic =GPIO_LOW,
};

button_t btn = {
	.button_pin.port = PORTA_INDEX,
	.button_pin.pin = GPIO_PIN4,
	.button_pin.direction = GPIO_DIRECTION_INPUT,
	.button_pin.logic = GPIO_LOW,
	.button_connection = BUTTON_ACTIVE_HIGH,
	.button_state = BUTTON_RELEASED
};
chr_lcd_4bit_t lcd1 = {
	.lcd_en.pin =GPIO_PIN2,
	.lcd_en.port = PORTC_INDEX,
	.lcd_en.direction = GPIO_DIRECTION_OUTPUT,
	.lcd_en.logic = GPIO_HIGH,

	.lcd_rs.pin =GPIO_PIN3,
	.lcd_rs.port = PORTC_INDEX,
	.lcd_rs.direction = GPIO_DIRECTION_OUTPUT,
	.lcd_rs.logic = GPIO_HIGH,

	.lcd_data[0].pin =GPIO_PIN0,
	.lcd_data[0].port = PORTC_INDEX,
	.lcd_data[0].direction = GPIO_DIRECTION_OUTPUT,
	.lcd_data[0].logic = GPIO_LOW,

	.lcd_data[1].pin =GPIO_PIN1,
	.lcd_data[1].port = PORTC_INDEX,
	.lcd_data[1].direction = GPIO_DIRECTION_OUTPUT,
	.lcd_data[1].logic = GPIO_LOW,

	.lcd_data[2].pin =GPIO_PIN1,
	.lcd_data[2].port = PORTA_INDEX,
	.lcd_data[2].direction = GPIO_DIRECTION_OUTPUT,
	.lcd_data[2].logic = GPIO_LOW,

	.lcd_data[3].pin =GPIO_PIN7,
	.lcd_data[3].port = PORTA_INDEX,
	.lcd_data[3].direction = GPIO_DIRECTION_OUTPUT,
	.lcd_data[3].logic = GPIO_LOW

	// .lcd_data[4].pin =GPIO_PIN4,
	// .lcd_data[4].port = PORTC_INDEX,
	// .lcd_data[4].direction = GPIO_DIRECTION_OUTPUT,
	// .lcd_data[4].logic = GPIO_LOW,

	// .lcd_data[5].pin =GPIO_PIN5,
	// .lcd_data[5].port = PORTC_INDEX,
	// .lcd_data[5].direction = GPIO_DIRECTION_OUTPUT,
	// .lcd_data[5].logic = GPIO_LOW,

	// .lcd_data[6].pin =GPIO_PIN6,
	// .lcd_data[6].port = PORTC_INDEX,
	// .lcd_data[6].direction = GPIO_DIRECTION_OUTPUT,
	// .lcd_data[6].logic = GPIO_LOW,

	// .lcd_data[7].pin =GPIO_PIN7,
	// .lcd_data[7].port = PORTC_INDEX,
	// .lcd_data[7].direction = GPIO_DIRECTION_OUTPUT,
	// .lcd_data[7].logic = GPIO_LOW,
};

relay_t relay_1 ={
	.relay_port=PORTA_INDEX , .relay_pin= GPIO_PIN2 ,.relay_status =REALY_OFF_STATUS
};
Std_ReturnType ret = E_NOT_OK;

dc_motor_t motor ={
	.dc_motor_pin[DC_MOTOR_PIN1].direction =GPIO_DIRECTION_OUTPUT
	,.dc_motor_pin[DC_MOTOR_PIN1].port =PORTA_INDEX
	,.dc_motor_pin[DC_MOTOR_PIN1].pin =GPIO_PIN5
	,.dc_motor_pin[DC_MOTOR_PIN1].logic= GPIO_LOW
	,.dc_motor_pin[DC_MOTOR_PIN2].direction =GPIO_DIRECTION_OUTPUT
	,.dc_motor_pin[DC_MOTOR_PIN2].port =PORTA_INDEX
	,.dc_motor_pin[DC_MOTOR_PIN2].pin =GPIO_PIN6
	,.dc_motor_pin[DC_MOTOR_PIN2].logic= GPIO_LOW
};

void App_Init(void){
	ret = gpio_pin_intialize(&pin1);
	ret = button_initialize(&btn);
	ret = gpio_pin_intialize(&pin2);
	ret = led_initialize(&RED);
	ret = relay_initialize(&relay_1);
	ret = dc_motor_initialize(&motor);
	//ret = seven_segement_port_intialize(PORTD_INDEX,SEGMENT_COMMON_ANODE);
	ret = keypad_initialize (&keypad1);
	ret = lcd_4bit_intialize(&lcd1);
	ret = lcd_4bit_send_command(&lcd1 ,_LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON );
}