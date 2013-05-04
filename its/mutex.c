#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//#include <unistd.h>

int counter = 0;

//pthread_mutex_t mylock = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t * plock;

void * mythread(void *arg)
{
	int i = 0;
	for (i = 0; i < 1000; i++)
	{
		int tmp;

//		pthread_mutex_lock(&mylock);
		pthread_mutex_lock(plock);

		tmp = counter;
		usleep(1);	
		counter = tmp + 1;

//		pthread_mutex_unlock(&mylock);
		pthread_mutex_unlock(plock);
		printf("%s: %d\n", (char *)arg, counter);
//		counter++;
	}
		printf("%s: %d\n", (char *)arg, counter);
	return NULL;
}

pthread_t pthid;
pthread_t pthid2;

int main(void)
{
	pthread_mutex_t tmp;
//	plock = malloc(sizeof(pthread_mutex_t));
	plock = &tmp;
	pthread_mutex_init(plock, NULL);

	pthread_create(&pthid, NULL, mythread, "p1");
	pthread_create(&pthid2, NULL, mythread, "p2");

	pthread_join(pthid, NULL);
	pthread_join(pthid2, NULL);

	pthread_mutex_destroy(plock);

	return 0;
}
