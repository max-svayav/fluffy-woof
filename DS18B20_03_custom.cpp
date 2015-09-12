

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
#include "OneWire.h"
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1
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
extern "C" void DS18B20_03_Outputs_custom_wrapper(const uint8_T *PIN,
			uint8_T *CRC,
			uint8_T *BYTE0,
			uint8_T *BYTE1,
			uint8_T *BYTE2,
			uint8_T *BYTE3,
			uint8_T *BYTE4,
			uint8_T *BYTE5,
			uint8_T *BYTE6,
			uint8_T *BYTE7)
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
OneWire  ds(PIN[0]); 
  byte i;
  byte present = 0;
  byte type_s;
  byte data[12];
  byte addr[8];
  double celsius;
  
  if ( !ds.search(addr)) {
    ds.reset_search();
    delay(250);
    return;
  }
  
  switch (addr[0]) {
    case 0x10:
      type_s = 1;
      break;
    case 0x28:
      type_s = 0;
      break;
    case 0x22:
      type_s = 0;
      break;
    default:
      return;
  } 
  
  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);        
  delay(1000);     
  present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE);        

  for ( i = 0; i < 9; i++) {          
    data[i] = ds.read();
  }

int16_t raw = (data[1] << 8) | data[0];
  
  if (type_s) {
    raw = raw << 3; 
    if (data[7] == 0x10) {
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } 
  else {
    byte cfg = (data[4] & 0x60);
    if (cfg == 0x00) raw = raw & ~7;  
    else if (cfg == 0x20) raw = raw & ~3; 
    else if (cfg == 0x40) raw = raw & ~1; 
  }
  celsius = (float)raw / 16.0;
BYTE0[0] = data[0];
BYTE1[0] = data[1];
BYTE2[0] = data[2];
BYTE3[0] = data[3];
BYTE4[0] = data[4];
BYTE5[0] = data[5];
BYTE6[0] = data[6];
BYTE7[0] = data[7];
CRC[0] = data[8];
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
