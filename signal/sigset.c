#include <signal.h>
#include <stdio.h>

int main(void)
{
	sigset_t s, p;

	sigemptyset(&s);
//	sigfillset(&s);
	sigaddset(&s, SIGINT);
//	sigaddset(&s, SIGTERM);
//	sigaddset(&s, SIGQUIT);

	sigprocmask(SIG_BLOCK, &s, NULL);
	
	int counter = 0;
	while (1)
	{
		counter++;
		if (counter > 5)
			sigprocmask(SIG_UNBLOCK, &s, NULL);
	//	sigpending(&p);
		printf("s = 0x%x\n", s);
		sleep(1);
	}

	return 0;
}
