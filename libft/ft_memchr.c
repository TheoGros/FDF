/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:40:44 by tgros             #+#    #+#             */
/*   Updated: 2016/11/06 14:51:56 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sc;

	i = 0;
	sc = (unsigned char *)s;
	while (i < n)
	{
		if (sc[i] == (unsigned char)c)
			return ((unsigned char *)&sc[i]);
		i++;
	}
	return (NULL);
}
