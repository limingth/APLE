#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd;

	printf("argv[1] = %s\n", argv[1]);
	fd = open(argv[1], O_RDONLY);

	printf("fd = %d\n", fd);
	dup2(fd, 0);
	close(fd);

	execlp("./a.out", "a.out", "fs", NULL);

	return 0;
}

