/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:20:01 by tuaydin           #+#    #+#             */
/*   Updated: 2024/10/16 21:18:10 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_di_type(t_fdata p_data, long val)
{
	if (p_data.f_flag == 0 && p_data.s_flag == 0)
		return (ft_putdigit(val));
	if ((p_data.f_flag == '-' || p_data.f_flag == 'w') && p_data.s_flag == 0)
		return (ft_putdigit_minus(p_data, val));
	if (p_data.f_flag == '0' && p_data.s_flag == 0)
		return (ft_putdigit_zero(p_data, val));
	if (p_data.f_flag == '.' && p_data.s_flag == 0)
		return (ft_putdigit_dot(p_data, val));
	if (p_data.f_flag == ' ' && p_data.s_flag == 0)
		return (ft_putdigit_space(val));
	if (p_data.f_flag == '+' && p_data.s_flag == 0)
		return (ft_putdigit_plus(val));
	if (p_data.f_flag == 'w' && p_data.s_flag == 0)
		return (ft_putdigit_width(val));
	return (0);
}
