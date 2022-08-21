/*
  FONT.H - for use with SDA5708 Library
  Created by Andreas Rohmann, released into public domain
  
  TODO
  
  - Mathematic Symbols
  - Electronic Symbols
*/

#ifndef __SDA5708_FONT__
#define __SDA5708_FONT__

#if (ARDUINO>=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define SDA5708_FONT_START  0x20

#ifdef SDA5708_EXCLUDE_SPECIAL
  #define _special 0
#else
  #define _special 0x10
#endif

#ifdef SDA5708_INCLUDE_ARROWS
  #define _arrows 0x10
#else
  #define _arrows 0
#endif

#ifdef SDA5708_INCLUDE_HBLOCKS
  #define _hblocks 0x10
#else
  #define _hblocks 0
#endif

#ifdef SDA5708_INCLUDE_VBLOCKS
  #define _vblocks 0x10
#else
  #define _vblocks 0
#endif

#ifdef SDA5708_INCLUDE_GRAPHICS
  #define _graphics 0x10
#else
  #define _graphics 0
#endif

#define SDA5708_FONT_END    (0x7F + _special + _arrows + _hblocks + _vblocks + _graphics)
 
#define SDA5708_FONT_LENGTH (SDA5708_FONT_END - SDA5708_FONT_START + 1)
#define SDA5708_FONT_BYTES  (SDA5708_FONT_LENGTH * 7)


