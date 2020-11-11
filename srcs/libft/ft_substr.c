/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edebi <edebi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:15:14 by edebi             #+#    #+#             */
/*   Updated: 2020/11/03 18:07:49 by edebi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	str_len;

	if (s == NULL)
		return (NULL);
	if ((str_len = ft_strlen(s)) <= start)
		len = 0;
	if (str_len > len)
		str_len = len;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr = ft_memcpy(ptr, s + start, str_len + 1);
	ptr[len] = '\0';
	return (ptr);
}
