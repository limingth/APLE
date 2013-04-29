#include <stdio.h>
#include <fcntl.h>

#define BUFSIZE		1024
char buf[BUFSIZE] = "hello";

int main(int argc, char *argv[])
{
	int fd = 0;

	if (argc >= 2)
	{
		fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0664);

		lseek(fd, 10, SEEK_SET);

		write(fd, buf, 5);

		close(fd);
	}

	return 0;
}
