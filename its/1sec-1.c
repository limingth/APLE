#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int flag = 0;

void * mythread(void *arg)
{
	sleep(1);
	flag = 1;
}

pthread_t pthid;

int main(void)
{
	int counter = 0;

	pthread_create(&pthid, NULL, mythread, NULL);

	while (flag == 0)
		printf("%d\n", counter++);

	return 0;
}
