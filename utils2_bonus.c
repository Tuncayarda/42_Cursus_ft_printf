/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:53:14 by tuaydin           #+#    #+#             */
/*   Updated: 2024/10/15 22:10:15 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_zero(t_fdata p_data, unsigned long val, int is_upper)
{
	int	count;

	count = 0;
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
	if (is_upper)
		count += ft_puthex(val, "0123456789ABCDEF");
	else
		count += ft_puthex(val, "0123456789abcdef");
	return (count);
}

int	ft_putstr_dot(t_fdata p_data, char *str)
{
	int	i;

	i = 0;
	while(str[i] && i < p_data.ff_val)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
