/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:21:09 by tgros             #+#    #+#             */
/*   Updated: 2017/01/08 14:51:58 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	When a key is released
*/

int		key_released(int keycode, t_map *map)
{
	if (keycode == KEY_ESCAPE)
	{
		free_map(*map);
		exit(0);
	}
	return (0);
}

int		movements(int keycode, t_map *map)
{
	if (keycode == KEY_A)
		map->pts_scale.x += map->pts_scale.y;
	else if (keycode == KEY_D)
		map->pts_scale.x -= map->pts_scale.y;
	else if (keycode == KEY_E && map->pts_scale.y < 1.0f)
		map->pts_scale.y += 0.01f;
	else if (keycode == KEY_Q && map->pts_scale.y > 0.01f)
		map->pts_scale.y -= 0.01f;
	else if (keycode == KEY_RIGHT)
		map->mlx.translation.x += map->pts_scale.y * 30;
	else if (keycode == KEY_LEFT)
		map->mlx.translation.x -= map->pts_scale.y * 30;
	else if (keycode == KEY_UP)
		map->mlx.translation.y -= map->pts_scale.y * 30;
	else if (keycode == KEY_DOWN)
		map->mlx.translation.y += map->pts_scale.y * 30;
	else
		return (0);
	return (1);
}

int		color(int keycode, t_map *map)
{
	if (keycode == KEY_C)
		color_map(map, 1);
	else if (keycode == KEY_DOT)
	{
		map->mlx.index = (map->mlx.index + 1) % 5;
		color_map(map, 0);
	}
	else if (keycode == KEY_COMMA)
	{
		map->mlx.index = map->mlx.index == 0 ? 4 : map->mlx.index - 1;
		color_map(map, 0);
	}
	else
		return (0);
	return (1);
}

/*
**	Key pressed event
*/

int		key_pressed(int keycode, t_map *map)
{
	int draw;

	draw = 0;
	if (keycode == KEY_A || keycode == KEY_D || keycode == KEY_E
		|| keycode == KEY_Q || keycode == KEY_RIGHT || keycode == KEY_LEFT
		|| keycode == KEY_UP || keycode == KEY_DOWN)
		draw = movements(keycode, map);
	else if ((keycode == KEY_PAD_ADD || keycode == KEY_EQUAL) && (draw = 1))
		map->mlx.case_size++;
	else if ((keycode == KEY_PAD_SUB || keycode == KEY_MINUS) &&
				map->mlx.case_size > 1 && (draw = 1))
		map->mlx.case_size--;
	else if (keycode == KEY_PAGE_UP && (draw = 1))
		map->pts_scale.z += 0.1;
	else if (keycode == KEY_PAGE_DOWN && map->pts_scale.z > 0.0 && (draw = 1))
		map->pts_scale.z -= 0.1;
	else if (keycode == KEY_C || keycode == KEY_DOT || keycode == KEY_COMMA)
		draw = color(keycode, map);
	else if ((keycode == KEY_R || keycode == KEY_SPACE) && (draw = 1))
		reset_values(map);
	if (draw)
		generate_map(map);
	return (0);
}

/*
**	When the red cross is clicked
*/

int		red_cross(int keycode, t_map *map)
{
	(void)keycode;
	(void)map;
	exit(0);
	return (0);
}
