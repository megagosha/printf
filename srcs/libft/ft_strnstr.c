/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:44:35 by edebi             #+#    #+#             */
/*   Updated: 2020/11/07 15:46:12 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	len_n;

	len_n = ft_strlen(needle);
	if (len_n > len)
		return ((char *)0);
	else
		i = len - len_n + 1;
	while (i > 0)
	{
		if (ft_strncmp(haystack, needle, len_n))
			haystack++;
		else
			return ((char *)haystack);
		i--;
	}
	return (NULL);
}
