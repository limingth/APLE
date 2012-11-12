#include <unistd.h>

char msg[14] = "hello, world!\n";

int main(void)
{
	write(1, msg, 14);
	
	_exit(0);
}
