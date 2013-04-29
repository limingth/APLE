#include <unistd.h>

char msg[] = "hello, world\n";

//int main(void)
void _start(void)
{
	write(1, msg, 13);

	_exit(0);
}
