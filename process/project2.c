#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	pid_t pid;
	int fd;
	char buf[32];
	char * filename = "log.txt";
	int ret;

	pid = fork();
	if (pid == 0)
	{
		printf("son running...\n");
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
		while (1)
		{
			ret = read(0, buf, 32);
			if (ret == 0)
				break;
			write(fd, buf, ret);
		}
	}
	else
	{
//		sleep(10);
		wait();

		printf("father running...\n");
		fd = open(filename, O_RDONLY);

		while (1)
		{
			int i;

			ret = read(fd, buf, 32);
			if (ret == 0)
				break;
			for (i = 0; i < ret; i++)
				putchar(buf[i]);
		}
	}

	close(fd);

	return 0;
}
