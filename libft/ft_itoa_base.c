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

static int	ft_nb_size(unsigned int nb, int b)
{
	int	size;

	size = 0;
	while (nb >= (unsigned int)b)
	{
		nb = nb / b;
		size++;
	}
	return (size + 1);
}

char		*ft_itoa_b(char c, unsigned int nbr, int b)
{
	char				*str;
	unsigned int		nb;
	int					index;
	int					size;

	nb = nbr;
	index = 0;
	size = ft_nb_size(nb, b);
	if (!(str = malloc(sizeof(*str) * (size + 1))))
		return (0);
	index = size - 1;
	while (index >= 0)
	{
		if (c == 'u')
			str[index] = (char)(nb % 10 + 48);
		if (c == 'x')
			str[index] = (nb % b < 10) ? nb % b + '0' : nb % b + 'a' - 10;
		if (c == 'X')
			str[index] = (nb % b < 10) ? nb % b + '0' : nb % b + 'A' - 10;
		index--;
		nb = nb / b;
	}
	str[index] = nb % b + 48;
	str[size] = '\0';
	return (str);
}
