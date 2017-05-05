/*
 * File:   pwm.c
 * Author: OSCAR
 *
 * Created on 29 de octubre de 2016, 10:49 AM
 */


#include <xc.h>
#include <plib/timers.h>
#include <plib/pwm.h>
#include "pwm.h"


int i = 0;
int countup = 1; //our flag to set up/down dutycycle
int DutyCycle = 0;
unsigned char Timer2Config; //PWM clock source


//void PWM_init(unsigned long pwm_freq)
//{
//    unsigned char pwm_value=0;
//    unsigned long Tpwm=0;
//    Tpwm=1/pwm_freq;
//    Timer2Config = T2_PS_1_16; //prescale 16
//    OpenTimer2(Timer2Config);
//    pwm_value= (char)((Tpwm /(4* _XTAL_FREQ* PRESCALER))-1);
////    pwm_value = (char)(((pwm_freq ) + 1) * 4 * _XTAL_FREQ * PRESCALER);             
//    OpenPWM1(pwm_value); //Open pwm at pwm frequency Hz
//    return;
//}

void PWM_init(unsigned char period)
{
    Timer2Config = T2_PS_1_16; //prescale 16
    OpenTimer2(Timer2Config);             
    OpenPWM1(period); //Open pwm at pwm frequency Hz
    return;
}
void PWM_DutyCycle(unsigned char percentageDuty )
{ 
   
    unsigned int DC=0, DutyCycle=0;
  
    DC=(unsigned int)(percentageDuty *10.23);
//    DutyCycle = (DC* _XTAL_FREQ);
//    SetDCPWM1(DutyCycle);
    SetDCPWM1(DC);
    return;
}