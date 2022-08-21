
/*
  EXAMPLE FOR SDA5708 LIBRARY
  demonstrates how to connect more than one individual display.
*/

// pin definitions

#define SDA_DATA_PIN        10    // data pin for both displays
#define SDA_CLOCK_PIN       11    // clock pin for both displays
#define SDA_RESET_PIN       12    // reset pin for both displays

#define SDA1_LOAD_PIN       A0    // load pin for first display
#define SDA2_LOAD_PIN       A1    // load pin for second display
#define SDA3_LOAD_PIN       A2    // load pin for second display

// create instances

#include <SDA5708.h>
SDA5708 sda1(SDA_RESET_PIN, SDA_DATA_PIN, SDA_CLOCK_PIN, SDA1_LOAD_PIN);
SDA5708 sda2(SDA_RESET_PIN, SDA_DATA_PIN, SDA_CLOCK_PIN, SDA2_LOAD_PIN);
SDA5708 sda3(SDA_RESET_PIN, SDA_DATA_PIN, SDA_CLOCK_PIN, SDA3_LOAD_PIN);

// init

void setup() {
  sda1.print((char*)"DISPlAY1");
  sda2.print((char*)"DISPLAY2");
  sda3.print((char*)"DISPLAY3");
}

// empty main loop

void loop() {
}
