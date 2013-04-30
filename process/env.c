#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *env[])
//int main(int argc, char *argv[])
//int main(void)
{
	int i = 0;
	char  * p = malloc(1);
	extern char **environ;

	printf("p = %p\n", p);
	printf("&i = %p\n", &i);
	printf("&environ = %p\n", &environ);
	return;

	for (i = 0; i < argc; i++)
		printf("argv[%d] = %s\n", i, argv[i]);

	for (i = 0; env[i]; i++)
	{
		printf("env[%d] = %s\n", i, env[i]);
		printf("&env[%d] = %p\n", i, &env[i]);
	}

	printf("HOME is %s\n", getenv("HOME"));
	printf("MYTEST is %s\n", getenv("MYTEST"));

	printf("&argc = %p\n", &argc);
	printf("argv = %p\n", argv);
	printf("env = %p\n", env);

	return 0;
}
