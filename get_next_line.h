/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:41:50 by hahadiou          #+#    #+#             */
/*   Updated: 2022/11/09 17:03:28 by hahadiou         ###   ########.fr       */
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
void	*ft_memcpy(void	*dst, const void	*src, size_t	n);
void	free_read_buffer(t_read_buffer *prb);

#endif