const unsigned char font[SDA5708_FONT_BYTES] PROGMEM = {

   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      // 20 SPACE
   0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x04,      // 21 !
   0x0A, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00,      // 22 „
   0x0A, 0x0A, 0x1F, 0x0A, 0x1F, 0x0A, 0x0A,      // 23 #
   0x04, 0x0F, 0x14, 0x0E, 0x05, 0x1E, 0x04,      // 24 $
   0x18, 0x19, 0x02, 0x04, 0x08, 0x13, 0x03,      // 25 %
   0x0C, 0x12, 0x14, 0x08, 0x15, 0x12, 0x0D,      // 26 &
   0x0C, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00,      // 27 '
   0x02, 0x04, 0x08, 0x08, 0x08, 0x04, 0x02,      // 28 (
   0x08, 0x04, 0x02, 0x02, 0x02, 0x04, 0x08,      // 29 )
   0x00, 0x04, 0x15, 0x0E, 0x15, 0x04, 0x00,      // 2A *
   0x00, 0x04, 0x04, 0x1F, 0x04, 0x04, 0x00,      // 2B +
   0x00, 0x00, 0x00, 0x00, 0x0C, 0x04, 0x08,      // 2C ,
   0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00,      // 2D -
   0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C,      // 2E .
   0x01, 0x01, 0x02, 0x04, 0x08, 0x10, 0x10,      // 2F /

   0x0E, 0x11, 0x11, 0x15, 0x11, 0x11, 0x0E,      // 30 0
   0x02, 0x06, 0x0A, 0x02, 0x02, 0x02, 0x07,      // 31 1
   0x0E, 0x11, 0x01, 0x06, 0x08, 0x11, 0x1F,      // 32 2
   0x0E, 0x11, 0x01, 0x06, 0x01, 0x11, 0x0E,      // 33 3
   0x10, 0x10, 0x12, 0x1F, 0x02, 0x02, 0x02,      // 34 4
   0x1F, 0x10, 0x1E, 0x01, 0x01, 0x11, 0x0E,      // 35 5
   0x06, 0x08, 0x10, 0x1E, 0x11, 0x11, 0x0E,      // 36 6
   0x1F, 0x11, 0x02, 0x04, 0x08, 0x08, 0x08,      // 37 7
   0x0E, 0x11, 0x11, 0x0E, 0x11, 0x11, 0x0E,      // 38 8
   0x0E, 0x11, 0x11, 0x0F, 0x01, 0x11, 0x0E,      // 39 9
   0x00, 0x0C, 0x0C, 0x00, 0x0C, 0x0C, 0x00,      // 3A :
   0x00, 0x0C, 0x0C, 0x00, 0x0C, 0x04, 0x08,      // 3B ;
   0x02, 0x04, 0x08, 0x10, 0x08, 0x04, 0x02,      // 3C <
   0x00, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x00,      // 3D =
   0x08, 0x04, 0x02, 0x01, 0x02, 0x04, 0x08,      // 3E >
   0x0E, 0x11, 0x01, 0x02, 0x04, 0x00, 0x04,      // 3F ?

   0x0E, 0x11, 0x01, 0x0D, 0x15, 0x15, 0x0E,      // 40 @
   0x0E, 0x11, 0x11, 0x11, 0x1F, 0x11, 0x11,      // 41 A
   0x1E, 0x11, 0x11, 0x1E, 0x11, 0x11, 0x1E,      // 42 B
   0x0E, 0x11, 0x10, 0x10, 0x10, 0x11, 0x0E,      // 43 C
   0x1C, 0x12, 0x11, 0x11, 0x11, 0x12, 0x1C,      // 44 D
   0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x1F,      // 45 E
   0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x10,      // 46 F
   0x0E, 0x11, 0x10, 0x17, 0x11, 0x11, 0x0F,      // 47 G
   0x11, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11,      // 48 H
   0x0E, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0E,      // 49 I
   0x07, 0x01, 0x01, 0x01, 0x01, 0x09, 0x06,      // 4A J
   0x11, 0x12, 0x14, 0x18, 0x14, 0x12, 0x11,      // 4B K
   0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1F,      // 4C L
   0x11, 0x1B, 0x15, 0x15, 0x11, 0x11, 0x11,      // 4D M
   0x11, 0x11, 0x19, 0x15, 0x13, 0x11, 0x11,      // 4E N
   0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E,      // 4F O

   0x1E, 0x11, 0x11, 0x1E, 0x10, 0x10, 0x10,      // 50 P
   0x0E, 0x11, 0x11, 0x11, 0x15, 0x12, 0x0D,      // 51 Q
   0x1E, 0x11, 0x11, 0x1E, 0x14, 0x12, 0x11,      // 52 R
   0x0F, 0x10, 0x10, 0x0E, 0x01, 0x01, 0x1E,      // 53 S
   0x1F, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,      // 54 T
   0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E,      // 55 U
   0x11, 0x11, 0x11, 0x11, 0x11, 0x0A, 0x04,      // 56 V
   0x11, 0x11, 0x11, 0x15, 0x15, 0x15, 0x0A,      // 57 W	
   0x11, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x11,      // 58 X
   0x11, 0x11, 0x11, 0x0A, 0x04, 0x04, 0x04,      // 59 Y
   0x1F, 0x01, 0x02, 0x04, 0x08, 0x10, 0x1F,      // 5A Z
   0x0E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0E,      // 5B [
   0x10, 0x10, 0x08, 0x04, 0x02, 0x01, 0x01,      // 5C backslash
   0x0E, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0E,      // 5D ]
   0x04, 0x0A, 0x11, 0x00, 0x00, 0x00, 0x00,      // 5E ^
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F,      // 5F _

   0x08, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00,      // 60 `
   0x00, 0x00, 0x0E, 0x01, 0x0F, 0x11, 0x0F,      // 61 a
   0x10, 0x10, 0x16, 0x19, 0x11, 0x11, 0x1E,      // 62 b
   0x00, 0x00, 0x0E, 0x11, 0x10, 0x11, 0x0E,      // 63 c
   0x01, 0x01, 0x0D, 0x13, 0x11, 0x11, 0x0F,      // 64 d
   0x00, 0x00, 0x0E, 0x11, 0x1F, 0x10, 0x0E,      // 65 e
   0x06, 0x09, 0x08, 0x1C, 0x08, 0x08, 0x08,      // 66 f
   0x00, 0x00, 0x0F, 0x11, 0x0F, 0x01, 0x0E,      // 67 g
   0x10, 0x10, 0x16, 0x19, 0x11, 0x11, 0x11,      // 68 h	
   0x04, 0x00, 0x0C, 0x04, 0x04, 0x04, 0x0E,      // 69 i
   0x02, 0x00, 0x06, 0x02, 0x02, 0x12, 0x0C,      // 6A j
   0x10, 0x10, 0x12, 0x14, 0x18, 0x14, 0x12,      // 6B k
   0x0C, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0E,      // 6C l
   0x00, 0x00, 0x1A, 0x15, 0x15, 0x11, 0x11,      // 6D m
   0x00, 0x00, 0x16, 0x19, 0x11, 0x11, 0x11,      // 6E n
   0x00, 0x00, 0x0E, 0x11, 0x11, 0x11, 0x0E,      // 6F o

   0x00, 0x00, 0x1E, 0x11, 0x1E, 0x10, 0x10,      // 70 p
   0x00, 0x00, 0x0D, 0x13, 0x0F, 0x01, 0x01,      // 71 q
   0x00, 0x00, 0x16, 0x19, 0x10, 0x10, 0x10,      // 72 r
   0x00, 0x00, 0x0E, 0x10, 0x0E, 0x01, 0x1E,      // 73 s
   0x08, 0x08, 0x1C, 0x08, 0x08, 0x09, 0x06,      // 74 t
   0x00, 0x00, 0x11, 0x11, 0x11, 0x13, 0x0D,      // 75 u
   0x00, 0x00, 0x11, 0x11, 0x11, 0x0A, 0x04,      // 76 v
   0x00, 0x00, 0x11, 0x11, 0x15, 0x15, 0x0A,      // 77 w
   0x00, 0x00, 0x11, 0x0A, 0x04, 0x0A, 0x11,      // 78 x
   0x00, 0x00, 0x11, 0x11, 0x0F, 0x01, 0x0E,      // 79 y
   0x00, 0x00, 0x1F, 0x02, 0x04, 0x08, 0x1F,      // 7A z
   0x02, 0x04, 0x04, 0x08, 0x04, 0x04, 0x02,      // 7B {
   0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,      // 7C |
   0x08, 0x04, 0x04, 0x02, 0x04, 0x04, 0x08,      // 7D }
   0x0D, 0x16, 0x00, 0x00, 0x00, 0x00, 0x00,      // 7E ~
   0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,      // 7F block

#ifndef SDA5708_EXCLUDE_SPECIAL
   0x11, 0x0E, 0x11, 0x11, 0x1F, 0x11, 0x11,      // A umlaut
   0x11, 0x0E, 0x11, 0x11, 0x11, 0x11, 0x0E,      // O umlaut
   0x11, 0x00, 0x11, 0x11, 0x11, 0x11, 0x0E,      // U umlaut
   0x11, 0x00, 0x0E, 0x01, 0x0F, 0x11, 0x0F,      // a umlaut
   0x11, 0x00, 0x0E, 0x11, 0x11, 0x11, 0x0E,      // o umlaut
   0x11, 0x00, 0x11, 0x11, 0x11, 0x13, 0x0D,      // u umlaut
   0x0C, 0x12, 0x14, 0x12, 0x11, 0x16, 0x10,      // ß
   0x07, 0x08, 0x1E, 0x08, 0x1E, 0x08, 0x07,      // Euro
   0x02, 0x05, 0x02, 0x04, 0x07, 0x00, 0x00,      // power 2
   0x06, 0x01, 0x06, 0x01, 0x06, 0x00, 0x00,      // power 3
   0x02, 0x05, 0x02, 0x00, 0x00, 0x00, 0x00,      // degree	
   0x00, 0x00, 0x12, 0x12, 0x12, 0x1D, 0x10,      // micro
   0x00, 0x0E, 0x11, 0x11, 0x11, 0x0A, 0x1B,      // ohms
   0x00, 0x04, 0x0E, 0x04, 0x00, 0x0E, 0x00,      // plusminus
   0x00, 0x00, 0x0A, 0x04, 0x0A, 0x00, 0x00,      // times
   0x00, 0x04, 0x00, 0x0E, 0x00, 0x04, 0x00,      // divide
#endif

#ifdef SDA5708_INCLUDE_ARROWS
   0x00, 0x04, 0x0C, 0x1F, 0x0C, 0x04, 0x00,      // arrow left
   0x00, 0x04, 0x06, 0x1F, 0x06, 0x04, 0x00,      // arrow right
   0x00, 0x04, 0x0E, 0x1F, 0x04, 0x04, 0x00,      // arrow up
   0x00, 0x04, 0x04, 0x1F, 0x0E, 0x04, 0x00,      // arrow down 
   0x00, 0x1E, 0x1C, 0x1C, 0x12, 0x01, 0x00,      // arrow left & up
   0x00, 0x0F, 0x07, 0x07, 0x09, 0x10, 0x00,      // arrow right & up
   0x00, 0x01, 0x12, 0x1C, 0x1C, 0x1E, 0x00,      // arrow left & down
   0x00, 0x10, 0x09, 0x07, 0x07, 0x0F, 0x00,      // arrow right & down
   0x00, 0x04, 0x08, 0x1F, 0x08, 0x04, 0x00,      // light arrow left
   0x00, 0x04, 0x02, 0x1F, 0x02, 0x04, 0x00,      // light arrow right
   0x00, 0x04, 0x0E, 0x15, 0x04, 0x04, 0x00,      // light arrow up
   0x00, 0x04, 0x04, 0x15, 0x0E, 0x04, 0x00,      // light arrow down 
   0x00, 0x1E, 0x18, 0x14, 0x12, 0x01, 0x00,      // light arrow left & up
   0x00, 0x0F, 0x03, 0x05, 0x09, 0x10, 0x00,      // light arrow right & up
   0x00, 0x01, 0x12, 0x14, 0x18, 0x1E, 0x00,      // light arrow left & down
   0x00, 0x10, 0x09, 0x05, 0x03, 0x0F, 0x00,      // light arrow right & down
#endif

#ifdef SDA5708_INCLUDE_HBLOCKS
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      // horizontal stripes - empty
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F,      // row 1
   0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F,      // row 1+2
   0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F,      // row 1-3
   0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x1F,      // row 1-4
   0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,      // row 1-5
   0x00, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,      // row 1-6
   0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,      // row 1-7
   0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,      // row 1-7
   0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00,      // row 2-7
   0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00, 0x00,      // row 3-7
   0x1F, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00,      // row 4-7
   0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00,      // row 5-7
   0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00,      // row 6+7
   0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      // row 7
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      // empty
#endif

#ifdef SDA5708_INCLUDE_VBLOCKS
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      // vertical stripes - empty
   0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,      // column 1
   0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,      // column 12
   0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C,      // column 123
   0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E,      // column 1234
   0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,      // column 12345
   0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,      // column  2345
   0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,      // column   345
   0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,      // column    45
   0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,      // column     5
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      // empty
   0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,      // column 1   5
   0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B,      // column 12 45
   0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,      // column 12345 
   0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E,      // column  234
   0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,      // column   3
#endif

#ifdef SDA5708_INCLUDE_GRAPHICS
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      // horizontal stripes - empty
   0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F,      // rows 1     7
   0x1F, 0x1F, 0x00, 0x00, 0x00, 0x1F, 0x1F,      // rows 12   67
   0x1F, 0x1F, 0x1F, 0x00, 0x1F, 0x1F, 0x1F,      // rows 123 567
   0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,      // rows 1234567
   0x00, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00,      // rows  23456
   0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x00, 0x00,      // rows   345
   0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00,      // rows    4
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      // empty
   0x00, 0x00, 0x04, 0x04, 0x04, 0x00, 0x00,      // special 1
   0x00, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x00,      // special 2
   0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,      // special 3
   0x1F, 0x1F, 0x1B, 0x1B, 0x1B, 0x1F, 0x1F,      // special 4
   0x1F, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1F,      // special 5 
   0x15, 0x0A, 0x15, 0x0A, 0x15, 0x0A, 0x15,      // checkerboard1
   0x0A, 0x15, 0x0A, 0x15, 0x0A, 0x15, 0x0A,      // checkerboard2
#endif

};

#endif // include
