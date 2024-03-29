#ifndef BUTTON_H
#define BUTTON_H

#include "ButtonState.h"

#include "ConfigDuration.h"

class Button {
  private:
    ButtonState lastState;
    int pin;
    int longPushDuration;
    int pushCounter;
    bool hasChanged;

    ButtonState returnState(ButtonState state);
    void resetCounter();

  public:
    Button() {}
    Button(int pin, int longPushDuration);
    Button(int pin, ConfigDuration* durationsConfig);
    ButtonState getState();
    bool hasStateChanged();
};

#endif