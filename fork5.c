#include <stdio.h>
#include <unistd.h>
int main()
{
	int a = fork();
	printf("Hello\n");
	printf("A is %d\n",a);
	printf("My PID is %d\n",getpid());
	printf("My Parent PID is %d\n",getppid());
	return 0;
}
