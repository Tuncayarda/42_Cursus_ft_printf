/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_len_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:59:21 by tuaydin           #+#    #+#             */
/*   Updated: 2024/10/17 10:45:22 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned long val)
{
	int	count;

	count = 0;
	if (val == 0)
		return (1);
	while (val > 0)
	{
		val /= 16;
		count++;
	}
	return (count);
}

int	ft_ptrlen(unsigned long val)
{
	int	count;

	count = 0;
	if (val == 0)
		return (3);
	while (val > 0)
	{
		val /= 16;
		count++;
	}
	return (count + 2);
}
