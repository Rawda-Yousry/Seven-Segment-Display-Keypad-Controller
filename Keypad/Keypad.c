/*
 * Keypad.c
 *
 *  Created on: May 5, 2023
 *      Author: Rawda Lenovo LapTop
 */

#include "Keypad.h"
#include "Gpio.h"
#include "Std_Types.h"

uint8 storedKey;
uint8 flag = 0;
uint8 changeVal = 1;

uint8 array[4][3]={
		{1,2,3},
		{4,5,6},
		{7,8,9},
		{0,0,0}
};

void Keypad_init(void)
{
	uint8 index = 0;
	for (index = COL_START_INDEX ; index <=COL_END_INDEX; index++){
		Gpio_ConfigPin(COL_PORT,index,GPIO_INPUT,PULL_UP);
	}
	// config rows
	for (index = ROW_START_INDEX ; index <= ROW_END_INDEX ; index++){
		Gpio_ConfigPin(ROW_PORT,index,GPIO_OUTPUT,GPIO_PUSH_PULL);
	// put output idel state pins  (deactivation for output pins)
		Gpio_WritePin(ROW_PORT,index,HIGH);
	}

}

void Keypad_manage(void)
{
	uint8 i,j;
	uint8 ok_or_not;
	uint8 pinReadPrevious;
	uint8 pinReadCurrent;

	for(i = ROW_START_INDEX; i <= ROW_END_INDEX; i++){
		// Active row
		ok_or_not = Gpio_WritePin(ROW_PORT,i,LOW);
		for(j = COL_START_INDEX; j <= COL_END_INDEX ; j++){
			// Read Column and debouncing effect
			pinReadPrevious = Gpio_ReadPin(COL_PORT,j);
			for(unsigned long k = 0; k<3000;k++);
			pinReadCurrent = Gpio_ReadPin(COL_PORT,j);
			if(pinReadCurrent == 0 && pinReadCurrent == pinReadPrevious){
				// if button pressed for first time
					if (flag == 1){
						// Change the key value only if we entered the Keypad_Getkey() function
						if(changeVal == 1 ){
						storedKey = array[i-ROW_START_INDEX][j-COL_START_INDEX];
						changeVal = 0;
						KeypadCallout_KeyPressNotification();
						flag = 0; // so not to enter in the if condition again if there is no falling edge
						}
					}
				}
			else{
				flag = 1; // change of state detected
			}
		}
		// Deactive row
		ok_or_not = Gpio_WritePin(ROW_PORT,i,HIGH);
	}

}


uint8 Keypad_Getkey(void)
{
	changeVal = 1;
	return storedKey;
}

