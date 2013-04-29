#include <sys/ioctl.h>
#include <stdio.h>

int main(void)
{
	struct winsize size;

	ioctl(1, TIOCGWINSZ, &size);

	printf("row %d, col %d\n", size.ws_row, size.ws_col);
	printf("xp %d, yp %d\n", size.ws_xpixel, size.ws_ypixel);

	return 0;
}
