#include <Arduino.h>

#include "./observers/ButtonDisplay.h"
#include "./observers/MidiModule.h"
#include "Button.h"
#include "ButtonDriverDirect.h"
#include "ButtonDriverMCP.h"
#include "LGFX.h"
#include "defines.h"

// foo prototypes
void IRAM_ATTR onInterrupt();

// init vars
LGFX display1 = LGFX(19);  // 19 - current csPin
ButtonDisplay btn_dsp1;
MidiModule midi_m;

// buttons subjects init
ButtonDriverMCP btnDrvMcp;
Button btn1 = Button(&btnDrvMcp, 0);

void setup() {
  Serial1.begin(115200);
  Serial2.begin(31250);  // midi port

  pinMode(BTN_INTERRUPT, INPUT_PULLUP);
  attachInterrupt(BTN_INTERRUPT, onInterrupt, FALLING);

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
  btn1.attach(&btn_dsp1);
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

  // observer
  if(btn1.getState()) {
    btn1.notifyObservers();
  }
}

void IRAM_ATTR onInterrupt() {
  // check what button have been pressed
  // update global state
}
