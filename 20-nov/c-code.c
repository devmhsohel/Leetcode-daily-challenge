int garbageCollection(char** garbage, int garbageSize, int* travel, int travelSize) {
    long long totalMinutes = 0;  // Total minutes needed for garbage collection
    long long currentTravelTime = 0;  // Current travel time

    // Add the initial minutes required to collect garbage at the first house
    totalMinutes += strlen(garbage[0]);

    int lastGarbageIndices[3] = {-1, -1, -1};  // Keep track of the last occurrence of each type of garbage

    // Iterate through each house starting from the second house
    for (int houseIndex = 1; houseIndex < garbageSize; houseIndex++) {
        // Add the minutes required to collect garbage at the current house
        totalMinutes += strlen(garbage[houseIndex]);

        // Update the indices of the last occurrence of each type of garbage
        if (strchr(garbage[houseIndex], 'M') != NULL)
            lastGarbageIndices[0] = houseIndex - 1;
        if (strchr(garbage[houseIndex], 'P') != NULL)
            lastGarbageIndices[1] = houseIndex - 1;
        if (strchr(garbage[houseIndex], 'G') != NULL)
            lastGarbageIndices[2] = houseIndex - 1;
    }

    // Iterate through each travel segment
    for (int travelIndex = 0; travelIndex < travelSize; travelIndex++) {
        // Add the current travel time
        currentTravelTime += travel[travelIndex];

        // Add the minutes required to collect garbage if a garbage truck is at the corresponding house
        for (int truckIndex = 0; truckIndex < 3; truckIndex++) {
            if (lastGarbageIndices[truckIndex] == travelIndex) {
                totalMinutes += currentTravelTime;
            }
        }
    }

    return (int)totalMinutes;
}