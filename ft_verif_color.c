/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 10:43:08 by jsaguez           #+#    #+#             */
/*   Updated: 2020/08/17 12:14:50 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_verif_color(char **tab, t_struct *info, int result, int type)
{
	if (ft_atoi(tab[0]) < 0 || ft_atoi(tab[0]) > 255)
		ft_error(3, info);
	if (ft_atoi(tab[1]) < 0 || ft_atoi(tab[1]) > 255)
		ft_error(3, info);
	if (ft_atoi(tab[2]) < 0 || ft_atoi(tab[2]) > 255)
		ft_error(3, info);
	result = ft_atoi(tab[0]) * (int)pow(256, 2) +
	ft_atoi(tab[1]) * 256 + ft_atoi(tab[2]);
	if (type == 1)
		info->f = ft_itoa(result);
	if (type == 2)
		info->c = ft_itoa(result);
}
