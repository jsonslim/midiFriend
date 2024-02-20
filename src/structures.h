#include <Arduino.h>

#include <vector>

#define MAXACTIONNAME 10  // ?
#define MAXBANKNAME 10

struct action {
  char tag0[MAXACTIONNAME + 1];
  union {
    char tag1[MAXACTIONNAME + 1];
    char name[MAXACTIONNAME + 1];
  };
  byte control;
  byte led;  // 0..LEDS-1 existing leds, if equal to LEDS no led assigned to
             // action, 255 = Use default led defined by control
  uint32_t color0;
  uint32_t color1;
  byte event;
  byte midiMessage;
  byte midiChannel; /* MIDI channel 1-16 */
  byte midiCode;    /* Program Change, Control Code, Note or Pitch Bend value to
                       send */
  byte midiValue1;
  byte midiValue2;
  char oscAddress[51];
  byte slot;  // 0..SLOTS-1 real slots. If equal to SLOTS no slot selected
  action *next;
};

struct bank {
  char pedalName[MAXACTIONNAME + 1];
  byte midiMessage;
  byte midiChannel;
  byte midiCode;
  byte midiValue1;
  byte midiValue2;
};

struct pedal {
  byte mode;           /* 1 = none
                          2 = momentary
                          3 = latch
                          4 = analog
                          5 = jog wheel
                          6 = momentary 2
                          7 = momentary 3
                          8 = latch 2
                          9 = ladder */
  byte pressMode;      /* 1 = single click
                          2 = double click
                          4 = long click
                          3 = single and double click
                          5 = single and long click
                          6 = double and long click
                          7 = single, double and long click */
  byte invertPolarity; /* 0 = disable
                          1 = enable   */
  byte latchEmulation; /* 0 = disable
                          1 = enable   */
  byte analogResponse;
  int expZero;           // [0, ADC_RESOLUTION-1]
  int expMax;            // [0, ADC_RESOLUTION-1]
  float snapMultiplier;  // a value from 0 to 1 that controls the amount of
                         // easing increase this to lessen the amount of easing
                         // (such as 0.1) and make the responsive values more
                         // responsive, but doing so may cause more noise to
                         // seep through when sleep is not enabled.
  float activityThreshold;  // the amount of movement that must take place for
                            // it to register as activity and start moving the
                            // output value
  int pedalValue[2];               // [0, ADC_RESOLUTION-1]
  unsigned long lastUpdate[2];     // last time the value is changed
};