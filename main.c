#include "get_next_line.h"
#include <stdio.h>
int	main(void)
{
	int	fd;
	int	fd2;

	fd = open("open_close_open.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	fd = open("open_close_open.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
