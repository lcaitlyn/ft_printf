/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:34:32 by lcaitlyn          #+#    #+#             */
/*   Updated: 2021/11/15 17:37:33 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
int		ft_toupper(int a);
size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
int		ft_put_char(char c);
void	ft_putnbr(int n);
void	ft_putstr(const char *s);
void	*ft_bzero(void *src, size_t b);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlcpy(char *dst, const char *src, size_t size);
void	rev_print(char *s);
int		ft_hexadecimal(unsigned long long d, int x);
char	*ft_itoa(int n);
int		ft_unsigned_int(unsigned int d);
char	*ft_strchr(const char *str, int a);

#endif
