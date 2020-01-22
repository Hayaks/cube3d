/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:26:38 by jsaguez           #+#    #+#             */
/*   Updated: 2019/11/13 14:54:08 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*point_dst;
	unsigned char	*point_src;
	size_t			i;

	i = 0;
	point_dst = (unsigned char*)dst;
	point_src = (unsigned char*)src;
	if (dst == NULL && src == NULL)
		return (0);
	while (i < n)
	{
		point_dst[i] = point_src[i];
		i++;
	}
	return (dst);
}
