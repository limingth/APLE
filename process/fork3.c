#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int global = 100;

int main(void)
{
	pid_t pid;
	int fd, fd2;
	int ret = 0;
	
	fd = open("test", O_WRONLY | O_CREAT);
/*
	ret = write(fd, "abcd", 4);
	printf("fd = %d\n", fd);
	printf("ret = %d\n", ret);

	fd2 = open("test", O_WRONLY | O_CREAT);
	printf("fd2 = %d\n", fd2);
	ret = write(fd2, "12345678", 8);
	printf("ret = %d\n", ret);

	close(fd);
	close(fd2);
*/

	//return;
	pid = fork();

	if (pid == 0)
	{
		ret = write(fd, "abcd", 4);
		printf("<son> global = %d\n", global);
	}
	else
	{
		ret = write(fd, "1234", 4);
		printf("<father> global = %d\n", global);
	}

	close(fd);

//	sleep(10);

	return 0;
}


