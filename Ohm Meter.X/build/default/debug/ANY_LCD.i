# 1 "ANY_LCD.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "D:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18F-K_DFP/1.5.114/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "ANY_LCD.c" 2
# 22 "ANY_LCD.c"
# 1 "D:\\Program Files\\Microchip\\xc8\\v2.35\\pic\\include\\c99\\stdint.h" 1 3



# 1 "D:\\Program Files\\Microchip\\xc8\\v2.35\\pic\\include\\c99\\musl_xc8.h" 1 3
# 4 "D:\\Program Files\\Microchip\\xc8\\v2.35\\pic\\include\\c99\\stdint.h" 2 3
# 22 "D:\\Program Files\\Microchip\\xc8\\v2.35\\pic\\include\\c99\\stdint.h" 3
# 1 "D:\\Program Files\\Microchip\\xc8\\v2.35\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 127 "D:\\Program Files\\Microchip\\xc8\\v2.35\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 142 "D:\\Program Files\\Microchip\\xc8\\v2.35\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long intptr_t;
# 158 "D:\\Program Files\\Microchip\\xc8\\v2.35\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 188 "D:\\Program Files\\Microchip\\xc8\\v2.35\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 229 "D:\\Program Files\\Microchip\\xc8\\v2.35\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 22 "D:\\Program Files\\Microchip\\xc8\\v2.35\\pic\\include\\c99\\stdint.h" 2 3


typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 144 "D:\\Program Files\\Microchip\\xc8\\v2.35\\pic\\include\\c99\\stdint.h" 3
# 1 "D:\\Program Files\\Microchip\\xc8\\v2.35\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 144 "D:\\Program Files\\Microchip\\xc8\\v2.35\\pic\\include\\c99\\stdint.h" 2 3
# 22 "ANY_LCD.c" 2

# 1 "./ANY_LCD.h" 1
# 68 "./ANY_LCD.h"
typedef struct any_lcd{
# 89 "./ANY_LCD.h"
 void (*lcd_write)(uint8_t bitfield);





 void (*delay_us)(uint32_t microseconds);

}any_lcd_t;
# 107 "./ANY_LCD.h"
void LCD_Reset(any_lcd_t lcd);





void LCD_WriteCMD(uint16_t cmd,any_lcd_t lcd);





void LCD_WriteString(char *str,any_lcd_t lcd);




void LCD_WriteData(uint16_t data,any_lcd_t lcd);
# 133 "./ANY_LCD.h"
void LCD_Init(any_lcd_t lcd);
# 23 "ANY_LCD.c" 2
# 42 "ANY_LCD.c"
static void LCD_MakeCMD(uint16_t *buffer,uint16_t data);
# 52 "ANY_LCD.c"
static void LCD_MakeData(uint16_t *buffer,uint16_t data);
# 62 "ANY_LCD.c"
static void LCD_SendBytes(uint16_t *buffer,any_lcd_t lcd,uint8_t len);
# 71 "ANY_LCD.c"
void LCD_WriteCMD(uint16_t cmd,any_lcd_t lcd){
    static uint16_t buffer[4];
    LCD_MakeCMD(buffer,cmd);
    LCD_SendBytes(buffer,lcd,4);
}





void LCD_WriteString(char *str,any_lcd_t lcd){

    static uint16_t buffer[4];
    while(*str){
        LCD_MakeData(buffer,*str);
        LCD_SendBytes(buffer,lcd,4);
        str++;
    }
}





void LCD_WriteData(uint16_t data,any_lcd_t lcd){
    static uint16_t buffer[4];
    LCD_MakeData(buffer,data);
    LCD_SendBytes(buffer,lcd,4);
}
# 108 "ANY_LCD.c"
void LCD_Init(any_lcd_t lcd){
    LCD_WriteCMD(0x33,lcd);
    LCD_WriteCMD(0x32,lcd);
    LCD_WriteCMD(0x28,lcd);
    LCD_WriteCMD(0x0F,lcd);
    LCD_WriteCMD(0x01,lcd);
    lcd.delay_us(1E4);
}





void LCD_Reset(any_lcd_t lcd){
    LCD_WriteCMD(0x01,lcd);
    lcd.delay_us(5E3);
    LCD_WriteCMD(0x02,lcd);
    lcd.delay_us(1E4);
}
# 137 "ANY_LCD.c"
static void LCD_MakeCMD(uint16_t *buffer,uint16_t data){



    buffer[0] = ((data & 0xF0) | 0x08 | 0x04) & (~0x01) & (~0x02);

    buffer[1] = ((data & 0xF0) | 0x08) & (~0x01) & (~0x02) & (~0x04);



    buffer[2] = (((data<<4) & 0xF0) | 0x08 | 0x04) & (~0x01) & (~0x02);

    buffer[3] = (((data<<4) & 0xF0) | 0x08) & (~0x01) & (~0x02) & (~0x04);
}
# 161 "ANY_LCD.c"
static void LCD_MakeData(uint16_t *buffer,uint16_t data){



    buffer[0] = ((data & 0xF0) | 0x08 | 0x04 | 0x01) & (~0x02);

    buffer[1] = ((data & 0xF0) | 0x08 | 0x01) & (~0x02) & (~0x04);



    buffer[2] = (((data<<4) & 0xF0) | 0x08 | 0x04 | 0x01) & (~0x02);

    buffer[3] = (((data<<4) & 0xF0) | 0x08 | 0x01) & (~0x02) & (~0x04);
}
# 184 "ANY_LCD.c"
static void LCD_SendBytes(uint16_t *buffer,any_lcd_t lcd,uint8_t len){

 for(uint8_t i = 0;i < len;i++){
  lcd.lcd_write(buffer[i]);
         lcd.delay_us(1E3);
 }

}
