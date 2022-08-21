
/*
  EXAMPLE FOR SDA5708 LIBRARY
  displays the whole character set scrolling through n displays
*/

// sketch configuration

#define DISPLAY_COUNT 3                // Number of connected displays
#define DISPLAY_CHARS 8*DISPLAY_COUNT  // Number of characters over all displays

// hardware configuration

#define SDA_LOAD_PIN        A0      // Load pin of first display
#define SDA_DATA_PIN        10      // Data pins
#define SDA_CLOCK_PIN       11      // Clock pins
#define SDA_RESET_PIN       12      // Reset pins

// enable all optional characters

#define SDA5708_INCLUDE_ARROWS
#define SDA5708_INCLUDE_HBLOCKS
#define SDA5708_INCLUDE_VBLOCKS
#define SDA5708_INCLUDE_GRAPHICS

// create instance of library

#include <SDA5708.h>
SDA5708 sda(DISPLAY_COUNT, SDA_RESET_PIN, SDA_DATA_PIN, SDA_CLOCK_PIN, SDA_LOAD_PIN);

// empty setup

void setup() {
}

// main loop

void loop() {
  
  sda.print((char*)"ShowFont");
  delay(1000);

  for (uint8_t i = SDA5708_FONT_START; i <= SDA5708_FONT_END - DISPLAY_CHARS + 1; i++) {
    for (uint8_t n = 0; n < DISPLAY_CHARS; n++) {
      sda.write(i+n, n);
    }
    delay(250);
  }
  delay(2000);
}
