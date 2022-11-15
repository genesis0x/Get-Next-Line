/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:41:47 by hahadiou          #+#    #+#             */
/*   Updated: 2022/11/09 15:53:59 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

static char	*realloc_line_buffer(t_line_buffer *pl)
{
	char	*new_buf;
	size_t	new_size;

	new_size = pl->size + 1;
	new_buf = malloc((new_size + 1) * sizeof(char));
	if (pl->buf)
	{
		if (new_buf)
			ft_memcpy(new_buf, pl->buf, pl->size);
		free(pl->buf);
	}
	pl->buf = new_buf;
	pl->size = new_size;
	return (new_buf);
}

static char	*alloc_read_buffer(t_read_buffer *pb)
{
	if (pb->buf == 0)
	{
		pb->buf = malloc(BUFFER_SIZE * sizeof(char));
		if (pb->buf == 0)
			return (0);
		pb->pos = 0;
		pb->size = 0;
	}
	return (pb->buf);
}

static int	read_file(int fd, t_read_buffer *rb)
{
	if (rb->pos >= rb->size)
	{
		rb->size = read(fd, rb->buf, BUFFER_SIZE);
		if (rb->size < 1)
			return (0);
		rb->pos = 0;
	}
	return (rb->buf[rb->pos++]);
}

static int	put_line_char(t_line_buffer *pl, char c)
{
	if (pl->pos >= pl->size)
	{
		if (realloc_line_buffer(pl) == 0)
			return (0);
	}
	pl->buf[pl->pos++] = c;
	if (c == '\n')
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	int						c;
	t_line_buffer			line;
	static t_read_buffer	rb;

	if (fd < 0 || fd == 1 || fd == 2 || read(fd, line.buf, 0) < 0)
		return (0);
	if (!(alloc_read_buffer(&rb)))
		return (0);
	line.buf = 0;
	line.pos = 0;
	line.size = 0;
	while (1)
	{
		c = read_file(fd, &rb);
		if (c == 0)
			break ;
		if (put_line_char(&line, c) == 0)
			break ;
	}
	if (line.pos == 0)
		free_read_buffer(&rb);
	else
		line.buf[line.pos] = 0;
	return (line.buf);
}
