/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 12:02:52 by tgros             #+#    #+#             */
/*   Updated: 2017/01/07 14:32:57 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Init all the values at the very begininng
*/

void	init_value(t_map *map)
{
	map->mlx.width = W_WIDTH_MIN;
	map->mlx.height = W_HEIGHT_MIN;
	map->mlx.case_size = DEFAULT_CASE_SIZE;
	map->pts_scale.x = 0.0f;
	map->pts_scale.y = 0.01f;
	map->pts_scale.z = 1.0f;
	map->mlx.translation.x = 0.0f;
	map->mlx.translation.y = 0.0f;
	map->mlx.is_color = 1;
	map->mlx.index = 4;
	map->mlx.image.image = NULL;
	map->mlx.image.str_image = NULL;
	map->mlx.mlx = NULL;
	map->modif = NULL;
}

/*
**	Init the color set depending on the altitude
*/

void	init_color_set(t_map *map)
{
	map->mlx.color_set[0][0] = 0x37574B;
	map->mlx.color_set[0][1] = 0x48D4C6;
	map->mlx.color_set[0][2] = 0x48D4C6;
	map->mlx.color_set[0][3] = 0x51F0E0;
	map->mlx.color_set[1][0] = 0xE80B00;
	map->mlx.color_set[1][1] = 0xE8005D;
	map->mlx.color_set[1][2] = 0xFF00AE;
	map->mlx.color_set[1][3] = 0xFF62AE;
	map->mlx.color_set[2][0] = 0x0017DF;
	map->mlx.color_set[2][1] = 0x2900F5;
	map->mlx.color_set[2][2] = 0x0D55FB;
	map->mlx.color_set[2][3] = 0x0DA8FB;
	map->mlx.color_set[3][0] = 0x0924A9;
	map->mlx.color_set[3][1] = 0x0D81FF;
	map->mlx.color_set[3][2] = 0x32CD32;
	map->mlx.color_set[3][3] = 0x359220;
}

/*
**	Display all the keyboard controls
*/

void	print_controls(void)
{
	ft_putendl("\n");
	ft_putendl("####################### CONTROLS ########################");
	ft_putendl("Rotate:\t\t\t\tA - D");
	ft_putendl("Change rotation angle:\t\tQ - E");
	ft_putendl("Change z-proportion:\t\tPageUp - PageDown");
	ft_putendl("Zoom in - zoom out:\t\t+ and - (NumPad)");
	ft_putendl("Translation x - y:\t\tRight - Left - Up - Down");
	ft_putendl("Enable / Disable the colors:\tC");
	ft_putendl("Change the color set:\t\t< - >");
	ft_putendl("Reset all the values:\t\tR - Space");
	ft_putendl("\nPress Escape or click the red cross to quit...");
	ft_putendl("#########################################################");
}

/*
**	Open, read, create the matrix and launch the drawing part
*/

void	fdf(const char *file_name)
{
	int		fd;
	t_map	map;

	fd = open_file(file_name);
	ft_putendl("======================== fdf ============================");
	ft_putstr("Reading the file: ");
	ft_putendl(file_name);
	map = read_file(fd);
	init_value(&map);
	map.file_name = ft_strdup(file_name);
	copy_tab(&map);
	init_generation(&map);
	init_color_set(&map);
	ft_putendl("Rendering...");
	create_window(file_name, &map);
	ft_putendl("Ready!");
	print_controls();
	render(&map);
	mlx_loop(map.mlx.mlx);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("usage: ./fdf <file>", 2);
		exit(1);
	}
	fdf(argv[1]);
	return (0);
}
