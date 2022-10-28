/*
 * fsm_manual.c
 *
 *  Created on: Oct 12, 2022
 *      Author: ASUS
 */
#include "fsm_manual.h"
#include "global.h"
void fsm_manual_run(){
	switch (status){
	case MAN_RED:
		//TODO
		if(timer1_flag==1){
			status= AUTO_RED;
			setTimer(5000);
		}
		if(button1_flag==1){
			button1_flag=0;
			status=MAN_GREEN;
			setTimer(10000);
		}
		break;
	case MAN_GREEN:
		break;
	case MAN_YELLOW:
		break;
	default:
		break;
	}
}
void fsm_automatic_run(){
	switch (status){
	case INIT:
		status=AUTO_RED;
		break;
	case AUTO_RED:
		if(timer1_flag==1){
			HAL_GPIO_WritePin(GPIOB, A_Pin,SET);
			HAL_GPIO_WritePin(GPIOB, B_Pin,RESET);
			setTimer(5000);
			status= AUTO_GREEN;
		}
		break;
	case AUTO_GREEN:
		if(timer1_flag==1){
			HAL_GPIO_WritePin(GPIOB, A_Pin,RESET);
			HAL_GPIO_WritePin(GPIOB, B_Pin,SET);
			setTimer(3000);
			status=AUTO_YELLOW;
		}
		break;
	case AUTO_YELLOW:
		if(timer1_flag==1){
			HAL_GPIO_WritePin(GPIOB, A_Pin,SET);
			HAL_GPIO_WritePin(GPIOB, B_Pin,SET);
			setTimer(2000);
			status=AUTO_RED;
		break;
	}
}
}
