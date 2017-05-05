/*******************************************************************************
 * Archivo: main.c
 * Autores: Ing. Oscar Rigoberto Carvajal Ortiz
 * Fecha: 28 de Osctubre de 2016, 07:03 PM
 * Versión: 1.0
 * IDE: MPLAB XC8
 * Empresa: Maestría en Ciencias de la Computación ITT
 * MCU: PIC18F4550

 ******************************************************************************/


#include <xc.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lcd.h"
#include "ADC.h"
#include "pic18f4550config.h"
#include "lm35.h"
#include "funciones.h"
#include <pic18f4550.h>
#include "fuzzy.h"
#include "pwm.h"

int main()
{

  mcu_init();Lcd_Init();Lcd_Clear();Init_ADC();Lcd_Set_Cursor(1,1);Lcd_Write_String("Inicio");
  PWM_init(0xFF);
  double duty,temperatura;
  
  while(1){
      
      temperatura=temp_sense(0);
      duty=fuzzy_system_single(temperatura);
      duty=(float)duty;
      Lcd_Set_Cursor(2,1);
      Lcd_Write_String("%PWM: ");
      Lcd_Write_Float(duty);
      PWM_DutyCycle(duty);
      
  }
  
  return 0;
}
 


