#include <stdio.h>
#include <fcntl.h>

void put_hex(char c)
{
	char * hex = "0123456789abcdef";

	putchar(hex[(c >> 4) & 0x0F]);
	putchar(hex[(c >> 0) & 0x0F]);

	putchar(' ');

	return;
}

#define OFFSET		0x34		// ELF header size, .text offset
#define SIZE		0x22		// ELF .text size

int main(int argc, char *argv[])
{
	char * filename = "hello";
	int fd = 0;
	int counter = 0;

	if (argc >= 2)
		filename = argv[1];

	printf("open file %s \n", filename);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("open file %s failed\n", filename);
		return 0;
	}

	lseek(fd, OFFSET, SEEK_SET);

	while (1)
	{
		char c;
		int ret = 0;

		ret = read(fd, &c, 1);
		if (ret == 0)
			break;

		put_hex(c);
		//printf("%x ", c);

		counter++;

		if (counter % 16 == 0)
			printf("\n");

		if (counter == SIZE)
			break;
	}

	close(fd);

	return 0;
}


