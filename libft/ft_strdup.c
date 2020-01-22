/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:37:00 by jsaguez           #+#    #+#             */
/*   Updated: 2019/11/13 15:02:18 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*chaine;
	int		i;

	chaine = malloc(sizeof(*chaine) * (ft_strlen(src) + 1));
	if (chaine == NULL)
		return (0);
	i = 0;
	while (src[i])
	{
		chaine[i] = src[i];
		i++;
	}
	chaine[i] = '\0';
	return (chaine);
}
