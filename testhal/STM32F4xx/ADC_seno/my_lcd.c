#include "my_lcd.h"

#define LCD_PIN_RS	10
#define LCD_PIN_EN	11
#define LCD_PIN_D4	12
#define LCD_PIN_D5	13
#define LCD_PIN_D6	14
#define LCD_PIN_D7	15

#define LCD_PORT	GPIOE

#define LCD_PINS	((1<<LCD_PIN_RS) | (1<<LCD_PIN_EN) | (1<<LCD_PIN_D4) | (1<<LCD_PIN_D5) | (1<<LCD_PIN_D6) | (1<<LCD_PIN_D7))
#define LCD_PINS_CTRL	((1<<LCD_PIN_RS) | (1<<LCD_PIN_EN))
#define LCD_PINS_DATA	((1<<LCD_PIN_D4) | (1<<LCD_PIN_D5) | (1<<LCD_PIN_D6) | (1<<LCD_PIN_D7))
#define LCD_PORT_MODE	PAL_MODE_OUTPUT_PUSHPULL
#define LCD_PIN_OFFSET	8

#define LCD_LINE0_DDRAMADDR		0x00
#define LCD_LINE1_DDRAMADDR		0x40
#define LCD_LINE2_DDRAMADDR		0x14
#define LCD_LINE3_DDRAMADDR		0x54

enum
{
	LCD_2X16_RESET = 0x30,
	LCD_2X16_4_BIT_BUS = 0x20,
	LCD_2X16_8_BIT_BUS = 0x30,
	LCD_2X16_LINE_ONE = 0x20,
	LCD_2X16_LINES_TWO = 0x28,
	LCD_2X16_FONT_5X8 = 0x20,
	LCD_2X16_FONT_5X10 = 0x24,
	LCD_2X16_DISPLAY_CLEAR = 0x01,
	LCD_2X16_DISPLAY_HOME = 0x02,
	LCD_2X16_DISPLAY_ON = 0x0C,
	LCD_2X16_DISPLAY_RIGHT = 0x1C,
	LCD_2X16_DISPLAY_LEFT = 0x18,
	LCD_2X16_DISPLAY_SHIFT = 0x05,
	LCD_2X16_CURSOR_ON = 0x0A,
	LCD_2X16_CURSOR_BLINK = 0x09,
	LCD_2X16_CURSOR_RIGHT = 0x14,
	LCD_2X16_CURSOR_LEFT = 0x10,
	LCD_2X16_SHIFT_RIGHT = 0x06,
	LCD_2X16_SHIFT_LEFT = 0x04,
	LCD_2X16_CGRAM_ADDR = 0x40,
	LCD_2X16_DDRAM_ADDR = 0x80,
	LCD_2X16_BUSY_FLAG = 0x80,
	LCD_2X16_NEXT_LINE0 = 0x00,
	LCD_2X16_NEXT_LINE1 = 0x40,
	LCD_2X16_NEXT_LINE2 = 0x14,
	LCD_2X16_NEXT_LINE3 = 0x54,
	LCD_2X16_COMMAND = 0x01,
	LCD_2X16_DATA = 0x00,
} lcd_2x16_command;

LcdStream lcdDriver;

static msg_t put
(void *ip, uint8_t chr) {
  (void)ip;

  Lcd_Write_Data(chr);

  return RDY_OK;
}

static const struct LcdStreamVMT vmt = {NULL, NULL, put, NULL};

void lsObjectInit(LcdStream *msp) {

  msp->vmt    = &vmt;
}

void LCD_DATA_DIR_OUT(void){
   palSetPadMode(LCD_PORT,LCD_PIN_RS,LCD_PORT_MODE);
   palSetPadMode(LCD_PORT,LCD_PIN_EN,LCD_PORT_MODE);
   palSetPadMode(LCD_PORT,LCD_PIN_D4,LCD_PORT_MODE);
   palSetPadMode(LCD_PORT,LCD_PIN_D5,LCD_PORT_MODE);
   palSetPadMode(LCD_PORT,LCD_PIN_D6,LCD_PORT_MODE);
   palSetPadMode(LCD_PORT,LCD_PIN_D7,LCD_PORT_MODE);
}

void Lcd_Write(uint8_t data){
  
  pal_lld_clearport(LCD_PORT, LCD_PINS_DATA);
  
  palSetPad(LCD_PORT, LCD_PIN_EN);
  
  pal_lld_setport(LCD_PORT, ((LCD_PINS_DATA | (data & 0xF0))<<LCD_PIN_OFFSET) );
  
  chThdSleepMicroseconds(1);
  
  palClearPad(LCD_PORT, LCD_PIN_EN);
}

void Lcd_Write_Command(uint8_t cmd){
   
  palClearPad(LCD_PORT, LCD_PIN_RS);

  Lcd_Write(cmd);
  Lcd_Write(cmd << 4);
  
}

void Lcd_Write_Data(uint8_t chr){
   
  palSetPad(LCD_PORT, LCD_PIN_RS);

  Lcd_Write(chr);
  Lcd_Write(chr << 4);

  palClearPad(LCD_PORT, LCD_PIN_RS);
   

}

void Lcd_Cursor(uint8_t column, uint8_t line){
   
   uint8_t position = LCD_2X16_DDRAM_ADDR;

  if (line == 1)
  {
    position |= LCD_2X16_NEXT_LINE1;
  }
  
  else if (line == 2)
  {
    position |= LCD_2X16_NEXT_LINE2;
  }
  
  else if (line == 3)
  {
    position |= LCD_2X16_NEXT_LINE3;
  }
  
  Lcd_Write_Command(position | column);
}

#define tunda 50

void Lcd_Init(void){
  
  lsObjectInit(&lcdDriver);
  
  LCD_DATA_DIR_OUT();
  
  pal_lld_clearport(LCD_PORT, LCD_PINS);

  chThdSleepMilliseconds(50);
  
  Lcd_Write(0x20);
  chThdSleepMicroseconds(tunda);
  
  Lcd_Write(0x20);
  chThdSleepMicroseconds(tunda);
  
  Lcd_Write(0x80);
  chThdSleepMicroseconds(tunda);
  
  Lcd_Write(0x00);
  Lcd_Write(0xc0);
  chThdSleepMicroseconds(tunda);
  
  Lcd_Write(0x00);
  Lcd_Write(0x60);
  
}

void Lcd_Clear (void){
  Lcd_Write_Command(0x01);
  chThdSleepMicroseconds(tunda);
}
