#include "software_timer.h"
#include "Button.h"
#include "main.h"
#include "global.h"
#include "segment.h"

int timer_flag=0;
int side_flag=0;
int count_flag=0;
int count2_flag=0;


int timer_count=0;
int side_count=0;
int count_count=0;
int count2_count=0;



void setTimer(int duration)
{
	timer_count=duration;
	timer_flag=0;
}

void timerRun()
{
	if(timer_count>0) timer_count--;
	if(timer_count==0) timer_flag=1;
}

void setSide(int duration)
{
	side_count=duration;
	side_flag=0;
}

void sideRun()
{
	if(side_count>0) side_count--;
	if(side_count==0) side_flag=1;
}

void setCount(int duration)
{
	count_count=duration;
	count_flag=0;
}


void countRun()
{
	if(count_count>0) count_count--;
	if(mode_flag==1)
	{
		status=RED;
		auto1=WAIT1;
		auto2=WAIT2;
		count_count=0;
		count2_count=0;
		timer_flag=1;
		mode_flag=0;

		seg1=0;
		seg2=0;
		seg3=0;
		seg4=0;

		HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, led_red_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, led_yellow_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, led_green_Pin, 0);
	}
	if(count_count==0) count_flag=1;
}

void setCount2(int duration)
{
	count2_count=duration;
	count2_flag=0;
}

void count2Run()
{
	if(count2_count>0) count2_count--;
	if(count2_count==0) count2_flag=1;
}


