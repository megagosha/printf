/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:08:27 by edebi             #+#    #+#             */
/*   Updated: 2020/11/12 19:40:42 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <stdio.h>

static void	init(t_params *params)
{
	printf("%s", va_arg(params->list, char*));
	printf("%s", va_arg(params->list, char*));
	printf("%s", va_arg(params->list, char*));

}

static int	count_args(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == '%')
			i++;
		else if(str[i] == '%')
			k++;
		i++;
	}
	return (k);
}

static int		set_flag(char *str)
{
	int	i;

	i = 0;
	while (ft_strchr(g_params->flags, str[i]))
	{
		if (str[i] == '*')
			g_var->flag_star = 1;
		else if (str[i] == '0')
			g_var->flag_zero = 1;
		else if (str[i] == '.')
			g_var->flag_dot = 1;
		else if (str[i] == '-')
			g_var->flag_dot = 1;
		i++;
	}
	return (i);
}

static int		get_width(char *str)
{
	int i;

	i = 0;
	if (str[i] == '*')
	{
		g_var->width = va_arg(g_params->list, int);
		return (1);
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
		i++;
	g_var->width = ft_atoi(str);
	return (i);
}

static int		get_precision(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '.')
		return (0);
	i++;
	if (str[i] == '*')
	{
		g_var->precision = va_arg(g_params->list, int);
		return (i + 1);
	}
	g_var->precision = ft_atoi(str + i);
	while (str[i] != '\0' && ft_isdigit(str[i]))
		i++;
	return (i);
}

static int		get_specifier(char *str)
{
	int	i;

	i = 0;
	if (!ft_strchr(g_params->conversions, str[i]))
	{
		printf("SAD ERROR\n");
		exit(0);
	}
	else
		g_var->specifier = str[i];
	return (1);
}

static void		print_var(void)
{
	if (g_var->specifier == 'c')
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
}

static int		trim(char *str)
{
	int	i;

	i = 0;

	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			i++;
			write(1, "%", 1);
		}
		else if (str[i] == '%')
		{
			i += set_flag(str);
			i += get_width(str + i);
			i += get_precision(str + i);
			i += get_specifier(str + i);
			print_var();
		}
		write(1, &str[i], 1);
		i++;
	}
}

static void		run(void)
{
	int		i;
	int		k;
	char	*str;

	str = g_params->str;
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == '%')
			i++;
		else if(str[i] == '%')
		{
			i += trim(str + i);
			k++;
		}
		i++;
	}
}

static void	init_var()
{
	if (g_var == NULL)
		g_var = malloc(sizeof(t_var) + 1);
	g_var->variable = NULL;
	g_var->flag_zero = 0;
	g_var->flag_minus = 0;
	g_var->flag_dot = 0;
	g_var->flag_star = 0;
	g_var->width = 0;
	g_var->precision = 0;
	g_var->length = 0;
	g_var->specifier = (char)0;
	return ;
}

/* @todo Add malloc check for NULL */
int			*init_params(char *c_str)
{
	g_params = malloc(sizeof(t_params) + 1);
	ft_strlcpy(g_params->conversions, "cspdiuxX\0", 9);
	ft_strlcpy(g_params->flags, "-0.*\0", 5);
	init_var();
	if (g_params == NULL)
		return (-1);
	g_params->n_args = count_args(c_str);
	if (g_params->n_args == 0)
		return (0);
	g_params->str = c_str;
	if (g_params->str == NULL)
		return (-1);
	return (1);
}

int			ft_printf(const char *str, ...)
{
	int			i;
	char		*c_str;
	int			j;

	c_str = (char *)str;
	j = init_params(c_str);
	if (j < 0)
		return (0);
	if (j == 0)
		return (ft_putstr_printf(c_str));
	va_start(g_params->list, str);
	run();
	va_end(g_params->list);
	return (0);
}

int			main(void)
{
	ft_printf("%%%dsdfsd%dfsfasdf%sdfsd%%", "hello1\n", "hello2\n");
}
