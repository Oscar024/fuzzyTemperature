/* 
 * File:   ADC.h
 * Author: oscar
 *
 * Created on 7 de junio de 2015, 17:15
 */

#ifndef ADC_H
#define	ADC_H

//#include<plib/adc.h>
#include <xc.h>


void Init_ADC(void);
int Leer_ADC(void);
void ADC_select_channel(unsigned char channel);


#endif	/* ADC_H */

