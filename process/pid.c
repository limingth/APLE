#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int pid;

	pid = getpid();
	printf("pid = %d\n", pid);

	printf("ppid = %d\n", getppid());

	//sleep(10);

	return 0;
}
