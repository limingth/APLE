#include <stdio.h>
#include <error.h>

int fd[2];

#define PRINT(x)	printf(#x " = %d\n", x);
int main(void)
{
	char buf[32] = "hello";
	char buf2[32] = "123456789";
	int ret = 0;

	pipe(fd);

	printf("fd: %d %d\n", fd[0], fd[1]);
//	printf("%s\n", strerror(141));

	printf("1\n");
//	close(fd[0]);
	printf("2\n");

	int counter = 0;
	while (1)
	{
		ret = write(fd[1], buf, 4);
		PRINT(ret);
		if (ret != 4)
			return 100;
		printf("counter = %d\n", counter++);
//		ret = read(fd[0], buf, 1);
//		if (ret != 1)
//			return 200;
		PRINT(ret);
	}
	printf("3\n");
	PRINT(ret);
	//close(fd[1]);

	ret = read(fd[0], buf2, 32);
	buf2[ret] = '\0';
	printf("buf is %s\n", buf2);
	PRINT(ret);
	ret = read(fd[0], buf2, 32);
	PRINT(ret);

	return 0;
}
