#include <stdio.h>
#include <stdlib.h>
#include "activities.h"

void solve(act *activities, int N) {
    int *dp = malloc(sizeof(int) * N);
    int *pred = malloc(sizeof(int) * N);

    if (!dp || !pred) {
        fprintf(stderr, "Out of memory (DP tables)\n");
        exit(1);
    }

    int best_sol = 0; /* Index of the best solution found so far */

    for (int i = 0; i < N; i++) {
        /* Base case: single activity duration */
        dp[i] = act_duration(activities[i]);
        pred[i] = -1;

        /* Look back at all previous activities */
        for (int j = 0; j < i; j++) {
            if (is_compatible(activities[j], activities[i])) {
                int current_val = dp[j] + act_duration(activities[i]);
                
                if (current_val > dp[i]) {
                    dp[i] = current_val;
                    pred[i] = j;
                }
            }
        }

        /* Track global maximum */
        if (dp[i] > dp[best_sol]) {
            best_sol = i;
        }
    }

    /* ---------------------- Output & Reconstruction --------------------- */
    
    printf("Max duration: %d\n", dp[best_sol]);
    printf("Selected activities (reverse order):\n");
    
    int curr = best_sol;
    while(curr != -1) {
        printf("  [%d, %d] (Duration: %d)\n", 
               activities[curr].s, 
               activities[curr].f, 
               act_duration(activities[curr]));
        curr = pred[curr];
    }

    free(dp);
    free(pred);
}

int main(int argc, char **argv) {

    /* -------------------------- Input Handling -------------------------- */
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Opening file");
        exit(1);
    }

    int N;
    if (fscanf(fp, "%d", &N) != 1) {
        fprintf(stderr, "Invalid file format\n");
        exit(1);
    }

    act *activities = malloc(sizeof(act) * N);
    if (!activities) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }

    for (int i = 0; i < N; i++) {
        fscanf(fp, "%d %d", &activities[i].s, &activities[i].f);
    }
    fclose(fp);

    /* ---------------- Sorting & Solving (DP Logic) ---------------------- */

    /* Sorting is mandatory for the Bottom-Up DP approach */
    activity_sort(activities, N);
    
    solve(activities, N);
    
    free(activities);

    return 0;
}
