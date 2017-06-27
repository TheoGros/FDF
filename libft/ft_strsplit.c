/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 08:48:56 by tgros             #+#    #+#             */
/*   Updated: 2016/11/08 09:23:07 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		nb_split(const char *s, char c)
{
	int current;
	int nb;

	current = 0;
	nb = 0;
	while (*s)
	{
		if (*s == c && current)
			current = 0;
		else if (*s != c && !current)
		{
			current = 1;
			nb++;
		}
		s++;
	}
	return (nb);
}

static	void	echec(char **ret)
{
	while (*ret)
	{
		free(*ret);
		ret++;
	}
	free(*ret);
	ret = NULL;
}

static	char	**process_split(const char *s, char c, char **ret)
{
	int		word_size;
	char	*tmp;
	char	**beg;

	word_size = 0;
	beg = ret;
	while (*s)
	{
		while (*s && *s != c)
		{
			word_size++;
			s++;
		}
		if (word_size != 0)
		{
			tmp = ft_strsub(s - word_size, 0, word_size);
			if (!tmp)
				echec(beg);
			*ret++ = tmp;
		}
		word_size = 0;
		while (*s == c)
			s++;
	}
	return (beg);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		nb_word;

	ret = NULL;
	if (!s)
		return (ret);
	nb_word = nb_split(s, c);
	ret = (char **)malloc(sizeof(char *) * (nb_word + 1));
	if (!ret)
		return (NULL);
	ret[nb_word] = 0;
	process_split(s, c, ret);
	return (ret);
}
