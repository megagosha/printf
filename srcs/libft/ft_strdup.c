/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:47:47 by edebi             #+#    #+#             */
/*   Updated: 2020/10/30 14:55:09 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len_str;
	char	*str;

	len_str = ft_strlen(s1);
	str = ft_calloc(len_str + 1, 1);
	if (str == NULL)
		return ((char *)0);
	ft_memcpy(str, s1, len_str + 1);
	return (str);
}
