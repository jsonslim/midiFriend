#include <Wire.h>

#include "ButtonDriver.h"

class ButtonDriverMCP : public ButtonDriver {
 public:
  ButtonDriverMCP() {}

  bool isPressed() override { return true; }
};