/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:42:05 by jsaguez           #+#    #+#             */
/*   Updated: 2019/11/13 15:04:38 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_size(int nb)
{
	int	size;

	size = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		size++;
	}
	return (size + 1);
}

static	int	ft_nombre(int nbr, int nb)
{
	if (nbr < 0)
		nb = nbr * -1;
	else
		nb = nbr;
	return (nb);
}

char		*ft_itoa(int nbr)
{
	char	*str;
	int		nb;
	int		index;
	int		size;

	nb = 0;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	nb = ft_nombre(nbr, nb);
	index = 0;
	size = ft_nb_size(nb);
	if (!(str = malloc(sizeof(*str) * (size + 1 + (nbr < 0 ? 1 : 0)))))
		return (0);
	if (nbr < 0 && (str[index] = '-'))
		size++;
	index = size - 1;
	while (nb >= 10)
	{
		str[index] = (char)(nb % 10 + 48);
		index--;
		nb = nb / 10;
	}
	str[index] = (char)(nb % 10 + 48);
	str[size] = '\0';
	return (str);
}
