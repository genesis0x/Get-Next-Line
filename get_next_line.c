#include "get_next_line.h"

void	free_read(t_read_buffer *fr)
{
	if (fr->buf)
	{
		free(fr->buf);
		fr->buf = 0;
	}
}

void	*ft_memcpy(void	*dst, void *src, int n)
{
	char *in_dst;
	char *in_src;

	if (!dst && !src)
		return 0;
	in_dst = (char *)dst;
	in_src = (char *)src;
	while (n-- > 0)
		*in_dst++ = *in_src++;
	return dst;
}

char	*read_c(t_buffer	*rb, int fd)
{
	rb->pos = 0;
	rb->size = 0;
	if (rb->pos >= rb->size)
	{
		rb->size = read(fd, rb->buf, BUFFER_SIZE);
		if (rb->size < 0)
			return 0;
		rb->size = 0;
	}
	rb->size++;
	return (rb->buf);
}

char	*read_c(t_buffer *rb, int fd);
char	*alloc_read_buffer(t_buffer *rb)
{
	if (rb->buf == 0)
	{
		rb->buf = malloc(sizeof(char) * BUFFER_SIZE);
		if (!rb->buf)
			return 0;
		rb->pos = 0;
		rb->size = 0;
	}
	//rb->buf = read_c(rb, fd);
	return (rb->buf);
}

char	*realloc_line_buffer(t_line_buffer	*plb)
{
	char	*new_buf;
	size_t	new_size;

	new_size = plb->size + BUFFER_SIZE;
	new_buf = malloc(sizeof(char) * (new_size + 1));
	if (plb->buf != NULL)
	{
		if (new_buf != NULL)
			ft_memcpy(new_buf, plb->buf, plb->size);
		free(plb->buf);
	}
	plb->buf = new_buf;
	plb->size = new_size;
	return (new_buf);
}

/*int	put_line(t_line_buffer *pl, char *s)
{
	if (pl->pos >= pl->size)
		realloc_line(pl);
	pl->buf = s;
	int i = 0;
	pl->pos++;
	while (s[i++])
		if(s[i] == '\n')
			return 0;;
	return 1;
}*/

int	put_line(t_line_buffer *plb, char s)
{
	if (plb->pos >= plb->size)
	{
		if (realloc_line_buffer(plb) == NULL)
			return (0);
	}
	//plb->pos++;
	plb->buf[plb->pos++] = s;
	//plb->buf = s;
	//int i = 0;
	//while (s[i++])
	if (s == '\n')
		return (0);
	return (1);
}

// char	*save_line(t_line_buffer *sl, char *s)
// {
// 	int i = 0;
// 	while (s[i++])
// 		sl->buf[i] = s[i];
// 	return (sl->buf);
// }

char *gnl(int fd)
{
	t_line_buffer line;
	char *hold;
	static t_read_buffer stc[BUFFER_SIZE];
//	line = malloc(sizeof(t_buffer));
	alloc_read_buffer(stc);
	line.buf = 0;
	line.size =0;
	line.pos = 0;
	int i = 0;
	hold = read_c(stc, fd);
	while (1)
	{
		//hold = read_c(&stc[fd], fd);
		//if (hold == 0)
		//	break ;
		if (put_line(&line, hold[i++]) == 0)
			break ;
			//else
				//put_line(&line, hold[i]);
	}
	if (line.pos == 0)
		free_read(stc);
	else
		line.buf[line.pos] = 0;
	return(line.buf);
}

int main(void)
{
	int fd = open("file", O_RDONLY);
	//t_buffer *s;
	//s = malloc(sizeof(t_buffer));
	printf("%s", gnl(fd));
	//printf("%s", gnl(fd));
	return 0;
}


/*
int main()
{
	int fd = open("file", O_RDONLY);
	t_buffer *s;
	s = malloc(sizeof(t_buffer));
	s->buf = malloc(100);
	printf("%s", read_c(s, fd));
	return 0;
}
char	*realloc_line(t_buffer *rl)
{
	char	*new_buf;
	int		new_size;

	new_size = rl->size + rl->pos + 1;
	new_buf = malloc(sizeof(char) * new_size);
	if (rl->buf)
	{
		if (new_buf)
			ft_memcpy(new_buf, rl->buf, rl->size);
		free(rl->buf);
	}
	rl->buf = new_buf;
	rl->size = new_size;
	return (new_buf);
}

char	put_line(t_buffer *pl, char c)
{
	if (pl->pos >= pl->size)
		if (realloc_line(pl) == 0)
			return 0;
	while (pl->buf)
	{
		pl->buf[pl->pos++] = c;
		if (c == '\n')
			return 0;
	}
	return 1;
}

char *gnl(int fd)
{
	t_buffer *s;
	s = malloc(sizeof(t_buffer));
	char *d;

char *get_next_line(int fd)
{
	int c;
	t_buffer *line;
	static t_buffer *r[BUFFER_SIZE];

	if (fd < 0)
		return 0;
	if (!(alloc_read_buffer(&r)))
		return 0;
	line->buf = 0;
	line->pos = 0;
	line->size = 0;
	while (1)
	{
		c = read_c(fd, r[fd]);
		if (c == 0)
			break ;
		if (put_line(line, c) == 0)
			break;
	}
	return (line->buf);
}*/
