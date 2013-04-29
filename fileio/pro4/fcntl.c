#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int ret = 0;
	char c = 'c'; 
	int fd;
	int flags = 0;

//	fd = open("/dev/tty", O_NONBLOCK);
//	printf("fd = %d\n", fd);
//	ret = read(fd, &c, 1);

	flags = fcntl(0, F_GETFL);
	printf("flags = %x\n", flags);
	flags |= O_NONBLOCK;
	printf("flags 2 = %x\n", flags);

	//fcntl(0, F_SETFL, flags);
	fcntl(0, F_SETFL, O_RDONLY | O_NONBLOCK);
	flags = fcntl(0, F_GETFL);
	printf("flags = %x\n", flags);

	ret = read(0, &c, 1);

	putchar(c);
	putchar('A');

	return 0;
}


