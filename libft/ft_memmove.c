/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:10:15 by tgros             #+#    #+#             */
/*   Updated: 2016/11/07 15:18:45 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdst;
	char	*csrc;

	cdst = (char *)dst;
	csrc = (char *)src;
	if (src < dst)
	{
		cdst += len - 1;
		csrc += len - 1;
		while (len--)
			*cdst-- = *csrc--;
	}
	else
	{
		while (len--)
			*cdst++ = *csrc++;
	}
	return (dst);
}
