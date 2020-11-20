/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:41:06 by edebi             #+#    #+#             */
/*   Updated: 2020/11/20 21:07:13 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

void		print_char(void)
{
	char	*str;
	char	c;
	char	*res;

	if ((res = malloc(sizeof(char) * 2)) == NULL)
	{
		g_params->error = -1;
		return ;
	}
	if (g_var->specifier == '%')
		c = '%';
	else
		c = (char)va_arg(g_params->list, int);
	res[0] = c;
	res[1] = '\0';
	if (c == '\0' && g_var->width > 0)
		g_var->width--;
	str = check_width(res);
	if (c == '\0')
		return (print_end_char(str));
	ft_putstr(str);
	free(str);
}

void		print_string(void)
{
	char	*str;
	size_t	len;

	str = va_arg(g_params->list, char*);
	if (str == NULL)
		str = check_width(ft_memcpy(malloc(sizeof(char) * 8), "(null)", 8));
	else
	{
		len = ft_strlen(str);
		str = ft_memcpy(malloc(sizeof(char) * len + 1), str, len + 1);
		if (str == NULL)
		{
			g_params->error = -1;
			return ;
		}
		str = check_width(str);
	}
	ft_putstr(str);
	free(str);
}

void		print_pointer(void)
{
	char			*str;
	char			*cp;
	unsigned long	x;

	x = va_arg(g_params->list, unsigned long);
	if (x == 0 && g_var->flag_dot == 1 && g_var->precision == 0)
		str = ft_memset(malloc(1), '\0', 1);
	else
		str = get_hex(x);
	if (str == NULL)
	{
		g_params->error = -1;
		return ;
	}
	str = get_dec_precision(str);
	cp = str;
	str = ft_strjoin("0x", str);
	free(cp);
	str = check_width(str);
	ft_putstr(str);
	free(str);
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
	if (str == NULL)
	{
		g_params->error = -1;
		return ;
	}
	str = get_dec_precision(str);
	str = check_width(str);
	ft_putstr(str);
	free(str);
}

void		print_unsigned(void)
{
	char	*str;
	int		x;

	x = va_arg(g_params->list, int);
	if (x == 0 && g_var->flag_dot == 1 && g_var->precision == 0)
		str = ft_memset(malloc(1), '\0', 1);
	else
		str = ft_itoa_unsigned(x);
	if (str == NULL)
	{
		g_params->error = -1;
		return ;
	}
	str = get_dec_precision(str);
	str = check_width(str);
	ft_putstr(str);
	free(str);
}
