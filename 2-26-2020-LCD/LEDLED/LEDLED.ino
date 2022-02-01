#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ThreeWire.h>
#include <RtcDS1302.h> 


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1



ThreeWire myWire(8,10,9); // IO, SCLK, CE 
RtcDS1302<ThreeWire> Rtc(myWire);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



void showDateTime(const RtcDateTime& dt){ 
 display.print(dt.Year(), DEC); 
 display.print('/'); 
 display.print(dt.Month(), DEC); 
 display.print('/'); 
 display.print(dt.Day(), DEC); 
 display.print(' '); 
 display.print(dt.Hour(), DEC); 
 display.print(':'); 
 display.print(dt.Minute(), DEC); 
 display.print(':'); 
 display.print(dt.Second(), DEC); 
 display.println();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Rtc.Begin();  
  RtcDateTime setting_time(2020,2,2,23,31,10); 
  Rtc.SetDateTime(setting_time); 

  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,3);
}

void loop() {
  RtcDateTime now = Rtc.GetDateTime();

  Serial.println(now);

  display.clearDisplay();
  display.setCursor(0,3);
  showDateTime(now);
  display.display();
  delay(1000);
}
