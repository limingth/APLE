#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int msg = 0;

#define MAKE_HANDLER(x)		\
	void myhandler##x(int signo)\
	{ \
		/*printf("pid: %d  myhandler" #x " : %d\n", getpid(), signo); */\
		msg = x;\
	}

MAKE_HANDLER(0);
MAKE_HANDLER(1);
MAKE_HANDLER(2);

int signo[3] = { SIGQUIT, SIGUSR1, SIGUSR2 };
void (*handler[3])(int signo) = { myhandler0, myhandler1, myhandler2 };

int send(pid_t pid, int msg)
{
	printf("send %d \n", msg);
	kill(pid, signo[msg]);
}

int install_handler(int signo[], void (*handler[])(int signo))
{
	int i;

	for (i = 0; i < 3; i++)
	{
		struct sigaction newact;

		newact.sa_handler = handler[i];
		sigemptyset(&newact.sa_mask);
		newact.sa_flags = 0;
		sigaction(signo[i], &newact, NULL);
	}
	return 0;
}

int get_rand(void)
{
	return rand() % 3;
}

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

	printf("father: %d  vs   child: %d\n", father, child);

	if (cmp(father, child) > 0)
		fwins++;
	else if (cmp(father, child) < 0)
		cwins++;

	printf("\t\t\t(%d vs %d)\n", fwins, cwins);

	if (fwins < 2 && cwins < 2)
		return 0;

	if (fwins == 2)
		printf("father wins!\n");

	if (cwins == 2)
		printf("child wins!\n");

	return 1;
}



int main(void)
{
	pid_t pid;
	install_handler(signo, handler);

	if ((pid = fork()) == 0)
	{
		printf("child pid is %d\n", getpid());

		while (1)
		{
			send(getppid(), get_rand());
		//	sleep(1);
		}
	}
	else
	{
		printf("father pid is %d\n", getpid());
		srand(time(NULL));
		while (1)
		{
			pause();
			printf("msg = %d\n", msg);
			if (judge(get_rand(), msg))
			{
				kill(pid, SIGTERM);
				exit(0);
			}
		}
		printf("child is end\n");
	}

	return 0;
}
