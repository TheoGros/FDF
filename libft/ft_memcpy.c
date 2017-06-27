/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:32:22 by tgros             #+#    #+#             */
/*   Updated: 2016/11/06 14:09:30 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *cdst;
	char *csrc;

	if (dst == src)
		return (dst);
	cdst = (char *)dst;
	csrc = (char *)src;
	while (n > 0)
	{
		*cdst++ = *csrc++;
		n--;
	}
	return (dst);
}
