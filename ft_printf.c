/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:38:19 by lcaitlyn          #+#    #+#             */
/*   Updated: 2021/11/15 17:36:30 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit(int d)
{
	char	*s;
	int		l;

	s = ft_itoa(d);
	if (!s)
		return (0);
	ft_putstr(s);
	l = ft_strlen(s);
	free(s);
	return (l);
}

int	ft_hex_checker(unsigned int d, char x)
{
	if (x == 'u')
	{
		if (d > 0)
			return (ft_unsigned_int(d));
	}
	if (d == 0)
	{
		ft_putchar('0');
		return (1);
	}
	else if (x == 'x')
		return (ft_hexadecimal(d, 0));
	else if (x == 'X')
		return (ft_hexadecimal(d, 1));
	else
		return (0);
}

int	ft_print_str(const char *ap)
{
	if (!ap)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(ap);
	return (ft_strlen(ap));
}

int	ft_arg_checker(va_list *ap, char x)
{
	if (x == 'd' || x == 'i')
		return (ft_print_digit(va_arg(*ap, int)));
	else if (x == 'c')
	{
		ft_putchar((char)va_arg(*ap, int));
		return (1);
	}
	else if (x == 's')
		return (ft_print_str(va_arg(*ap, const char *)));
	else if (x == 'p')
	{
		ft_putstr("0x");
		return (ft_hexadecimal(va_arg(*ap, unsigned long), 0) + 2);
	}
	else if (x == 'x' || x == 'X' || x == 'u')
		return (ft_hex_checker(va_arg(*ap, unsigned long), x));
	else if (x == '%')
		return (ft_put_char('%'));
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		l;
	va_list	ap;

	va_start(ap, s);
	i = 0;
	l = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (ft_strchr("cspdiuxX%", s[i]))
				l += ft_arg_checker(&ap, s[i]);
			else
				i--;
		}		
		else
			l = l + ft_put_char (s[i]);
		i++;
	}
	va_end(ap);
	return (l);
}
