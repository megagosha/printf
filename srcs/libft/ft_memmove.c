/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:09:18 by edebi             #+#    #+#             */
/*   Updated: 2020/11/03 14:19:50 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cp_dst;
	const char	*cp_src;

	if (src == NULL && dst == NULL)
		return (NULL);
	cp_dst = dst;
	cp_src = src;
	if (cp_src > cp_dst)
	{
		while (len--)
		{
			*cp_dst = *cp_src;
			cp_dst++;
			cp_src++;
		}
	}
	else
	{
		while (len > 0)
		{
			cp_dst[len - 1] = cp_src[len - 1];
			len--;
		}
	}
	return (dst);
}
