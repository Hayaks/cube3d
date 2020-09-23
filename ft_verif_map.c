/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:16:48 by jsaguez           #+#    #+#             */
/*   Updated: 2020/09/23 09:46:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_verif_pos(t_struct *info)
{
	if (info->mlx->dirx == 0)
		ft_error(2, info);
}

void	ft_verif_map(t_struct *info)
{
	size_t	i;
	size_t	j;

	j = 1;
	if (info->map == NULL)
		ft_error(2, info);
	while (j < (size_t)(info->i - 1))
	{
		i = 0;
		while (info->map[j][i])
		{
			if (info->map[j][i] != '1' && info->map[j][i] != ' ' &&
			((ft_strlen(info->map[j - 1]) - 1) < i ||
			(ft_strlen(info->map[j + 1]) - 1) < i))
				ft_error(2, info);
			if (info->map[j][i] != '1' && info->map[j][i] != ' ' &&
			(info->map[j - 1][i] == ' ' || info->map[j + 1][i] == ' ' ||
			info->map[j][i - 1] == ' ' ||
			info->map[j][i + 1] == ' '))
				ft_error(2, info);
			i++;
		}
		j++;
	}
	ft_verif_pos(info);
}
