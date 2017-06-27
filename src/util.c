/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:56:08 by tgros             #+#    #+#             */
/*   Updated: 2017/01/14 13:23:34 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Return the "height" of a char** tab
*/

int		string_array_len(const char **tab)
{
	int ret;

	ret = 0;
	while (tab[ret])
		ret++;
	return (ret);
}

/*
**	Print a message in stderr and quit the program
*/

void	error(const char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

/*
**	Get the min and max in y / x axis in the modified map
*/

void	min_max(t_map *map, t_point *min, t_point *max)
{
	int i;
	int j;

	i = -1;
	j = -1;
	min->x = map->modif[0][0].point.x;
	min->y = map->modif[0][0].point.y;
	max->x = map->modif[0][0].point.x;
	max->y = map->modif[0][0].point.y;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->modif[i][j].point.x > max->x)
				max->x = map->modif[i][j].point.x;
			if (map->modif[i][j].point.x < min->x)
				min->x = map->modif[i][j].point.x;
			if (map->modif[i][j].point.y > max->y)
				max->y = map->modif[i][j].point.y;
			if (map->modif[i][j].point.y < min->y)
				min->y = map->modif[i][j].point.y;
		}
	}
}

/*
**	Reset all the values
*/

void	reset_values(t_map *map)
{
	map->mlx.case_size = map->mlx.orig_size;
	map->pts_scale.x = 0.0f;
	map->pts_scale.y = 0.01f;
	map->pts_scale.z = 0.0f;
	map->mlx.index = 4;
	map->mlx.translation.x = 0.0f;
	map->mlx.translation.y = 0.0f;
	map->pts_scale.z = 1.0f;
	color_map(map, 0);
}

void	reduce_z(t_map *map, t_point *min, t_point *max)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->orig[i][j].point.z /= 2;
			map->orig[i][j].point.z /= 2;
			(*min).y /= 2;
			(*max).y /= 2;
			j++;
		}
		i++;
	}
}
