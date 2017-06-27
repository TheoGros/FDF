/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbignbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:56:07 by tgros             #+#    #+#             */
/*   Updated: 2016/12/01 12:28:39 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbignbr(long long int n)
{
	unsigned long long int nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	if (nb >= 10)
	{
		ft_putbignbr(nb / 10);
		ft_putchar((char)((nb % 10) + '0'));
	}
	else
		ft_putchar((char)(nb + '0'));
}
