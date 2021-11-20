/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:42:42 by lcaitlyn          #+#    #+#             */
/*   Updated: 2021/11/15 16:47:16 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsign_len_counter(unsigned int d)
{
	int	l;

	l = 0;
	if (d > 0)
		l = ft_unsign_len_counter(d / 10);
	if (d > 0)
		l++;
	return (l);
}

int	ft_unsigned_int(unsigned int d)
{
	char	*set;
	char	*s;
	char	*p;
	int		l;

	set = "0123456789";
	l = ft_unsign_len_counter(d);
	s = ft_calloc(l + 1, sizeof(char));
	if (!s)
		return (0);
	p = s;
	while (l--)
	{
		*s++ = set[d % 10];
		d = d / 10;
	}
	*s = '\0';
	l = ft_strlen(p);
	rev_print(p);
	free(p);
	return (l);
}
