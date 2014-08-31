#include "ch.h"
#include "hal.h"

#include "my_lcd.h"
#include "adcmppt.h"
#include "my_pin.h"
#include "my_process.h"

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

int main(void) {
  
  halInit();
  chSysInit();
  
  Adc_Init();
  Lcd_Init();
  Lcd_Clear();

  Lcd_Clear();
  Lcd_Cursor(0,0);
  chprintf((BaseSequentialStream *)&lcdDriver,"MPPT Energy Monitor");
  Pin_Setup();
    
  while (TRUE){
    if(palReadPad(GPIOE,1)==PAL_HIGH){
      menu++;
      if(menu==5){menu=1;}
    }
    chThdSleepMilliseconds(500);
  };
}