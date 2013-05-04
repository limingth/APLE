#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sig_chld(int signo)
{
	int status;
	printf("my sig int handler\n");
	wait(&status);
	printf("status %x\n", status);
	exit(0);
}

int main(void)
{
	if (fork() == 0)
	{
		printf("child process\n");
		sleep(5);
		printf("father, sorry\n");
		exit(54);
	}
	else
	{
		struct sigaction newact;
		/* install my handler */
		newact.sa_handler = sig_chld;
		sigaction(SIGCHLD, &newact, NULL);

		printf("father process\n");
		
		while (1)
		{
			sleep(1);
			printf("father\n");
		}
	}

	return 0;
}
