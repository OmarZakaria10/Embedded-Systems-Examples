/*
 * app.h
 *
 *  Created on: Sep 19, 2023
 *      Author: GTX
 */

#ifndef APP_H_
#define APP_H_

#include "STM32F103C6.h"
typedef enum{
	IN_GARAGE,
	OUT_GARAGE
}Car_State;

typedef struct {
	uint32_t ID;
	Car_State state;
}Driver_t;

#endif /* APP_H_ */
