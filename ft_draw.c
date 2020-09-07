/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:11:46 by jsaguez           #+#    #+#             */
/*   Updated: 2020/09/07 15:51:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_transparent(int *img, int pixel, t_struct *info)
{
	int i;
	int c;
	int f;

	i = 0;
	c = ft_atoi(info->c);
	f = ft_atoi(info->f);
	while (i < pixel)
	{
		if (img[i] == 0 && i < (pixel / 2))
			img[i] = c;
		if (img[i] == 0 && i > (pixel / 2))
			img[i] = f;
		i++;
	}
}

void	ft_init_draw(t_struct *info, t_mlx *mlx, t_draw *d)
{
	d->y = 0;
	d->camerax = (2.0 * (float)d->x / (float)info->x) - 1.0;
	d->raydirx = mlx->dirx + mlx->planex * d->camerax;
	d->raydiry = mlx->diry + mlx->planey * d->camerax;
	d->mapx = (int)mlx->posx;
	d->mapy = (int)mlx->posy;
	d->deltadistx = fabs(1 / d->raydirx);
	d->deltadisty = fabs(1 / d->raydiry);
	d->hit = 0;
	d->side = 0;
}

void	ft_wall(t_struct *info, t_draw *d)
{
	while (d->y <= d->end)
	{
		d->texy = (d->y * 2 - info->y + d->hauteurligne)
		* (64 / 2) / d->hauteurligne;
		if ((d->x + info->x * d->y) > 0 && (d->texx + d->texy * 64) > 0)
		{
			if (d->side == 0 && d->raydirx < 0)
				d->img[d->x + info->x * d->y] =
				info->text->no[d->texx + d->texy * 64];
			else if (d->side == 0 && d->raydirx > 0)
				d->img[d->x + info->x * d->y] =
				info->text->so[d->texx + d->texy * 64];
			else if (d->side == 1 && d->raydiry < 0)
				d->img[d->x + info->x * d->y] =
				info->text->we[d->texx + d->texy * 64];
			else if (d->side == 1 && d->raydiry > 0)
				d->img[d->x + info->x * d->y] =
				info->text->ea[d->texx + d->texy * 64];
			if (d->img[d->x + info->x * d->y] == 0)
				d->img[d->x + info->x * d->y]++;
		}
		d->y++;
	}
}

void	ft_floor(t_struct *info, t_mlx *mlx, t_draw *d)
{
	while (d->y < info->y)
	{
		d->currentdist = info->y / (2.0 * d->y - info->y);
		d->weight = d->currentdist / d->perpwalldist;
		d->currentfloorx = d->weight * d->floorxwall +
		(1.0 - d->weight) * mlx->posx;
		d->currentfloory = d->weight * d->floorywall +
		(1.0 - d->weight) * mlx->posy;
		d->floortextx = (int)(d->currentfloorx * 64) % 64;
		d->floortexty = (int)(d->currentfloory * 64) % 64;
		if ((d->x + info->x * d->y) > 0
		&& d->floortextx + d->floortexty * 64 > 0)
		{
			d->img[d->x + info->x * d->y] =
		info->text->f[d->floortextx + d->floortexty * 64];
			d->img[d->x + info->x * (info->y - d->y)] =
		info->text->c[d->floortextx + d->floortexty * 64];
		}
		d->y++;
	}
}

void	ft_draw(t_struct *info, t_mlx *mlx, t_draw *d)
{
	d->x = 0;
	d->img = ft_imgaddr(mlx->img);
	while (d->x < info->x)
	{
		ft_init_draw(info, mlx, d);
		ft_vector(info, mlx, d);
		ft_wall(info, d);
		if (BONUS == 1)
			ft_floor(info, mlx, d);
		mlx->perp[d->x] = d->perpwalldist;
		d->x++;
	}
	if (BONUS == 0)
		ft_transparent(d->img, (info->x * info->y), info);
	ft_sp(info, info->mlx, info->sprites, info->sp);
	if (info->ac == 3)
		ft_bmp(info);
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->img, 0, 0);
}
