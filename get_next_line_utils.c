/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:41:44 by hahadiou          #+#    #+#             */
/*   Updated: 2022/10/30 22:30:57 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*in_dst;
	unsigned char	*in_src;

	if (!dst && !src)
		return (NULL);
	in_dst = (unsigned char *)dst;
	in_src = (unsigned char *)src;
	while (n-- > 0)
		*in_dst++ = *in_src++;
	return (dst);
}

void	free_read_buffer(t_read_buffer *prb)
{
	if (prb->buf != 0)
	{
		free(prb->buf);
		prb->buf = 0;
	}
}
