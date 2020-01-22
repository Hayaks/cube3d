/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:39:10 by jsaguez           #+#    #+#             */
/*   Updated: 2019/11/13 15:04:54 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*chaine;
	int		i;

	i = 0;
	if (!s || !f)
		return (0);
	chaine = ft_strdup(s);
	if (!chaine)
		return (0);
	while (chaine[i])
	{
		chaine[i] = f(i, chaine[i]);
		i++;
	}
	chaine[i] = 0;
	return (chaine);
}
