/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:30:20 by tgros             #+#    #+#             */
/*   Updated: 2016/11/05 11:23:18 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*new_str;
	size_t	i;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * size + 1);
	if (!new_str)
		return (NULL);
	while (i <= size)
	{
		new_str[i] = '\0';
		i++;
	}
	return (new_str);
}
