#include "Button.h"

#include "ButtonDriver.h"

Button::Button(ButtonDriver *btnDriver, int pin) {
  this->driver = btnDriver;
  for(int i = 0; i < MAX_OBSERVERS; ++i) {
    observers[i] = nullptr;
  }

  // use the pin in driver
}

void Button::attach(Observer *observer) {
  if(this->observerCount < MAX_OBSERVERS) {
    observers[this->observerCount++] = observer;
  } else {
    // Handle the case where the array is full. Perhaps ignore or log an error.
  }
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

bool Button::getButtonState(void) { return this->state; }
