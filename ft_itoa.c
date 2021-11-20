/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:53:27 by lcaitlyn          #+#    #+#             */
/*   Updated: 2021/10/27 15:53:29 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dgtcnt(long nl, int sign)
{
	int	i;

	i = 0;
	if (nl == 0)
		return (1);
	while (nl > 0)
	{
		nl = nl / 10;
		i++;
	}
	return (i + sign);
}

char	*ft_convert(char *s, long nl, int sign)
{
	int	i;
	int	len;

	i = 0;
	len = ft_dgtcnt(nl, sign);
	s[--len] = nl % 10 + '0';
	nl = nl / 10;
	while (nl > 0)
	{
		len--;
		s[len] = nl % 10 + '0';
		nl = nl / 10;
	}
	if (sign == 1)
		s[0] = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	nl;
	int		sign;
	int		i;

	i = 0;
	sign = 0;
	if (n < 0)
	{
		nl = (long)n * -1;
		sign = 1;
	}
	else
		nl = (long)n;
	s = ft_calloc((ft_dgtcnt(nl, sign) + 1), sizeof(char));
	if (!s)
		return (NULL);
	return (ft_convert(s, nl, sign));
}
