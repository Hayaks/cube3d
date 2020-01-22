/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:26:37 by jsaguez           #+#    #+#             */
/*   Updated: 2019/11/13 15:02:34 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*chaine;
	unsigned int	i;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	chaine = malloc(sizeof(*chaine) * (len + 1));
	if (!chaine)
		return (0);
	i = 0;
	while (s[i] && i < len)
	{
		chaine[i] = s[i + start];
		i++;
	}
	chaine[i] = '\0';
	return (chaine);
}
