#include <stdio.h>

typedef struct program {
    int num, at, bt, ct, tat, wt, done, rt, priority;
} pr;

int main() {
    int n, choice;
    printf("NAME: Divyansh Thakur | SECTION: C | ROLL NUMBER: 25\n");
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    pr arr[n];
    for (int i = 0; i < n; i++) {
        arr[i].num = i + 1;
        printf("Enter Arrival Time for P%d: ", i + 1);
        scanf("%d", &arr[i].at);
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &arr[i].bt);
        printf("Enter Priority for P%d (Lower number = Higher priority): ", i + 1);
        scanf("%d", &arr[i].priority);
        arr[i].ct = arr[i].tat = arr[i].wt = 0;
        arr[i].done = 0;
        arr[i].rt = arr[i].bt;
    }

    printf("\nChoose Scheduling Type:\n1. Non-Preemptive Priority\n2. Preemptive Priority\nEnter choice: ");
    scanf("%d", &choice);

    int completed = 0, curr_time = 0;
    float total_wt = 0, total_tat = 0;
    int prev_idx = -1;

    printf("\nGantt Chart (Process execution timeline):\n");
    printf("Time\tProcess\n");

    if (choice == 1) {
        while (completed < n) {
            int idx = -1;
            int highest_priority = 1e9;

            for (int i = 0; i < n; i++) {
                if (arr[i].at <= curr_time && arr[i].done == 0) {
                    if (arr[i].priority < highest_priority ||
                       (arr[i].priority == highest_priority && arr[i].at < arr[idx].at)) {
                        highest_priority = arr[i].priority;
                        idx = i;
                    }
                }
            }

            if (idx != -1) {
                if (idx != prev_idx) {
                    printf("%d\tP%d\n", curr_time, arr[idx].num);
                    prev_idx = idx;
                }
                curr_time += arr[idx].bt;
                arr[idx].ct = curr_time;
                arr[idx].tat = arr[idx].ct - arr[idx].at;
                arr[idx].wt = arr[idx].tat - arr[idx].bt;
                arr[idx].done = 1;
                total_wt += arr[idx].wt;
                total_tat += arr[idx].tat;
                completed++;
            } else {
                if (prev_idx != -1) {
                    printf("%d\tIdle\n", curr_time);
                    prev_idx = -1;
                }
                curr_time++;
            }
        }
    } else if (choice == 2) {
        while (completed < n) {
            int idx = -1;
            int highest_priority = 1e9;

            for (int i = 0; i < n; i++) {
                if (arr[i].at <= curr_time && arr[i].done == 0) {
                    if (arr[i].priority < highest_priority ||
                       (arr[i].priority == highest_priority && arr[i].at < arr[idx].at)) {
                        highest_priority = arr[i].priority;
                        idx = i;
                    }
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
    } else {
        printf("Invalid choice\n");
        return 1;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j].priority < arr[i].priority ||
               (arr[j].priority == arr[i].priority && arr[j].at < arr[i].at)) {
                pr temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
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
