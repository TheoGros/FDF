/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:15:51 by tgros             #+#    #+#             */
/*   Updated: 2016/11/06 10:17:52 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)s + ft_strlen(s);
	while (tmp != s && *tmp != (char)c)
		tmp--;
	if (*tmp == (char)c)
		return (&(*tmp));
	return (NULL);
}
