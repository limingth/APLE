#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int msg = 0;

#define MAKE_HANDLER(x)		\
	void myhandler##x(int signo)\
	{ \
		/* printf("pid: %d  myhandler" #x " : %d\n", getpid(), signo); */\
		msg = x;\
	}

MAKE_HANDLER(0);
MAKE_HANDLER(1);
MAKE_HANDLER(2);

int signo[3] = { SIGQUIT, SIGUSR1, SIGUSR2 };
void (*handler[3])(int signo) = { myhandler0, myhandler1, myhandler2 };

int send(pid_t pid, int msg)
{
//	printf("send to pid = %d, msg = %d \n", pid, msg);
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

char name[][16] = { "child", "father" };

int judge(int father, int child)
{
	static int fwins = 0;
	static int cwins = 0;

//	printf("<%d> father: %d  vs   child: %d\n", getpid(), father, child);

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

void playing_with(pid_t opid, int id)
{
	while (1)
	{
		int tmp = get_rand();
		sigset_t newmask, oldmask, suspmask;

		/* block 3 signals and save mask */
		sigemptyset(&newmask);
		sigaddset(&newmask, signo[0]);
		sigaddset(&newmask, signo[1]);
		sigaddset(&newmask, signo[2]);
		sigprocmask(SIG_BLOCK, &newmask, &oldmask);

		/* usleep to make sure another process to run to send */
		usleep(1000*10);
		send(opid, tmp);
		printf("%s: %d\n", name[id], tmp);

		/* suspend */
		sigdelset(&suspmask, signo[0]);
		sigdelset(&suspmask, signo[1]);
		sigdelset(&suspmask, signo[2]);
		sigsuspend(&suspmask);

//		printf("pid: %d  get msg = %d\n", getpid(), msg);

		/* unblock 3 signals */
		sigprocmask(SIG_SETMASK, &oldmask, NULL);

#define SWAP(a, b)		{	a = a ^ b;  b = a ^ b;  a = a ^ b; 	}
		if (id == 0)
			SWAP(tmp, msg);

		if (judge(tmp, msg))
		{
			printf("%s process exit \n", name[id]);
			return;
		}

		if (id == 0)
			printf("------------------\n");
	}
	return;
}

int main(void)
{
	pid_t pid;

	install_handler(signo, handler);

	if ((pid = fork()) == 0)
	{
		int opid = getppid();
		printf("child pid is %d\n", getpid());

		playing_with(opid, 0);
	}
	else	// father
	{
		int opid = pid;
		printf("father pid is %d\n", getpid());
		srand(time(NULL));

		playing_with(pid, 1);
		wait();
	}

	return 0;
}
