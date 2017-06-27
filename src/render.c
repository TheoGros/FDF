/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 09:18:02 by tgros             #+#    #+#             */
/*   Updated: 2017/01/07 15:09:06 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Create the image with the given properties
*/

void	create_image(void *mlx, int width, int height, t_map *map)
{
	t_image *image;

	image = &map->mlx.image;
	image->image = mlx_new_image(mlx, width, height);
	if (!image->image)
		error("Unexpected error: image allocation");
	image->str_image = mlx_get_data_addr(image->image,
			&(image->bit), &(image->size_line), &(image->endian));
	if (!map->mlx.image.str_image)
		error("Unexpected error: image allocation");
}

/*
**	Init a new mlx window with the given properties
*/

void	create_window(const char *str, t_map *map)
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;

	width = map->mlx.width;
	height = map->mlx.height;
	mlx = mlx_init();
	win = mlx_new_window(mlx, width, height, str ? (char *)str : "fdf");
	map->mlx.mlx = mlx;
	map->mlx.win = win;
	mlx_key_hook(win, &key_released, map);
	mlx_hook(win, 17, 0, &red_cross, map);
	mlx_hook(win, 2, 0, &key_pressed, map);
	create_image(mlx, width, height, map);
}

void	render_line(int i, t_map *map)
{
	t_case	beg;
	t_case	col;
	t_case	line;
	int		j;

	j = -1;
	while (++j < map->width - 1)
	{
		beg = map->modif[i][j];
		col = map->modif[i][j + 1];
		line = map->modif[i + 1][j];
		draw_line(&beg, &col, map);
		draw_line(&beg, &line, map);
	}
	beg = map->modif[i][j];
	line = map->modif[i + 1][j];
	draw_line(&beg, &line, map);
}

/*
**	Draw each edge of the map tab
*/

void	render(t_map *map)
{
	int		i;
	int		j;
	t_case	beg;
	t_case	col;

	i = -1;
	j = -1;
	while (++i < map->height - 1)
		render_line(i, map);
	while (++j < map->width - 1)
	{
		beg = map->modif[i][j];
		col = map->modif[i][j + 1];
		draw_line(&beg, &col, map);
	}
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
	map->mlx.image.image, 0, 0);
}
