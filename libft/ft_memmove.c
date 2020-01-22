/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 08:48:29 by jsaguez           #+#    #+#             */
/*   Updated: 2019/11/13 14:58:45 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*point_dst;
	unsigned char	*point_src;
	size_t			i;

	point_dst = (unsigned char*)dst;
	point_src = (unsigned char*)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	if (point_dst > point_src)
		while (i++ < n)
			point_dst[n - i] = point_src[n - i];
	else
	{
		while (i < n)
		{
			point_dst[i] = point_src[i];
			i++;
		}
	}
	return (dst);
}
