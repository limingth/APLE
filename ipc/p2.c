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

	fprintf(stderr, "father: %d  vs   child: %d\n", father, child);

	if (cmp(father, child) > 0)
		fwins++;
	else if (cmp(father, child) < 0)
		cwins++;

	fprintf(stderr, "\t\t\t(%d vs %d)\n", fwins, cwins);

	if (fwins < 2 && cwins < 2)
		return 0;

	if (fwins == 2)
		fprintf(stderr, "father wins!\n");

	if (cwins == 2)
		fprintf(stderr, "child wins!\n");

	return 1;
}

int main(void)
{
	int fi;
	int my;

//	srand(time(NULL));
	srand(100);
	while (1)
	{
		my = get_rand();
		// must output with a newline and then fflush stdout
		printf("%d\n", my);
		fflush(stdout);

		scanf("%d", &fi);

		// if return 1, then sb wins
		if (judge(my, fi))
			exit(0);
	}

	return 0;
}
