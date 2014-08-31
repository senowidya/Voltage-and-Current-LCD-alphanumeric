#include "my_lcd.h"
#include "my_process.h"
#include "my_pin.h"
#include <math.h>

char string[LCD_LONG];

extern LcdStream lcdDriver;
extern adcsample_t adc_val;
extern adcsample_t adc_val2;
extern adcsample_t adc_val3;
extern adcsample_t adc_val4;
extern adcsample_t adc_val5;
extern adcsample_t adc_val6;
extern adcsample_t adc_val7;
extern adcsample_t adc_val8;
extern adcsample_t adc_val9;
extern adcsample_t adc_val10;
extern adcsample_t adc_val11;
extern adcsample_t adc_val12;
extern adcsample_t adc_val13;
extern adcsample_t adc_val14;
extern adcsample_t adc_val15;

#define adctovoltage_MPPT 0.00989800976801
#define adctovoltage_real 0.000732600732601
#define adctocurrent 0.027688875
#define ambang 0
// #define melayang 100

float volt1, volt2,volt3, volt4, \
      volt5, volt6,volt7,volt8, \
      volt9, volt10, volt11, volt12, \
      volt13, volt14, volt15;
      
void volt_setup (void){
  
      volt1=(float) (adc_val-ambang)*adctovoltage_MPPT;
      volt2=(float) (adc_val2-ambang)*adctovoltage_MPPT;
      volt3=(float) (adc_val3-ambang)*adctovoltage_MPPT;
      volt4=(float) (adc_val4-ambang)*adctovoltage_MPPT;
      volt5=(float) (adc_val5-ambang)*adctovoltage_MPPT;
      volt6=(float) (adc_val6-ambang)*adctovoltage_MPPT;
      volt7=(float) (adc_val7-ambang)*adctovoltage_MPPT;
      volt8=(float) (adc_val8-ambang)*adctovoltage_MPPT;
      volt9=(float) (adc_val9-ambang)*adctovoltage_MPPT;
      volt10=(float) (adc_val10-ambang)*adctovoltage_MPPT;
      volt11=(float) (adc_val11-ambang)*adctovoltage_MPPT;
      volt12=(float) (adc_val12-ambang)*adctovoltage_MPPT;
      volt13=(float) (adc_val13-ambang)*adctovoltage_MPPT;
      volt14=(float) (adc_val14-ambang)*adctovoltage_MPPT;
      volt15=(float) (adc_val15-ambang)*adctovoltage_MPPT;          
     }



