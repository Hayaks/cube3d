/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:13:15 by jsaguez           #+#    #+#             */
/*   Updated: 2020/03/09 14:13:19 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_up(t_struct *info, t_mlx *mlx, float v)
{
	if (info->map[(int)(mlx->posx + mlx->dirx * 0.5)][(int)mlx->posy]
	!= '1' && info->map[(int)(mlx->posx + mlx->dirx * 0.5)][(int)mlx->posy]
	!= '2' && mlx->up == 1)
		mlx->posx += mlx->dirx * v;
	if (info->map[(int)mlx->posx][(int)(mlx->posy + mlx->diry * 0.5)]
	!= '1' && info->map[(int)mlx->posx][(int)(mlx->posy + mlx->diry * 0.5)]
	!= '2' && mlx->up == 1)
		mlx->posy += mlx->diry * v;
}

void	ft_down(t_struct *info, t_mlx *mlx, float v)
{
	if (info->map[(int)(mlx->posx - mlx->dirx * 0.5)][(int)mlx->posy]
	!= '1' && info->map[(int)(mlx->posx - mlx->dirx * 0.5)][(int)mlx->posy]
	!= '2' && mlx->down == 1)
		mlx->posx -= mlx->dirx * v;
	if (info->map[(int)mlx->posx][(int)(mlx->posy - mlx->diry * 0.5)]
	!= '1' && info->map[(int)mlx->posx][(int)(mlx->posy - mlx->diry * 0.5)]
	!= '2' && mlx->down == 1)
		mlx->posy -= mlx->diry * v;
}

void	ft_right(t_struct *info, t_mlx *mlx, float v)
{
	if (info->map[(int)(mlx->posx + mlx->planex * 0.5)][(int)mlx->posy]
	!= '1' && info->map[(int)(mlx->posx + mlx->planex * 0.5)][(int)mlx->posy]
	!= '2' && mlx->right == 1)
		mlx->posx += mlx->planex * v;
	if (info->map[(int)mlx->posx][(int)(mlx->posy + mlx->planey * 0.5)]
	!= '1' && info->map[(int)mlx->posx][(int)(mlx->posy + mlx->planey * 0.5)]
	!= '2' && mlx->right == 1)
		mlx->posy += mlx->planey * v;
}

void	ft_left(t_struct *info, t_mlx *mlx, float v)
{
	if (info->map[(int)(mlx->posx - mlx->planex * 0.5)][(int)mlx->posy]
	!= '1' && info->map[(int)(mlx->posx - mlx->planex * 0.5)][(int)mlx->posy]
	!= '2' && mlx->left == 1)
		mlx->posx -= mlx->planex * v;
	if (info->map[(int)mlx->posx][(int)(mlx->posy - mlx->planey * 0.5)]
	!= '1' && info->map[(int)mlx->posx][(int)(mlx->posy - mlx->planey * 0.5)]
	!= '2' && mlx->left == 1)
		mlx->posy -= mlx->planey * v;
}

void	ft_move(t_struct *info)
{
	float	v;

	v = info->mlx->v;
	ft_up(info, info->mlx, v);
	ft_down(info, info->mlx, v);
	ft_right(info, info->mlx, v);
	ft_left(info, info->mlx, v);
}
