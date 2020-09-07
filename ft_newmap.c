/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:13:50 by jsaguez           #+#    #+#             */
/*   Updated: 2020/09/07 17:52:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

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
	info->mlx->v = 0.1;
	ft_bzero(info->text, sizeof(t_text));
	ft_bzero(info->sprites, sizeof(*info->sprites) * (info->nb));
	ft_bzero(info->d, sizeof(t_draw));
	ft_bzero(info->sp, sizeof(t_sp));
}
