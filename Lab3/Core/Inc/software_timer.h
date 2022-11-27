/*
 * software_timer.h
 *
 *  Created on: Nov 14, 2022
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

int timer_flag;
int side_flag;
int count_flag;
int count2_flag;

void setTimer(int duration);
void setSide(int duration);
void setCount(int duration);
void setCount2(int duration);

void timerRun();
void sideRun();
void countRun();
void count2Run();

#endif /* INC_SOFTWARE_TIMER_H_ */
