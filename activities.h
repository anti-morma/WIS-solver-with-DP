#ifndef ACTIVITIES_H
#define ACTIVITIES_H

/* Represents a single activity with a time interval. */
typedef struct {
    int s; // Start time
    int f; // Finish time
} act;

/* * Sorts an array of activities based on their start time (ascending).
 * Complexity: O(N log N) average case.
 * * v: Pointer to the array of activities.
 * count: Number of elements in the array.
 */
void activity_sort(act *v, int count);

/* * Calculates the weight (duration) of an activity.
 * Returns: (finish - start).
 */
int act_duration(act a);

/* * Checks if activity 'a' is compatible with activity 'b'.
 * Assumption: We are checking if 'a' can logically precede 'b'.
 * * Returns: 1 if 'a' finishes before or exactly when 'b' starts.
 * 0 otherwise.
 */
int is_compatible(act a, act b);

#endif
