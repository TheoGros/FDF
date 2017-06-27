/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:45:41 by tgros             #+#    #+#             */
/*   Updated: 2017/01/08 14:53:13 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Convert a hex string (0x... format) to int
*/

int		hex_to_int(char *num)
{
	int len;
	int res;
	int ind;

	if (!num)
		return (-1);
	ind = 0;
	res = 0;
	len = ft_strlen(num);
	len--;
	while (ft_toupper(num[len]) != 'X')
	{
		if (num[len] >= '0' && num[len] <= '9')
			res += (num[len] - '0') * pow(16, ind);
		else if (ft_toupper(num[len]) >= 'A' && ft_toupper(num[len]) <= 'F')
			res += (ft_toupper(num[len]) - 'A' + 10) * pow(16, ind);
		ind++;
		len--;
	}
	return (res);
}

/*
**	Takes a hex (int) color and return the rgb value
*/

t_point	int_to_rgb(int color)
{
	t_point rgb;

	rgb.x = (color & 0x00FF0000) >> 16;
	rgb.y = (color & 0x0000FF00) >> 8;
	rgb.z = (color & 0x000000FF);
	return (rgb);
}

/*
**	Takes an rgb format in argument and return the hexa (int) value
*/

int		rgb_to_int(t_point rgb)
{
	int r;
	int g;
	int b;

	r = ((int)rgb.x & 0xff) << 16;
	g = ((int)rgb.y & 0xff) << 8;
	b = ((int)rgb.z & 0xff);
	return (r + g + b);
}

/*
**	Set the color in the map at the given position
*/

void	set_color_pos(t_map *map, int i, int j, int is_set)
{
	float	alt;

	if (map->mlx.is_color && is_set)
		map->modif[i][j].color = 0xFFFFFF;
	else
	{
		if (map->mlx.index == 4)
			map->modif[i][j].color = map->orig[i][j].color;
		else
		{
			alt = map->modif[i][j].point.z;
			if (alt <= 1.0)
				map->modif[i][j].color = map->mlx.color_set[map->mlx.index][0];
			else if (alt <= 20.0)
				map->modif[i][j].color = map->mlx.color_set[map->mlx.index][1];
			else if (alt <= 40.0)
				map->modif[i][j].color = map->mlx.color_set[map->mlx.index][2];
			else
				map->modif[i][j].color = map->mlx.color_set[map->mlx.index][3];
		}
	}
}

/*
**	Color the map with the current index
*/

void	color_map(t_map *map, int is_set)
{
	int		i;
	int		j;

	i = -1;
	if (!map->mlx.is_color && is_set == 0)
		return ;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			set_color_pos(map, i, j, is_set);
	}
	if (is_set)
		map->mlx.is_color = !map->mlx.is_color;
}
