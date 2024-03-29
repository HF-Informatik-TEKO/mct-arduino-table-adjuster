#ifndef PRESETCONTROLLER_H
#define PRESETCONTROLLER_H

#include "WorkState.h"
#include "Button.h"
#include "PresetStorage.h"

#include "ConfigUsersPresets.h"
#include "ConfigUsersPresetsDefault.h"
#include "ConfigDuration.h"


class PresetController {
    private:
      PresetStorage* storage;
      Button** buttons;
      int pressedButton;
      int numberOfButtons;

      WorkState returnValue(WorkState state, int button);

    public: 
      PresetController(
        ConfigUsersPresets* users, 
        ConfigUsersPresetsDefault* userDefaults, 
        ConfigDuration* durationsConfig
      );
      WorkState getState();
      int getPresetValue();
      void setPresetValue(int value);
};

#endif