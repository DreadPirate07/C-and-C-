#ifndef TRAFFIC_CONTROL_H
#define TRAFFIC_CONTROL_H

#include "junction.h"
#include <stddef.h>

void switchToNextState(Junction *junction);
void initializeJunctions(Junction junctions[], size_t count);
void updateJunctionStates(Junction junctions[], size_t count);

#endif // TRAFFIC_CONTROL_H
