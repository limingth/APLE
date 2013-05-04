#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//#include <unistd.h>

pthread_mutex_t mylock = PTHREAD_MUTEX_INITIALIZER;
int msg;

pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;

void * c(void *arg)
{
	int counter = 0;

	while (1)
	{
		counter++;

		pthread_mutex_lock(&mylock);
		// 1. release mylock  2. wait for has_product   3. when ok, regain mylock
		pthread_cond_wait(&has_product, &mylock);
		printf("%s: %d -> %d\n", (char *)arg, counter, msg);
		pthread_mutex_unlock(&mylock);
	}
}

void * p(void *arg)
{
	int counter = 0;

	while (1)
	{
		counter++;

		pthread_mutex_lock(&mylock);
		msg = rand() % 100;
		printf("%s: %d -> %d\n", (char *)arg, counter, msg);
		pthread_mutex_unlock(&mylock);
		// wake up
		pthread_cond_signal(&has_product);
//		sleep(1);
	}

	return NULL;
}

pthread_t pthid;
pthread_t pthid2;

int main(void)
{
	pthread_create(&pthid, NULL, p, "produce");
	pthread_create(&pthid2, NULL, c, "consume");

	pthread_join(pthid, NULL);
	pthread_join(pthid2, NULL);


	return 0;
}
