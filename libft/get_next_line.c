/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 08:59:37 by tgros             #+#    #+#             */
/*   Updated: 2016/11/28 12:04:39 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*resize_str(char *str, char buf[])
{
	int		len;
	char	*tmp;

	len = str ? ft_strlen(str) : 0;
	tmp = (char *)malloc(sizeof(char) * (len + BUFF_SIZE) + 1);
	if (!tmp)
		return (NULL);
	if (str)
	{
		ft_strcpy(tmp, str);
		free(str);
	}
	ft_strcpy(tmp + len, buf);
	return (tmp);
}

static t_file	*find_read(t_file *head, int fd)
{
	t_file *tmp;
	t_file *cursor;

	if ((cursor = head) && head)
	{
		while (cursor->next && cursor->fd != fd)
			cursor = cursor->next;
		if (cursor->fd == fd)
		{
			cursor->eof = (!cursor->str || cursor->done) ? 0 : cursor->eof;
			if (cursor->str == NULL && (cursor->done = 0))
				return (cursor);
			else if (cursor->done == 1 && (cursor->str = NULL))
				return (NULL);
			return (cursor);
		}
	}
	tmp = (t_file*)malloc(sizeof(t_file));
	tmp->str = NULL;
	tmp->next = NULL;
	if (head)
		cursor->next = tmp;
	return (tmp);
}

static int		read_buf(t_file **head, char buf[], int fd)
{
	int ret;

	while (!(*head)->eof && (!(*head)->str || !ft_strchr((*head)->str, '\n')))
	{
		ft_bzero(buf, BUFF_SIZE);
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		if (ret != BUFF_SIZE && ((*head)->eof = 1))
		{
			if ((*head)->str && !ft_strlen((*head)->str) && !ft_strlen(buf))
			{
				(*head)->str = NULL;
				(*head)->done = 1;
				return (0);
			}
		}
		buf[ret] = '\0';
		(*head)->str = resize_str((*head)->str, buf);
	}
	if ((*head)->eof && ft_strlen((*head)->str) == 0 && ((*head)->done = 1))
	{
		(*head)->str = NULL;
		return (0);
	}
	return (1);
}

static void		set_line(int ret, char **line, t_file **head)
{
	char	*tmp;

	if (ret == -1)
	{
		*line = ft_strdup((*head)->str);
		(*head)->done = 1;
	}
	else
	{
		*line = ft_strnew(ret);
		ft_strncpy(*line, (*head)->str, ret);
		tmp = ft_strdup((*head)->str + ret + 1);
		free((*head)->str);
		(*head)->str = tmp;
		if ((*head)->eof == 1 && ft_strlen((*head)->str) == 0)
			(*head)->done = 1;
	}
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*cur;
	t_file			*head;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	head = find_read(cur, fd);
	if (head == NULL)
		return (0);
	else if (head && head->str == NULL && (head->eof = 0))
		head->done = 0;
	head->fd = fd;
	if (!cur)
		cur = head;
	if (head->done == 1)
		return (0);
	ret = read_buf(&head, buf, fd);
	if (ret == -1 || ret == 0)
		return (ret);
	tmp = ft_strchr(head->str, '\n');
	ret = tmp ? tmp - head->str : -1;
	set_line(ret, line, &head);
	return (1);
}
