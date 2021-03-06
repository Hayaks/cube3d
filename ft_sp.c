/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:41:52 by jsaguez           #+#    #+#             */
/*   Updated: 2020/03/10 14:42:00 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_vide(t_struct *info, int *img)
{
	int i;

	i = 0;
	while (i < (info->x * info->y))
	{
		if (img[i] == 0)
			img[i] = 0xFFFFFFFF;
		i++;
	}
}

void	ft_init(t_struct *info, t_mlx *mlx, t_s **sprites, t_sp *sp)
{
	sprites[sp->final[sp->i]]->img = ft_imgaddr(mlx->img);
	sp->spritex = sprites[sp->final[sp->i]]->x + 0.5 - mlx->posx;
	sp->spritey = sprites[sp->final[sp->i]]->y + 0.5 - mlx->posy;
	sp->invdet = 1.0 /
	(mlx->planex * mlx->diry - mlx->planey * mlx->dirx);
	sp->transformx = sp->invdet *
	(mlx->diry * sp->spritex - mlx->dirx * sp->spritey);
	sp->transformy = sp->invdet *
	(-mlx->planey * sp->spritex + mlx->planex * sp->spritey);
	sp->spritescreenx = (int)((info->x / 2) *
	(1.0 + sp->transformx / sp->transformy));
	sp->spriteheight = abs((int)(info->y / sp->transformy));
	sp->drawstarty = -sp->spriteheight / 2 + info->y / 2;
	if (sp->drawstarty < 0)
		sp->drawstarty = 0;
	sp->drawendy = sp->spriteheight / 2 + info->y / 2;
	if (sp->drawendy >= info->y)
		sp->drawendy = info->y;
	sp->spritewidth = abs((int)(info->y / sp->transformy));
	sp->drawstartx = -sp->spritewidth / 2 + sp->spritescreenx;
	if (sp->drawstartx < 0)
		sp->drawstartx = 0;
	sp->drawendx = sp->spritewidth / 2 + sp->spritescreenx;
	if (sp->drawendx >= info->x)
		sp->drawendx = info->x;
}

void	ft_ds(t_struct *info, t_mlx *mlx, t_s **sprites, t_sp *sp)
{
	sp->y = sp->drawstarty;
	sp->texx = (int)((256 * (sp->drawstartx - (-sp->spritewidth / 2
	+ sp->spritescreenx)) * info->text->sx / sp->spritewidth) / 256);
	if (sp->transformy >= 0 && sp->drawstartx >= 0 && sp->drawstartx <=
	info->x && sp->transformy < mlx->perp[sp->drawstartx])
		while (sp->y < sp->drawendy && sp->y < info->y)
		{
			sp->d = sp->y * 256 - info->y * 128 + sp->spriteheight * 128;
			sp->texy = ((sp->d * info->text->sy) / sp->spriteheight) / 256;
			if ((info->text->sx * sp->texy + sp->texx) > 0)
				if (info->text->s[info->text->sx * sp->texy + sp->texx] != 0)
					sprites[sp->final[sp->i]]->img[sp->drawstartx + info->x *
				sp->y] = info->text->s[info->text->sx * sp->texy + sp->texx];
			sp->y++;
		}
	sp->drawstartx++;
}

void	ft_sp(t_struct *info, t_mlx *m, t_s **s, t_sp *sp)
{
	sp->final = NULL;
	if (!(sp->final = malloc(sizeof(*sp->final) * (info->nb + 1))))
		ft_error(1, info);
	ft_bzero(sp->final, sizeof(*sp->final) * info->nb + 1);
	sp->i = 0;
	sp->y = 0;
	while (sp->y < info->nb)
	{
		s[sp->y]->dist = ((int)m->posx - s[sp->y]->x) *
		((int)m->posx - s[sp->y]->x) + ((int)m->posy -
		s[sp->y]->y) * ((int)m->posy - s[sp->i]->y);
		sp->y++;
	}
	sp->final = ft_tri(info, sp->final);
	while (sp->i < (info->nb) && sp->final[sp->i] != -1)
	{
		ft_init(info, m, s, sp);
		while (sp->drawstartx < sp->drawendx)
			ft_ds(info, m, s, sp);
		s[sp->final[sp->i]]->dist = 0.0;
		sp->i++;
	}
	free(sp->final);
	sp->final = NULL;
}
