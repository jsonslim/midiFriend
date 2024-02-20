#include <Adafruit_MCP23X17.h>
#include <Arduino.h>

#include "Button.h"
#include "LGFX.h"

Adafruit_MCP23X17 mcp;
LGFX display;

void setup() {
  Serial.begin(115200);
  pinMode(21, INPUT_PULLUP);

  if(!mcp.begin_I2C()) {
    Serial.println("MCP init error");
  }

  mcp.pinMode(0, INPUT_PULLUP);

  display.init();
  display.setRotation(display.getRotation() ^ 1);
  display.setBrightness(128);
  display.setColorDepth(24);

  display.fillScreen(TFT_BLACK);
  display.drawRect(0, 0, display.width(), display.height(), 0x00FF00U);

  display.setTextColor(TFT_GREEN);

  display.setCursor(2, 40);
  display.setFont(&fonts::Font4);
  display.setTextDatum(textdatum_t::middle_center);
  display.drawString("DELAY", display.width() / 2, display.height() / 2);

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

  display.fillScreen(TFT_GREEN);
  display.setTextColor(TFT_BLACK);
  display.drawString("DELAY", display.width() / 2, display.height() / 2);
  delay(800);

  display.fillScreen(TFT_BLACK);
  display.setTextColor(TFT_GREEN);
  display.drawString("DELAY", display.width() / 2, display.height() / 2);
  delay(800);

  if(!mcp.digitalRead(0)) {
    Serial.println("Button Pressed!");
  }

  // observer
  if(button1.isPressed()) {
    button1.notifyObservers();
  }
  if(button2.isPressed()) {
    button2.notifyObservers();
  }
}
