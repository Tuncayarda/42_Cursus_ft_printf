/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:14:21 by tuaydin           #+#    #+#             */
/*   Updated: 2024/10/17 20:43:04 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_space_width(t_fdata p_data, char *str)
{
	int	count;
	
	count = 0;
	while (p_data.sf_val > ft_strlen(str))
	{
		count += ft_putchar(' ');
		p_data.sf_val--;
	}
	if (str)
		count += ft_putstr(str);
	return (count);
}

int	ft_putdigit_minus_zero(t_fdata p_data, long val)
{
	int count;

	count = 0;
	if (p_data.sf_val > ft_digitlen(val))
	{
		count += ft_putdigit(val);
		while(p_data.sf_val > ft_digitlen(val))
		{
			count += ft_putchar(' ');
			p_data.sf_val--;
		}
	}
	else
		count += ft_putdigit(val);
	return (count);
}
int	ft_putstr_space(t_fdata p_data, char *str)
{
	int count;

	count = 0;
	while(p_data.ff_val > 1)
	{
		count += ft_putchar(' ');
		p_data.ff_val--;
	}
	if (!(str[0]) && p_data.ff_val != 0)
		count += ft_putchar(' ');
	count += ft_putstr(str);

	return (count);
}
