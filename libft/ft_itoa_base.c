/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:44:43 by tgros             #+#    #+#             */
/*   Updated: 2016/12/08 12:06:56 by tgros            ###   ########.fr       */
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

static char		*get_str(char *str, int n, int is_neg, int base)
{
	const char *tmp;

	tmp = str;
	while (n != 0)
	{
		if (n % base > 9)
			*str = (n % base) - 10 + 'a';
		else
			*str = (n % base) + '0';
		n = (n / base >> 0);
		str++;
	}
	if (is_neg && base == 10)
	{
		*str = '-';
		str++;
	}
	if (n == 0)
		*str = '0';
	return ((char *)tmp);
}

char			*ft_itoa_base(int n, int base)
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
	while (tmp /= base)
		size++;
	res = (char *)malloc(sizeof(char) * size + is_neg + 1);
	if (!res)
		return (NULL);
	if (is_neg && base == 10)
	{
		*res = '-';
		n *= -1;
	}
	get_str(res, n, is_neg, base);
	res[size + is_neg] = '\0';
	reverse(res);
	return (res);
}
