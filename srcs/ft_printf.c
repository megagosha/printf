/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:08:27 by edebi             #+#    #+#             */
/*   Updated: 2020/11/14 18:40:23 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"
#include <stdio.h>

t_var		*g_var;
t_params	*g_params;

/* static void	init(t_params *params)
{
	printf("%s", va_arg(params->list, char*));
	printf("%s", va_arg(params->list, char*));
	printf("%s", va_arg(params->list, char*));

} */

static void	init_var(void)
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
	while (ft_strchr((const char *)g_params->flags, str[i]))
	{
		if (str[i] == '*')
			g_var->flag_star = 1;
		else if (str[i] == '0')
			g_var->flag_zero = 1;
		else if (str[i] == '.')
			g_var->flag_dot = 1;
		else if (str[i] == '-')
			g_var->flag_minus = 1;
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
void		print_global_debug(void)
{
	printf("Printing g_params struct: \nn_args %d\nstr: %s\nconversions %s\nflags %s\n", g_params->n_args, g_params->str, g_params->conversions, g_params->flags);
	printf("\nPrinting g_var struct: \nvar %p\nflag_zero: %d\nflag_minus %d\nflag_dot %d\nflag_star %d\nwidth %d\nprecision %u\nlength int %d\nspecifier %c \n", g_var->variable, g_var->flag_zero, g_var->flag_minus, g_var->flag_dot, g_var->flag_star, g_var->width, g_var->precision, g_var->length, g_var->specifier);
	return ;
}

static int		get_specifier(char *str)
{
	int	i;

	i = 0;
	if (!ft_strchr((const char *)g_params->conversions, str[i]))
	{
		print_global_debug();
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
			init_var();
			i++;
			i += set_flag(str + i);
			i += get_width(str + i);
			i += get_precision(str + i);
			i += get_specifier(str + i);
			print_var();
		}
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/* @todo Add malloc check for NULL */
int			init_params(char *c_str)
{
	g_params = malloc(sizeof(t_params) + 1);
	g_params->conversions = malloc(sizeof(char) * 9);
	g_params->flags = malloc(sizeof(char) * 5);
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
	char		*c_str;
	int			j;

	c_str = (char *)str;
	j = init_params(c_str);
	if (j < 0)
		return (0);
	if (j == 0)
		return (ft_putstr_count(c_str));
	va_start(g_params->list, str);
	trim(g_params->str);
	va_end(g_params->list);
	return (0);
}

/* int			main(void)
{
	ft_printf("Hello %-10X\n", 234434);
} */