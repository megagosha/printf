/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:01:52 by edebi             #+#    #+#             */
/*   Updated: 2020/11/20 18:02:40 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int			set_flag(char *str)
{
	int	i;

	i = 0;
	while (ft_strchr((const char *)g_params->flags, str[i]))
	{
		if (str[i] == '0')
			g_var->flag_zero = 1;
		else if (str[i] == '-')
			g_var->flag_minus = 1;
		i++;
	}
	return (i);
}

int			get_width(char *str)
{
	int i;

	i = 0;
	if (str[i] == '*')
	{
		if ((g_var->width = va_arg(g_params->list, int)) < 0)
		{
			g_var->width = -g_var->width;
			g_var->flag_minus = 1;
			g_var->flag_zero = 0;
		}
		return (1);
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
		i++;
	if (i > 0)
		g_var->width = ft_atoi(str);
	if (g_var->width < 0)
	{
		g_var->width = -g_var->width;
		g_var->flag_minus = 1;
		g_var->flag_zero = 0;
	}
	return (i);
}

int			get_precision(char *str)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	if (str[i] != '.')
		return (0);
	g_var->flag_dot = 1;
	i++;
	if (str[i] == '*')
	{
		if ((k = va_arg(g_params->list, int)) < 0)
		{
			k = 0;
			g_var->flag_dot = 0;
		}
		g_var->precision = k;
		return (i + 1);
	}
	g_var->precision = ft_atoi(str + i);
	if (g_var->precision < 0)
		g_var->flag_dot = 0;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		i++;
	return (i);
}

int			get_specifier(char *str)
{
	int	i;

	i = 0;
	if (!ft_strchr((const char *)g_params->conversions, str[i]))
	{
		g_var->specifier = 0;
		return (1);
	}
	else
		g_var->specifier = str[i];
	return (1);
}
