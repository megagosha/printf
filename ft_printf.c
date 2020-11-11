/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:08:27 by edebi             #+#    #+#             */
/*   Updated: 2020/11/11 19:50:58 by edebi            ###   ########.fr       */
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
	int	beg;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			beg = i;
			while (str[i] == '%')
				i++;
			if ((i - beg) % 2 != 0)
				k++;
			i--;
		}
		i++;
	}
	return (k);
}

int			ft_printf(const char *str, ...)
{
	t_params	*params;
	int			i;
	char		*c_str;

	c_str = (char *)str;
	params = malloc(sizeof(t_params) + 1);
	i = 0;
	va_start(params->list, c_str);
	if (str)
	{
		params->n_args = count_args(c_str);
		run(params);
	}
	va_end(params->list);
	return (0);
}

int			main(void)
{
	ft_printf("%%He%l%%l%o%%", "hello1\n", "hello2\n");
}
