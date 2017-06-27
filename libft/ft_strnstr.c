/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:58:09 by tgros             #+#    #+#             */
/*   Updated: 2016/11/07 08:53:17 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verify_small_str(char *big, const char *little, size_t len,
		size_t little_len)
{
	if (little_len > len)
		return (0);
	while (*little && len)
	{
		if (*big != *little)
			return (0);
		little++;
		big++;
		len--;
	}
	return (1);
}

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		find;
	size_t	little_len;

	find = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (*big && little_len <= len)
	{
		if (*big == little[0])
		{
			find = verify_small_str((char *)big, little, len, little_len);
			if (find)
				return ((char *)&(*big));
		}
		len--;
		big++;
	}
	return (NULL);
}
