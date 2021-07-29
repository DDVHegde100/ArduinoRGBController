#include <MKR1000_TLC5940.h>
#include <MKR1000_Interupts.h>

#include "RGBConverter.h"

RGBConverter converter;

double h1 = 0.0;
double h2 = 0.25;
double h3 = 0.5;
double h4 = 0.75;

void setup() {
  // put your setup code here, to run once:
  TLC_init();
  //Serial.println("setup complete");
}

void loop() {
  byte rgb1[3];
  byte rgb2[3];
  byte rgb3[3];
  byte rgb4[3];

  converter.hsvToRgb(h1, 1.0, 1.0, rgb1); // r: 255 g: 255 b: 255
  converter.hsvToRgb(h2, 1.0, 1.0, rgb2); // r: 143 g: 143 b: 143
  converter.hsvToRgb(h3, 1.0, 1.0, rgb3); // r: 63 g: 63 b: 63
  converter.hsvToRgb(h4, 1.0, 1.0, rgb4);// r: 47 g: 47 b: 47

  TLC_SetChannel(0, _c(rgb1[0]), _c(rgb1[1]), _c(rgb1[2]));  
  TLC_SetChannel(1, _c(rgb2[0]), _c(rgb2[1]), _c(rgb2[2]));  
  TLC_SetChannel(2, _c(rgb3[0]), _c(rgb3[1]), _c(rgb3[2]));  
  TLC_SetChannel(3, _c(rgb4[0]), _c(rgb4[1]), _c(rgb4[2]));  

  h1 += 0.05;
  h2 += 0.05;
  h3 += 0.05;
  h4 += 0.05;

  if(h1 > 1.0)
    h1 = 0.0;
  if(h2 > 1.0)
    h2 = 0.0;
  if(h3 > 1.0)
    h3 = 0.0;
  if(h4 > 1.0)
    h4 = 0.0;

  delay(35);
}

//Convert 0-255 to the 3080-4059 range that's visable on the board
int _c (int v){
  return (((v - 0) * (4059 - 3080)) / (255 - 0)) + 3080;
}
