/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:39:40 by edebi             #+#    #+#             */
/*   Updated: 2020/11/03 17:42:56 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	a;
	int				i;

	i = 0;
	a = (unsigned char)c;
	if (src == NULL && dst == NULL)
		return (NULL);
	while (n > 0)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		if (((unsigned char *)src)[i] == a)
			return ((unsigned char *)dst + i + 1);
		n--;
		i++;
	}
	return (NULL);
}
