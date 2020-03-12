/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_longlong.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:25:00 by jsaguez           #+#    #+#             */
/*   Updated: 2019/12/16 14:25:03 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_nb_size(unsigned long nb, int base)
{
	int	size;

	size = 0;
	while (nb >= base)
	{
		nb = nb / base;
		size++;
	}
	return (size + 1);
}

char		*ft_itoa_base_longlong(unsigned long nbr, int base)
{
	char			*str;
	unsigned long	nb;
	int				index;
	int				size;

	nb = nbr;
	index = 0;
	size = ft_nb_size(nb, base);
	if (!(str = malloc(sizeof(*str) * (size + 1))))
		return (0);
	index = size - 1;
	while (index >= 0)
	{
		str[index] = (nb % base < 10) ? nb % base + '0' : nb % base + 'a' - 10;
		index--;
		nb = nb / base;
	}
	str[index] = nb % base + 48;
	str[size] = '\0';
	return (str);
}
