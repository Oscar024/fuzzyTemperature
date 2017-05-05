/*
 * File:   funciones.c
 * Author: OSCAR
 *
 * Created on October 28, 2016, 9:31 PM
 */


#include <xc.h>



void mcu_init(void){
    //Inicialización MCU PIC18F4550
    TRISA=TRISB=TRISC=TRISD=TRISE=0;                          //Pines como salidas
    PORTA=PORTB=PORTC=PORTD=PORTE=0;
    

    return;

}
