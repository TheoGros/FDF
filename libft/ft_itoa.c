/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:12:00 by tgros             #+#    #+#             */
/*   Updated: 2016/11/09 10:19:59 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	void	reverse(char *str)
{
	char tmp;
	char *end;

	end = str + ft_strlen(str) - 1;
	while (str < end)
	{
		tmp = *str;
		*str = *end;
		*end = tmp;
		str++;
		end--;
	}
}

static char		*get_str(char *str, int n, int is_neg)
{
	const char *tmp;

	tmp = str;
	while (n != 0)
	{
		*str = (n % 10) + '0';
		n /= 10;
		str++;
	}
	if (is_neg)
	{
		*str = '-';
		str++;
	}
	if (n == 0)
		*str = '0';
	return ((char *)tmp);
}

char			*ft_itoa(int n)
{
	int		is_neg;
	int		tmp;
	int		size;
	char	*res;

	size = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_neg = n < 0 ? 1 : 0;
	tmp = n;
	while (tmp /= 10)
		size++;
	res = (char *)malloc(sizeof(char) * size + is_neg + 1);
	if (!res)
		return (NULL);
	if (is_neg)
	{
		*res = '-';
		n *= -1;
	}
	get_str(res, n, is_neg);
	res[size + is_neg] = '\0';
	reverse(res);
	return (res);
}
