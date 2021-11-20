/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:32:21 by lcaitlyn          #+#    #+#             */
/*   Updated: 2021/11/15 16:39:13 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	unsigned int	nb;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	else if (n > 2147483647)
	{
		ft_putchar('2');
		n = 147483647;
	}
	nb = (unsigned int)n;
	if (n > 9)
		ft_putnbr(nb / 10);
	ft_putchar((char)(nb % 10 + 48));
}
