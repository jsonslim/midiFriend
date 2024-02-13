#include <Wire.h>
#include "ButtonDriver.h"

class ButtonDriverMCP : public ButtonDriver {
 public:
  ButtonDriverMCP() {}

  bool isPressed() override {
    if(!mcp.digitalRead(0)) {
      Serial.println("Button Pressed!");
    }
  }
};