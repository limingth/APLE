#include <stdio.h>
#include <signal.h>

void myhandler(int signo)
{
	printf("myhandler called\n");
	return;
}

int mysleep(int sec)
{
	struct sigaction newact, oldact;
	sigset_t newmask, oldmask;
	sigset_t suspmask;
	int i;

	/* step 0: install handler */
	newact.sa_handler = myhandler;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;
	sigaction(SIGALRM, &newact, &oldact);

	/* step 1: block SIGALRM */
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGALRM);
	sigprocmask(SIG_BLOCK, &newmask, &oldmask);

	/* step 2: alarm(n) */
	printf("alarm called\n");
	alarm(sec);
/*
	for (i = 0; i < 1000000000; i++)
		;
 */
/*
	printf("pause called\n");
	pause();
*/
	/* step 3: sigsuspend = unblock + pause() */
	suspmask = oldmask;
	sigdelset(&suspmask, SIGALRM);
	sigsuspend(&suspmask);

	/* restore oldact */
	sigaction(SIGALRM, &oldact, NULL);
	sigprocmask(SIG_SETMASK, &oldmask, NULL);

	return 1;
}

int main(void)
{
	int counter = 0;
	int ret;

	while (1)
	{
		printf("sleep begin!\n");
		ret = mysleep(1);
		printf("sleep end!, ret = %d\n", ret);
		
		counter++;
		#if 1
		if (counter > 3)
		{
			break;
		}
		#endif
	}

	printf("alarm 2\n");
	alarm(2);

	while (1)
		printf("...\n");

	return 0;
}
