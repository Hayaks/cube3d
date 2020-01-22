/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:28:08 by jsaguez           #+#    #+#             */
/*   Updated: 2019/11/13 15:04:25 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strdup_spe(char *s, int end, int size)
{
	char	*chaine;
	int		i;
	int		start;

	i = 0;
	start = end - size;
	if ((chaine = malloc(sizeof(*chaine) * size + 1)) == 0)
		return (0);
	while (i < size)
	{
		chaine[i] = s[start + i];
		i++;
	}
	chaine[i] = '\0';
	return (chaine);
}

static char	**ft_remplissage(char *s, char c, char **point_tab)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = -1;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			j++;
		}
		if (j > 0)
			point_tab[++x] = ft_strdup_spe(s, i, j);
		j = 0;
	}
	point_tab[x + 1] = 0;
	return (point_tab);
}

char		**ft_split(char const *s, char c)
{
	char	**point_tab;
	int		nbr;
	int		i;

	i = 1;
	nbr = 0;
	if (!s)
		return (0);
	if (s[0] == '\0')
	{
		point_tab = malloc(sizeof(*point_tab) * 1);
		return (ft_remplissage((char*)s, c, point_tab));
	}
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			nbr++;
		i++;
	}
	if (s[i - 1] != c)
		nbr++;
	if ((point_tab = malloc(sizeof(*point_tab) * (nbr + 1))) == 0)
		return (0);
	return (ft_remplissage((char*)s, c, point_tab));
}
