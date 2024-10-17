/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:36:56 by tuaydin           #+#    #+#             */
/*   Updated: 2024/10/17 12:29:15 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_digitlen(long val)
{
	int	count;

	count = 0;
	if (val == 0)
		return (1);
	if (val < 0)
	{
		val = -val;
		count++;
	}
	while (val > 0)
	{
		val /= 10;
		count++;
	}
	return (count);
}

int	ft_uatoi(char **sptr)
{
	size_t	rtn;

	rtn = 0;
	while (**sptr >= '0' && **sptr <= '9')
	{
		rtn *= 10;
		rtn += **sptr - '0';
		(*sptr)++;
	}
	return (rtn);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (6);
	while (s[i])
		i++;
	return (i);
}

int	ft_uatoi1(char *sptr)
{
	size_t	rtn;

	rtn = 0;
	while (*sptr >= '0' && *sptr <= '9')
	{
		rtn *= 10;
		rtn += *sptr - '0';
		sptr++;
	}
	return (rtn);
}
