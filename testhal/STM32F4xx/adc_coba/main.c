#include "ch.h"
#include "hal.h"

#include "my_lcd.h"
#include "my_adc.h"
#include "my_pin.h"
#include "my_process.h"
#include "aksesoris.h"

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
extern adcsample_t adc_val16;
extern adcsample_t adc_val17;
extern adcsample_t adc_val18;
extern adcsample_t adc_val19;
extern adcsample_t adc_val20;

extern uint8_t menu;

extern char string[LCD_LONG];

char start=0;

int main(void) {
  
  halInit();
  chSysInit();
  aksesoris_setup();
  Adc_Init();
  Lcd_Init();
  Lcd_Clear();
  chprintf((BaseSequentialStream *)&lcdDriver,"Preparing");
  
  for(start=0;start<10;start++){
    Lcd_Cursor(0,2);
    chprintf((BaseSequentialStream *)&lcdDriver,"PROGRESS %5i",start);
    chThdSleepMilliseconds(10);
  };
  chThdSleepMilliseconds(500);
  
  Lcd_Clear();
  Lcd_Cursor(0,0);
  chprintf((BaseSequentialStream *)&lcdDriver,"MPPT Voltage Monitor");
  Pin_Setup();
  
    
  while (TRUE){
    
    if(palReadPad(GPIOE,1)==PAL_LOW){
      menu++;
      if(menu==4){menu=1;}
    }
    chThdSleepMilliseconds(500);
  };
}