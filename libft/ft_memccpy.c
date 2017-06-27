/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:31:13 by tgros             #+#    #+#             */
/*   Updated: 2016/11/05 15:31:45 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*cdst;
	const unsigned char	*csrc;
	unsigned char		occur;

	cdst = dst;
	csrc = src;
	occur = c;
	while (n != 0)
	{
		if ((*cdst++ = *csrc++) == occur)
			return (cdst);
		n--;
	}
	return (NULL);
}
