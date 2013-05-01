#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid = 1;

	pid = fork();
	if (pid == 0)
	{
		int fd;

		printf("son running...\n");
		//while (1);
		//fd = *(int *)0;
		exit(0x12);
	}
	else
	{
	//	while (1);
		int status;
//		sleep(10);
		wait(&status);
		printf("father running...\n");
		printf("status = 0x%x\n", status);
	}

	return 0;
}
