#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * mythread(void *arg)
{
	int counter = 0;
	while (1)
		printf("%d\n", counter++);
}

pthread_t pthid;

int main(void)
{

	pthread_create(&pthid, NULL, mythread, NULL);

	sleep(1);
	exit(0);

	return 0;
}
