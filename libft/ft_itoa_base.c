/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:38:26 by jsaguez           #+#    #+#             */
/*   Updated: 2019/12/13 14:06:30 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_size(unsigned int nb, int base)
{
	int	size;

	size = 0;
	while (nb >= (unsigned int)base)
	{
		nb = nb / base;
		size++;
	}
	return (size + 1);
}

char		*ft_itoa_base(char c, unsigned int nbr, int base)
{
	char				*str;
	unsigned int		nb;
	int					index;
	int					size;

	nb = nbr;
	index = 0;
	size = ft_nb_size(nb, base);
	if (!(str = malloc(sizeof(*str) * (size + 1))))
		return (0);
	index = size - 1;
	while (index >= 0)
	{
		if (c == 'u')
			str[index] = (char)(nb % 10 + 48);
		if (c == 'x')
			str[index] = (nb % base < 10) ? nb % base + '0' : nb % base + 'a' - 10;
		if (c == 'X')
			str[index] = (nb % base < 10) ? nb % base + '0' : nb % base + 'A' - 10;
		index--;
		nb = nb / base;
	}
	str[index] = nb % base + 48;
	str[size] = '\0';
	return (str);
}
