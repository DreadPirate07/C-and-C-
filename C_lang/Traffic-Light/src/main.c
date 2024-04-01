#include <stdio.h>
#include <unistd.h>
#include "traffic_control.h"
#include "timer.h"
#include "junction.h"

#define JUNCTION_COUNT 5

int main()
{
    // Array to hold the state and timers for all junctions
    Junction junctions[JUNCTION_COUNT];

    // Initialize junctions to their default states and timers
    initializeJunctions(junctions, JUNCTION_COUNT);

    // Main control loop
    while (1)
    {
        // Update the state of all junctions based on their timers
        updateJunctionStates(junctions, JUNCTION_COUNT);

        // Update the timers for all junctions
        updateTimers(junctions, JUNCTION_COUNT);

        // For demonstration purposes, print the state of each junction
        for (int i = 0; i < JUNCTION_COUNT; i++)
        {
            printf("Junction %d: %s\n", i + 1, junctions[i].state == LIGHT_STATE_GO ? "GO" : "STOP");
        }
        printf("\n");

        // Sleep for 1 second before the next cycle
        sleep(1);
    }

    return 0; // This line is never reached
}
