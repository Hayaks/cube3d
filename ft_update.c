/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:16:16 by jsaguez           #+#    #+#             */
/*   Updated: 2020/03/09 14:16:17 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_rotate(mlx_param *mlx)
{
	float	v;
	float	tempdirx;
	float	tempplanex;

	v = 0.05;
	if (mlx->rightr == 1)
	{
		tempdirx = mlx->dirx;
		mlx->dirx = mlx->dirx * cos(-v) - mlx->diry * sin(-v);
		mlx->diry = tempdirx * sin(-v) + mlx->diry * cos(-v);
		tempplanex = mlx->planex;
		mlx->planex = mlx->planex * cos(-v) - mlx->planey * sin(-v);
		mlx->planey = tempplanex * sin(-v) + mlx->planey * cos(-v);
	}
	if (mlx->leftr == 1)
	{
		tempdirx = mlx->dirx;
		mlx->dirx = mlx->dirx * cos(v) - mlx->diry * sin(v);
		mlx->diry = tempdirx * sin(v) + mlx->diry * cos(v);
		tempplanex = mlx->planex;
		mlx->planex = mlx->planex * cos(v) - mlx->planey * sin(v);
		mlx->planey = tempplanex * sin(v) + mlx->planey * cos(v);
	}
}

int		ft_update(t_struct *info)
{
	ft_move(info);
	ft_rotate(info->mlx);
	ft_bzero(info->d->img, sizeof(*info->d->img) * (info->x * info->y));
	ft_draw(info, info->mlx, info->d);
	return (0);
}
