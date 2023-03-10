// Adafruit_NeoMatrix example for single NeoPixel Shield.
// Scrolls 'Howdy' across the matrix in a portrait (vertical) orientation.

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
#define PSTR  // Make Arduino Due happy
#endif

#define PIN 12

// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_GRBW    Pixels are wired for GRBW bitstream (RGB+W NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)


// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(22, 22, PIN,
                                               NEO_MATRIX_TOP + NEO_MATRIX_RIGHT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
                                               NEO_GRB + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255), matrix.Color(182, 157, 157),
};

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(5);
  matrix.setTextColor(colors[0]);
}

int x = 0;
int y = 0;
int pass = 0;

void printHowdy() {
  matrix.fillScreen(0);
  matrix.setCursor(x, 3);
  matrix.setTextSize(2);
  matrix.print(F("Howdy"));
  // matrix.drawLine(0, 0, matrix.width(), 0, colors[0]);
  if (--x < -60) {
    x = matrix.width();
    if (++pass >= 3) pass = 0;
    matrix.setTextColor(colors[pass]);
  }
  matrix.show();
  delay(100);
}

void printBus() {
  matrix.fill(0);
  matrix.setCursor(x + 24, 5);
  matrix.print(F("5Mini"));
  matrix.setTextSize(2);
  matrix.drawCircle(x + 5, 16, 2, colors[0]);
  matrix.drawCircle(x + 16, 16, 2, colors[0]);
  matrix.drawLine(x + 4, 14, x + 18, 14, 0);
  matrix.drawRect(x + 1, 7, 20, 9, colors[3]);
  matrix.drawRect(x + 1, 7, 4, 6, colors[2]);
  matrix.drawRect(x + 6, 7, 4, 5, colors[2]);
  matrix.drawRect(x + 10, 7, 4, 5, colors[2]);
  matrix.drawRect(x + 14, 7, 4, 5, colors[2]);
  if (--x < -75) {
    x = matrix.width();
  }
  matrix.show();
  delay(100);
}

void loop() {
  printBus();
  // printHowdy();
}