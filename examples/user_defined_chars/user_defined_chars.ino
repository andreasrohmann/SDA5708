
/*
  EXAMPLE FOR SDA5708 LIBRARY
  demonstrates how to define user defined characters
*/

// hardware configuration

#define SDA_LOAD_PIN        A0      // Load pin of first display
#define SDA_DATA_PIN        10      // Data pins
#define SDA_CLOCK_PIN       11      // Clock pins
#define SDA_RESET_PIN       12      // Reset pins

// create instance

#include <SDA5708.h>
SDA5708 sda(SDA_RESET_PIN, SDA_DATA_PIN, SDA_CLOCK_PIN, SDA_LOAD_PIN);

// init

void setup() {
  // define characters
  sda.createChar(0xF0, 
       B10101,
       B01010,
       B10101,
       B01010,
       B10101,
       B01010,
       B10101);
  sda.createChar(0xF1, 
       B01010,
       B10101,
       B01010,
       B10101,
       B01010,
       B10101,
       B01010);
  // show characters
  sda.write(0xF0,0);
  sda.write(0xF1,1);
  sda.write(0xF0,2);
  sda.write(0xF1,3);
  sda.write(0xF0,4);
  sda.write(0xF1,5);
  sda.write(0xF0,6);
  sda.write(0xF1,7);
}

// empty main loop

void loop() {
}
