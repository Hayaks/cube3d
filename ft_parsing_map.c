/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 12:56:07 by jsaguez           #+#    #+#             */
/*   Updated: 2020/03/09 14:14:51 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_setplayer(char *temp, int j, t_struct *info)
{
	if (info->mlx->dirx == 0 && info->mlx->diry == 0)
	{
		info->mlx->posx = info->i + 0.5;
		info->mlx->posy = j + 0.5;
		if (temp[j] == 'N')
			info->mlx->dirx = -1.0;
		else if (temp[j] == 'S')
			info->mlx->dirx = 1.0;
		else if (temp[j] == 'E')
			info->mlx->diry = 1.0;
		else
			info->mlx->diry = -1.0;
		if (info->mlx->dirx != 0)
			info->mlx->planey = -info->mlx->dirx;
		else
			info->mlx->planex = -info->mlx->diry;
	}
	else
		ft_error(2, info);
}

void	ft_parsing_sprite(int j, t_struct *info)
{
	if (!(info->sprites[info->nb] = malloc(sizeof(t_s))))
		ft_error(1, info);
	info->sprites[info->nb]->x = info->i;
	info->sprites[info->nb]->y = j;
	info->sprites[info->nb]->dist = 0.0;
	info->nb++;
}

void	ft_parsing_map(char *line, t_struct *info)
{
	char	*temp;
	int		j;

	temp = ft_strdup(line);
	j = 0;
	while (temp[j])
	{
		if (!(ft_strchr(MAP, temp[j])))
			ft_error(2, info);
		if (ft_strchr(POS, temp[j]))
			ft_setplayer(temp, j, info);
		if (temp[j] == '2')
			ft_parsing_sprite(j, info);
		j++;
	}
	if (info->i == 0)
		if (!(info->map = malloc(sizeof(*info->map) * 30)))
			ft_error(1, info);
	info->map[info->i] = ft_strdup(temp);
	if (info->map[info->i][j - 1] != '1' &&
	info->map[info->i][j - 1] != ' ')
		ft_error(2, info);
	info->i++;
	free(temp);
}
