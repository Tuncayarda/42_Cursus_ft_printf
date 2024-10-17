/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:26:48 by tuaydin           #+#    #+#             */
/*   Updated: 2024/10/17 12:04:08 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_zero_dot(t_fdata p_data, long val, int is_upper)
{
	int	count;

	count = 0;
	if (ft_hexlen(val) < p_data.sf_val)
		p_data.ff_val -= p_data.sf_val - ft_hexlen(val);
	while (p_data.ff_val-- > ft_hexlen(val))
		count += ft_putchar(' ');
	while (p_data.sf_val > ft_hexlen(val))
	{
		count += ft_putchar('0');
		p_data.sf_val--;
	}
	if (p_data.sf_val != 0)
	{
		if (is_upper)
			count += ft_puthex(val, is_upper);
		else
			count += ft_puthex(val, is_upper);
	}
	else
		count += ft_putchar(' ');
	return (count);
}

int	ft_putptr_width(t_fdata p_data, unsigned long val)
{
	int	count;

	count = 0;
	while (p_data.ff_val > ft_ptrlen(val))
	{
		count += ft_putchar(' ');
		p_data.ff_val--;
	}
	count += ft_putptr(val);
	return (count);
}

int	ft_putdigit_dot_zero(t_fdata p_data, long val)
{
	int	count;

	count = 0;
	if (val < 0)
	{
		val = -val;
		count += ft_putchar('-');
	}
	if (p_data.sf_val == 0 && val > 0)
		return (count + ft_putdigit(val));
	while (p_data.sf_val > ft_digitlen(val))
	{
		count += ft_putchar('0');
		p_data.sf_val--;
	}
	if (p_data.sf_val != 0)
		return (count + ft_putdigit(val));
	return (count);
}

int	ft_puthex_dot_zero(t_fdata p_data, long val, int is_upper)
{
	int	count;

	count = 0;
	if (p_data.sf_val == 0 && val > 0)
		return (count + ft_puthex(val, is_upper));
	while (p_data.sf_val > ft_hexlen(val))
	{
		count += ft_putchar('0');
		p_data.sf_val--;
	}
	if (p_data.sf_val != 0)
		return (count + ft_puthex(val, is_upper));
	return (count);
}

int		ft_putpercent_zero(t_fdata p_data)
{
	int	count;

	count = 0;
	while (p_data.ff_val > 1)
	{
		count += ft_putchar('0');
		p_data.ff_val--;
	}
	count += ft_putchar('%');
	return (count);
}