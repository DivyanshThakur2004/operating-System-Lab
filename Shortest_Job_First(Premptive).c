#include <stdio.h>
typedef struct program {
    int num, at, bt, ct, tat, wt, done, rt;
} pr;

int main() {
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    pr arr[n];

    for (int i = 0; i < n; i++) {
        arr[i].num = i + 1;
        printf("Enter %d process's Arrival Time: ", i + 1);
        scanf("%d", &arr[i].at);
        printf("Enter %d process's Burst Time: ", i + 1);
        scanf("%d", &arr[i].bt);
        arr[i].ct = arr[i].tat = arr[i].wt = 0;
        arr[i].done = 0;
        arr[i].rt = arr[i].bt;
    }

    int completed = 0, curr_time = 0;
    float total_wt = 0, total_tat = 0;

    int prev_idx = -1;

    printf("\nGantt Chart (Process execution timeline):\n");
    printf("Time\tProcess\n");

    while (completed < n) {
        int idx = -1;
        int min_rt = 1e9;

        for (int i = 0; i < n; i++) {
            if (arr[i].at <= curr_time && arr[i].done == 0 && arr[i].rt < min_rt) {
                min_rt = arr[i].rt;
                idx = i;
            }
        }

        if (idx != -1) {
            if (idx != prev_idx) {
                printf("%d\tP%d\n", curr_time, arr[idx].num);
                prev_idx = idx;
            }

            arr[idx].rt--;
            curr_time++;

            if (arr[idx].rt == 0) {
                arr[idx].done = 1;
                arr[idx].ct = curr_time;
                arr[idx].tat = arr[idx].ct - arr[idx].at;
                arr[idx].wt = arr[idx].tat - arr[idx].bt;

                total_wt += arr[idx].wt;
                total_tat += arr[idx].tat;
                completed++;
            }
        } else {
            if (prev_idx != -1) {
                printf("%d\tIdle\n", curr_time);
                prev_idx = -1;
            }
            curr_time++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", arr[i].num, arr[i].at, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt);
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turn Around Time: %.2f\n", total_tat / n);

    return 0;
}
