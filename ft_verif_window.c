/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 09:53:58 by jsaguez           #+#    #+#             */
/*   Updated: 2020/09/05 11:50:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_verif_window(t_struct *info, t_mlx *mlx)
{
	int	sizex;
	int	sizey;

	mlx_get_screen_size(mlx->init, &sizex, &sizey);
	info->x = (info->x < (sizex / 2)) ? (sizex / 2) : info->x;
	info->y = (info->y < (sizey / 2)) ? (sizey / 2) : info->y;
	info->x = (info->x > sizex) ? sizex : info->x;
	info->y = (info->y > sizey) ? sizey : info->y;
	mlx->perp = malloc(sizeof(float) * (sizex));
	ft_bzero(mlx->perp, sizeof(float) * sizex);
}
