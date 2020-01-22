/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:45:44 by jsaguez           #+#    #+#             */
/*   Updated: 2019/11/13 15:10:41 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*point_s1;
	unsigned char	*point_s2;
	size_t			i;

	point_s1 = (unsigned char*)s1;
	point_s2 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (point_s1[i] == point_s2[i] && i < n - 1)
		i++;
	return (point_s1[i] - point_s2[i]);
}
