#include "Button.h"

#include <Adafruit_MCP23X17.h>

#include "ButtonDriver.h"

Adafruit_MCP23X17 mcp;

Button::Button(ButtonDriver *btnDriver, int pin) {
  this->driver = btnDriver;
  this->pin = pin;
  for(int i = 0; i < MAX_OBSERVERS; ++i) {
    observers[i] = nullptr;
  }
}

void Button::init(int mode) {
  if(!mcp.begin_I2C()) {
    Serial.println("MCP init error");
  }
  mcp.pinMode(this->pin, mode);
}

void Button::attach(Observer *observer) {
  observers[this->observerCount++] = observer;
}

void Button::detach(Observer *observer) {
  for(int i = 0; i < this->observerCount; ++i) {
    if(observers[i] == observer) {
      observers[i] = nullptr;  // Remove the observer
      // Shift the rest of the elements up to fill the gap
      for(int j = i; j < this->observerCount - 1; ++j) {
        observers[j] = observers[j + 1];
      }

      observers[this->observerCount - 1] = nullptr;  // Avoid dangling pointers
      this->observerCount--;
      break;  // Exit the loop after removing the observer
    }
  }
}

void Button::notifyObservers() {
  for(int i = 0; i < this->observerCount; ++i) {
    if(observers[i] != nullptr) {  // Check if the observer slot is not empty
      observers[i]->update(/* message */ 0);
    }
  }
}

bool Button::getState(void) {
  if(!mcp.digitalRead(0)) {  // todo use mcp driver but before try debounce2mcp
    Serial.println("Button Pressed!");
  }

  return mcp.digitalRead(0);
}
