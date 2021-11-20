/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:51:57 by lcaitlyn          #+#    #+#             */
/*   Updated: 2021/10/27 15:51:59 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;

	s = (void *)malloc((count) * size);
	if (!s)
		return (NULL);
	s[0] = '\0';
	ft_bzero (s, count * size);
	return (s);
}
