/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:50:15 by edebi             #+#    #+#             */
/*   Updated: 2020/11/19 21:11:08 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"
#include <stdlib.h>
#include "libft.h"

t_var *g_var = NULL;
// width - count hex length
// if width > hex length
// allcoate width mem
// write spaces and null terminate
//strlcat hex;
//width
//.presicion

//n = size of string to create
//c = char to append
char	*append_leading(char *str, char c, size_t n)
{
	char	*res;
	size_t	len;
	int		minus;

	minus = 0;
	len = ft_strlen(str);
	if (len >= n)
		return (str);
	//@todo malloc error handling;
	res = malloc(sizeof(char) * n + 1);
	res = ft_memset(res, c, n - len);
	res[n - len] = '\0';
	ft_strlcat(res, str, n + 1);
	if (minus)
		res[0] = '-';
	free(str);
	return (res);
}


char	*append_trailing(char *str, char c, size_t n)
{
	char	*res;
	size_t	len;
	len = ft_strlen(str);
	if (len >= n)
		return (str);
	//@todo malloc error handling;
	res = malloc(sizeof(char) * n + 1);
	res = ft_memset(res, c, n);
	res[n] = '\0';
	ft_memcpy(res, str, len);
	free(str);
	return (res);
}

char	*print_string_precision(char *str)
{
	unsigned int		i;

	i = 0;
	str[g_var->precision] = '\0';
	return (str);
}

char	*check_width(char *str)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	str = ft_memcpy(malloc(sizeof(char) * str_len + 1), str, str_len);
	if (g_var->precision > 0 && ft_strchr("iuxX", g_var->specifier))
		str = append_leading(str, '0', g_var->precision);
	if (g_var->flag_dot != 0 && g_var->specifier == 's')
		str = print_string_precision(str);
	if (g_var->flag_zero == 1 && g_var->flag_minus == 0)
		str = append_leading(str, '0', g_var->width);
	if (g_var->flag_minus == 1)
		str = append_trailing(str, ' ', g_var->width);
	if ((g_var->flag_zero == 0) ||
	(g_var->flag_zero == 1 && g_var->flag_minus == 0 && g_var->precision != 0 &&
	!ft_strrchr("dixXou", g_var->specifier)))
		str = append_leading(str, ' ', g_var->width);
	return (str);
}

char *get_dec_precision(char *str)
{
	unsigned int	len;
	int				minus;

	if (g_var->flag_zero == 1 && g_var->flag_dot == 0)
		g_var->precision = g_var->width;
	if (g_var->flag_zero == 1 && g_var->flag_dot == 1)
		g_var->flag_zero = 0;
	if (g_var->precision == 0)
		return (str);
	minus = 0;
	len = ft_strlen(str);
	if (len > 0 && str[0] == '-')
	{
		minus = 1;
	}
	if ((unsigned int)g_var->precision > len)
	{
		if (minus)
			str[0] = '0';
		if (g_var->flag_dot == 1 && minus)
			g_var->precision++;
		str = ft_memcpy(malloc(sizeof(char) * len + 2), str, ft_strlen(str));
		str = append_leading(str, '0', g_var->precision);
		if (minus == 1)
			str[0] = '-';
	}
	return (str);
}
/* int main(void)
{
	char	*str;
	size_t	str_len;

	g_var = malloc(sizeof(t_var) + 1);
	g_var->specifier = 'x';
	g_var->width = 10;
	g_var->precision = 8;
	g_var->flag_zero = 1;
	g_var->flag_minus = 1;
	str = get_hex(1323232414);
	str = check_width(str);
	ft_putstr(str);
	printf("\n%.9x\n", 1323232414);
	printf("\n%-10.9x\n", 1323232414);
}
 */

