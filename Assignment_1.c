#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, time = 0, completed = 0, min_index;
    
    char pid[20][10];
    int at[20], bt[20], wt[20], tat[20], ct[20], done[20] = {0};

    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes:\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%s %d %d", pid[i], &at[i], &bt[i]);
    }

    while(completed < n) {
        int min_bt = 9999;
        min_index = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && done[i] == 0) {
                if(bt[i] < min_bt) {
                    min_bt = bt[i];
                    min_index = i;
                }
            }
        }

        if(min_index == -1) {
            time++; // idle CPU
        } else {
            ct[min_index] = time + bt[min_index];
            tat[min_index] = ct[min_index] - at[min_index];
            wt[min_index] = tat[min_index] - bt[min_index];

            total_wt += wt[min_index];
            total_tat += tat[min_index];

            time = ct[min_index];
            done[min_index] = 1;
            completed++;
        }
    }

    printf("\nWaiting Time:\n");
    for(i = 0; i < n; i++) {
        printf("%s %d\n", pid[i], wt[i]);
    }

    printf("\nTurnaround Time:\n");
    for(i = 0; i < n; i++) {
        printf("%s %d\n", pid[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}
