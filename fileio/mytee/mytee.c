#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd = 0;

#define BUFSIZE		1024
	char buf[BUFSIZE];

	if (argc >= 2)
		fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0664);

	while (1)
	{
		int ret;

		ret = read(0, buf, BUFSIZE);
		if (ret == 0)
			break;

		write(1, buf, ret);
		if (fd > 0)
			write(fd, buf, ret);
	}

	if (fd > 0)
		close(fd);

	return 0;
}
