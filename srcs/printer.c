/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:41:06 by edebi             #+#    #+#             */
/*   Updated: 2020/11/14 18:04:10 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

void		print_char(void)
{
	char	*str;
	char	c;
	char	res[2];

	c = (char)va_arg(g_params->list, int);
	res[0] = c;
	res[1] = '\0';
	str = check_width(res);
	ft_putstr(str);
	//free(str);
}

void		print_string(void)
{
	char	*str;

	str = va_arg(g_params->list, char*);
	str = check_width(str);
	ft_putstr(str);
}

void		print_pointer(void)
{
	char			*str;
	unsigned long	x;

	x = va_arg(g_params->list, unsigned long);
	write(1, "0x", 2);
	str = get_hex(x);
	str = check_width(str);
	ft_putstr(str);
	//free(str);
}

void		print_decimal(void)
{
	char			*str;
	int	x;

	x = va_arg(g_params->list, int);
	str = ft_itoa(x);
	str = check_width(str);
	ft_putstr(str);
	//free(str);
}

void		print_unsigned(void)
{
	char			*str;
	int	x;

	x = va_arg(g_params->list, unsigned int);
	str = ft_itoa(x);
	str = check_width(str);
	ft_putstr(str);
	//free(str);
}

void		print_hex(void)
{
	unsigned int	x;
	char			*str;

	x = va_arg(g_params->list, unsigned int);
	str = get_hex(x);
	str = check_width(str);
	ft_putstr(str);
	//free(str);
}
