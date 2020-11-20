/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:50:15 by edebi             #+#    #+#             */
/*   Updated: 2020/11/20 21:14:13 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

char	*append_leading(char *str, char c, size_t n)
{
	char	*res;
	size_t	len;
	int		minus;

	minus = 0;
	len = ft_strlen(str);
	if (len >= n)
		return (str);
	res = malloc(sizeof(char) * n + 1);
	if (res == NULL)
	{
		g_params->error = -1;
		return ((char *)0);
	}
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
	res = malloc(sizeof(char) * n + 1);
	if (res == NULL)
	{
		g_params->error = -1;
		return ((char *)0);
	}
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
	if (g_var->precision > 0 && ft_strchr("iuxX", g_var->specifier))
		str = append_leading(str, '0', g_var->precision);
	if (g_var->flag_dot != 0 && g_var->specifier == 's')
		str[g_var->precision] = '\0';
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

char	*get_dec_precision(char *str)
{
	unsigned int	len;
	int				minus;
	char			*fr;

	if (check_global())
		return (str);
	minus = 0;
	if ((len = ft_strlen(str)) > 0 && str[0] == '-')
		minus = 1;
	if (g_var->flag_dot == 1 && minus)
		g_var->precision++;
	if ((unsigned int)g_var->precision > len)
	{
		if (minus)
			str[0] = '0';
		fr = str;
		str = ft_memcpy(malloc(1 * len + 2), str, ft_strlen(str) + 1);
		if (str == NULL)
			g_params->error = -1;
		free(fr);
		str = append_leading(str, '0', g_var->precision);
		if (minus == 1)
			str[0] = '-';
	}
	return (str);
}
