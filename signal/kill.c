#include <stdio.h>
#include <signal.h>

int main(int argc, char *argv[])
{
	int pid;
	int signo;

	if (argc < 3)
	{
		printf("./main pid signo\n");
		return 0;
	}

	pid = atoi(argv[1]);
	signo = atoi(argv[2]);

	printf("pid = %d, signo = %d\n", pid, signo);
	kill(pid, signo);

	return 0;
}
