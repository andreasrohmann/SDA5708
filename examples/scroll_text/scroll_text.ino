
/*
  EXAMPLE FOR SDA5708 LIBRARY
  interrupt driven scrolling text 
*/

#include <avr/interrupt.h>

char text[] = 
"SDA-5708   DEMONSTRATION        "
"This nice little 8 character 5x8 dot matrix display from Siemens "
"is easy to handle and more flexible than standard LCD displays. "
"Every dot can be controlled individually but it has no integrated font. "
"I created this tiny and lightweight library for Arduino which provides "
"standard ASCII characters, special characters and graphic symbols. "
"Exactly what I needed for simple projects.     "
"Feel free to use or contribute: github.com/andreasrohmann/SDA5708"
;

#define INITIAL_DELAY 1000          // 2 seconds
#define SCROLL_SPEED 167            // 167 milliseconds
#define REPEAT_COUNT 0              // 0 = infinite
#define REPEAT_DELAY 3000           // 1 second

// hardware configuration

#define DISPLAY_COUNT 3             // Number of connected displays

#define SDA_LOAD_PIN        A0      // Load pin of first display
#define SDA_DATA_PIN        10      // Data pins
#define SDA_CLOCK_PIN       11      // Clock pins
#define SDA_RESET_PIN       12      // Reset pins

// create instance 

#include <SDA5708.h>
SDA5708 sda(DISPLAY_COUNT, SDA_RESET_PIN, SDA_DATA_PIN, SDA_CLOCK_PIN, SDA_LOAD_PIN);

// variables

uint8_t state;    // state machine
int pointer;      // text pointer
int repeat;       // repeat count

// init 

void setup() {
  // init timer 1    
  TCCR1A = 0;
  TCCR1B = _BV(WGM13);
  // print first 8 chars
  pointer = 0;
  writeChars();
  state = 1;
  repeat = REPEAT_COUNT;
  startTimer(INITIAL_DELAY);
}

// empty main loop

void loop() {
}

// helper function to write 8 bytes of text from pointer position
void writeChars() {
    for (int i=0; i<8*DISPLAY_COUNT; i++) {
      sda.write(text[pointer+i], i);
    }
}

// interrupt service routine

ISR(TIMER1_OVF_vect) {
  switch(state) {
    case 1:   // initial delay 
      state = 2;
      break;
    case 2:   // scrolling text
      if (pointer==0) startTimer(SCROLL_SPEED); 
      pointer++;
      writeChars();
      // end of text ?
      if (pointer >= strlen(text)-8*DISPLAY_COUNT) {
        if (repeat==0) {
          state = 3;
        } else {
          if (repeat>1) {
            startTimer(REPEAT_DELAY);
            state = 3;
          } else {
            // repeat abgelaufen, stop
            state = 5;
          }
          repeat--;
        }
      } 
      break;
    case 3: // repeat delay
      startTimer(REPEAT_DELAY);
      state = 4;
      break;
    case 4: // start over
      pointer = 0;
      writeChars();
      state = 2;      
      break;
    case 5: // final delay
      state = 6;
      break;
    case 6: // finish
      TIMSK1 &= ~_BV(TOIE1);                                       // clears the timer overflow interrupt enable bit 
      TCCR1B &= ~(_BV(CS10) | _BV(CS11) | _BV(CS12));              // clears all clock selects bits
      sda.clear();
      break;
  }
}


void startTimer(long ms) {
  if (ms > 0) setPeriod(ms);
  TIMSK1 = _BV(TOIE1);                                             // sets the timer overflow interrupt enable bit
  sei();                                                           // ensures that interrupts are globally enabled
}

#define TMRRES 65536                                               // timer resolution
void setPeriod(long ms) {
  uint8_t bits;
  long cycles = (F_CPU * ms) / 2000;                               // the counter runs backwards after TOP, interrupt is at BOTTOM so divide microseconds by 2
  if (cycles < TMRRES)              bits = _BV(CS10);              // no prescale, full xtal
  else if ((cycles >>= 3) < TMRRES) bits = _BV(CS11);              // prescale by /8
  else if ((cycles >>= 3) < TMRRES) bits = _BV(CS11) | _BV(CS10);  // prescale by /64
  else if ((cycles >>= 2) < TMRRES) bits = _BV(CS12);              // prescale by /256
  else if ((cycles >>= 2) < TMRRES) bits = _BV(CS12) | _BV(CS10);  // prescale by /1024
  else cycles = TMRRES - 1, bits = _BV(CS12) | _BV(CS10);          // request was out of bounds, set as maximum
  ICR1 = cycles;                                                   // ICR1 is TOP in p & f correct pwm mode
  TCCR1B &= ~(_BV(CS10) | _BV(CS11) | _BV(CS12));
  TCCR1B |= bits;                                                  // reset clock select register
}
