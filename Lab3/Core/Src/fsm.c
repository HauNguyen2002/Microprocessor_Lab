#include "Button.h"
#include "global.h"
#include "software_timer.h"

int red=0;
int yellow=0;
int green=0;
int seg1=0;
int seg2=0;
int seg3=0;
int seg4=0;
int temp=0;
int temp_auto1=0;
int temp_auto2=0;
void fsm_run()
{
	switch (status)
	{
	case RED:
		HAL_GPIO_WritePin(GPIOA, led_green_Pin,0);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin,0);
		if(timer_flag==1)
		{
			HAL_GPIO_TogglePin(GPIOA, led_red_Pin);
			HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
			setTimer(50);
		}
		if(inc_flag==1)
		{
			if(temp>=99) temp=99;
			else temp++;
			seg1=temp-((temp/10)*10);
			seg2=temp/10;
			seg3=seg1;
			seg4=seg2;
			inc_flag=0;
		}
		if(set_flag==1)
		{
			red=temp;
			set_flag=0;
		}
		if(mode_flag==1)
		{
			status=YELLOW;
			seg1=0;
			seg2=0;
			seg3=0;
			seg4=0;
			temp=0;
			mode_flag=0;
		}
		break;
	case YELLOW:
		HAL_GPIO_WritePin(GPIOA, led_red_Pin,0);
		HAL_GPIO_WritePin(GPIOA, LED_RED_Pin,0);
		if(timer_flag==1)
		{
			HAL_GPIO_TogglePin(GPIOA, led_yellow_Pin);
			HAL_GPIO_TogglePin(GPIOA, LED_YELLOW_Pin);
			setTimer(50);
		}
		if(inc_flag==1)
		{
			if(temp>=99) temp=99;
			else temp++;
			seg1=temp-((temp/10)*10);
			seg2=temp/10;
			seg3=seg1;
			seg4=seg2;
			inc_flag=0;
		}
		if(set_flag==1)
		{
			yellow=temp;
			set_flag=0;
		}
		if(mode_flag==1)
		{
			status=GREEN;
			seg1=0;
			seg2=0;
			seg3=0;
			seg4=0;
			temp=0;
			mode_flag=0;
		}
		break;
	case GREEN:
		HAL_GPIO_WritePin(GPIOA, led_yellow_Pin,0);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin,0);
		if(timer_flag==1)
		{
			HAL_GPIO_TogglePin(GPIOA, led_green_Pin);
			HAL_GPIO_TogglePin(GPIOA, LED_GREEN_Pin);
			setTimer(50);
		}
		if(inc_flag==1)
		{
			if(temp>=99) temp=99;
			else temp++;
			seg1=temp-((temp/10)*10);
			seg2=temp/10;
			seg3=seg1;
			seg4=seg2;
			inc_flag=0;
		}
		if(set_flag==1)
		{
			green=temp;
			set_flag=0;
		}
		if(mode_flag==1)
		{
			HAL_GPIO_WritePin(GPIOA, led_green_Pin,0);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin,0);

			mode_flag=0;
			seg1=0;
			seg2=0;
			seg3=0;
			seg4=0;
			temp=0;
			temp_auto1=red;
			temp_auto2=green;
			auto1=AUTO_RED_1;
			auto2=AUTO_GREEN_2;
			status= AUTO;
		}
		break;
	}
}

void auto1_run()
{
	switch(auto1)
	{
	case AUTO_RED_1:
		if(count_flag==1)
		{
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, 0);
			seg1=temp_auto1-((temp_auto1/10)*10);
			seg2=temp_auto1/10;
			temp_auto1--;
			if(temp_auto1<0)
			{
				temp_auto1=green;
				auto1=AUTO_GREEN_1;
				break;
			}
			setCount(100);
		}
		break;
	case AUTO_GREEN_1:
		if(count_flag==1)
		{
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, 1);
			seg1=temp_auto1-((temp_auto1/10)*10);
			seg2=temp_auto1/10;
			temp_auto1--;
			if(temp_auto1<0)
			{
				temp_auto1=yellow;
				auto1=AUTO_YELLOW_1;
				break;
			}
			setCount(100);
		}
		break;
	case AUTO_YELLOW_1:
		if(count_flag==1)
		{
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, 0);
			seg1=temp_auto1-((temp_auto1/10)*10);
			seg2=temp_auto1/10;
			temp_auto1--;
			if(temp_auto1<0)
			{
				temp_auto1=red;
				auto1=AUTO_RED_1;
				break;
			}
			setCount(100);
		}
		break;
	}
}

void auto2_run()
{
	switch(auto2)
	{
	case AUTO_RED_2:
		if(count2_flag==1)
		{
			HAL_GPIO_WritePin(GPIOA, led_red_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, led_yellow_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, led_green_Pin, 0);
			seg3=temp_auto2-((temp_auto2/10)*10);
			seg4=temp_auto2/10;
			temp_auto2--;
			if(temp_auto2<0)
			{
				temp_auto2=green;
				auto2=AUTO_GREEN_2;
				break;
			}
			setCount2(100);
		}
		break;
	case AUTO_GREEN_2:
		if(count2_flag==1)
		{
			HAL_GPIO_WritePin(GPIOA, led_red_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, led_yellow_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, led_green_Pin, 1);
			seg3=temp_auto2-((temp_auto2/10)*10);
			seg4=temp_auto2/10;
			temp_auto2--;
			if(temp_auto2<0)
			{
				temp_auto2=yellow;
				auto2=AUTO_YELLOW_2;
				break;
			}
			setCount2(100);
		}
		break;
	case AUTO_YELLOW_2:
		if(count2_flag==1)
		{
			HAL_GPIO_WritePin(GPIOA, led_red_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, led_yellow_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, led_green_Pin, 0);
			seg3=temp_auto2-((temp_auto2/10)*10);
			seg4=temp_auto2/10;
			temp_auto2--;
			if(temp_auto2<0)
			{
				temp_auto2=red;
				auto2=AUTO_RED_2;
				break;
			}
			setCount2(100);
		}
		break;
	}
}

void segment()
{
	switch (side)
	{
	case SIDE1:
		if(side_flag==1)
		{
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, 0);
			display7SEG_u(seg1);
			display7SEG_t(seg2);
			side=SIDE2;
			setSide(25);
		}
		break;
	case SIDE2:
		if(side_flag==1)
		{
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, 1);
			display7SEG_u(seg3);
			display7SEG_t(seg4);
			side=SIDE1;
			setSide(25);
		}
		break;
	}
}

