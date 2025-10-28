#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    printf("Enter Number of Page Frames: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Invalid Input\n");
        return 0;
    }

    printf("Enter Number of Page References: ");
    scanf("%d", &m);
    if (m < 1) {
        printf("Invalid Input\n");
        return 0;
    }

    int ssd[m];
    printf("Enter Sequence of Page References: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &ssd[i]);
    }

    int ram[n];
    int front = 0, count = 0;
    int pageFaults = 0, pageHits = 0;

    printf("\nThe Page Replacement FIFO Representation is as Follows:\n");

    for (int i = 0; i < m; i++) {
        int page = ssd[i];
        int found = 0;
        for (int j = 0; j < count; j++) {
            if (ram[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            ram[front] = page;
            front = (front + 1) % n;
            if (count < n) count++;
            pageFaults++;
        } else {
            pageHits++;
        }
        printf("Step %2d: ", i + 1);
        for (int j = 0; j < count; j++) {
            printf("%d ", ram[j]);
        }
        if (!found)
            printf(" <- Page Fault");
        else
            printf(" <- Page Hit");
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", pageFaults);
    printf("Total Page Hits   = %d\n", pageHits);
    float hitRatio = (float)pageHits / m;
    printf("Hit Ratio         = %.2f\n", hitRatio);

    return 0;
}
