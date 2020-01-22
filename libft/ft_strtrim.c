/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:05:34 by jsaguez           #+#    #+#             */
/*   Updated: 2019/11/13 15:04:10 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		return (0);
	ft_bzero(mem, size);
	return (mem);
}

static char	*ft_remplissage(char *chaine, size_t i, size_t j, const char *s1)
{
	size_t	c;

	c = 0;
	while (i <= j)
	{
		chaine[c] = s1[i];
		c++;
		i++;
	}
	chaine[c] = '\0';
	return (chaine);
}

char		*ft_strtrim(const char *s1, const char *set)
{
	char	*chaine;
	size_t	i;
	size_t	j;
	size_t	size;

	if (!set || !s1)
		return (0);
	i = 0;
	j = 0;
	size = ft_strlen((char*)s1);
	while (s1[i] && ft_charset((char)s1[i], (char*)set) == 1)
		i++;
	if (i == size)
		return (ft_memalloc(size));
	while (s1[j + 1])
		j++;
	while (s1[j] && ft_charset((char)s1[j], (char*)set) == 1)
		j--;
	chaine = malloc(sizeof(*chaine) * (j - i + 2));
	if (!chaine)
		return (0);
	chaine = ft_remplissage(chaine, i, j, s1);
	return (chaine);
}
