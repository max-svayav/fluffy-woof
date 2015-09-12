

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
#include "Arduino.h"
#include "LiquidCrystal.h"
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
extern "C" void LCD1602_02_Outputs_custom_wrapper(const uint8_T *RS_PIN,
			const uint8_T *EN_PIN,
			const uint8_T *D4_PIN,
			const uint8_T *D5_PIN,
			const uint8_T *D6_PIN,
			const uint8_T *D7_PIN,
			const uint8_T *SYMBOL_CODE_1,
			const uint8_T *SYMBOL_CODE_2,
			const uint8_T *LINE_1,
			const uint8_T *COLUMN_1,
			const uint8_T *LINE_2,
			const uint8_T *COLUMN_2,
			const uint8_T *CURSOR_ON,
			const real32_T *NUMBER_1,
			const real32_T *NUMBER_2)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
*/
#ifndef MATLAB_MEX_FILE
LiquidCrystal lcd(RS_PIN[0], EN_PIN[0], D4_PIN[0], D5_PIN[0], D6_PIN[0], D7_PIN[0]);
lcd.begin(16, 2);
lcd.setCursor(0, 0);
lcd.print(char(SYMBOL_CODE_1[0]));
lcd.setCursor(1, 0);
lcd.print(char(SYMBOL_CODE_1[1]));
lcd.setCursor(2, 0);
lcd.print(char(SYMBOL_CODE_1[2]));
lcd.setCursor(3, 0);
lcd.print(char(SYMBOL_CODE_1[3]));
lcd.setCursor(4, 0);
lcd.print(char(SYMBOL_CODE_1[4]));
lcd.setCursor(5, 0);
lcd.print(char(SYMBOL_CODE_1[5]));
lcd.setCursor(6, 0);
lcd.print(char(SYMBOL_CODE_1[6]));
lcd.setCursor(7, 0);
lcd.print(char(SYMBOL_CODE_1[7]));
lcd.setCursor(8, 0);
lcd.print(char(SYMBOL_CODE_1[8]));
lcd.setCursor(9, 0);
lcd.print(char(SYMBOL_CODE_1[9]));
lcd.setCursor(10, 0);
lcd.print(char(SYMBOL_CODE_1[10]));
lcd.setCursor(11, 0);
lcd.print(char(SYMBOL_CODE_1[11]));
lcd.setCursor(12, 0);
lcd.print(char(SYMBOL_CODE_1[12]));
lcd.setCursor(13, 0);
lcd.print(char(SYMBOL_CODE_1[13]));
lcd.setCursor(14, 0);
lcd.print(char(SYMBOL_CODE_1[14]));
lcd.setCursor(15, 0);
lcd.print(char(SYMBOL_CODE_1[15]));

lcd.setCursor(0, 1);
lcd.print(char(SYMBOL_CODE_2[0]));
lcd.setCursor(1, 1);
lcd.print(char(SYMBOL_CODE_2[1]));
lcd.setCursor(2, 1);
lcd.print(char(SYMBOL_CODE_2[2]));
lcd.setCursor(3, 1);
lcd.print(char(SYMBOL_CODE_2[3]));
lcd.setCursor(4, 1);
lcd.print(char(SYMBOL_CODE_2[4]));
lcd.setCursor(5, 1);
lcd.print(char(SYMBOL_CODE_2[5]));
lcd.setCursor(6, 1);
lcd.print(char(SYMBOL_CODE_2[6]));
lcd.setCursor(7, 1);
lcd.print(char(SYMBOL_CODE_2[7]));
lcd.setCursor(8, 1);
lcd.print(char(SYMBOL_CODE_2[8]));
lcd.setCursor(9, 1);
lcd.print(char(SYMBOL_CODE_2[9]));
lcd.setCursor(10, 1);
lcd.print(char(SYMBOL_CODE_2[10]));
lcd.setCursor(11, 1);
lcd.print(char(SYMBOL_CODE_2[11]));
lcd.setCursor(12, 1);
lcd.print(char(SYMBOL_CODE_2[12]));
lcd.setCursor(13, 1);
lcd.print(char(SYMBOL_CODE_2[13]));
lcd.setCursor(14, 1);
lcd.print(char(SYMBOL_CODE_2[14]));
lcd.setCursor(15, 1);
lcd.print(char(SYMBOL_CODE_2[15]));

lcd.setCursor(COLUMN_1[0], LINE_1[0]);
lcd.print((NUMBER_1[0]));
lcd.setCursor(COLUMN_2[0], LINE_2[0]);
lcd.print((NUMBER_2[0]));
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
