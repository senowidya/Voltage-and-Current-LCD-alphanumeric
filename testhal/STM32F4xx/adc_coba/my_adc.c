/*
    ChibiOS/RT - Copyright (C) 2006-2013 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "ch.h"
#include "hal.h"
#include "my_adc.h"

#define ADC_GRP_NUM_CHANNELS   15
#define ADC_GRP_BUF_DEPTH      10

static adcsample_t samples[ADC_GRP_NUM_CHANNELS * ADC_GRP_BUF_DEPTH];

adcsample_t adc_val;
adcsample_t adc_val2;
adcsample_t adc_val3;
adcsample_t adc_val4;
adcsample_t adc_val5;
adcsample_t adc_val6;
adcsample_t adc_val7;
adcsample_t adc_val8;
adcsample_t adc_val9;
adcsample_t adc_val10;
adcsample_t adc_val11;
adcsample_t adc_val12;
adcsample_t adc_val13;
adcsample_t adc_val14;
adcsample_t adc_val15;

uint32_t adc_buff;
uint32_t adc_buff2;
uint32_t adc_buff3;
uint32_t adc_buff4;
uint32_t adc_buff5;
uint32_t adc_buff6;
uint32_t adc_buff7;
uint32_t adc_buff8;
uint32_t adc_buff9;
uint32_t adc_buff10;
uint32_t adc_buff11;
uint32_t adc_buff12;
uint32_t adc_buff13;
uint32_t adc_buff14;
uint32_t adc_buff15;



/*
 * ADC streaming callback.
 */
