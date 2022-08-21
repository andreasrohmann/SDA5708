
/*
  EXAMPLE FOR SDA5708 LIBRARY
  demonstrates how to minimize the memory footprint
*/

// hardware configuration

#define SDA_LOAD_PIN        A0      // Load pin of first display
#define SDA_DATA_PIN        10      // Data pins
#define SDA_CLOCK_PIN       11      // Clock pins
#define SDA_RESET_PIN       12      // Reset pins

// minimize memory usage

#define SDA5708_NO_UDC                      // no user defined characters
#define SDA5708_EXCLUDE_SPECIAL             // limit font to standard ascii range 0x20 to 0x7F

// create instance

#include <SDA5708.h>
SDA5708 sda(SDA_RESET_PIN, SDA_DATA_PIN, SDA_CLOCK_PIN, SDA_LOAD_PIN);

// empty setup

void setup() {
}

// empty main loop

void loop() {
}
