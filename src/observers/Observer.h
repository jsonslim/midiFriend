#ifndef OBSERVER_H
#define OBSERVER_H

class Observer
{
public:
    virtual void update(int message) = 0;
};

#endif // OBSERVER_H