#include <stdio.h>
#include <signal.h>

void sig_term(int signo)
{
	printf("my term handler\n");

	return;
}


int main(void)
{
	int counter = 0;
	// 1024 / 5 = 204
	// 1024 / 8 = 128

	struct sigaction newact, oldact;

	newact.sa_handler = sig_term;
	//newact.sa_flags = 0;
	//sigaction(SIGINT, &newact, &oldact);
	sigaction(SIGTERM, &newact, &oldact);

	while (1)
	{	
		printf("%7d\r", counter++);
//		counter = 1 / 0;
//		printf("%d\n", *(int *)0);
		fflush(stdout);
//		usleep(100);
//		sleep(1);
		usleep(1000*500);
	}
	
	return 0;
}
