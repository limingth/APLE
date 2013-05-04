#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
//#include <unistd.h>

pthread_mutex_t mylock = PTHREAD_MUTEX_INITIALIZER;
int p1_msg;
int p2_msg;

//pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;
sem_t p1_has_product;	// init as 0
sem_t p2_has_product;	// init as 0
sem_t p1_is_empty;		// init as 1
sem_t p2_is_empty;		// init as 1

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

void * c(void *arg)
{
	int counter = 0;

	while (1)
	{
		counter++;

		sem_wait(&p1_has_product);
		sem_wait(&p2_has_product);

		pthread_mutex_lock(&mylock);
		printf("%s: %d -> %d vs %d\n", (char *)arg, counter, p1_msg, p2_msg);
		pthread_mutex_unlock(&mylock);

		// if return 1, then sb wins
		if (judge(p1_msg, p2_msg))
			exit(0);

	//	sleep(1);
		sem_post(&p1_is_empty);
		sem_post(&p2_is_empty);
	}
}

void * p2(void *arg)
{
	int counter = 0;

	while (1)
	{
		counter++;

		sem_wait(&p1_is_empty);

		pthread_mutex_lock(&mylock);
		p2_msg = rand() % 3;
		printf("%s: counter %d -> msg %d\n", (char *)arg, counter, p2_msg);
		pthread_mutex_unlock(&mylock);

		sem_post(&p2_has_product);
//		sleep(1);
	}

	return NULL;
}

void * p1(void *arg)
{
	int counter = 0;

	while (1)
	{
		counter++;

		sem_wait(&p2_is_empty);

		pthread_mutex_lock(&mylock);
		p1_msg = rand() % 3;
		printf("%s: counter %d -> msg %d\n", (char *)arg, counter, p1_msg);
		pthread_mutex_unlock(&mylock);

		sem_post(&p1_has_product);
//		sleep(1);
	}

	return NULL;
}

pthread_t pthid1;
pthread_t pthid2;
pthread_t pthid3;

int main(void)
{
	srand(time(NULL));

	sem_init(&p1_has_product, 0, 0);
	sem_init(&p2_has_product, 0, 0);
	sem_init(&p1_is_empty, 0, 1);
	sem_init(&p2_is_empty, 0, 1);

	pthread_create(&pthid1, NULL, p1, "produce1");
	pthread_create(&pthid2, NULL, p2, "produce2");
	pthread_create(&pthid3, NULL, c, "consume");

	pthread_join(pthid1, NULL);
	pthread_join(pthid2, NULL);
	pthread_join(pthid3, NULL);

	return 0;
}
