/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:41:06 by edebi             #+#    #+#             */
/*   Updated: 2020/11/16 03:18:14 by edebi            ###   ########.fr       */
/*       x                                                                     */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdio.h>

void		print_char(void)
{
	char	*str;
	char	c;
	char	res[2];

	if (g_var->specifier == '%')
		c = '%';
	else
		c = (char)va_arg(g_params->list, int);
	res[0] = c;
	res[1] = '\0';
	if (c == '\0' && g_var->width > 0)
		g_var->width--;
	str = check_width(res);
	ft_putstr(str);
	if (c == '\0')
	{
		g_params->return_val++;
		write(1, &c, 1);
	}
	//free(str);
}

void		print_string(void)
{
	char	*str;

	str = va_arg(g_params->list, char*);
	if (str == NULL)
		str = check_width("(null)");
	else
		str = check_width(str);
	ft_putstr(str);
}

void		print_pointer(void)
{
	char			*str;
	char			*cp;
	unsigned long	x;

	x = va_arg(g_params->list, unsigned long);
	if (!x)
		x = 0;
	str = get_hex(x);
	str = get_dec_precision(str);
	cp = str;
	str = ft_strjoin("0x", str);
	free(cp);
	str = check_width(str);
	ft_putstr(str);
	//free(str);
}

void		print_decimal(void)
{
	char			*str;
	long int		x;

	x = va_arg(g_params->list, int);
	if (x == 0 && g_var->flag_dot == 1 && g_var->precision == 0)
		str = ft_memset(malloc(1), '\0', 1);
	else
		str = ft_itoa(x);
	str = get_dec_precision(str);
	// printf("str %s\n", str);
	str = check_width(str);
	ft_putstr(str);
	//free(str);
}

void		print_unsigned(void)
{
	char			*str;
	int	x;

	x = va_arg(g_params->list, int);
	if (x == 0 && g_var->flag_dot == 1 && g_var->precision == 0)
		str = ft_memset(malloc(1), '\0', 1);
	else
		str = ft_itoa_unsigned(x);
	str = get_dec_precision(str);
	// printf("str %s\n", str);
	str = check_width(str);
	ft_putstr(str);
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
	//free(str);
}
