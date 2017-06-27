/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:38:27 by tgros             #+#    #+#             */
/*   Updated: 2016/11/08 09:42:45 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	int		i;
	int		max;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	max = (size - 1) - dst_len;
	while (src[i] && i < max)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	i = src_len + dst_len + max + 1;
	return (i < (int)(src_len + dst_len) ? i : src_len + dst_len);
}
