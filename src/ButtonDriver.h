//  The generic interface (abstract class) for button drivers.
//  This interface declares methods that all button drivers must implement,
//  such as checking the button's state.

#ifndef BUTTONDRIVER_H
#define BUTTONDRIVER_H

class ButtonDriver
{
public:
    virtual ~ButtonDriver() {}
    virtual bool isPressed() = 0; // Returns true if the button is pressed
};

#endif
