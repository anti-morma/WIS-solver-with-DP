#include "activities.h"

/* ----------------- Public API Implementation ----------------- */

int act_duration(act a) {
    return a.f - a.s;
}

int is_compatible(act a, act b) {
    /* Check if activity 'a' ends before activity 'b' starts.
     * If true, they can be sequenced as A -> B without overlap. */
    return a.f <= b.s;
}

/* ----------------- Private Internals (Static) ----------------- */

static void swap(act *a, act *b) {
    act tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Standard Lomuto partition scheme.
 * The pivot is chosen as the last element of the array segment. */
static int partition(act *v, int low, int high) {
    int pivot = v[high].s; // Sort based on start time
    int i = low - 1;

    for (int j = low; j < high; j++) {
        /* If current element starts earlier than or at the same time as pivot,
         * move it to the left side. */
        if (v[j].s <= pivot) {
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i + 1], &v[high]);
    return (i + 1);
}

/* Recursive QuickSort implementation. */
static void quick_sort(act *v, int low, int high) {
    if (low < high) {
        /* pi is partitioning index, v[pi] is now at right place */
        int pi = partition(v, low, high);

        quick_sort(v, low, pi - 1);
        quick_sort(v, pi + 1, high);
    }
}

/* ----------------- Public Sort Wrapper ----------------- */

void activity_sort(act *v, int count) {
    if (count > 1) {
        /* We hide the recursion details (low/high indices) from the user */
        quick_sort(v, 0, count - 1);
    }
}
