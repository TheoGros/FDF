/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 11:45:50 by tgros             #+#    #+#             */
/*   Updated: 2017/01/13 10:43:21 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Get the color in the little str string
*/

int		get_color(char *str)
{
	char	*pos;
	int		color;

	pos = ft_strchr(str, ',');
	if (pos)
	{
		if (pos - str > 8)
			error("Number too large");
		color = hex_to_int(str);
	}
	else
	{
		if (ft_strlen(str) > 8)
			error("Number too large");
		color = 0xFAFAFA;
	}
	return (color);
}

/*
**	Fill up the tab with the point, color etc. depending on the string tab
*/

void	fill_tab(t_case ***tab, char **split_tab)
{
	int		i;
	int		j;
	char	**line;

	i = 0;
	while ((*tab)[i])
	{
		j = 0;
		line = ft_strsplit(split_tab[i], ' ');
		while (line[j])
		{
			(*tab)[i][j].point.x = j;
			(*tab)[i][j].point.y = i;
			(*tab)[i][j].point.z = ft_atoi(line[j]);
			(*tab)[i][j].color = get_color(line[j]);
			j++;
		}
		free_string_tab(line);
		if (j == 0)
			error("Empty line");
		i++;
	}
}

/*
**	Malloc the t_case tab with the calculated width / height values
*/

t_map	create_tab(int line_size, char *file)
{
	t_map	map;
	char	**split_tab;
	int		nb_line;
	int		i;

	i = -1;
	split_tab = ft_strsplit(file, '|');
	if (!split_tab)
		error("Unexpected error");
	nb_line = string_array_len((const char **)split_tab);
	map.orig = (t_case **)malloc(sizeof(t_case *) * (nb_line + 1));
	if (!map.orig)
		error("Unexpected error");
	while (++i < nb_line)
	{
		map.orig[i] = (t_case *)malloc(sizeof(t_case) * line_size);
		if (!map.orig[i])
			free_case_tab(i, map.orig);
	}
	map.orig[i] = NULL;
	fill_tab(&map.orig, split_tab);
	free_string_tab(split_tab);
	map.width = line_size;
	map.height = nb_line;
	return (map);
}

/*
**	Split the line to check the validity && copy into the file variable(string)
**	Character used for the separation = '|'
*/

void	parse_line(const char *line, char **file, int *line_size)
{
	char	*cur;
	char	**coord_tab;
	int		i;

	i = 0;
	coord_tab = ft_strsplit((char *)line, ' ');
	if (!coord_tab)
		error("Unexpected error");
	else if (*line_size == -1)
		*line_size = string_array_len((const char **)coord_tab);
	else if (string_array_len((const char **)coord_tab) != *line_size)
	{
		free_string_tab(coord_tab);
		error("Invalid file");
	}
	if (!*file)
		*file = ft_strnew(1);
	cur = *file;
	*file = ft_strjoin(*file, "|");
	free(cur);
	cur = *file;
	*file = ft_strjoin(*file, line);
	free(cur);
	free_string_tab(coord_tab);
}
