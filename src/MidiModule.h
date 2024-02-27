#ifndef MIDIMODULE_H
#define MIDIMODULE_H

#include <MIDI.h>

#include "Observer.h"


class MidiModule : public Observer {
 public:
  void update(int message);
};

#endif