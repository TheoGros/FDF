/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 12:05:45 by tgros             #+#    #+#             */
/*   Updated: 2017/03/03 16:28:29 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "keycode.h"

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../mlx/mlx.h"
# include <math.h>

# define DEFAULT_CASE_SIZE 32
# define W_WIDTH 1024
# define W_WIDTH_MIN 512
# define W_WIDTH_MAX 2300
# define W_HEIGHT 1024
# define W_HEIGHT_MIN 512
# define W_HEIGHT_MAX 1200

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
}				t_point;

typedef struct	s_case
{
	int			color;
	t_point		point;
}				t_case;

typedef struct	s_image
{
	void		*image;
	char		*str_image;
	int			bit;
	int			size_line;
	int			endian;
}				t_image;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			case_size;
	int			orig_size;
	char		is_color;
	int			index;
	int			color_set[4][4];
	t_point		translation;
	t_image		image;
}				t_mlx;

typedef struct	s_map
{
	t_case		**orig;
	t_case		**modif;
	t_point		pts_scale;
	t_mlx		mlx;
	char		*file_name;
	int			width;
	int			height;
}				t_map;

int				open_file(const char *file_name);
int				string_array_len(const char **tab);
int				key_released(int keycode, t_map *map);
int				key_pressed(int keycode, t_map *map);
int				red_cross(int keycode, t_map *map);
int				hex_to_int(char *hex);
int				rgb_to_int(t_point rgb);

void			init_generation(t_map *map);
void			parse_line(const char *line, char **file, int *line_size);
void			error(const char *str);
void			aff_case_tab(t_case **tab, int width);
void			free_string_tab(char **tab);
void			free_case_tab(int length, t_case **tab);
void			free_map(t_map map);
void			fill_tab(t_case ***tab, char **split_tab);
void			create_window(const char *str, t_map *map);
void			write_string(t_map *map, int x, int y, int color);
void			draw_line(t_case *a, t_case *b, t_map *m);
void			render(t_map *map);
void			copy_tab(t_map *map);
void			modify_map(t_map *map, t_point *translation);
void			generate_map(t_map *map);
void			min_max(t_map *map, t_point *min, t_point *max);
void			color_map(t_map *map, int is_set);
void			create_image(void *mlx, int width, int height, t_map *map);
void			reset_values(t_map *map);
void			reduce_z(t_map *map, t_point *min, t_point *max);

t_map			create_tab(int line_size, char *file);
t_map			read_file(const int fd);
t_point			int_to_rgb(int color);

#endif
