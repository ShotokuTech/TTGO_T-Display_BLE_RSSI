#include <TFT_eSPI.h>
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI(135, 240); // Invoke custom library

void setup()
{

    tft.init();
    tft.setRotation(3);
    tft.setTextColor(TFT_GREEN);
    tft.setTextDatum(MC_DATUM);
    tft.setTextSize(2);
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0);
    tft.println("12345678901234567890");
    tft.println("12345678901234567890");  
    tft.println("12345678901234567890");  
    tft.println("12345678901234567890");  
    tft.println("12345678901234567890");  
    tft.println("12345678901234567890");
    tft.println("12345678901234567890");  
    tft.println("12345678901234567890");
}    

void loop()
{
            
//    delay(1000);
//    tft.fillScreen(TFT_BLACK);
//    delay(1000);
    
}
