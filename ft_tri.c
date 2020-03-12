/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:16:09 by jsaguez           #+#    #+#             */
/*   Updated: 2020/03/09 14:16:10 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_recup(t_struct *info, float *tab, int i, int j)
{
	while (i < info->nb)
	{
		tab[j] = info->sprites[i]->dist;
		j++;
		i++;
	}
	i = 0;
	j = 0;
}

void	ft_temp(t_struct *info, int i, int j, float *tab)
{
	float	*temp;

	temp = NULL;
	if (!(temp = malloc(sizeof(*temp) * (info->nb + 1))))
		ft_error(1, info);
	ft_bzero(temp, sizeof(*temp) * (info->nb + 1));
	while ((j + 1) < info->nb)
	{
		if (tab[j] < tab[j + 1])
		{
			temp[i] = tab[j];
			tab[j] = tab[j + 1];
			tab[j + 1] = temp[i];
			i++;
			j = 0;
		}
		j++;
	}
	i = 0;
	j = 0;
	free(temp);
}

int		*ft_tri(t_struct *info, int *final)
{
	int		i;
	int		j;
	float	*tab;

	tab = NULL;
	if (!(tab = malloc(sizeof(*tab) * (info->nb + 1))))
		ft_error(1, info);
	i = 0;
	j = 0;
	ft_recup(info, tab, i, j);
	ft_temp(info, i, j, tab);
	while (j < info->nb)
	{
		while ((int)tab[j] != (int)info->sprites[i]->dist)
			i++;
		final[j] = i;
		info->sprites[i]->dist = 0.0;
		i = 0;
		j++;
	}
	free(tab);
	final[j] = -1;
	return (final);
}
