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

void	ft_newmlx(mlx_param *mlx)
{
	mlx->posx = 0;
	mlx->posy = 0;
	mlx->dirx = 0;
	mlx->diry = 0;
	mlx->planex = 0;
	mlx->planey = 0;
	mlx->up = 0;
	mlx->down = 0;
	mlx->left = 0;
	mlx->right = 0;
	mlx->leftr = 0;
	mlx->rightr = 0;
	mlx->v = 0.05;
	mlx->perp = malloc(sizeof(float) * (2560));
	ft_bzero(mlx->perp, sizeof(float) * 2560);
}

void	ft_newmap(t_struct *info)
{
	ft_newmlx(info->mlx);
	ft_bzero(info->text, sizeof(text_param));
	ft_bzero(info->sprites, sizeof(*info->sprites) * (info->nb * 2));
	ft_bzero(info->d, sizeof(draw_param));
	ft_bzero(info->sp, sizeof(s_param));
}
