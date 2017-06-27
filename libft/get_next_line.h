/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 08:59:31 by tgros             #+#    #+#             */
/*   Updated: 2017/01/13 10:45:56 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 4096

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct		s_file
{
	int				fd;
	int				eof;
	int				done;
	char			*str;
	struct s_file	*next;
}					t_file;

int					get_next_line(const int fd, char **line);

#endif
