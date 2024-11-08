#ifndef COMPONENTBUNDLE_H
#define COMPONENTBUNDLE_H

#include "componentbattery.h"
#include "componentbluetooth.h"

class ComponentBundle
{
public:
    ComponentBattery* comBat;
    ComponentBluetooth* comBle;
};

#endif // COMPONENTBUNDLE_H
