#include <stdio.h>
#include <pthread.h>

void * mythread(void * arg)
{
  int i = 0;
	int sum = 0;
	int begin = (int)arg;

	for (i = 0; i < 10; i++)
	{
		sum += begin + i;
		printf("add %d\n", begin + i);
	}

	return (void *)sum;
}

int main(void)
{
	pthread_t tid[10];
	void * ret;
	int sum = 0;
	int i = 0;

	printf("demo thread, pid = %d\n", getpid());

	for (i = 0; i < 10; i++)
	{
		pthread_create(&tid[i], NULL, mythread, (void *)(i*10+1));
//		pthread_detach(tid[i]);
	}

	for (i = 0; i < 10; i++)
	{
		pthread_join(tid[i], &ret); 
		sum += (int)ret;
	}

	printf("sum = %d\n", sum);

#if 0
	for (i = 0; i < 10; i++)
	{
		printf("1\n");
		pthread_join(tid[i], &ret); 
		printf("2\n");
		sum += (int)ret;
		printf("3\n");
	}

	printf("sum = %d\n", sum);
#endif

	return 0;
}
