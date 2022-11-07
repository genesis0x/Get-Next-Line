#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

typedef	struct s_bricole{
	int size;
	int pos;
	char *buf;
}	t_buffer;

typedef t_buffer t_line_buffer;
typedef t_buffer t_read_buffer;

char	*get_next_line(int fd);

#endif
