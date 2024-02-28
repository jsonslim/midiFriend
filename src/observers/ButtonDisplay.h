#ifndef BUTTONDISPLAY
#define BUTTONDISPLAY

#include "Observer.h"

class ButtonDisplay : public Observer {
 public:
  void update(int message);
};

#endif