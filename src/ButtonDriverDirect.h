#include <Wire.h>

#include "ButtonDriver.h"

class ButtonDriverDirect : public ButtonDriver {
 public:
  ButtonDriverDirect() {}

  bool isPressed() override { return true; }
};