/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:43:08 by tuaydin           #+#    #+#             */
/*   Updated: 2024/10/17 15:19:07 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s_type(t_fdata p_data, char *str)
{
	if (p_data.f_flag == 0 && p_data.s_flag == 0)
		return (ft_putstr(str));
	if (p_data.f_flag == '-'&& p_data.s_flag == 0)
		return (ft_putstr_minus(p_data, str));
	if (p_data.f_flag == '.' && (p_data.s_flag == 0 || p_data.s_flag == '0'))
		return (ft_putstr_dot(p_data, str));
	if (p_data.f_flag == 'w' && p_data.s_flag == 0)
		return (ft_putstr_width(p_data, str));
	if (p_data.f_flag == 'w' && p_data.s_flag == '.')
		return (ft_putstr_width_dot(p_data, str));
	if (p_data.f_flag == '-' && p_data.s_flag == '.')
		return (ft_putstr_minus_dot(p_data, str));
	if (p_data.f_flag == '.' && p_data.s_flag == '0')
		return (ft_putstr_dot(p_data, str));
	if (p_data.f_flag == ' ' && p_data.s_flag == 'w')
		return (ft_putstr_space_width(p_data, str));
	if (p_data.f_flag == ' ' && p_data.s_flag == 0)
		return (ft_putstr_space_width(p_data, str));
	return (0);
}
