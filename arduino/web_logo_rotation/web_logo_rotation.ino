#include "U8glib.h"
#include "logos.h"

U8GLIB_SH1106_128X64 u8g(13, 11, 10, 9); // SCK = 13, MOSI = 11, CS = 10, A0 = 9

const int pageCount = 2;
int page;

void pageRuby() {
  u8g.drawBitmapP( 23, 0, 11, 64, ruby_au_bitmap); // 81x64 so 23 X offset and 11 bytes wide
}
void pageRails() {
  u8g.drawBitmapP( 0, 8, 16, 48, rails_bitmap); // 128x48 so 8 Y offset full width of 16 bytes wide
}
void   pageRoro() {
  u8g.drawBitmapP( 23, 0, 11, 64, roro_bitmap); // 82x64 so 23 X offset and 11 bytes wide
}
void  pageReact() {
  u8g.drawBitmapP( 27, 0, 10, 64, react_bitmap); // 74x64 so 27 X offset and 10 bytes wide
}
void  pageFailureDriven() {
  u8g.drawBitmapP( 34, 0, 8, 64, failure_driven_bitmap); // 60x64 so 34 X offset and 8 bytes wide
}
void  pageArduino () {
  u8g.drawBitmapP( 17, 0, 12, 64, arduino_bitmap); // 94x64 so 17 X offset and 12 bytes wide
}
void  pageFresho () {
  u8g.drawBitmapP( 0, 0, 16, 64, fresho_bitmap); // 128x64 so 0 X offset full width of 16 bytes wide
}
void  pageCloudScale() {
  u8g.drawBitmapP( 0, 0, 16, 64, cloud_scale_bitmap); // 128x64 so 0 X offset full width of 16 bytes wide
}

void (*pages[pageCount])() = {
//  pageRuby,
//  pageRails,
//  pageRoro,
//  pageReact,
//  pageFailureDriven,
//  pageArduino,
  pageFresho,
  pageCloudScale
};

void setup() {
  // flip screen, if required
  // u8g.setRot180();
}

void loop() {
  // picture loop
  u8g.firstPage();
  do {
    (*pages[page])();
  } while (u8g.nextPage());

  page++;
  if (page == pageCount) {
    page = 0;
  }
  // rebuild the picture after some delay
  delay(800);
}
