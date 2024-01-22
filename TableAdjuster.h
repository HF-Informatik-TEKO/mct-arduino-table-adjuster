#ifndef TABLEADJUSTER_H
#define TABLEADJUSTER_H

#include "PresetController.h"
#include "TableController.h"
#include "WorkState.h"

class TableAdjuster {
  private:
    PresetController preset;
    TableController table;
    WorkState state;
    int height;
    int timeoutCounter;

    void moveTable();
    void setHeight();
    void resetState();
    void changeState(WorkState newState);
    void timeout(String className);

  public:
    TableAdjuster();
    void cycle();
};

#endif