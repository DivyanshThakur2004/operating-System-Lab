#include <stdio.h>

typedef struct {
    int pid, at, bt, priority, wt, tat, ft;
} Process;

int main() {
    int n, time = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n], temp;
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter AT, BT and Priority for Process %d: ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at || (p[i].at == p[j].at && p[i].priority > p[j].priority)) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    time = p[0].at;
    for (int i = 0; i < n; i++) {
        if (time < p[i].at) time = p[i].at;
        p[i].wt = time - p[i].at;
        time += p[i].bt;
        p[i].ft = time;
        p[i].tat = p[i].ft - p[i].at;
    }

    printf("\nPID\tAT\tBT\tPriority\tWT\tTAT\tFT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].priority, p[i].wt, p[i].tat, p[i].ft);
    }

    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) printf("| P%d ", p[i].pid);
    printf("|\n0");
    for (int i = 0; i < n; i++) printf("   %d", p[i].ft);
    printf("\n");

    return 0;
}
