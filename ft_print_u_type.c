/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:36:27 by tuaydin           #+#    #+#             */
/*   Updated: 2024/10/15 21:55:51 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u_type(t_fdata p_data, unsigned long val)
{
	if (p_data.f_flag == 0 && p_data.s_flag == 0)
		return (ft_putdigit(val));
	if ((p_data.f_flag == '-' || p_data.f_flag == 'w') && p_data.s_flag == 0)
		return (ft_putdigit_minus(p_data, (long)val));
	if (p_data.f_flag == '0' && p_data.s_flag == 0)
		return (ft_putdigit_zero(p_data, val));
	return (0);
}