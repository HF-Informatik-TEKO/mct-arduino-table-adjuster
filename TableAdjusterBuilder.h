#ifndef BUILDER_H
#define BUILDER_H

#include "TableAdjuster.h"

class TableAdjusterBuilder {
  private:
    ConfigUsersPresets* usersPresetConfig = new ConfigUsersPresets();
    ConfigDuration* durationsConfig = new ConfigDuration();
    ConfigUsersPresetsDefault* userPresetDefault = new ConfigUsersPresetsDefault();
    ConfigUltrasonic* ultrasonicConfig = new ConfigUltrasonic();
    ConfigStatusLight* statusConfig = new ConfigStatusLight();
    ConfigServo* servoConfig = new ConfigServo();

  public:
    TableAdjusterBuilder() {}

    TableAdjuster& build() {
      Serial.println("Builder::build Start Build");
      PresetController* pc = new PresetController(usersPresetConfig, userPresetDefault, durationsConfig);
      TableController* tc = new TableController(ultrasonicConfig, servoConfig);
      StatusLight* status = new StatusLight(statusConfig);

      TableAdjuster* ta = new TableAdjuster(usersPresetConfig, durationsConfig, pc, tc, status);
      Serial.println("Builder::build Finish Build");
      return *ta;
    }

#pragma region ConfigUsersPresets
    TableAdjusterBuilder& setPinBtnPresets(int pos, int pin) {
      usersPresetConfig->pinBtnPresets[pos] = pin;
      return *this;
    }

    TableAdjusterBuilder& setPinBtnUser(int pin) {
      usersPresetConfig->pinBtnUser = pin;
      return *this;
    }

    TableAdjusterBuilder& setPinBtnEmergency(int pin) {
      usersPresetConfig->pinBtnEmergency = pin;
      return *this;
    }

    TableAdjusterBuilder& setActiveUsers(int number) {
      int set = number;
      if (number > 5 || number < 0) {
        set = 5;  
      }
      usersPresetConfig->activeUsers = set;
      return *this;
    }

    TableAdjusterBuilder& setActivePresets(int number) {
      int set = number;
      if (number > 5 || number < 0) {
        set = 5;  
      }
      usersPresetConfig->activePresets = set;
      return *this;
    }
#pragma endregion

#pragma region ConfigDuration
    TableAdjusterBuilder& setLoopDurationMs(int duration) {
      durationsConfig->loopDurationMs = duration;
      return *this;
    }
    TableAdjusterBuilder& setTimeoutDurationMs(int duration) {
      durationsConfig->timeoutDurationMs = duration;
      return *this;
    }

    TableAdjusterBuilder& setButtonLongPressMs(int duration) {
      durationsConfig->buttonLongPressMs = duration;
      return *this;
    }
#pragma endregion

#pragma region DefaultsConfig
    TableAdjusterBuilder& setDefaultUser(int number) {
      userPresetDefault->defaultUser = number;
      return *this;
    }

    TableAdjusterBuilder& setDefaultValues(int pos, int values[5]) {
      for (int i = 0; i < 5; i++) {
        userPresetDefault->defaultPresetValues[pos][i] = values[i];
      }
      return *this;
    }
#pragma endregion

#pragma region Ultrasonic
    TableAdjusterBuilder& setPinUltrasonicTrigger(int pin) {
      ultrasonicConfig->trigger = pin;
      return *this;
    }

    TableAdjusterBuilder& setPinUltrasonicEcho(int pin) {
      ultrasonicConfig->echo = pin;
      return *this;
    }

    TableAdjusterBuilder& setHeightTolerance(int tolerance) {
      ultrasonicConfig->tolerance = tolerance;
      return *this;
    }
#pragma endregion

#pragma region StatusLight
    TableAdjusterBuilder& setPinStatusLedRed(int pin) {
      statusConfig->pinLedRed = pin;
      return *this;
    }

    TableAdjusterBuilder& setPinStatusLedGreen(int pin) {
      statusConfig->pinLedGreen = pin;
      return *this;
    }

    TableAdjusterBuilder& setPinStatusLedYellow(int pin) {
      statusConfig->pinLedYellow = pin;
      return *this;
    }
#pragma endregion

#pragma region Servo
    TableAdjusterBuilder& setPinServo(int pin) {
      servoConfig->pin = pin;
      return *this;
    }

    TableAdjusterBuilder& setMoveUpAngle(int angle) {
      servoConfig->upPos = angle;
      return *this;
    }

    TableAdjusterBuilder& setMoveStopAngle(int angle) {
      servoConfig->stopPos = angle;
      return *this;
    }

    TableAdjusterBuilder& setMoveDownAngle(int angle) {
      servoConfig->downPos = angle;
      return *this;
    }
#pragma endregion
};

#endif