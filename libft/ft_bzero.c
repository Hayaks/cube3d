/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:04:49 by jsaguez           #+#    #+#             */
/*   Updated: 2019/11/13 14:53:47 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*point;
	size_t			i;

	i = 0;
	point = (unsigned char*)s;
	while (i < n)
	{
		point[i] = 0;
		i++;
	}
}
