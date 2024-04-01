#ifndef TIMER_H
#define TIMER_H

#include "junction.h"
#include <stddef.h>

void initializeTimer(Junction *junction, uint32_t duration);
void updateTimers(Junction junctions[], size_t count);
int isTimerElapsed(const Junction *junction);

#endif // TIMER_H
