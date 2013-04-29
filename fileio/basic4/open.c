#include <stdio.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	int ret = -2;
	char buf[10];

#define PRINT(x)	printf("<debug> " #x " = %x\n", x)
#define PRINTD(x)	printf("<int> " #x " = %d\n", x)

	PRINT(O_RDONLY);
	PRINT(O_WRONLY);
	PRINT(O_RDWR);
	printf("O_RDONLY = %x\n", O_RDONLY);
//	printf("O_WRONLY = %x\n", O_WRONLY);
//	printf("O_RDWR = %x\n", O_RDWR);

//	fd = open("test.txt", O_WRONLY | O_CREAT);
	fd = open("test.txt", O_RDONLY);
	PRINTD(fd);

	ret = read(fd, buf, 10);
	PRINTD(ret);
	ret = read(0, buf, 10);
	PRINTD(ret);

	ret = write(1, buf, ret);
	PRINTD(ret);

	ret = close(fd);
	PRINTD(ret);

	return 0;
}
