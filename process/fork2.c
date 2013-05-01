#include <stdio.h>
#include <unistd.h>

int global = 100;

int main(void)
{
	pid_t pid;


	printf("before fork\n");
//	printf("global = %d\n", global);
//	printf("&global = %p\n", &global);

	pid = fork();
	printf("after fork\n");

	if (pid == 0)
	{
		global = 300;
		printf("<son> global = %d\n", global);
		printf("<son> &global = %p\n", &global);
	}
	else
	{
		sleep(1);
	//	global = 200;
		printf("<father> global = %d\n", global);
		printf("<father> &global = %p\n", &global);
	}

//	sleep(10);

	return 0;
}


