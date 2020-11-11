/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:01:17 by edebi             #+#    #+#             */
/*   Updated: 2020/10/29 19:15:37 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *cp_s1;
	unsigned char *cp_s2;

	cp_s1 = (unsigned char *)s1;
	cp_s2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*cp_s1 != *cp_s2)
			return (*cp_s1 - *cp_s2);
		cp_s1++;
		cp_s2++;
	}
	return (0);
}
