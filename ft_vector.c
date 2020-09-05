/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:16:40 by jsaguez           #+#    #+#             */
/*   Updated: 2020/09/05 12:44:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_hauteur(t_struct *info, t_draw *d)
{
	d->hauteurligne = (float)fabs((float)(info->y / d->perpwalldist));
	d->start = (int)(-d->hauteurligne / 2 + info->y / 2);
	d->end = (int)(d->hauteurligne / 2 + info->y / 2);
	if (d->start < 0)
		d->start = 0;
	if (d->end >= info->y)
		d->end = info->y;
	d->y = d->start;
}

void	ft_texx(t_draw *d)
{
	d->texx = (int)(d->wallx * 64);
	if (d->side == 0 && d->raydirx > 0)
	{
		d->texx = 64 - d->texx - 1;
		d->floorxwall = d->mapx;
		d->floorywall = d->mapy + d->wallx;
	}
	else if (d->side == 0 && d->raydirx < 0)
	{
		d->floorxwall = d->mapx + 1.0;
		d->floorywall = d->mapy + d->wallx;
	}
	else if (d->side == 1 && d->raydiry < 0)
	{
		d->texx = 64 - d->texx - 1;
		d->floorxwall = d->mapx + d->wallx;
		d->floorywall = d->mapy + 1.0;
	}
	else if (d->side == 1 && d->raydiry > 0)
	{
		d->floorxwall = d->mapx + d->wallx;
		d->floorywall = d->mapy;
	}
}

void	ft_perp(t_mlx *mlx, t_draw *d)
{
	if (d->side == 0)
	{
		d->perpwalldist = (float)fabs(((float)d->mapx
		- mlx->posx + (1.0 - (float)d->stepx) / 2.0) / d->raydirx);
		d->wallx = mlx->posy + ((d->mapx
		- mlx->posx + (1 - d->stepx) / 2) / d->raydirx) * d->raydiry;
	}
	else
	{
		d->perpwalldist = (float)fabs(((float)d->mapy
		- mlx->posy + (1.0 - (float)d->stepy) / 2.0) / d->raydiry);
		d->wallx = mlx->posx + ((d->mapy - mlx->posy
		+ (1 - d->stepy) / 2) / d->raydiry) * d->raydirx;
	}
	d->wallx -= floor(d->wallx);
}

void	ft_hit(t_struct *info, t_draw *d)
{
	while (d->hit == 0)
	{
		if (d->sidedistx < d->sidedisty)
		{
			d->sidedistx += d->deltadistx;
			d->mapx += d->stepx;
			d->side = 0;
		}
		else
		{
			d->sidedisty += d->deltadisty;
			d->mapy += d->stepy;
			d->side = 1;
		}
		if (info->map[d->mapx][d->mapy] == '1')
			d->hit = 1;
	}
}

void	ft_vector(t_struct *info, t_mlx *mlx, t_draw *d)
{
	if (d->raydirx < 0)
	{
		d->stepx = -1;
		d->sidedistx = (mlx->posx - d->mapx) * d->deltadistx;
	}
	else
	{
		d->stepx = 1;
		d->sidedistx = (d->mapx + 1.0 - mlx->posx) * d->deltadistx;
	}
	if (d->raydiry < 0)
	{
		d->stepy = -1;
		d->sidedisty = (mlx->posy - d->mapy) * d->deltadisty;
	}
	else
	{
		d->stepy = 1;
		d->sidedisty = (d->mapy + 1.0 - mlx->posy) * d->deltadisty;
	}
	ft_hit(info, d);
	ft_perp(mlx, d);
	ft_texx(d);
	ft_hauteur(info, d);
}
