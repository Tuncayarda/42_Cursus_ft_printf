/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:16:00 by tuaydin           #+#    #+#             */
/*   Updated: 2024/10/17 12:01:48 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent_type(t_fdata p_data)
{
	if (p_data.f_flag == 0 && p_data.s_flag == 0)
		return (ft_putchar('%'));
	if (p_data.f_flag == 'w' && p_data.s_flag == 0)
		return (ft_putpercent_width(p_data));
	if (p_data.f_flag == '-' && p_data.s_flag == 0)
		return (ft_putpercent_minus(p_data));
	if (p_data.f_flag == '0' && p_data.s_flag == 0)
		return (ft_putpercent_zero(p_data));
	return (0);
}
