
/*
  EXAMPLE FOR SDA5708 LIBRARY
  Loops over all integers from 0 to 65535 and displays the
  decimal value, hexadecimal value and PI times the value.
  3 displays connected together are needed for this demo.
*/

// sketch configuration

#define DISPLAY_COUNT 3                // Number of connected displays
#define DISPLAY_CHARS 8*DISPLAY_COUNT  // Number of characters over all displays

// hardware configuration

#define SDA_LOAD_PIN        A0         // Load pin of first display
#define SDA_DATA_PIN        10         // Data pins of all displays
#define SDA_CLOCK_PIN       11         // Clock pins of all displays
#define SDA_RESET_PIN       12         // Reset pins of all displays

// create instance of library

#include <SDA5708.h>
SDA5708 sda(DISPLAY_COUNT, SDA_RESET_PIN, SDA_DATA_PIN, SDA_CLOCK_PIN, SDA_LOAD_PIN);

// initial message

void setup() {
  sda.print("Using: SPRINTF & DTOSTRF");
  delay(2000);
  sda.clear();
}

// needed buffers

char buf[DISPLAY_CHARS];  // buffer for sprintf function
char flt[12];             // vuffer for converting float to String

// main loop

void loop() {
  for (uint16_t i=0; i<=0xffff; i++) {
    // convert float to string, sprintf doesn't support floats
    dtostrf(i*PI, 9, 4, flt);
    // fill buffer 
    sprintf(buf, "%5u - %04X - %s", i, i, flt);
    // print at position 0
    sda.println(buf);
    // give humans time to read
    delay(100);
  }
}
