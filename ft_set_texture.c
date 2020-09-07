/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:15:24 by jsaguez           #+#    #+#             */
/*   Updated: 2020/09/07 17:55:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_texture_bonus(t_struct *info, t_text *text)
{
	text->cp = NULL;
	text->fp = NULL;
	if (!(text->cp = mlx_xpm_file_to_image(
	info->mlx->init, info->c, &text->cx, &text->cy)))
		ft_error(3, info);
	text->c = ft_imgaddr(text->cp);
	if (!(text->fp = mlx_xpm_file_to_image(
	info->mlx->init, info->f, &text->fx, &text->fy)))
		ft_error(3, info);
	text->f = ft_imgaddr(text->fp);
}

void	ft_texture_null(t_text *text)
{
	text->nop = NULL;
	text->sop = NULL;
	text->wep = NULL;
	text->eap = NULL;
	text->sp = NULL;
}

void	ft_set_texture(t_struct *info, t_text *text)
{
	ft_texture_null(text);
	if (!(text->nop = mlx_xpm_file_to_image(
	info->mlx->init, info->no, &text->nox, &text->noy)))
		ft_error(3, info);
	text->no = ft_imgaddr(text->nop);
	if (!(text->sop = mlx_xpm_file_to_image(
	info->mlx->init, info->so, &text->sox, &text->soy)))
		ft_error(3, info);
	text->so = ft_imgaddr(text->sop);
	if (!(text->wep = mlx_xpm_file_to_image(
	info->mlx->init, info->we, &text->wex, &text->wey)))
		ft_error(3, info);
	text->we = ft_imgaddr(text->wep);
	if (!(text->eap = mlx_xpm_file_to_image(
	info->mlx->init, info->ea, &text->eax, &text->eay)))
		ft_error(3, info);
	text->ea = ft_imgaddr(text->eap);
	if (!(text->sp = mlx_xpm_file_to_image(
	info->mlx->init, info->s, &text->sx, &text->sy)))
		ft_error(3, info);
	text->s = ft_imgaddr(text->sp);
	if (BONUS == 1)
		ft_texture_bonus(info, text);
}
