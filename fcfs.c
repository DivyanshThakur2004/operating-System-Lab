#include <stdio.h>
typedef struct program{
	int num, at, bt, ct, tat, wt;
} pr;
int main()
{
	int n;
	printf("Enter Number of Processes:");
	scanf("%d", &n);
	pr arr[n];
	for(int i = 0; i < n; i++)
	{
		arr[i].num = i + 1;
		printf("Enter %d process's Arrival Time:", i + 1);
		scanf("%d", &arr[i].at);
		printf("Enter %d process's Burst Time:", i + 1);
		scanf("%d", &arr[i].bt);
		arr[i].ct = 0;
		arr[i].tat = 0;
		arr[i].wt = 0;
	}
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < n - i - 1; j++) {
			if(arr[j].at > arr[j+1].at) {
				pr temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	arr[0].ct = arr[0].at + arr[0].bt;
	for(int i = 1; i < n; i++) {
		if(arr[i].at > arr[i-1].ct)
			arr[i].ct = arr[i].at + arr[i].bt;
		else
			arr[i].ct = arr[i-1].ct + arr[i].bt;
	}
	for(int i = 0; i < n; i++)
	{
		arr[i].tat = arr[i].ct - arr[i].at;
		arr[i].wt = arr[i].tat - arr[i].bt;
	}
	float avgwt=0.00,avgtat=0.00;
	for(int i=0;i<n;i++)
	{
		avgwt = avgwt + arr[i].wt;
		avgtat = avgtat + arr[i].tat;
	}
	avgtat = (float)(avgtat/n);
	avgwt = (float)(avgwt/n);
	for(int i = 0; i < n; i++)
	{
		printf("Process %d: Arrival Time=%d Burst Time=%d Completion Time=%d Turn Around Time=%d Waiting Time=%d\n", arr[i].num, arr[i].at, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt);
	}
	printf("The Average Waiting time is %f and the Average Turn around time is %f\n",avgwt,avgtat);
	return 0;
}
