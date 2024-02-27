#include <Adafruit_MCP23X17.h>
#include <Arduino.h>

#include "Button.h"
#include "ButtonDriverDirect.h"
#include "ButtonDriverMCP.h"
#include "LGFX.h"
#include "MidiModule.h"
#include "defines.h"

// init vars
Adafruit_MCP23X17 mcp;
LGFX display1 = LGFX(19);  // 19 - current csPin
MidiModule midi_m;

// buttons subjects init
ButtonDriverMCP btnDrvMcp;
Button btn1 = Button(&btnDrvMcp, 0);

void setup() {
  Serial1.begin(115200);
  Serial2.begin(31250);  // midi port

  pinMode(BTN_INTERRUPT, INPUT_PULLUP);

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

  // attach midi observer
  btn1.attach(&midi_m);
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
  if(btn1.getButtonState()) {
    btn1.notifyObservers();
  }
}
