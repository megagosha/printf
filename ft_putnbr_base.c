/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:04:07 by edebi             #+#    #+#             */
/*   Updated: 2020/11/13 15:53:13 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "printf.h"
#include <stdio.h>

void	ft_putchar(char *dst, int n, char c)
{
	dst[n] = c;
}

int		count_len(unsigned nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

char	get_char(char *base, int n)
{
	if (g_var->specifier == 'x' && n > 10)
		return (base[n] + 32);
	return (base[n]);
}

void	ft_putnbr_base(unsigned nb, char *dst, int i)
{
	if (nb >= 16)
	{
		ft_putnbr_base(nb / 16, dst, i - 1);
		ft_putnbr_base(nb % 16, dst, i);
	}
	else
		ft_putchar(dst, i, get_char("0123456789ABCDEF", nb));
}

char	*get_hex(unsigned nb)
{
	int		len;
	char	*str;

	len = count_len(nb);
	str = malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	ft_putnbr_base(nb, str, len - 1);
	return (str);
}
