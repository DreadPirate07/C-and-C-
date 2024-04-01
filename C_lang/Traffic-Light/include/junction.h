#ifndef JUNCTION_H
#define JUNCTION_H

#include <stdint.h>

// Define traffic light states
typedef enum
{
    LIGHT_STATE_STOP, // Red light (except for left turn)
    LIGHT_STATE_GO    // Green light for straight and right turn
} TrafficLightState;

// Structure to hold the state and timer of a junction
typedef struct
{
    TrafficLightState state;
    uint32_t timer; // Timer in seconds, controls state duration
} Junction;


#endif // JUNCTION_H
