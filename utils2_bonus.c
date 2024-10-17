/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:53:14 by tuaydin           #+#    #+#             */
/*   Updated: 2024/10/17 13:24:02 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_zero(t_fdata p_data, unsigned long val, int is_upper)
{
	int	count;
	int	flag;

	flag = 0;
	count = 0;
	if (p_data.ff_val != 0)
		flag = 1;
	if (val < 0)
	{
		val = -val;
		count += ft_putchar('-');
		p_data.ff_val--;
	}
	while (p_data.ff_val > ft_hexlen(val))
	{
		count += ft_putchar('0');
		p_data.ff_val--;
	}
	if (flag || val > 0)
	{
		if (is_upper)
			count += ft_puthex(val, is_upper);
		else
			count += ft_puthex(val, is_upper);
	}
	return (count);
}

int	ft_putstr_dot(t_fdata p_data, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putnull(p_data.ff_val));
	while (str[i] && i < p_data.ff_val)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putdigit_dot(t_fdata p_data, long val)
{
	int	count;

	count = 0;
	if (val < 0)
	{
		val = -val;
		count += ft_putchar('-');
	}
	while (p_data.ff_val > ft_digitlen(val))
	{
		count += ft_putchar('0');
		p_data.ff_val--;
	}
	
	if (p_data.ff_val != 0 || val > 0)
		count += ft_putdigit(val);
	return (count);
}

int	ft_puthex_sharp(t_fdata p_data, unsigned long val, int is_upper)
{
	int		count;

	count = 0;
	if (val)
	{
		if (is_upper)
			count += ft_putstr("0X");
		else
			count += ft_putstr("0x");
	}
	count += ft_puthex_minus(p_data, val, is_upper);
	return (count);
}

int	ft_putdigit_space(long val)
{
	int	count;

	count = 0;
	if (val >= 0)
		count += ft_putchar(' ');
	count += ft_putdigit(val);
	return (count);
}
