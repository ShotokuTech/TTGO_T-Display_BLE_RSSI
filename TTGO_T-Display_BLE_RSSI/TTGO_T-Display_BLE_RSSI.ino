/*
   Based on Neil Kolban example for IDF: https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleScan.cpp
   Ported to Arduino ESP32 by Evandro Copercini
*/

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

#include <TFT_eSPI.h>
#include <SPI.h>
TFT_eSPI tft = TFT_eSPI(135, 240); // Invoke custom library

#include "Button2.h"
#define BUTTON_1            35
Button2 btn1(BUTTON_1);
int btn1Click = true;

int scanTime = 5; //In seconds
BLEScan* pBLEScan;

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
    void onResult(BLEAdvertisedDevice advertisedDevice) {
      int rssi = advertisedDevice.getRSSI();
//      name = advertisedDevice.getName();
//      tft.print("Rssi: ");
      tft.print(rssi);
      tft.print("  ");
//      tft.println(advertisedDevice.getName().toString().c_str());
      tft.println(advertisedDevice.getName().c_str());
    }
};

void button_init()
{
    btn1.setPressedHandler([](Button2 & b) {
        btn1Click = true;      
    });
}

void button_loop()
{
    btn1.loop();
}

void setup() {
  Serial.begin(9600);
  Serial.println("Scanning...");

  tft.init();
  tft.setRotation(3);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.setTextDatum(MC_DATUM);
  tft.setTextSize(2);
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(0, 0);

  button_init();

  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan(); //create new scan
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true); //active scan uses more power, but get results faster
  pBLEScan->setInterval(100);
  pBLEScan->setWindow(99);  // less or equal setInterval value
}

void loop() {
  button_loop();
  if(btn1Click){
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0);
    tft.println("Scanning");
    BLEScanResults foundDevices = pBLEScan->start(scanTime, false);
    tft.setCursor(0, 0);
    tft.println("Scan done!");
    pBLEScan->clearResults();   // delete results fromBLEScan buffer to release memory

    btn1Click = false;
            
  }
}
