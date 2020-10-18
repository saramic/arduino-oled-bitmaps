#include "U8glib.h"
U8GLIB_SH1106_128X64 u8g(13, 11, 10, 9); // SCK = 13, MOSI = 11, CS = 10, A0 = 9

const unsigned char fleur_de_lis_bitmap[] PROGMEM = {
  0x0, 0x1, 0x80, 0x0,
  0x0, 0x2, 0x40, 0x0,
  0x0, 0x2, 0x40, 0x0,
  0x0, 0x4, 0x20, 0x0,
  0x0, 0x4, 0x20, 0x0,
  0x0, 0x8, 0x10, 0x0,
  0x0, 0x8, 0x10, 0x0,
  0x0, 0x10, 0x8, 0x0,
  0x1, 0x90, 0x9, 0x80,
  0x6, 0x70, 0xe, 0x60,
  0x8, 0x10, 0x8, 0x10,
  0x8, 0x8, 0x10, 0x10,
  0x8, 0x8, 0x10, 0x10,
  0x8, 0x4, 0x20, 0x10,
  0xc, 0x4, 0x20, 0x30,
  0x4, 0x72, 0x4e, 0x20,
  0x4, 0x5a, 0x5a, 0x20,
  0x4, 0x46, 0x62, 0x20,
  0x2, 0x8f, 0xf1, 0x40,
  0x1, 0x10, 0x8, 0x80,
  0x0, 0x10, 0x8, 0x0,
  0x0, 0x10, 0x8, 0x0,
  0x0, 0x4f, 0xf2, 0x0,
  0x0, 0x65, 0xa6, 0x0,
  0x0, 0x9b, 0xd9, 0x0,
  0x0, 0x82, 0x41, 0x0,
  0x0, 0x86, 0x61, 0x0,
  0x0, 0x8a, 0x51, 0x0,
  0x0, 0x4a, 0x52, 0x0,
  0x0, 0x32, 0x4c, 0x0,
  0x0, 0x1, 0x80, 0x0,
  0x0, 0x1, 0x80, 0x0
};

void setup() {
  // flip screen, if required
  u8g.setRot180();
}

void loop() {
  // picture loop
  u8g.firstPage();
  do {
    // draw the bitmap on the page
    u8g.drawBitmapP( 0, 0, 4, 32, fleur_de_lis_bitmap);
  } while (u8g.nextPage());

  // rebuild the picture after some delay
  delay(1000);
}