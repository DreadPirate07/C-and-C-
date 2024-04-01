#include "junction.h"
#include "timer.h"

// Global variable to keep track of the current active junction
static size_t currentGoJunction = 0;

// Function prototypes
void switchToNextState(Junction *junction);

// Switches the traffic light to the next state for a given junction
void switchToNextState(Junction *junction)
{
    if (junction->state == LIGHT_STATE_GO)
    {
        junction->state = LIGHT_STATE_STOP;
        // Assuming a fixed duration for simplicity. This could be dynamic based on traffic flow, time of day, etc.
        initializeTimer(junction, 10); // Transition to stop for 10 seconds
    }
    else
    {
        junction->state = LIGHT_STATE_GO;
        // Similar assumption as above for demonstration purposes
        initializeTimer(junction, 15); // Transition to go for 15 seconds
    }
}

// Initializes all junctions to a default state at the start
void initializeJunctions(Junction junctions[], size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        junctions[i].state = LIGHT_STATE_STOP; // Start all junctions in the stop state
        initializeTimer(&junctions[i], 5);     // Initially, all junctions wait for 5 seconds
    }
    // Optionally start the first junction as "GO"
    junctions[0].state = LIGHT_STATE_GO;
    initializeTimer(&junctions[0], 15); // Duration for "GO" state for the first junction
}

// Updates the state of all junctions based on their timers
void updateJunctionStates(Junction junctions[], size_t count)
{
    // Check if the current "GO" junction's timer has elapsed
    if (isTimerElapsed(&junctions[currentGoJunction]))
    {
        // Change the current "GO" junction to "STOP"
        junctions[currentGoJunction].state = LIGHT_STATE_STOP;
        initializeTimer(&junctions[currentGoJunction], 10); // Set a delay before this junction can go again

        // Move to the next junction
        currentGoJunction = (currentGoJunction + 1) % count;

        // Set the next junction to "GO"
        junctions[currentGoJunction].state = LIGHT_STATE_GO;
        initializeTimer(&junctions[currentGoJunction], 15); // Duration for "GO" state
    }
}
