/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 12:21:45 by tgros             #+#    #+#             */
/*   Updated: 2017/01/14 13:23:56 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Create another t_case double array in order to preserve the original coords
*/

void	copy_tab(t_map *map)
{
	int i;

	i = 0;
	map->modif = (t_case **)malloc(sizeof(t_case *) * (map->height + 1));
	if (!map->modif)
		error("Unexpected error");
	while (i < map->height)
	{
		map->modif[i] = (t_case *)malloc(sizeof(t_case) * map->width);
		if (!map->modif[i])
			error("Unexpected error");
		ft_memcpy(map->modif[i], map->orig[i], sizeof(t_case) * map->width);
		i++;
	}
	map->modif[map->height] = NULL;
}

/*
**	Resize the window width length and the case_size in order to fit
**	the screen size
*/

void	resize_obj(t_map *map, t_point *delta, t_point min, t_point max)
{
	while (map->mlx.height < (int)delta->y || map->mlx.width < delta->x)
	{
		if (map->mlx.width < W_WIDTH_MAX && map->mlx.width < delta->x)
			map->mlx.width += 256;
		else if (map->mlx.height < W_HEIGHT_MAX && map->mlx.height < delta->y)
			map->mlx.height += 256;
		else if (map->mlx.case_size > 1)
			map->mlx.case_size--;
		else
			reduce_z(map, &min, &max);
		delta->x = (max.x * map->mlx.case_size) - (min.x * map->mlx.case_size);
		delta->y = (max.y * map->mlx.case_size) - (min.y * map->mlx.case_size);
	}
	map->mlx.orig_size = map->mlx.case_size;
}

/*
**	Compute the translation to center the fdf
*/

void	compute_translation(t_map *map, t_point *translation)
{
	t_point	min;
	t_point	max;
	t_point	delta;

	translation->z = 1.0f;
	min_max(map, &min, &max);
	delta.y = (max.y * map->mlx.case_size) - (min.y * map->mlx.case_size);
	delta.x = (max.x * map->mlx.case_size) - (min.x * map->mlx.case_size);
	if (!map->mlx.mlx)
		resize_obj(map, &delta, min, max);
	delta.x = ((map->mlx.width - delta.x) / 2) / map->mlx.case_size;
	delta.y = ((map->mlx.height - delta.y) / 2) / map->mlx.case_size;
	translation->x = delta.x - min.x + map->mlx.translation.x;
	translation->y = delta.y - min.y + map->mlx.translation.y;
}

/*
**	Compute the iso
*/

t_point	get_calculated_point(t_map *map, t_point *translation, int i, int j)
{
	t_point orig;
	t_point final;
	float	angle;

	orig.x = map->orig[i][j].point.x;
	orig.y = map->orig[i][j].point.y;
	orig.z = map->orig[i][j].point.z;
	orig.z *= map->pts_scale.z;
	angle = map->pts_scale.x;
	final.x = orig.x * cos(angle) - orig.y * sin(angle);
	final.y = orig.x * sin(angle) + orig.y * cos(angle);
	orig.x = final.x;
	orig.y = final.y;
	final.x = (orig.x + orig.y) + translation->x;
	final.y = (-orig.z + (1.0 / 2.0) * (orig.y - orig.x)) + translation->y;
	return (final);
}

/*
**	Get a new map, with all the modifications applied
*/

void	modify_map(t_map *map, t_point *translation)
{
	int		i;
	int		j;
	t_point	final;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			final = get_calculated_point(map, translation, i, j);
			if ((int)translation->z == 1)
			{
				final.x *= map->mlx.case_size;
				final.y *= map->mlx.case_size;
			}
			map->modif[i][j].point.x = final.x;
			map->modif[i][j].point.y = final.y;
		}
	}
	if ((int)translation->z == 1)
		return ;
	compute_translation(map, translation);
	modify_map(map, translation);
}
