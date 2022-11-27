/*
 * Button.c
 *
 *  Created on: Nov 14, 2022
 *      Author: ASUS
 */
#include "Button.h"
#include"global.h"

int mode1 = NORMAL_STATE;
int mode2 = NORMAL_STATE;
int mode3 = NORMAL_STATE;
int mode4 = NORMAL_STATE;

int inc1 = NORMAL_STATE;
int inc2 = NORMAL_STATE;
int inc3 = NORMAL_STATE;
int inc4 = NORMAL_STATE;

int set1 = NORMAL_STATE;
int set2 = NORMAL_STATE;
int set3 = NORMAL_STATE;
int set4 = NORMAL_STATE;

int mode_flag=0;
int inc_flag=0;
int set_flag=0;

int mode_timeout=200;
int inc_timeout=200;
int set_timeout=200;

void subMODEProcess()
{
	mode_flag=1;
}

void subINCProcess()
{
	inc_flag=1;
}

void subSETProcess()
{
	set_flag=1;
}

void getMODEInput()
{
	mode3= mode2;
	mode2= mode1;
	mode1= HAL_GPIO_ReadPin(GPIOB, mode_Pin);
	if(mode1==mode2 && mode2==mode3)
	{
		if(mode3!=mode4)
		{
			mode4=mode3;
			if(mode4==PRESSED_STATE)
			{
				subMODEProcess();
			}
		}
		else
		{
			mode_timeout--;
			if(mode_timeout==0)
			{
				mode4= NORMAL_STATE;
				mode_timeout=200;
			}
		}
	}
}


void getINCInput()
{
	inc3= inc2;
	inc2= inc1;
	inc1= HAL_GPIO_ReadPin(GPIOB, inc_Pin);
	if(inc1==inc2 && inc2==inc3)
	{
		if(inc3!=inc4)
		{
			inc4=inc3;
			if(inc4==PRESSED_STATE)
			{
				subINCProcess();
				inc_timeout=100;
			}
		}
		else
		{
			inc_timeout--;
			if(inc_timeout==0)
			{
				if(inc4==PRESSED_STATE)
				{
					subINCProcess();
					inc_timeout=40;
				}
				else
				{
					inc4= NORMAL_STATE;
					inc_timeout=200;
				}
			}
		}
	}
}

void getSETInput()
{
	set3= set2;
	set2= set1;
	set1= HAL_GPIO_ReadPin(GPIOB, set_Pin);
	if(set1==set2 && set2==set3)
	{
		if(set3!=set4)
		{
			set4=set3;
			if(set4==PRESSED_STATE)
			{
				subSETProcess();
			}
		}
		else
		{
			set_timeout--;
			if(set_timeout==0)
			{
				set4= NORMAL_STATE;
				set_timeout=200;
			}
		}
	}
}


