/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:40:57 by tgros             #+#    #+#             */
/*   Updated: 2017/01/08 14:51:29 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Free a string array
*/

void	free_string_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

/*
**	Free the case tab
*/

void	free_case_tab(int length, t_case **tab)
{
	int i;

	i = 0;
	if (length > 0)
	{
		while (i < length)
			free(tab[i++]);
	}
	else
	{
		while (tab[i])
			free(tab[i++]);
	}
	free(tab);
}

/*
**	Free the whole map
*/

void	free_map(t_map map)
{
	free(map.file_name);
	free_case_tab(-1, map.orig);
	free_case_tab(-1, map.modif);
}
