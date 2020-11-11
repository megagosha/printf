/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:39:55 by edebi             #+#    #+#             */
/*   Updated: 2020/11/03 18:43:56 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*str;

	if (!s1 || !set)
		return ((char *)s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	len = ft_strlen(s1 + start) + start;
	end = len - 1;
	while (s1[end] && ft_strrchr(set, s1[end]))
		end--;
	if (start >= len)
		len = 1;
	else
		len = len - start - (len - end) + 2;
	str = malloc(len);
	if (str == NULL)
		return ((char *)0);
	ft_strlcpy(str, s1 + start, end - start + 2);
	str[end - start + 2] = '\0';
	return (str);
}
