/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:36:48 by tuaydin           #+#    #+#             */
/*   Updated: 2024/10/15 20:54:56 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_isflag(char c)
{
	if (c == '-' || c == '0' || c == '.')
		return (c);
	return (0);
}

void	ft_passflag(char **sptr)
{
	char	c;

	c = **sptr;
	while (**sptr == c)
		(*sptr)++;
}

char	ft_isvalidtype(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (c);
	return (0);
}

int	ft_putchar_minus(t_fdata p_data, char c)
{
	int	count;

	count = 0;
	count += ft_putchar(c);
	while (p_data.ff_val > 1)
	{
		count += ft_putchar(' ');
		p_data.ff_val--;
	}
	return (count);
}

int	ft_putstr_minus(t_fdata p_data, char *str)
{
	int	count;

	count = 0;
	count += ft_putstr(str);
	while (p_data.ff_val > ft_strlen(str))
	{
		count += ft_putchar(' ');
		p_data.ff_val--;
	}
	return (count);
}
