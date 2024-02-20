#include <Adafruit_MCP23X17.h>
#include <Arduino.h>

#include "Button.h"
#include "LGFX.h"

Adafruit_MCP23X17 mcp;
LGFX display1 = LGFX(19); //19 - current csPin

void setup() {
  Serial.begin(115200);
  pinMode(21, INPUT_PULLUP);

  if(!mcp.begin_I2C()) {
    Serial.println("MCP init error");
  }

  mcp.pinMode(0, INPUT_PULLUP);

  display1.init();
  display1.setRotation(display1.getRotation() ^ 1);
  display1.setBrightness(128);
  display1.setColorDepth(24);

  display1.fillScreen(TFT_BLACK);
  display1.drawRect(0, 0, display1.width(), display1.height(), 0x00FF00U);

  display1.setTextColor(TFT_GREEN);

  display1.setCursor(2, 40);
  display1.setFont(&fonts::Font4);
  display1.setTextDatum(textdatum_t::middle_center);
  display1.drawString("DELAY", display1.width() / 2, display1.height() / 2);

  // start observer pattern //
  // buttons subjects init
  // todo add drivers and pins
  // Button btn1 = new Button(,0);
  // Button btn2 = new Button(,0);
  // Button btn3 = new Button(,0);
  // Button btn4 = new Button(,0);
  // Button btn5 = new Button(,0);
  // Button btn6 = new Button(,0);
  // Button btn7 = new Button(,0);
  // Button btn8 = new Button(,0);
  // todo attach observers
}

void loop() {
  Serial.println("loop");

  display1.fillScreen(TFT_GREEN);
  display1.setTextColor(TFT_BLACK);
  display1.drawString("DELAY", display1.width() / 2, display1.height() / 2);
  delay(800);

  display1.fillScreen(TFT_BLACK);
  display1.setTextColor(TFT_GREEN);
  display1.drawString("DELAY", display1.width() / 2, display1.height() / 2);
  delay(800);

  if(!mcp.digitalRead(0)) {
    Serial.println("Button Pressed!");
  }

  // observer
  // if(button1.isPressed()) {
  //   button1.notifyObservers();
  // }
  // if(button2.isPressed()) {
  //   button2.notifyObservers();
  // }
}
