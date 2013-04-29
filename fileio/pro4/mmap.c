#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
	char * filename = "hello";
	int fd = 0;
	int counter = 0;
	char * p;

	if (argc >= 2)
		filename = argv[1];

	printf("open file %s \n", filename);

	fd = open(filename, O_RDWR);
	if (fd < 0)
	{
		printf("open file %s failed\n", filename);
		return 0;
	}

	p = mmap(NULL, 10, PROT_WRITE, MAP_SHARED, fd, 0);
	printf("p = %s\n", p);
	close(fd);	

	printf("p = %p\n", p);
	p[4] = 'T';

	sleep(10);

	munmap(p, 10);
	printf("p = %p\n", p);
	p[4] = 'D';

	return 0;
}


