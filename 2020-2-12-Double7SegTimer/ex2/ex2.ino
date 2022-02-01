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

void loop() {
    Button BTN_UP = Button(2);
    Button BTN_DOWN = Button(3);
    Button BTN_TOGGLE = Button(4);

    int i = 0;
    int count_speed = 1;

    const int BTN_DELAY = 100;

    while(true) {
        if(BTN_UP.is_newly_press()) {
            count_speed = 1;
            delay(BTN_DELAY);
            continue;
        }
        if(BTN_DOWN.is_newly_press()) {
            count_speed = -1;
            delay(BTN_DELAY);
            continue;
        }
        if(BTN_TOGGLE.is_newly_press()) {
            count_speed = count_speed == 0 ? 1 : 0;
            delay(BTN_DELAY);
            continue;
        }

        i = min(99, max(0, i + count_speed));

        if(i == 0) {
            // TODO: make this a constant
            tone(7, 100, DISPLAY_DELAY);
        }

        dec_display(l, r, i);
        delay(DISPLAY_DELAY);
    }
}
