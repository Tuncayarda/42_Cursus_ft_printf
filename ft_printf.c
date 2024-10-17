/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:49:50 by tuaydin           #+#    #+#             */
/*   Updated: 2024/10/17 19:06:08 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
static int	ft_do_print(va_list *args, t_fdata print_data)
{
	//printf("\n%c/ %ld/ %c/ %ld/ %c/\n", print_data.f_flag, print_data.ff_val, print_data.s_flag, print_data.sf_val, print_data.v_type);
	if (print_data.v_type == 'c')
		return (ft_print_c_type(print_data, va_arg(*args, int)));
	if (print_data.v_type == 's')
		return (ft_print_s_type(print_data, va_arg(*args, char *)));
	if (print_data.v_type == 'p')
		return (ft_print_p_type(print_data, va_arg(*args, unsigned long)));
	if (print_data.v_type == 'd' || print_data.v_type == 'i')
		return (ft_print_di_type(print_data, (long)va_arg(*args, int)));
	if (print_data.v_type == 'u')
		return (ft_print_u_type(print_data, va_arg(*args, unsigned int)));
	if (print_data.v_type == 'x')
		return (ft_print_x_type(print_data, va_arg(*args, unsigned int), 0));
	if (print_data.v_type == 'X')
		return (ft_print_x_type(print_data, va_arg(*args, unsigned int), 1));
	if (print_data.v_type == '%')
		return (ft_print_percent_type(print_data));
	return (0);
}

static char	ft_check_after_dot(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (!ft_isvalidtype(str[i]))
	{
		if (str[i] >= '1' && str[i]<= '9')
			flag = 1;
		if (str[i] == '0' && !flag)
			return ('0');
		i++;
	}
	return (0);
}

static char	ft_check_after_zero(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (!ft_isvalidtype(str[i]))
	{
		
		if (str[i] >= '1' && str[i]<= '9')
			flag = 1;
		if (str[i] == '0' && !flag)
			return ('0');
		if (str[i] == '.')
			return ('.');
		if (str[i] == ' ')
			return (' ');
		i++;
	}
	return (0);
}

static char	ft_check_after_minus(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (!ft_isvalidtype(str[i]))
	{
		if (str[i] >= '1' && str[i]<= '9')
			flag = 1;
		if (str[i] == '0' && !flag)
			return ('0');
		if (str[i] == '.')
			return ('.');
		i++;
	}
	return (0);
}

static char ft_check_after_space(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (!ft_isvalidtype(str[i]))
	{
		if (str[i] >= '1' && str[i]<= '9')
			flag = 1;
		if (str[i] == '0' && !flag)
			return ('0');
		if (str[i] == '.')
			return ('.');
		if (str[i] == '-')
			return ('-');
		i++;
	}
	return (0);
}

static int	ft_define_flags(va_list *args, char **sptr)
{
	t_fdata pd;
	
	pd.f_flag = 0;
	pd.s_flag = 0;
	(*sptr)++;
	if (**sptr >= '1' && **sptr <= '9')
	{
		pd.f_flag = 'w';
		pd.ff_val = ft_uatoi(sptr);
		pd.s_flag = 0;
		pd.v_type = ft_isvalidtype(**sptr);
	}
	else if (**sptr == '.')
	{
		pd.f_flag = '.';
		pd.s_flag = ft_check_after_dot(*sptr);
		if (pd.s_flag == '0')
		{
			pd.ff_val = 0;
			(*sptr)++;
			pd.sf_val = ft_uatoi(sptr);
			pd.v_type = ft_isvalidtype(**sptr);
		}
		else
		{
			(*sptr)++;
			pd.ff_val = ft_uatoi(sptr);
			pd.s_flag = 0;
			pd.sf_val = 0;
			pd.v_type = ft_isvalidtype(**sptr);
		}
	}
	else if (**sptr == '0')
	{
		pd.f_flag = '0';
		(*sptr)++;
		pd.s_flag = ft_check_after_zero(*sptr);
		pd.ff_val = ft_uatoi(sptr);
		pd.sf_val = 0;
		pd.v_type = ft_isvalidtype(**sptr);
	}
	else if (**sptr == ' ')
	{
		pd.f_flag = ' ';
		pd.s_flag = ft_check_after_space(*sptr);
		(*sptr)++;
		pd.ff_val = 0;
		if (pd.s_flag != '0')
			pd.ff_val = ft_uatoi(sptr);
		pd.sf_val = 0;
		if (pd.s_flag == '0')
			pd.sf_val = ft_uatoi(sptr);
		if (pd.s_flag == '.' || pd.s_flag == '-')
		{
			(*sptr)++;
			pd.sf_val = ft_uatoi(sptr);
		}

		pd.v_type = ft_isvalidtype(**sptr);
	}
	else if (**sptr == '-')
	{
		pd.f_flag = '-';
		pd.s_flag = ft_check_after_minus(*sptr);
		(*sptr)++;
		pd.ff_val = 0;
		pd.sf_val = 0;
		if(pd.s_flag != '0')
			pd.ff_val = ft_uatoi(sptr);
		if (pd.s_flag == '0')
			pd.sf_val = ft_uatoi(sptr);
		if (pd.s_flag == '.')
		{
			(*sptr)++;
			pd.sf_val = ft_uatoi(sptr);
		}
		pd.v_type = ft_isvalidtype(**sptr);
	}
	else if(**sptr == '#')
	{
		pd.f_flag = '#';
		(*sptr)++;
		pd.ff_val = ft_uatoi(sptr);
		pd.s_flag = 0;
		pd.sf_val = 0;
		pd.v_type = ft_isvalidtype(**sptr);
	}
	else if (ft_isvalidtype(**sptr))
	{
		pd.f_flag = 0;
		pd.s_flag = 0;
		pd.v_type = **sptr;
	}
	return (ft_do_print(args, pd));
	
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	if (str)
	{
		while (*str)
		{
			if (*str != '%')
				count += ft_putchar(*str);
			else if (*str == '%')
				count += ft_define_flags(&args, (char **)&str);
			str++;
		}
	}
	va_end(args);
	return (count);
}
