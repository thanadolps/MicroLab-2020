#include <SPI.h>
#include "common.h"

SevenSegment l = SevenSegment(9);
SevenSegment r = SevenSegment(8);

void setup()
{
    Serial.begin(9600);
    SPI.begin();
    SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));
}


const int DISPLAY_DELAY = 500;

void loop()
{
    for(int i = 0; i < 100; i++) {
      dec_display(l, r, i);
      delay(DISPLAY_DELAY);
    }
    for(int i = 99; i > 0; i--) {
        dec_display(l, r, i);
        delay(DISPLAY_DELAY);
    }
}
