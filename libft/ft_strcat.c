/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:23:48 by tgros             #+#    #+#             */
/*   Updated: 2016/11/06 14:23:49 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *tmp;

	tmp = s1;
	while (*s1)
		s1++;
	while ((*s1 = *s2))
	{
		s1++;
		s2++;
	}
	*s1 = '\0';
	return (tmp);
}
