#include "my_pin.h"
#include "my_lcd.h"
#include "my_process.h"
#include "chprintf.h"
#include "memstreams.h"
#include "evtimer.h"

extern char string[LCD_LONG];

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

extern float volt1,volt2,volt3,volt4, \
	     volt5,volt6,volt7,volt8, \
	     volt9,volt10,volt11,volt12, 
	     volt13, volt14, volt15, volt16, \
	     volt17, volt18, volt19, volt20;
extern float current1,current2,current3,current4;
extern float current1voltdiver,current2voltdiver;

uint8_t menu=1;

static WORKING_AREA(wa_pinThread, 128);
static msg_t pinThread(void *arg) {
  (void)arg;
 while (TRUE) {
      if(menu==1){
      volt_setup();
      Lcd_Cursor(0,3);
      chprintf((BaseSequentialStream *)&lcdDriver,"modul = %i",menu);
      Lcd_Cursor(0,1);
      chsnprintf(string,LCD_LONG,"V01=%5.2f V02=%5.2f",adc_val12);
      chprintf((BaseSequentialStream *)&lcdDriver,"%s",string);
      Lcd_Cursor(0,2);
      chsnprintf(string,LCD_LONG,"V03=%5.2f V04=%5.2f",volt3,volt4);
      chprintf((BaseSequentialStream *)&lcdDriver,"%s",string);
      Lcd_Cursor(10,3);
      chsnprintf(string,LCD_LONG,"V05=%5.2f",volt5);
      chprintf((BaseSequentialStream *)&lcdDriver,"%s",string);
    }
    else if(menu==2){
      volt_setup();
      Lcd_Cursor(0,3);
      chprintf((BaseSequentialStream *)&lcdDriver,"modul = %i",menu);
      Lcd_Cursor(0,1);
      chsnprintf(string,LCD_LONG,"V06=%5.2f V07=%5.2f",volt6,volt7);
      chprintf((BaseSequentialStream *)&lcdDriver,"%s",string);
      Lcd_Cursor(0,2);
      chsnprintf(string,LCD_LONG,"V08=%5.2f V09=%5.2f",volt8,volt9);
      chprintf((BaseSequentialStream *)&lcdDriver,"%s",string);
      Lcd_Cursor(10,3);
      chsnprintf(string,LCD_LONG,"V10=%5.2f",volt10);
      chprintf((BaseSequentialStream *)&lcdDriver,"%s",string);
    }
    else if(menu==3){
      volt_setup();
      Lcd_Cursor(0,3);
      chprintf((BaseSequentialStream *)&lcdDriver,"modul = %i",menu);
      Lcd_Cursor(0,1);
      chsnprintf(string,LCD_LONG,"V11=%5.2f V12=%5.2f",volt11,volt12);
      chprintf((BaseSequentialStream *)&lcdDriver,"%s",string);
      Lcd_Cursor(0,2);
      chsnprintf(string,LCD_LONG,"V13=%5.2f V14=%5.2f",volt13,volt14);
      chprintf((BaseSequentialStream *)&lcdDriver,"%s",string);
      Lcd_Cursor(10,3);
      chsnprintf(string,LCD_LONG,"V15=%5.2f",volt15);
      chprintf((BaseSequentialStream *)&lcdDriver,"%s",string);
          }
    else if(menu==4){
      volt_setup();
      Lcd_Cursor(0,3);
      chprintf((BaseSequentialStream *)&lcdDriver,"modul = %i           ",menu);
      Lcd_Cursor(0,1);
      chsnprintf(string,LCD_LONG,"I1=%5.2f  VD1=%5.2f",current1,current1voltdiver);
      chprintf((BaseSequentialStream *)&lcdDriver,"%s",string);
      Lcd_Cursor(0,2);
      chsnprintf(string,LCD_LONG,"I2=%5.2f  VD2=%5.2f",current2,current2voltdiver);
      chprintf((BaseSequentialStream *)&lcdDriver,"%s",string);
                
    }
    
    
//     Lcd_Cursor(0,3);
//     chprintf((BaseSequentialStream *)&lcdDriver,"modul = %2i",menu);
  }
  return 0;
}

void Pin_Setup(void){
  palSetPadMode(GPIOC,1,PAL_MODE_INPUT_PULLDOWN);
  chThdCreateStatic(wa_pinThread, sizeof(wa_pinThread), NORMALPRIO, pinThread, NULL);
}
