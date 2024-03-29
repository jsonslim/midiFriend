#ifndef BUTTON_H
#define BUTTON_H

#include "./observers/Observer.h"
#include "ButtonDriver.h"

class Button
{
    int pin;
    bool state = false;
    static const int MAX_OBSERVERS = 10;
    Observer *observers[MAX_OBSERVERS];
    int observerCount = 0;
    ButtonDriver* driver;

public:
    Button(ButtonDriver* btnDriver, int pin);
    void init(int mode);
    void attach(Observer *observer);
    void detach(Observer *observer);
    void notifyObservers();
    bool getState(void);
};

#endif