#include "MidiModule.h"

MIDI_CREATE_DEFAULT_INSTANCE();

void MidiModule::update(int message) {
  // message is a button num
  // todo get a midi command from preset object based on the msg/num
  MIDI.sendNoteOn(42, message, 1);
}