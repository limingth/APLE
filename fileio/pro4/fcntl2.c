#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int ret = 0;
	char c = 'c'; 
	int fd;
	int flags = 0;

	printf("argc = %d\n", argc);

	flags = fcntl(0, F_GETFL);
	printf("flags = %x\n", flags);

	flags = fcntl(1, F_GETFL);
	printf("flags = %x\n", flags);

	flags = fcntl(2, F_GETFL);
	printf("flags = %x\n", flags);

	return 0;
}


