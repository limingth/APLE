#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;

#if 1
	if (fork() != 0)
		return 0;

	setsid();
#endif
	if (chdir("/") < 0)
		return (1);

	close(0);
	fd = open("/dev/null", O_RDWR);
	printf("fd = %d\n", fd);
	dup2(0, 1);
	dup2(0, 2);

	while (1);

	return 0;
}
