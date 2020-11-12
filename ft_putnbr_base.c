/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:04:07 by edebi             #+#    #+#             */
/*   Updated: 2020/11/12 21:22:30 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	get_char(char *base, int n)
{
	if (g_var->specifier == 'x' && n > 10)
		return (base[n] + 32);
	return (base[n]);
}

void	ft_putnbr_base(unsigned nb)
{
	if (nb >= 16)
	{
		ft_putnbr_base(nb / 16);
		ft_putnbr_base(nb % 16);
	}
	else
		ft_putchar(get_char("0123456789ABCDEF", nb));
}
