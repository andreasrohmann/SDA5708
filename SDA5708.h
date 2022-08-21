/*
  SDA5708.H – Library for using SDA5708 Display(s) from old Nokia DBOX1 Receivers
  Created by Andreas Rohmann, released into public domain.
*/

#ifndef __SDA5708__
#define __SDA5708__

#if (ARDUINO>=100)
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#include "font.h"

// constants
#define SDA5708_BRIGHTNESS_MAX  0
#define SDA5708_BRIGHTNESS_MIN  6
#define SDA5708_BRIGHTNESS_OFF  7

class SDA5708 : public Print {
  
	public:
	
	// constructors
	SDA5708(uint8_t pin_reset, uint8_t pin_data, uint8_t pin_clock, uint8_t pin_load);
    SDA5708(uint8_t no_of_displays, uint8_t pin_reset, uint8_t pin_data, uint8_t pin_clock, uint8_t pin_load);

	// methods
	void reset();
	void clear();
	void setBrightness(uint8_t bright);
	void setCursor(uint8_t pos);

	size_t write(uint8_t chr, uint8_t pos);
    size_t write(uint8_t chr);

	size_t print(const __FlashStringHelper *);
	size_t print(const String &);
	size_t print(const char[]);
	size_t print(char);
	size_t print(unsigned char, int = DEC);
	size_t print(int, int = DEC);
	size_t print(unsigned int, int = DEC);
	size_t print(long, int = DEC);
	size_t print(unsigned long, int = DEC);
	size_t print(double, int = 2);
	size_t print(const Printable&);
	
	size_t println(const __FlashStringHelper *);
	size_t println(const String &s);
	size_t println(const char[]);
	size_t println(char);
	size_t println(unsigned char, int = DEC);
	size_t println(int, int = DEC);
	size_t println(unsigned int, int = DEC);
	size_t println(long, int = DEC);
	size_t println(unsigned long, int = DEC);
	size_t println(double, int = 2);
	size_t println(const Printable&);
	size_t println(void);

	// optional methods
	#ifndef SDA5708_NO_UDC
  		void createChar(uint8_t no, uint8_t r0, uint8_t r1, uint8_t r2, uint8_t r3, uint8_t r4, uint8_t r5, uint8_t r6);
	#endif

  private:

    // internal variables
    uint8_t _no_of_displays = 1;  // displays to control, default for 1 display
    uint8_t _no_of_digits = 8;    // available digits, default for 1 display
    uint8_t _pin_load;            // load pin of first display
    uint8_t _pin_data;            // common data pin for data transfer
    uint8_t _pin_clock;           // common clock pin for data transfer
    uint8_t _pin_reset;           // common display reset signal
    uint8_t _position;            // internal write position

    // internal methods
    void send_byte(uint8_t display_no, uint8_t b);
    void set_ports();
    
	// optional internal variables
	#ifndef SDA5708_NO_UDC 
  		char udc[16*7];
	#endif

};

// --------------------------------------------------------------------------------
// All methods need to be integrated into the header file to be compiled with
// the Arduino sketch. Otherwise defines wouldn't be recognized during compile time.
// Normally these methods would be in a separate .CPP file. 
// One of the disadvantages by using the Arduino IDE :-(
// --------------------------------------------------------------------------------

/*
 * Constructor of this class for using a single SDA5708 display.
 */
SDA5708::SDA5708(uint8_t pin_reset, uint8_t pin_data, uint8_t pin_clock, uint8_t pin_load) 
{
    _pin_reset = pin_reset;
    _pin_data = pin_data;
    _pin_clock = pin_clock;
    _pin_load = pin_load;
    set_ports();
    reset();
}

/*
 * Constructor of this class for using multiple SDA5708 displays.
 */
SDA5708::SDA5708(uint8_t no_of_displays, uint8_t pin_reset, uint8_t pin_data, uint8_t pin_clock, uint8_t pin_load) 
{
    _no_of_displays = no_of_displays;
    _no_of_digits = 8*no_of_displays;
    _pin_reset = pin_reset;
    _pin_data = pin_data;
    _pin_clock = pin_clock;
    _pin_load = pin_load;
    set_ports();
    reset();
}


/*
 * Internal method to initialize all used output pins.
 */
void SDA5708::set_ports() 
{
    pinMode(_pin_reset, OUTPUT);
    pinMode(_pin_data, OUTPUT);
    pinMode(_pin_clock, OUTPUT);
    for (uint8_t x = 0; x < _no_of_displays; x++) {
        pinMode(_pin_load + x, OUTPUT);
    }
}


/*
 * This method performs a hardware reset of all connected displays.
 * The internal write position is set to 0.
 */
void SDA5708::reset() 
{
    for (uint8_t x = 0; x < _no_of_displays; x++) {
        digitalWrite(_pin_load + x, HIGH);
        digitalWrite(_pin_reset, LOW);
        digitalWrite(_pin_reset, HIGH);
    }
    _position = 0;
}


/*
 *  Internal method to send one byte to a particular display.
 */
void SDA5708::send_byte(uint8_t display_no, uint8_t data) 
{
    // enable display
    digitalWrite(_pin_load + display_no, LOW);
    // send 8 bits
    for (uint8_t x = 0; x <= 7; x++) {
        // set data pin 
        digitalWrite(_pin_data, ((data >> x) & 0x01));
        // toggle SDCLK 
        digitalWrite(_pin_clock, HIGH);
        digitalWrite(_pin_clock, LOW);
    }
    // disable display
    digitalWrite(_pin_load + display_no, HIGH);
}


