#include <xc.h>

#include "lm35.h"
#include "ADC.h"
#include "lcd.h"

#define _XTAL_FREQ 4000000



double temp_sense(unsigned char canal)
{
    double vin=0,adc_result=0,temperatura=0;
      ADC_select_channel(canal);
      adc_result= (double) Leer_ADC();
      vin=(adc_result*5)/(1024);
      temperatura=vin*100;
//      if(canal==0){
//           Lcd_Clear();
           Lcd_Set_Cursor(1,1);
//           Lcd_Write_String("temp:           ");
           Lcd_Write_String("temp: ");
//      }
//      else if (canal==1){
////           Lcd_Clear();
//           Lcd_Set_Cursor(2,1);
//           Lcd_Write_String("temp2: ");
//      }
     
      Lcd_Write_Float(temperatura);
      Lcd_Write_String(" C");
      for(int i=0; i<50;i++)
          __delay_ms(20);
      return temperatura;
}
