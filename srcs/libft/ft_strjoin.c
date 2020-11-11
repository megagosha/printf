/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:54:45 by edebi             #+#    #+#             */
/*   Updated: 2020/11/03 18:09:59 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return ((char *)0);
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	str = malloc(len + 1);
	if (str == NULL)
		return ((char *)0);
	ft_memset(str, '\0', len + 1);
	if (ft_strlcat(str, s1, len + 1) >= len + 1)
		return ((char *)0);
	if (ft_strlcat(str, s2, len + 1) >= len + 1)
		return ((char *)0);
	return (str);
}
