
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	printf("ppid = %d\n", getppid());

	// high-level function as printf/scanf/fopen/fclose
	//exit(260);

	// low-level function as read/write/open/close
	_exit(10);

	printf("ppid = %d\n", getppid());

	return 0;
}
