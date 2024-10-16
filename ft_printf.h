/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:48:31 by tuaydin           #+#    #+#             */
/*   Updated: 2024/10/16 21:10:52 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

static const char null[7] = "(null)";

typedef struct flag_data
{
	char		v_type;
	char		f_flag;
	char		s_flag;
	long		ff_val;
	long		sf_val;
}				t_fdata;

int		ft_printf(const char *str, ...);
int		ft_uatoi(char **sptr);
int		ft_print_c_type(t_fdata print_data, char c);
int		ft_print_s_type(t_fdata p_data, char *str);
int		ft_print_p_type(t_fdata p_data, unsigned long val);
int		ft_print_di_type(t_fdata p_data, long val);
int		ft_print_u_type(t_fdata p_data, unsigned long val);
int		ft_print_x_type(t_fdata p_data, unsigned long val, int is_upper);
int		ft_print_percent_type(t_fdata p_data);
int		ft_strlen(char *s);
int		ft_digitlen(long val);
int		ft_hexlen(unsigned long val);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putptr(unsigned long val);
int		ft_putdigit(long val);
int		ft_puthex(unsigned long val, const char *base);
int		ft_putnstr(char *s, int val);
int		ft_putnull(int val);
char	ft_isflag(char c);
void	ft_passflag(char **sptr);
char	ft_isvalidtype(char c);
int		ft_putchar_minus(t_fdata p_data, char c);
int		ft_putstr_minus(t_fdata p_data, char *str);
int		ft_putptr_minus(t_fdata p_data, unsigned long val);
int		ft_putdigit_minus(t_fdata p_data, long val);
int		ft_puthex_minus(t_fdata p_data, unsigned long val, int is_upper);
int		ft_putpercent_minus(t_fdata p_data);
int		ft_putdigit_zero(t_fdata p_data, long val);
int		ft_puthex_zero(t_fdata p_data, unsigned long val, int is_upper);
int		ft_putstr_dot(t_fdata p_data, char *str);
int		ft_putdigit_dot(t_fdata p_data, long val);
int		ft_puthex_sharp(t_fdata p_data, unsigned long val, int is_upper);
int		ft_putstr_space(t_fdata p_data, char *str);
int		ft_putdigit_space(long val);
int		ft_putdigit_plus(long val);
int		ft_putchar_width(t_fdata p_data, char c);
int		ft_putstr_width(t_fdata p_data, char *str);
int		ft_putpercent_width(t_fdata p_data);
int		ft_putchar_dot(t_fdata p_data, char c);

int		ft_putstr_width_dot(t_fdata p_data, char *str);
int		ft_putstr_minus_dot(t_fdata p_data, char *str);
#endif