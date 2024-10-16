/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:05:47 by tuaydin           #+#    #+#             */
/*   Updated: 2024/10/16 19:33:51 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c_type(t_fdata p_data, char c)
{
	if ((p_data.f_flag == 0 || p_data.f_flag == '.')&& p_data.s_flag == 0)
		return (ft_putchar(c));
	if (p_data.f_flag == '-' && p_data.s_flag == 0)
		return (ft_putchar_minus(p_data, c));
	if (p_data.f_flag == 'w' && p_data.s_flag == 0)
		return (ft_putchar_width(p_data, c));
	return (0);
}
