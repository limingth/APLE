#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

unsigned long counter = 0;

void * mythread(void *arg)
{
//	sleep(10);
	sleep(1);
	printf("1sec = 0x%x\n", counter);
	printf("1sec = %d\n", counter);
	//printf("1sec = 0x%x\n", counter/10);
	exit(0);
}

pthread_t pthid;

int main(void)
{

	pthread_create(&pthid, NULL, mythread, NULL);

	while (1)
		counter++;
//		printf("%d\n", counter++);

	return 0;
}
