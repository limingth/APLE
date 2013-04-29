#include <stdio.h>

int main(void)
{
	int num;
	int flags;
	FILE *fp;

	fp = fopen("test0", "r+");
	if (fp != NULL)
	{
		printf("fp = %d\n", fp->_fileno);
		printf("mode = %x\n", fp->_flags);
//		return 0;
	}

	fp = fopen("test", "w+");
	if (fp != NULL)
	{
		printf("fp = %d\n", fp->_fileno);
		printf("mode = %x\n", fp->_flags);
		return 0;
	}

	num = stdin->_fileno;
	printf("num = %d\n", num);
	flags = stdin->_flags;
	printf("flags = %x\n", flags);

	num = stdout->_fileno;
	printf("num = %d\n", num);
	flags = stdout->_flags;
	printf("flags = %x\n", flags);

	num = stderr->_fileno;
	printf("num = %d\n", num);

	return 0;
}
