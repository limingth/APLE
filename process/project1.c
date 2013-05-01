#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//#include <sys/wait.h>

int main(void)
{
	pid_t pid = 1;
	char * filename = "log.txt";

	pid = fork();
	if (pid == 0)
	{
		int fd;
		printf("son running...\n");
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
		dup2(fd, 1);
		close(fd);
		execlp("cat", "cat", NULL);
	}
	else
	{
//		sleep(10);
		wait();
		printf("father running...\n");
		execlp("cat", "cat", filename, NULL);
	}

	return 0;
}
