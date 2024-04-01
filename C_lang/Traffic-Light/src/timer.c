#include "junction.h"
#include <time.h>

// Initializes the timer for a given junction
void initializeTimer(Junction *junction, uint32_t duration)
{
    junction->timer = duration;
}

// Updates the timer for all junctions. Should be called periodically.
void updateTimers(Junction junctions[], size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        if (junctions[i].timer > 0)
        {
            junctions[i].timer--;
        }
    }
}

// Checks if the timer for a given junction has elapsed
int isTimerElapsed(const Junction *junction)
{
    return junction->timer == 0;
}
