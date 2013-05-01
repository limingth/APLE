#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int ret = 0;
	//char *argv[] = {"ls", "-l", "-i", "-a", NULL};
	char *argv[] = {"./a.out", "100", "200", NULL};
	char *env[] = {"USER=aka", NULL};

	printf("before exec \n");

//	ret = execlp("ls", "ls", "-a", NULL);
//	ret = execvp("ls", argv);
	ret = execvpe("./a.out", argv, env);
//	ret = execvp("./a.out", argv);
	printf("after exec ret = %d\n", ret);

	if (fork() == 0)
		ret = execl("./a.out", "./add", "100", "200", NULL);

	sleep(1);

	if (fork() == 0)
		ret = execl("./a.out", "./sub", "100", "200", NULL);

	printf("after exec ret = %d\n", ret);

	return 0;
}
