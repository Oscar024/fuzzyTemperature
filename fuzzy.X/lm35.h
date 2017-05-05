/* 
 * File:   funciones.h
 * Author: oscar
 *
 * Created on 6 de junio de 2015, 17:30
 */

#ifndef LM35_H
#define	LM35_H


#define __XTAL_FREQ 4000000

#define MODO PORTBbits.RB7
#define CHANNEL PORTBbits.RB6



double temp_sense(unsigned char canal);

#endif	/* FUNCIONES_H */

