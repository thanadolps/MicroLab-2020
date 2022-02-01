#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1

#define BTN_1 = 12;
#define BTN_2 = 13;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12, INPUT);
  pinMode(13, INPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  display.clearDisplay();


  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,3);

  display.fillCircle(SCREEN_WIDTH/2, SCREEN_HEIGHT/4, SCREEN_WIDTH/8, 1);
  display.fillCircle(SCREEN_WIDTH/2, 3*SCREEN_HEIGHT/4, SCREEN_WIDTH/8, 1);
  display.display();
}

void loop() {
  
  display.clearDisplay();

  if(!digitalRead(12)) {
    display.fillCircle(SCREEN_WIDTH/2, SCREEN_HEIGHT/4, SCREEN_WIDTH/8, 1);
  }

  if(!digitalRead(13)) {
    display.fillCircle(SCREEN_WIDTH/2, 3*SCREEN_HEIGHT/4, SCREEN_WIDTH/8, 1);
  }
  
  display.display();
  
  delay(100);
}
