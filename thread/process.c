#include <unistd.h>
#include <stdio.h>

int global = 100;

//#define PRINT(x)	printf(#x " = %d\n", x)
#define PRINT(x, y)	{ printf(#x ": " #y " = %d(%p)\n", y, &y); test(y++); sleep(1); }

int test(int new)
{
	static int t;

	printf("id: %d,  t 1 = %d (%p)\n", getpid(), t, &t);
	t = new;
	printf("id: %d,  t 2 = %d (%p)\n", getpid(), t, &new);

	return 0;
}

int main(void)
{
	if (fork() == 0)	// child
	{
		global = 200;
		while (1)
			PRINT(child, global);
	}
	else 	// father
	{
		global = 50;
		while (1)
			PRINT(father, global);
		wait();
	}

	return 0;
}
