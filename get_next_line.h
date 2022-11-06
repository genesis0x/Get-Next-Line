/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:41:50 by hahadiou          #+#    #+#             */
/*   Updated: 2022/11/03 14:57:50 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_buffer
{
	char	*buf;
	size_t	pos;
	size_t	size;
}	t_buffer;

typedef t_buffer	t_line_buffer;
typedef t_buffer	t_read_buffer;

char	*get_next_line(int fd);
// char *gnl(int fd);
// int BBN(char *s, char c);
// char *join(char *s1, char *s2);
// char *strjoin_li_makadir_walo(char *s1, char *s2);
// char *ft_read_file(int fd, char *ret);
// int ft_strchr(char *s, int c);
// char *ft_strjoin(char  *s1, char *s2);
// char *ft_get_line(char *buffer);
// char *ft_get_next_line(char *buffer);
// int ft_strlen(char *s);
// void	*ft_calloc(size_t count, size_t size);
// void	*ft_memset(void *b, int c, size_t len);
// void	ft_bzero(void *s, size_t n);
// char *ft_join_and_free(char *ret, char *buffer);
// char *gnl(int fd);
// char *ft_get_next_line_v3(int fd);
// void ft_saw(char *s);
void	*ft_memcpy(void	*dst, const void	*src, size_t	n);
void	free_read_buffer(t_read_buffer *prb);

#endif
