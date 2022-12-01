/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:56:47 by hahadiou          #+#    #+#             */
/*   Updated: 2022/12/01 11:19:29 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 0
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 0
#  endif
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
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
void	*ft_memcpy(void	*dst, const void	*src, size_t	n);
void	free_buffer(t_read_buffer *prb);

#endif
