/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:03:04 by edebi             #+#    #+#             */
/*   Updated: 2020/11/20 21:12:11 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

void		print_var(void)
{
	if (g_var->specifier == 'c' || g_var->specifier == '%')
		print_char();
	else if (g_var->specifier == 's')
		print_string();
	else if (g_var->specifier == 'p')
		print_pointer();
	else if (g_var->specifier == 'd' || g_var->specifier == 'i')
		print_decimal();
	else if (g_var->specifier == 'u')
		print_unsigned();
	else if (g_var->specifier == 'x' || g_var->specifier == 'X')
		print_hex();
	else if (g_var->specifier == 0)
		return ;
}

void		print_hex(void)
{
	unsigned int	x;
	char			*str;

	x = va_arg(g_params->list, unsigned int);
	if (x == 0 && g_var->flag_dot == 1 && g_var->precision == 0)
		str = ft_memset(malloc(1), '\0', 1);
	else
		str = get_hex(x);
	str = get_dec_precision(str);
	str = check_width(str);
	ft_putstr(str);
	free(str);
}

void		print_end_char(char *str)
{
	if (g_var->flag_minus == 0)
		ft_putstr(str);
	write(1, "\0", 1);
	if (g_var->flag_minus == 1)
		ft_putstr(str);
	g_params->return_val++;
	free(str);
}

int			check_global(void)
{
	if (g_var->flag_zero == 1 && g_var->flag_minus == 1)
		g_var->flag_zero = 0;
	if (g_var->flag_zero == 1 && g_var->flag_dot == 0)
		g_var->precision = g_var->width;
	if (g_var->flag_zero == 1 && g_var->flag_dot == 1)
		g_var->flag_zero = 0;
	if (g_var->precision == 0)
		return (1);
	return (0);
}
