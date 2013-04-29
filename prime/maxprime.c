
//#include <stdio.h>

int printf(const char * format, ...);
int scanf(const char * format, ...);


#include <math.h>

//#define debug //
//#define debug(format, args...)	 fprintf(stderr, format, ##args)
#define debug(format, args...)	 //fprintf(stderr, format, ##args)

int main(void)
{
	int end = 10;
	int i, j;
	int counter = 0;
	int max = 0;

	debug("hello, max prime\n");
	scanf("%d", &end);
	debug("end = %d\n", end);

	counter = 0;
	for (i = 2; i <= end; i++)
	{
		int factor = 0;
		debug("i = %d\n", i);
		for (j = 1; j <= sqrt(i); j++)
	//	for (j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				debug("%d ", j);
				factor++;
			}
		}
		debug("\n");
		debug("factor = %d\n", factor);
		if (factor == 1)
		{
			counter++;
			max = i;
			debug("find a prime %d\n", i);
		}
	}

	debug("counter = %d, max = %d\n", counter, max);
	printf("%d %d\n", counter, max);

	return 0;
}

