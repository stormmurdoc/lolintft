#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <XPT2046_Touchscreen.h>

// Lolin Wemos D1 mini
#define TFT_CS D0  //for D1 mini or TFT I2C Connector Shield (V1.1.0 or later)
#define TFT_DC D8  //for D1 mini or TFT I2C Connector Shield (V1.1.0 or later)
#define TFT_RST -1 //for D1 mini or TFT I2C Connector Shield (V1.1.0 or later)
#define TS_CS D3   //for D1 mini or TFT I2C Connector Shield (V1.1.0 or later)

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
XPT2046_Touchscreen ts(TS_CS);

void setup()
{
  Serial.begin(115200);
  Serial.println("Starting!");
  tft.begin();
  ts.begin();
  ts.setRotation(1);
  splashScreen();
  Serial.println("Init done!");
}

void loop(void)
{
  if (ts.touched())
  {
    TS_Point p = ts.getPoint();

     tft.fillScreen(ILI9341_BLACK);
     tft.setCursor(0, 0);

     tft.print("Pressure = ");
     tft.println(p.z);
     tft.print("X = ");
     tft.println(p.x);
     tft.print("Y = ");
     tft.println(p.y);
     delay(500);
     drawScreen();
  }
}

void drawScreen()
{
   tft.fillScreen(ILI9341_BLACK);
   //yield();
   tft.setCursor(0, 0);
   tft.setTextSize(3);
   tft.setTextColor(ILI9341_WHITE);
   tft.println("Hello World!");
   tft.setTextColor(ILI9341_RED);
   tft.println("Red code");
   tft.setTextSize(1);
   tft.setTextColor(ILI9341_WHITE);
}

void splashScreen()
{
  //unsigned long start = micros();
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0, 130);
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_WHITE);
  tft.println("Starting...Press to start");
  //return micros() - start;
}
