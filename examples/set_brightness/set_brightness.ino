
/*
  SAMPLE FOR SDA5708 LIBRARY
  demonstrates use of setBrightness function
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
    sda.print((char*)"SDA 5708");
}

// main loop

void loop() {
  for (uint8_t b = SDA5708_BRIGHTNESS_MAX; b < SDA5708_BRIGHTNESS_MIN; b++) {
    sda.setBrightness(b);
    delay(200);
  }
  for (uint8_t b = SDA5708_BRIGHTNESS_MIN; b > SDA5708_BRIGHTNESS_MAX; b--) {
    sda.setBrightness(b);
    delay(200);
  }
}
