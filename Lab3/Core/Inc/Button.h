/*
 * Button.h
 *
 *  Created on: Nov 14, 2022
 *      Author: ASUS
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int mode_flag;
extern int set_flag;
extern int inc_flag;

void getMODEInput();
void getSETInput();
void getINCInput();
#endif /* INC_BUTTON_H_ */
