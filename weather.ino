#include <Adafruit_SSD1306.h>

// Use with an I2C attached OLED display on an ESP microcontroller.

// Paramters are: display width, display height, &Wire, reset pin
Adafruit_SSD1306 display(128, 64, &Wire, -1);
unsigned char thermometer[] = {8,20,212,20,20,220,28,28,220,28,62,127,127,127,62,28};
unsigned char droplet[] = {0,4,8,8,24,24,60,60,126,126,255,255,255,255,126,60};
unsigned char sun[] = {1,0,65,4,32,8,3,128,15,224,15,224,31,240,223,246,31,240,15,224,15,224,3,128,32,8,65,4,1,0,0,0};
unsigned char cloud[] = {3,192,7,224,15,240,127,254,255,255,255,255,255,255,127,254};
unsigned char rain[] = {33,8,66,16,132,32};
unsigned char lightning[] = {3,224,7,192,15,128,3,192,7,0,6,0,8,0};

void setup() {
  Serial.begin(9600);  
  Serial.println();
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // 0x3C is the I2C bus address of the display
    Serial.println("Failed to find a display");
  }
  else {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println("Current Conditions");

    display.drawBitmap(0,12, thermometer, 8, 16, 1);
    display.setTextSize(2);
    display.setCursor(12,14);
    display.print("112");
    display.setTextSize(1);
    display.println("F");

    display.drawBitmap(54,12, droplet, 8, 16, 1);
    display.setTextSize(2);
    display.setCursor(66,14);
    display.print("100");
    display.setTextSize(1);
    display.println("%");

    display.drawBitmap(112,12, sun, 16, 16, 1);

    display.drawBitmap(0,32, sun, 16, 16, 1);
    display.drawBitmap(32,36, cloud, 16, 8, 1);
    display.drawBitmap(64,32, cloud, 16, 8, 1);
    display.drawBitmap(64,42, rain, 16, 3, 1);
    display.drawBitmap(96,32, cloud, 16, 8, 1);
    display.drawBitmap(96,42, lightning, 16, 7, 1);
    display.display();
  }

  ESP.deepSleep(30e6);
}

void loop() {
  delay(1000);
}
