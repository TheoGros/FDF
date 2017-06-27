/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pts_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 16:32:09 by tgros             #+#    #+#             */
/*   Updated: 2017/01/07 16:47:13 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Return a point that contains the rgb increment value needed
**	to go from hex1 to hex2
*/

t_point	get_color_inc(int hex1, int hex2, t_point *color, float step)
{
	t_point step_color;
	t_point color0;
	t_point color1;

	color0 = int_to_rgb(hex1);
	color1 = int_to_rgb(hex2);
	step_color.x = (color1.x - color0.x) / step;
	step_color.y = (color1.y - color0.y) / step;
	step_color.z = (color1.z - color0.z) / step;
	color->x = color0.x;
	color->y = color0.y;
	color->z = color0.z;
	return (step_color);
}

t_point	get_inc(t_point *start, t_point *end)
{
	t_point	delta;
	t_point	inc;
	float	step;

	delta.x = end->x - start->x;
	delta.y = end->y - start->y;
	if (fabs(delta.x) > fabs(delta.y))
		step = fabs(delta.x);
	else
		step = fabs(delta.y);
	inc.x = delta.x / step;
	inc.y = delta.y / step;
	inc.z = step;
	return (inc);
}

/*
**	Allow to write at the x;y position in the mlx image string
*/

void	write_string(t_map *map, int x, int y, int color)
{
	char	*str_image;
	int		pos;
	t_point	rgb_color;

	if (y < 0 || x < 0 || y >= map->mlx.height || x >= map->mlx.width)
		return ;
	rgb_color = int_to_rgb(color);
	pos = (y * 4 * map->mlx.width) + (x * 4);
	str_image = map->mlx.image.str_image;
	str_image[pos + 2] = rgb_color.x;
	str_image[pos + 1] = rgb_color.y;
	str_image[pos] = rgb_color.z;
	str_image[pos + 3] = 0;
}

/*
**	Draw a line from the start point to the end point, using the DDA algorithm
*/

void	draw_line(t_case *start, t_case *end, t_map *map)
{
	t_point	inc;
	t_point	coord;
	t_point step_color;
	t_point color;
	int		i;

	i = 0;
	inc = get_inc(&start->point, &end->point);
	coord.x = start->point.x;
	coord.y = start->point.y;
	step_color = get_color_inc(start->color, end->color, &color, inc.z);
	while (i < inc.z - 1)
	{
		coord.x += inc.x;
		coord.y += inc.y;
		color.x += step_color.x;
		color.y += step_color.y;
		color.z += step_color.z;
		coord.z = rgb_to_int(color);
		write_string(map, coord.x, coord.y, (int)coord.z);
		i++;
	}
}
