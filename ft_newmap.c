/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:13:50 by jsaguez           #+#    #+#             */
/*   Updated: 2020/03/09 14:13:52 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_newmlx(t_mlx *mlx)
{
	mlx->v = 0.05;
	mlx->perp = malloc(sizeof(float) * (2560));
	ft_bzero(mlx->perp, sizeof(float) * 2560);
}

void	ft_newmap(t_struct *info)
{
	if (!(info->mlx = malloc(sizeof(t_mlx))))
		ft_error(1, info);
	if (!(info->text = malloc(sizeof(t_text))))
		ft_error(1, info);
	if (!(info->sprites = malloc(sizeof(*info->sprites) * (info->nb))))
		ft_error(1, info);
	if (!(info->d = malloc(sizeof(t_draw))))
		ft_error(1, info);
	if (!(info->sp = malloc(sizeof(t_sp))))
		ft_error(1, info);
	ft_bzero(info->mlx, sizeof(t_mlx));
	ft_newmlx(info->mlx);
	ft_bzero(info->text, sizeof(t_text));
	ft_bzero(info->sprites, sizeof(*info->sprites) * (info->nb));
	ft_bzero(info->d, sizeof(t_draw));
	ft_bzero(info->sp, sizeof(t_sp));
}
