/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:33:30 by lcaitlyn          #+#    #+#             */
/*   Updated: 2021/11/15 16:33:31 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len_counter(unsigned long long d)
{
	int	l;

	l = 0;
	if (d > 0)
		l = ft_hex_len_counter(d / 16);
	if (d > 0)
		l++;
	return (l);
}

int	ft_hex(unsigned long long d, int x)
{
	char	*set;
	char	*s;
	char	*p;
	int		l;

	set = "0123456789abcdef";
	l = ft_hex_len_counter(d);
	s = ft_calloc(l + 1, sizeof(char));
	if (!s)
		return (0);
	p = s;
	while (l--)
	{
		if (x == 1)
			*s++ = ft_toupper(set[d % 16]);
		else
			*s++ = set[d % 16];
		d = d / 16;
	}
	*s = '\0';
	l = ft_strlen(p);
	rev_print(p);
	free(p);
	return (l);
}

int	ft_hexadecimal(unsigned long long d, int x)
{
	if (!d)
	{
		ft_putchar('0');
		return (1);
	}
	else
		return (ft_hex(d, x));
}
