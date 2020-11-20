/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:08:27 by edebi             #+#    #+#             */
/*   Updated: 2020/11/20 22:10:46 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

t_var			*g_var;
t_params		*g_params;

static void		trim(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			init_var();
			i++;
			i += set_flag(str + i);
			i += get_width(str + i);
			i += get_precision(str + i);
			i += get_specifier(str + i);
			print_var();
		}
		if (str[i] != '\0' && str[i] != '%')
		{
			g_params->return_val++;
			write(1, &str[i], 1);
			i++;
		}
	}
	return ;
}

int				ft_printf(const char *str, ...)
{
	char		*c_str;
	int			j;

	c_str = (char *)str;
	j = init_params(c_str);
	if (j < 0)
		return (-1);
	else
	{
		va_start(g_params->list, str);
		trim(g_params->str);
		va_end(g_params->list);
	}
	return (free_mem());
}
