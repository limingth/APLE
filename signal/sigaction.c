#include <signal.h>
#include <stdio.h>

void sig_int(int signo)
{
	int local = 0;
	printf("my sig int handler\n");
	printf("<handler> &local = %p\n", &local);
}

int main(void)
{
	int local = 0;
	struct sigaction newact;
	sigset_t s, p;

	/* install my handler */
	newact.sa_handler = sig_int;
	sigaction(SIGINT, &newact, NULL);

	sigemptyset(&s);
//	sigfillset(&s);
	sigaddset(&s, SIGINT);
//	sigaddset(&s, SIGTERM);
//	sigaddset(&s, SIGQUIT);

	sigprocmask(SIG_BLOCK, &s, NULL);

	sig_int(0);
	sig_int(0);
	sig_int(0);
	
	int counter = 0;
	while (1)
	{
		counter++;
		if (counter > 5)
			sigprocmask(SIG_UNBLOCK, &s, NULL);
	//	sigpending(&p);
		printf("s = 0x%x\n", *(int *)&s);
		sleep(1);
		printf("&local = %p\n", &local);
	}

	return 0;
}
