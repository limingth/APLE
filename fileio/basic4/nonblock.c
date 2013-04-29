#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

	//extern errno;

int main(void)
{
	int fd;
	int ret = 0;
	int counter = 0;
	char buf[10];


	fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
	//fd = open("/dev/tty", O_RDONLY);

	printf("fd = %d\n", fd);

tryagain:
	if (counter >= 5)
		goto end;

	sleep(1);
//	usleep(100*1000);
	ret = read(fd, buf, 10);
	//printf("ret = %d\n", ret);
	counter++;


	if (ret < 0)
	{	printf("errno = %d\n", errno);
		printf("ret = %d\n", ret);
		goto tryagain;
	}

	ret = write(1, buf, ret);

end:
	return 0;
}

