#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
//#include <unistd.h>

pthread_mutex_t mylock = PTHREAD_MUTEX_INITIALIZER;
int msg;

//pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;
sem_t has_product;	// init as 0
sem_t is_empty;		// init as 1

void * c(void *arg)
{
	int counter = 0;

	while (1)
	{
		counter++;

		sem_wait(&has_product);

		pthread_mutex_lock(&mylock);
		printf("%s: %d -> %d\n", (char *)arg, counter, msg);
		pthread_mutex_unlock(&mylock);

		sem_post(&is_empty);
	}
}

void * p(void *arg)
{
	int counter = 0;

	while (1)
	{
		counter++;

		sem_wait(&is_empty);

		pthread_mutex_lock(&mylock);
		msg = rand() % 100;
		printf("%s: %d -> %d\n", (char *)arg, counter, msg);
		pthread_mutex_unlock(&mylock);

		sem_post(&has_product);
//		sleep(1);
	}

	return NULL;
}

pthread_t pthid;
pthread_t pthid2;

int main(void)
{
	sem_init(&has_product, 0, 0);
	sem_init(&is_empty, 0, 1);

	pthread_create(&pthid, NULL, p, "produce");
	pthread_create(&pthid2, NULL, c, "consume");

	pthread_join(pthid, NULL);
	pthread_join(pthid2, NULL);

	return 0;
}
