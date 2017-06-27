/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 10:27:45 by tgros             #+#    #+#             */
/*   Updated: 2017/01/09 14:34:48 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_generation(t_map *map)
{
	t_point translation;

	translation.x = 0.0f;
	translation.y = 0.0f;
	map->mlx.translation.z = 0.0f;
	modify_map(map, &translation);
}

void	generate_map(t_map *map)
{
	t_point translation;

	translation.x = 0.0f;
	translation.y = 0.0f;
	map->mlx.translation.z = 0.0f;
	mlx_clear_window(map->mlx.mlx, map->mlx.win);
	ft_bzero(map->mlx.image.str_image,
			map->mlx.image.size_line * map->mlx.height);
	modify_map(map, &translation);
	render(map);
	map->mlx.translation.z = 0.0f;
}
