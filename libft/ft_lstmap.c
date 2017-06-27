/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:16:39 by tgros             #+#    #+#             */
/*   Updated: 2016/11/07 18:04:30 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	liberer(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		tmp = lst->next;
		free(lst->content);
		lst = NULL;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tete;
	t_list	*list;
	t_list	*tmp;
	int		premier;

	premier = 1;
	tete = NULL;
	while (lst)
	{
		list = ft_lstnew((f(lst))->content, (f(lst)->content_size));
		if (!list)
			liberer(tete);
		if (premier)
		{
			premier = 0;
			tete = list;
			tmp = list;
		}
		else
			tmp->next = list;
		tmp = list;
		lst = lst->next;
		list = list->next;
	}
	return (tete);
}
