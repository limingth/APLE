#include <stdio.h>
#include <signal.h>

void sig_term(int signo)
{
	printf("my alarm term handler\n");
	sleep(1);
	alarm(1);
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
	sigaction(SIGALRM, &newact, &oldact);

	alarm(1);
	while (1)
	{	
		printf("%d\n", counter++);
	}
	
	return 0;
}
