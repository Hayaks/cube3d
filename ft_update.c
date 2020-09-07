/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:16:16 by jsaguez           #+#    #+#             */
/*   Updated: 2020/09/07 17:48:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_rotate(t_mlx *mlx)
{
	float	v;
	float	tempdirx;
	float	tempplanex;

	v = 0.15;
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
	mlx_destroy_image(info->mlx->init, info->mlx->img);
	info->mlx->img = mlx_new_image(info->mlx->init, info->x, info->y);
	ft_bzero(info->d->img, sizeof(*info->d->img) * (info->x * info->y));
	ft_draw(info, info->mlx, info->d);
	return (0);
}
