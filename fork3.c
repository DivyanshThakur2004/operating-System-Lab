#include <stdio.h>
#include <unistd.h>

void childprocess(int arr[],int n,int id)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]%2!=0)
		{
			sum=sum+arr[i];
		}
	}
	printf("The odd sum of the array is %d\n",sum);
	printf("The ID of the Process is %d\n",id);
}


void parentprocess(int arr[],int n,int id)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]%2==0)
		{
			sum=sum+arr[i];
		}
	}
	printf("The Even sum of the Array is %d\n",sum);
	printf("The ID of the Process is %d\n",id);
}

int main()
{
	pid_t pid;
	int n;
	printf("Enter Number of Elements in the Array:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter Elements:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	pid = fork();
	if(pid==0)
	{
		childprocess(arr,n,getpid());
	}
	else if(pid>0)
	{
		parentprocess(arr,n,getpid());
	}
	else{
		printf("process Failed\n");
	}
	return 0;
}
