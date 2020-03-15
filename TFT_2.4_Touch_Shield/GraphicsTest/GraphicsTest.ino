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

  // read diagnostics (optional but can help debug problems)
  uint8_t x = tft.readcommand8(ILI9341_RDMODE);
  Serial.print("Display Power Mode: 0x");
  Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDMADCTL);
  Serial.print("MADCTL Mode: 0x");
  Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDPIXFMT);
  Serial.print("Pixel Format: 0x");
  Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDIMGFMT);
  Serial.print("Image Format: 0x");
  Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDSELFDIAG);
  Serial.print("Self Diagnostic: 0x");
  Serial.println(x, HEX);

  Serial.println(F("Benchmark                Time (microseconds)"));
  delay(10);
  Serial.print(F("Screen fill              "));
  //Serial.println(testFillScreen());


  ts.begin();
  ts.setRotation(1);

  pinMode(D4, OUTPUT);
  delay(500);


  
  Serial.println(F("Done!"));
}

void loop(void)
{
 digitalWrite(D4,0);
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
      
     digitalWrite(D4,0);
     
   }

  delay(500);
  digitalWrite(D4,1);
  
}

unsigned long printScreen()
{
  unsigned long start = micros();
  
  return micros() - start;
}
