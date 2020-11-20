/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:59:48 by edebi             #+#    #+#             */
/*   Updated: 2020/11/20 22:10:32 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int			init_params(char *c_str)
{
	g_params = malloc(sizeof(t_params) + 1);
	g_params->conversions = malloc(sizeof(char) * 10);
	g_params->flags = malloc(sizeof(char) * 5);
	g_params->return_val = 0;
	g_params->error = 0;
	ft_strlcpy(g_params->conversions, "cspdiuxX%\0", 10);
	ft_strlcpy(g_params->flags, "-0\0", 5);
	init_var();
	if (g_params == NULL)
		return (-1);
	g_params->str = c_str;
	if (g_params->str == NULL)
		return (-1);
	return (1);
}

void		init_var(void)
{
	if (g_var == NULL)
		g_var = malloc(sizeof(t_var) + 1);
	g_var->flag_zero = 0;
	g_var->flag_minus = 0;
	g_var->flag_dot = 0;
	g_var->width = 0;
	g_var->precision = 0;
	g_var->length = 0;
	g_var->specifier = (char)0;
	return ;
}

int			free_mem(void)
{
	int	i;

	i = g_params->return_val;
	free(g_params->conversions);
	free(g_params->flags);
	va_end(g_params->list);
	free(g_params);
	return (i);
}
