/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:14:50 by tgros             #+#    #+#             */
/*   Updated: 2016/11/03 17:45:39 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dup;

	if (!(dup = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	dup = ft_strcpy(dup, s1);
	return (dup);
}
