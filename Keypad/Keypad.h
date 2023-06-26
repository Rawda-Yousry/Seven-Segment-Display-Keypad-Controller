/*
 * Keypad.h
 *
 *  Created on: May 4, 2023
 *      Author: Rawda Lenovo LapTop
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Gpio.h"

#define COL_PORT GPIO_B
#define COL_START_INDEX 0
#define COL_END_INDEX 2

#define ROW_PORT GPIO_B
#define ROW_START_INDEX 5
#define ROW_END_INDEX 8


void Keypad_init(void);

void Keypad_manage(void);

void KeypadCallout_KeyPressNotification(void);

uint8 Keypad_Getkey(void);


#endif /* KEYPAD_H_ */
