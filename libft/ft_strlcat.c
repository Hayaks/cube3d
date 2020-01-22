/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:27:06 by jsaguez           #+#    #+#             */
/*   Updated: 2019/11/13 15:01:12 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	s;
	size_t	total;

	i = 0;
	s = 0;
	while (dest[i] && i < size)
		i++;
	if (i >= size)
		return (size + ft_strlen(src));
	total = ft_strlen(dest) + ft_strlen(src);
	while (i < size - 1 && src[s])
		dest[i++] = src[s++];
	dest[i] = '\0';
	return (total);
}