static void adccallback(ADCDriver *adcp, adcsample_t *buffer, size_t n) {

  (void)buffer;
  (void)n;
   int i;
  
  if (adcp->state == ADC_COMPLETE){
    
    adc_buff=0;
    adc_buff2=0;
    adc_buff3=0;
    adc_buff4=0;
    adc_buff5=0;
    adc_buff6=0;
    adc_buff7=0;
    adc_buff8=0;
    adc_buff9=0;    
    adc_buff10=0;
    adc_buff11=0;
    adc_buff12=0;
    adc_buff13=0;
    adc_buff14=0;
    adc_buff15=0;
          
    for(i=0;i<10;i++){
    adc_buff=adc_buff+samples[0+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff2=adc_buff2+samples[1+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff3=adc_buff3+samples[2+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff4=adc_buff4+samples[3+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff5=adc_buff5+samples[4+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff6=adc_buff6+samples[5+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff7=adc_buff7+samples[6+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff8=adc_buff8+samples[7+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff9=adc_buff9+samples[8+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff10=adc_buff10+samples[9+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff11=adc_buff11+samples[10+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff12=adc_buff12+samples[11+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff13=adc_buff13+samples[12+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff14=adc_buff14+samples[13+(ADC_GRP_NUM_CHANNELS*i)];
    adc_buff15=adc_buff15+samples[14+(ADC_GRP_NUM_CHANNELS*i)];
           
    };  
    adc_val= adc_buff/10;
    adc_val2= adc_buff2/10;
    adc_val3= adc_buff3/10;
    adc_val4= adc_buff4/10;
    adc_val5= adc_buff5/10;
    adc_val6= adc_buff6/10;
    adc_val7= adc_buff7/10;
    adc_val8= adc_buff8/10;
    adc_val9= adc_buff9/10;     
    adc_val10= adc_buff10/10;
    adc_val11= adc_buff11/10;
    adc_val12= adc_buff12/10;
    adc_val13= adc_buff13/10;
    adc_val14= adc_buff14/10;
    adc_val15= adc_buff15/10;
  }
}

/*
 * ADC conversion group.
 * Mode:        Continuous, 16 samples of 8 channels, SW triggered.
 * Channels:    IN11, IN12, IN11, IN12, IN11, IN12, Sensor, VRef.
 */
static const ADCConversionGroup adcgrpcfg = {
  FALSE,
  ADC_GRP_NUM_CHANNELS,
  adccallback,
  NULL,
  0,                        /* CR1 */
  ADC_CR2_SWSTART,	/* CR2 */
  ADC_SMPR1_SMP_AN10(ADC_SAMPLE_56) | ADC_SMPR1_SMP_AN11(ADC_SAMPLE_56) | \
  ADC_SMPR1_SMP_AN12(ADC_SAMPLE_56) | ADC_SMPR1_SMP_AN13(ADC_SAMPLE_56) | \
  ADC_SMPR1_SMP_AN14(ADC_SAMPLE_56) | ADC_SMPR1_SMP_AN15(ADC_SAMPLE_56) ,
    
  ADC_SMPR2_SMP_AN1(ADC_SAMPLE_56) | ADC_SMPR2_SMP_AN2(ADC_SAMPLE_56) | \
  ADC_SMPR2_SMP_AN3(ADC_SAMPLE_56) | ADC_SMPR2_SMP_AN4(ADC_SAMPLE_56) | \
  ADC_SMPR2_SMP_AN5(ADC_SAMPLE_56) | ADC_SMPR2_SMP_AN6(ADC_SAMPLE_56) | \
  ADC_SMPR2_SMP_AN7(ADC_SAMPLE_56) | ADC_SMPR2_SMP_AN8(ADC_SAMPLE_56) |  \
  ADC_SMPR2_SMP_AN9(ADC_SAMPLE_56),                        /* SMPR2 */
    
  ADC_SQR1_NUM_CH(ADC_GRP_NUM_CHANNELS) | ADC_SQR1_SQ13_N(ADC_CHANNEL_IN12) | ADC_SQR1_SQ14_N(ADC_CHANNEL_IN13) | \
  ADC_SQR1_SQ15_N(ADC_CHANNEL_IN14),
  
  ADC_SQR2_SQ7_N(ADC_CHANNEL_IN6) | ADC_SQR2_SQ8_N(ADC_CHANNEL_IN7) | \
  ADC_SQR2_SQ9_N(ADC_CHANNEL_IN8) | ADC_SQR2_SQ10_N(ADC_CHANNEL_IN9) | \
  ADC_SQR2_SQ11_N(ADC_CHANNEL_IN10) | ADC_SQR2_SQ12_N(ADC_CHANNEL_IN11),
    
  ADC_SQR3_SQ6_N(ADC_CHANNEL_IN5)   | ADC_SQR3_SQ5_N(ADC_CHANNEL_IN4) |
  ADC_SQR3_SQ4_N(ADC_CHANNEL_IN3)   | ADC_SQR3_SQ3_N(ADC_CHANNEL_IN2) |
  ADC_SQR3_SQ2_N(ADC_CHANNEL_IN1)   | ADC_SQR3_SQ1_N(ADC_CHANNEL_IN0)
};


/*
 * Application entry point.
 */
static WORKING_AREA(wa_adcThread, 128);
static msg_t adcThread(void *arg) {
  (void)arg;
  while (TRUE) {
    chThdSleepMilliseconds(100);
    adcStartConversion(&ADCD1, &adcgrpcfg, samples, ADC_GRP_BUF_DEPTH);
  }
  return 0;
}

void Adc_Init(void){
  palSetPadMode(GPIOA,0,PAL_MODE_INPUT_ANALOG);  //ADC 1
  palSetPadMode(GPIOA,1,PAL_MODE_INPUT_ANALOG);  //ADC 2
  palSetPadMode(GPIOA,2,PAL_MODE_INPUT_ANALOG);  //ADC 3
  palSetPadMode(GPIOA,3,PAL_MODE_INPUT_ANALOG);  //ADC 4
  palSetPadMode(GPIOA,4,PAL_MODE_INPUT_ANALOG);  //ADC 5
  
  palSetPadMode(GPIOA,5,PAL_MODE_INPUT_ANALOG);  //ADC 6
  palSetPadMode(GPIOA,6,PAL_MODE_INPUT_ANALOG);  //ADC 7
  palSetPadMode(GPIOA,7,PAL_MODE_INPUT_ANALOG);  //ADC 8
  palSetPadMode(GPIOB,0,PAL_MODE_INPUT_ANALOG);  //ADC 9
  palSetPadMode(GPIOB,1,PAL_MODE_INPUT_ANALOG);  //ADC 10  
  
  palSetPadMode(GPIOC,0,PAL_MODE_INPUT_ANALOG);  //ADC 11
  palSetPadMode(GPIOC,1,PAL_MODE_INPUT_ANALOG);  //ADC 12
  palSetPadMode(GPIOC,2,PAL_MODE_INPUT_ANALOG);  //ADC 13
  palSetPadMode(GPIOC,3,PAL_MODE_INPUT_ANALOG);  //ADC 14
  palSetPadMode(GPIOC,4,PAL_MODE_INPUT_ANALOG);  //ADC 15
  adcStart(&ADCD1, NULL);
  chThdCreateStatic(wa_adcThread, sizeof(wa_adcThread), NORMALPRIO, adcThread, NULL);
}