#include "aksesoris.h"
#include "ch.h"
#include "hal.h"

void riting_kanan(void){
  palSetPad(GPIOD,12);
  palSetPad(GPIOE,6);
  chThdSleepMilliseconds(500);     
  palClearPad(GPIOD,12);
  palClearPad(GPIOE,6);  
  chThdSleepMilliseconds(500);
     
  }
  void riting_kiri(void){
  palSetPad(GPIOD, 13);
  palSetPad(GPIOE,4);
  chThdSleepMilliseconds(500);
  palClearPad(GPIOD,13);
  palClearPad(GPIOE,4);
  chThdSleepMilliseconds(500);
  }
 void hazard(void){
    palSetPad(GPIOD, 12);  
    palSetPad(GPIOD, 13);
    palSetPad(GPIOE,4);
    palSetPad(GPIOE,6);
    chThdSleepMilliseconds(500);
    palClearPad(GPIOD, 12); 
    palClearPad(GPIOD,13);
    palClearPad(GPIOE,4);
    palClearPad(GPIOE,6);
    chThdSleepMilliseconds(500); 
  } 
  void klakson(void){
 palSetPad(GPIOD,14);
 palSetPad(GPIOE,2);
   }

static WORKING_AREA(wa_aksesorisThread, 128);
static msg_t aksesorisThread(void *arg) {
  (void)arg;
 while (TRUE) {
      if(palReadPad(GPIOE,3)==PAL_LOW){
      riting_kanan();
      }else{palClearPad(GPIOD,12);}
   
      if(palReadPad(GPIOE,5)==PAL_LOW){
      riting_kiri();
      }else{palClearPad(GPIOD,13);}
   
      if(palReadPad(GPIOC,13)==PAL_LOW){
      hazard();
      }else{palClearPad(GPIOD, 12); 
	palClearPad(GPIOD,13);}
   
      if(palReadPad(GPIOC,15)==PAL_LOW){
      klakson();
      }else{palClearPad(GPIOD,14);}
  }
  return 0;
}

void aksesoris_setup(void){
  palSetPadMode(GPIOD,12, PAL_MODE_OUTPUT_PUSHPULL),palSetPadMode(GPIOE,4, PAL_MODE_OUTPUT_PUSHPULL);
  palSetPadMode(GPIOD,13, PAL_MODE_OUTPUT_PUSHPULL),palSetPadMode(GPIOE,6, PAL_MODE_OUTPUT_PUSHPULL);
  palSetPadMode(GPIOE,15, PAL_MODE_OUTPUT_PUSHPULL),palSetPadMode(GPIOE,2, PAL_MODE_OUTPUT_PUSHPULL);
  
    
  palSetPadMode(GPIOE,3, PAL_MODE_INPUT_PULLDOWN);
  palSetPadMode(GPIOE,5, PAL_MODE_INPUT_PULLDOWN);
  palSetPadMode(GPIOC,13, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOC,14, PAL_MODE_INPUT_PULLUP);
  
  chThdCreateStatic(wa_aksesorisThread, sizeof(wa_aksesorisThread), NORMALPRIO, aksesorisThread, NULL);
}
