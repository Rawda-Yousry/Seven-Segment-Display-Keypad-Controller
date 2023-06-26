/*
 * Name : Rawda Yousry Hamada
 * Sec : 1
 * BN : 35
 *
 *
 *
 */

#include "Gpio.h"
#include "Rcc.h"
#include "Std_Types.h"
#include "Gpio_Private.h"
#include "Bit_Operations.h"
#include "stdio.h"
#include "Keypad.h"



int main(){
	Rcc_Init();
	Rcc_Enable(RCC_GPIOA);
	Rcc_Enable(RCC_GPIOB);

	Keypad_init();

	uint32 i = 0;

	for(i = 0 ; i<=6; i++){
		Gpio_ConfigPin(GPIO_A,i,GPIO_OUTPUT,GPIO_PUSH_PULL);
	}

	while(1){
		Keypad_manage();
		for(unsigned long k = 0; k<10000;k++);
	}
	return 0;
}

void KeypadCallout_KeyPressNotification(){
		uint8 key;
		uint8 ok_or_not = 0;
		key = Keypad_Getkey();
		switch(key){
		case 0:
			ok_or_not = Gpio_WritePin(GPIO_A, 0, HIGH);
			ok_or_not = Gpio_WritePin(GPIO_A, 1, HIGH);
			ok_or_not = Gpio_WritePin(GPIO_A, 2, HIGH);
			ok_or_not = Gpio_WritePin(GPIO_A, 3, HIGH);
			ok_or_not = Gpio_WritePin(GPIO_A, 4, HIGH);
			ok_or_not = Gpio_WritePin(GPIO_A, 5, HIGH);
			ok_or_not = Gpio_WritePin(GPIO_A, 6, LOW);
			break;
		case 1:
			ok_or_not = Gpio_WritePin(GPIO_A, 0, LOW);
			ok_or_not = Gpio_WritePin(GPIO_A, 1, HIGH);
			ok_or_not = Gpio_WritePin(GPIO_A, 2, HIGH);
			ok_or_not = Gpio_WritePin(GPIO_A, 3, LOW);
			ok_or_not = Gpio_WritePin(GPIO_A, 4, LOW);
			ok_or_not = Gpio_WritePin(GPIO_A, 5, LOW);
			ok_or_not = Gpio_WritePin(GPIO_A, 6, LOW);
			break;

		case 2:
			ok_or_not = Gpio_WritePin(GPIO_A, 0, HIGH);
			ok_or_not = Gpio_WritePin(GPIO_A, 1, HIGH);
			ok_or_not = Gpio_WritePin(GPIO_A, 2, LOW);
			ok_or_not = Gpio_WritePin(GPIO_A, 3, HIGH);
			ok_or_not = Gpio_WritePin(GPIO_A, 4, HIGH);
			ok_or_not = Gpio_WritePin(GPIO_A, 5, LOW);
			ok_or_not = Gpio_WritePin(GPIO_A, 6, HIGH);
			break;
		 case 3:
			ok_or_not = Gpio_WritePin(GPIO_A, 0, HIGH);
			ok_or_not = Gpio_WritePin(GPIO_A, 1, HIGH);
			ok_or_not = Gpio_WritePin(GPIO_A, 2, HIGH);
			ok_or_not = Gpio_WritePin(GPIO_A, 3, HIGH);
			ok_or_not = Gpio_WritePin(GPIO_A, 4, LOW);
			ok_or_not = Gpio_WritePin(GPIO_A, 5, LOW);
			ok_or_not = Gpio_WritePin(GPIO_A, 6, HIGH);

		 break;
		 case 4:
			ok_or_not = Gpio_WritePin(GPIO_A, 0, LOW);
			ok_or_not =Gpio_WritePin(GPIO_A, 1, HIGH);
			ok_or_not =Gpio_WritePin(GPIO_A, 2, HIGH);
			ok_or_not =Gpio_WritePin(GPIO_A, 3, LOW);
			ok_or_not =Gpio_WritePin(GPIO_A, 4, LOW);
			ok_or_not =Gpio_WritePin(GPIO_A, 5, HIGH);
			ok_or_not =Gpio_WritePin(GPIO_A, 6, HIGH);
		 break;
		 case 5:
			ok_or_not = Gpio_WritePin(GPIO_A, 0, HIGH);
			ok_or_not = Gpio_WritePin(GPIO_A, 1, LOW);
			ok_or_not =Gpio_WritePin(GPIO_A, 2, HIGH);
			ok_or_not =Gpio_WritePin(GPIO_A, 3, HIGH);
			ok_or_not =Gpio_WritePin(GPIO_A, 4, LOW);
			ok_or_not =Gpio_WritePin(GPIO_A, 5, HIGH);
			ok_or_not =Gpio_WritePin(GPIO_A, 6, HIGH);
		break;
		 case 6:
			 ok_or_not =Gpio_WritePin(GPIO_A, 0, HIGH);
			 ok_or_not =Gpio_WritePin(GPIO_A, 1, LOW);
			 ok_or_not =Gpio_WritePin(GPIO_A, 2, HIGH);
			 ok_or_not =Gpio_WritePin(GPIO_A, 3, HIGH);
			 ok_or_not =Gpio_WritePin(GPIO_A, 4, HIGH);
			 ok_or_not =Gpio_WritePin(GPIO_A, 5, HIGH);
			 ok_or_not =Gpio_WritePin(GPIO_A, 6, HIGH);
		 break;
		 case 7:
			 ok_or_not =Gpio_WritePin(GPIO_A, 0, HIGH);
			 ok_or_not =Gpio_WritePin(GPIO_A, 1, HIGH);
			 ok_or_not =Gpio_WritePin(GPIO_A, 2, HIGH);
			 ok_or_not =Gpio_WritePin(GPIO_A, 3, LOW);
			 ok_or_not =Gpio_WritePin(GPIO_A, 4, LOW);
			 ok_or_not =Gpio_WritePin(GPIO_A, 5, LOW);
			 ok_or_not =Gpio_WritePin(GPIO_A, 6, LOW);
			break;
		 case 8:
			 ok_or_not =Gpio_WritePin(GPIO_A, 0, HIGH);
			 ok_or_not =Gpio_WritePin(GPIO_A, 1, HIGH);
			 ok_or_not =Gpio_WritePin(GPIO_A, 2, HIGH);
			 ok_or_not =Gpio_WritePin(GPIO_A, 3, HIGH);
			 ok_or_not =Gpio_WritePin(GPIO_A, 4, HIGH);
			 ok_or_not =Gpio_WritePin(GPIO_A, 5, HIGH);
			 ok_or_not =Gpio_WritePin(GPIO_A, 6, HIGH);
			 break;

		 case 9:
			 ok_or_not =Gpio_WritePin(GPIO_A, 0, HIGH);
			 ok_or_not =Gpio_WritePin(GPIO_A, 1, HIGH);
			 ok_or_not =Gpio_WritePin(GPIO_A, 2, HIGH);
			 ok_or_not =Gpio_WritePin(GPIO_A, 3, LOW);
			 ok_or_not =Gpio_WritePin(GPIO_A, 4, LOW);
			 ok_or_not =Gpio_WritePin(GPIO_A, 5, HIGH);
			 ok_or_not =Gpio_WritePin(GPIO_A, 6, HIGH);
		 break;
		default:
			break;
		}

}
