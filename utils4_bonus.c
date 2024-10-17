/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:47:50 by tuaydin           #+#    #+#             */
/*   Updated: 2024/10/17 08:22:30 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_width_dot(t_fdata p_data, char *str)
{
	int	count;
	
	count = 0;
	if (p_data.sf_val > ft_strlen(str))
		p_data.sf_val = ft_strlen(str);
	while (p_data.ff_val > p_data.sf_val)
	{
		count += ft_putchar(' ');
		p_data.ff_val--;
	}
	count += ft_putnstr(str, p_data.sf_val);
	return (count);
}
int	ft_putnstr(char *s, int val)
{
	int	rtn;

	rtn = 0;
	if (!s)
		return (ft_putnull(val));
	while (*s && val)
	{
		rtn += ft_putchar(*s);
		s++;
		val--;
	}
	return (rtn);
}

int	ft_putstr_minus_dot(t_fdata p_data, char *str)
{
	int	count;
	
	count = 0;
	if (p_data.sf_val > ft_strlen(str))
		p_data.sf_val = ft_strlen(str);
	count += ft_putnstr(str, p_data.sf_val);
	while (p_data.ff_val > p_data.sf_val)
	{
		count += ft_putchar(' ');
		p_data.ff_val--;
	}
	return (count);
}

int	ft_putnull(int val)
{
	int	count;

	count = 0;
	while (count < val)
		count += ft_putchar(null[count]);
	return (count);
}

int		ft_putdigit_width(t_fdata p_data, long val)
{
	int	count;

	count = 0;
	while (p_data.ff_val > ft_digitlen(val))
	{
		count += ft_putchar(' ');
		p_data.ff_val--;	
	}
	count += ft_putdigit(val);
	return (count);
}
