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

#include <pthread.h>
pthread_t pthid;

void * mythread(void * arg)
{
	int tmp = 0;
	printf("\n\n\n");
	printf("arg is %s\n", (char *)arg);
	printf("pthid is  %x\n", (int)pthread_self());
	printf("&arg is %p\n", &arg);
	printf("&tmp is %p\n", &tmp);
	printf("&global is %p\n", &global);

	test(500);	

	return (void *)0;
}

int main(void)
{
//	mythread("main thread\n");
	//return 0;

	printf("pthid 1 = %x\n", (int)pthid);
	// create thread
	pthread_create(&pthid, NULL, mythread, "my test thread");
	printf("pthid 2 = %x\n", (int)pthid);
	pthread_join(pthid, NULL);

	pthread_create(&pthid, NULL, mythread, "my test thread");
	printf("pthid 2 = %x\n", (int)pthid);
	pthread_join(pthid, NULL);

	pthread_create(&pthid, NULL, mythread, "my test thread");
	printf("pthid 2 = %x\n", (int)pthid);
	pthread_join(pthid, NULL);
	

	pthread_create(&pthid, NULL, mythread, "my test thread");
	printf("pthid 2 = %x\n", (int)pthid);
	pthread_join(pthid, NULL);
	global = 50;

//	while (1)
		;
	//PRINT(father, global);

	return 0;
}
