/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:08:53 by jsaguez           #+#    #+#             */
/*   Updated: 2019/11/13 14:58:59 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*point;
	size_t	i;

	point = (char*)s;
	i = 0;
	while (i < n)
	{
		if (point[i] == c)
			return (&point[i]);
		i++;
	}
	return (0);
}
