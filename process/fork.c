#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;

	printf("<father1> getpid = %d\n", getpid());

	printf("before fork\n");
	pid = fork();
	printf("after fork\n");

	if (pid == 0)
	{
		printf("<son> pid = %d\n", pid);
		printf("<son> getpid = %d\n", getpid());
	}
	else
	{
		printf("<father> pid = %d\n", pid);
		printf("<father2> getpid = %d\n", getpid());
	}

//	sleep(10);

	return 0;
}


