
#include "ADC.h"


void Init_ADC(void)
{
    ADCON1bits.PCFG=0b1100; //Entradas AN0-AN2 configuradas como analógicas
    ADCON0bits.CHS = 0b0000; //Selección de canal AN1 por Default
//    ADCON0bits.VCFG = 0b00;  //Voltage Reference Configuration bit Default
    TRISAbits.TRISA0=TRISAbits.TRISA1=TRISAbits.TRISA3=1; //Pines como entradas
    ADCON0bits.ADON = 1;        // A/D Converter module is enabled
    ADCON2bits.ADFM=1; //Justificación a la derecha
    ADCON2bits.ADCS=0b110; // Fosc/64
    ADCON2bits.ACQT = 0b111; //A/D Acquisition Time Select bits a 20 TAD

    return;
}

int Leer_ADC(void)
{
    int dato_adc=0;

    ADCON0bits.GO = 1;          // A/D conversion in progress
    while(ADCON0bits.GO);       // Wait until A/D conversion finish
//    while (ADCON0bits.GO) continue;   //wait till ADC conversion is over
//    ADCON0bits.ADON = 0;        // A/D Converter module is disabled
    dato_adc = ADRESH;          //AD result high
    dato_adc = dato_adc<<8;     //AD result high to most significant Byte ADRESH
    dato_adc = dato_adc+ADRESL; //Valor digital del ADC ADRESH + ADRESL
    ADCON0bits.GO = 0;          // A/D conversion in progress

    return dato_adc;            //Devuelve el valor digital del ADC
}

void ADC_select_channel(unsigned char channel)
{
    switch (channel){
        case 0:
            ADCON0bits.CHS=0b0000;      //Se selecciona AN0
            break;
        case 1:
            ADCON0bits.CHS=0b0001;      //Se selecciona AN1
            break;
        case 2:
            ADCON0bits.CHS=0b0010;      //Se selecciona AN2
            break;
        case 3:
            ADCON0bits.CHS=0b0011;      //Se selecciona AN3
            break;
        case 4:
            ADCON0bits.CHS=0b0100;      //Se selecciona AN4
            break;
        case 5:
            ADCON0bits.CHS=5;
            break;
        case 6:
            ADCON0bits.CHS=0b0110;      //Se selecciona AN6
            break;
        case 7:
            ADCON0bits.CHS=0b00111;      //Se selecciona AN7
            break;
        case 8:
            ADCON0bits.CHS=8;      //Se selecciona AN7
            break;
        case 9:
            ADCON0bits.CHS=9;      //Se selecciona AN7
            break;
        case 10:
            ADCON0bits.CHS=10;      //Se selecciona AN7
            break;
        case 11:
            ADCON0bits.CHS=11;      //Se selecciona AN7
            break;
        case 12:
            ADCON0bits.CHS=12;      //Se selecciona AN7
            break;
        default :
            ADCON0bits.CHS=0b0000;
            break;
    }

    return;
}

//void Leer_SO(void)
//{
//    double copia=0.0;
//
//    copia=(double)Leer_ADC();
//    copia*=21;
//    copia=round(copia/1024);
//    NO=(int)copia;
//}

