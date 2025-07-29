#include <stdio.h>
#include <unistd.h>
int main()
{
	fork();
	printf("Hello\n");
	fork();
	printf("World\n");
	fork();
	printf("How are you?\n");
	return 0;
}
	
