/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:09:27 by tuaydin           #+#    #+#             */
/*   Updated: 2024/10/16 21:06:01 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	rtn;

	rtn = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
	{
		rtn += ft_putchar(*s);
		s++;
	}
	return (rtn);
}

int	ft_putptr(unsigned long val)
{
	int		count;
	char	*base;
	char	buffer[16];
	int		i;

	count = 0;
	base = "0123456789abcdef";
	if (!val)
		return (ft_putstr("0x0"));
	count += ft_putstr("0x");
	i = 0;
	while (val > 0)
	{
		buffer[i++] = base[val % 16];
		val /= 16;
	}
	while (i > 0)
		count += ft_putchar(buffer[--i]);
	return (count);
}

int	ft_puthex(unsigned long val, const char *base)
{
	int		count;
	char	buffer[16];
	int		i;

	count = 0;
	if (!val)
		return (ft_putstr("0"));
	i = 0;
	while (val > 0)
	{
		buffer[i++] = base[val % 16];
		val /= 16;
	}
	while (i > 0)
		count += ft_putchar(buffer[--i]);
	return (count);
}

int	ft_putdigit(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count += ft_putchar('-');
		count += ft_putdigit(n);
	}
	else if (n > 9)
	{
		count += ft_putdigit(n / 10);
		count += ft_putdigit(n % 10);
	}
	else if (n <= 9)
		count += ft_putchar(n + 48);
	return (count);
}
