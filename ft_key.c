/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:10:17 by jsaguez           #+#    #+#             */
/*   Updated: 2020/03/09 14:11:36 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	ft_presskey(int key, t_struct *info)
{
	if (key == 13)
		info->mlx->up = 1;
	if (key == 1)
		info->mlx->down = 1;
	if (key == 0)
		info->mlx->left = 1;
	if (key == 2)
		info->mlx->right = 1;
	if (key == 123)
		info->mlx->leftr = 1;
	if (key == 124)
		info->mlx->rightr = 1;
	if (key == 257)
		info->mlx->v = 0.1;
	if (key == 53)
		ft_error(5, info);
	return (1);
}

int	ft_releasekey(int key, t_struct *info)
{
	if (key == 13)
		info->mlx->up = 0;
	if (key == 1)
		info->mlx->down = 0;
	if (key == 0)
		info->mlx->left = 0;
	if (key == 2)
		info->mlx->right = 0;
	if (key == 123)
		info->mlx->leftr = 0;
	if (key == 124)
		info->mlx->rightr = 0;
	if (key == 257)
		info->mlx->v = 0.05;
	return (1);
}
