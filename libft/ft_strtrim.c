/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:15:56 by tgros             #+#    #+#             */
/*   Updated: 2016/11/08 11:32:15 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		beg;
	int		end;
	int		i;
	int		len;
	char	*str;

	if (!s)
		return (NULL);
	beg = 0;
	end = 0;
	i = -1;
	len = ft_strlen(s);
	while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
		beg++;
	i = 1;
	if (beg == len)
		return ((char *)ft_memalloc(1));
	while (s[len - i] == ' ' || s[len - i] == '\n' || s[len - i] == '\t')
	{
		end++;
		i++;
	}
	str = ft_strsub(s, beg, len - beg - end);
	return (str);
}
