#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int get_rand(void)
{
	return rand() % 3;
}

int cmp(int a, int b)
{
	if (a == b)
		return 0;

	if (a - b == 1 || a - b == -2)
		return 1;

	return -1;
}

int judge(int father, int child)
{
	static int fwins = 0;
	static int cwins = 0;

	printf("father: %d  vs   child: %d\n", father, child);

	if (cmp(father, child) > 0)
		fwins++;
	else if (cmp(father, child) < 0)
		cwins++;

	printf("\t\t\t(%d vs %d)\n", fwins, cwins);

	if (fwins < 2 && cwins < 2)
		return 0;

	if (fwins == 2)
		printf("father wins!\n");

	if (cwins == 2)
		printf("child wins!\n");

	return 1;
}

int main(void)
{
	int fd[2];
	pid_t pid;
	char fi;

	pipe(fd);

	pid = fork();

	if (pid == 0) 	// child
	{
		close(fd[1]);	// close write
		
		srand(time(NULL));
		while (1)
		{
			read(fd[0], &fi, 1);

			// if return 1, then sb wins
			if (judge(fi, get_rand()))
				exit(0);
		}
	}
	else // father
	{
		close(fd[0]);	// close read

		while (1)
		{
			fi = get_rand();
			write(fd[1], &fi, 1);

			sleep(1);
		}
	}

	return 0;
}
