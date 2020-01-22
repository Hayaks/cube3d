/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 09:10:38 by jsaguez           #+#    #+#             */
/*   Updated: 2019/11/13 15:02:47 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*chaine;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	if (!(chaine = malloc(sizeof(chaine) *
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
		chaine[j++] = s1[i++];
	i = 0;
	while (s2[i])
		chaine[j++] = s2[i++];
	chaine[j] = '\0';
	return (chaine);
}
