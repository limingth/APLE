#include <stdio.h>
#include <signal.h>

void myhandler(int signo)
{
	printf("myhandler called\n");
	return;
}

int main(void)
{
	struct sigaction newact;
	int ret;

	newact.sa_handler = myhandler;
	sigaction(SIGINT, &newact, NULL);

	printf("pause begin!\n");
	ret = pause();
	printf("pause end!, ret = %d\n", ret);

	return 0;
}