/*
 * This method sets the cursor (nect writing position)
 * to the given value. SDA displays are always treated 
 * as single line displays.
 */
void SDA5708::setCursor(uint8_t pos)
{
    _position = pos;
}

/*
 * This method clears all registered displays 
 * and sets the internal write position to 0. 
 */
void SDA5708::clear() 
{
    for (uint8_t x = 0; x < _no_of_displays; x++) {
        send_byte(x, B11000000);
        send_byte(x, B11100000);
    }
    _position = 0;
}


/*
 * This method sets the brightness for all characters 
 * of all registered displays. Values are from 0 to 7: 
 * 0=maximum brighnexx, 6=minimum brightness, 7=off
 */
void SDA5708::setBrightness(uint8_t bright) 
{
    for (uint8_t x = 0; x < _no_of_displays; x++) {
        send_byte(x, B11100000 | (bright & B00000111));
    }
}




/*
 * This method writes a character at a given position.
 * If the position is out of range nothing happens.
 * After writing the character the internal write 
 * position points to the next digit. 
 */
size_t SDA5708::write(uint8_t chr, uint8_t pos) {
    // safety, write position in visible range
    if (pos >= _no_of_digits) return;
    // determine display to write to
    uint8_t disp = pos>>3;
    // set adress register (position)
    send_byte(disp, B10100000 | (pos & B00000111));
    // limit character range
    if ((chr >= SDA5708_FONT_START) && (chr <= SDA5708_FONT_END)) {
        // send character from font
        for (uint8_t i=0; i<7; i++) {
            send_byte(disp, pgm_read_byte(&font[(chr-SDA5708_FONT_START)*7+i]));
        }
    }
    // optional user defined characters
    #ifndef SDA5708_NO_UDC 
    else if ((chr >= 0xF0) && (chr <= 0xFF)) {
        // send character from udc
        for (uint8_t i=0; i<7; i++) {
            send_byte(disp, udc[(chr-0xF0)*7+i]);
        }
    }
    #endif // #ifndef SDA5708_NO_UDC
    _position++;
    return 1;
}


/*
 * This method writes a character at the internal write position.
 * After writing the character the internal write 
 * position points to the next digit.
 */
size_t SDA5708::write(uint8_t chr) {
    return write(chr, _position);
}



// suppport for basic printing 

size_t SDA5708::print(const __FlashStringHelper *fsh) 
{
    Print::print(fsh);
}

size_t SDA5708::print(const String& string)
{
    Print::print(string);
}

size_t SDA5708::print(const char string[])
{
    Print::print(string);
}

size_t SDA5708::print(char c)
{
    Print::print(c);
}

size_t SDA5708::print(unsigned char c, int base)
{
    Print::print(c, base);
}

size_t SDA5708::print(int i, int base)
{
    Print::print(i, base);
}

size_t SDA5708::print(unsigned int ui, int base)
{
    Print::print(ui, base);
}

size_t SDA5708::print(long l, int base)
{
    Print::print(l, base);
}

size_t SDA5708::print(unsigned long ul, int base)
{
    Print::print(ul, base);
}

size_t SDA5708::print(double num, int digits)
{
    Print::print(num, digits);
}

size_t SDA5708::print(const Printable& printable)
{
    Print::print(printable)	;
}

/*
 * Positioning of cursor happens before printing.
 * println() means that printing starts at position 0.
 */

size_t SDA5708::println(const __FlashStringHelper* fsh)
{
    _position = 0;
    Print::print(fsh);
}

size_t SDA5708::println(const String &s)
{
    _position = 0;
    Print::print(s);
}

size_t SDA5708::println(const char string[])
{
    _position = 0;
    Print::print(string);
}

size_t SDA5708::println(char c)
{
    _position = 0;
    Print::print(c);
}

size_t SDA5708::println(unsigned char b, int base)
{
    _position = 0;
    Print::print(b, base);
}

size_t SDA5708::println(int num, int base)
{
    _position = 0;
    Print::print(num, base);
}

size_t SDA5708::println(unsigned int num, int base)
{
    _position = 0;
    Print::print(num, base);
}

size_t SDA5708::println(long num, int base)
{
    _position = 0;
    Print::print(num, base);
}

size_t SDA5708::println(unsigned long num, int base)
{
    _position = 0;
    Print::print(num, base);
}

size_t SDA5708::println(double num, int digits)
{
    _position = 0;
    Print::print(num, digits);
}

size_t SDA5708::println(const Printable& printable)
{
    _position = 0;
    Print::print(printable);
}

size_t SDA5708::println(void)
{
    _position = 0;
}



#ifndef SDA5708_NO_UDC
/*
 * This method creates a user defined character.
 * User defined charcters must be in the range from 0xF0 to 0xFF
 */
void SDA5708::createChar(uint8_t no, uint8_t r0, uint8_t r1, uint8_t r2, uint8_t r3, uint8_t r4, uint8_t r5, uint8_t r6) {
  if (no>=0xF0 & no<=0xFF) {
    no -= 0xF0;
    udc[7*no+0] = r0;
    udc[7*no+1] = r1;
    udc[7*no+2] = r2;
    udc[7*no+3] = r3;
    udc[7*no+4] = r4;
    udc[7*no+5] = r5;
    udc[7*no+6] = r6;
  }
}
#endif // #ifndef SDA5708_NO_UDC



#endif // #ifndef __SDA5708__
