/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:22:20 by tgros             #+#    #+#             */
/*   Updated: 2016/11/06 14:25:52 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verify_small_str(char *start, const char *little)
{
	while (*little)
	{
		if (*start != *little)
		{
			return (0);
		}
		little++;
		start++;
	}
	return (1);
}

char		*ft_strstr(const char *big, const char *little)
{
	int		find;

	find = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (*big)
	{
		if (*big == little[0])
		{
			find = verify_small_str((char *)big, little);
			if (find)
				return ((char *)&(*big));
		}
		big++;
	}
	return (NULL);
}
