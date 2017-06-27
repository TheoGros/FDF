/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 12:32:09 by tgros             #+#    #+#             */
/*   Updated: 2017/01/24 09:42:39 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Open the file and check the fd. Exit if an error occurs.
*/

int		open_file(const char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror(file_name);
		exit(1);
	}
	return (fd);
}

void	reading_error(char *str, int fd)
{
	ft_putendl_fd(str, 2);
	close(fd);
	exit(1);
}

/*
**	Read the file and return the data structure that contains the parsed map.
*/

t_map	read_file(const int fd)
{
	char	*line;
	char	*file;
	int		line_size;
	int		nb_line;
	t_map	map;

	line = NULL;
	file = NULL;
	line_size = -1;
	nb_line = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (line == NULL || ft_strlen(line) == 0)
			error("Empty line");
		nb_line++;
		parse_line(line, &file, &line_size);
		free(line);
	}
	if (!line)
		reading_error("No data found.", fd);
	else if (nb_line < 1 || (line_size == 1 && nb_line == 1))
		reading_error("Not enough coords.", fd);
	map = create_tab(line_size, file);
	free(file);
	return (map);
}
