#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i = 0;

	if (argc <= 2)
		return -1;

	printf("hello, %s\n", getenv("USER"));

	for (i = 0; i < argc; i++)
		printf("argv[%d] = %s\n", i, argv[i]);

	if (strcmp(argv[0], "./add") == 0)
		printf("%s result: %d\n", argv[0], atoi(argv[1]) + atoi(argv[2]));
	else if (strcmp(argv[0], "./sub") == 0)
		printf("%s result: %d\n", argv[0], atoi(argv[1]) - atoi(argv[2]));

	return 0;
}
