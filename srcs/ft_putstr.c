/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:07:55 by edebi             #+#    #+#             */
/*   Updated: 2020/11/12 15:43:51 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_putstr_count(char *str)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			write(1, &str[i], 1);
			k++;
			i += 2;
			continue;
		}
		write(1, &str[i], 1);
		i++;
	}
	return (i - k);
}

void	init_g_var()
{
	
}
