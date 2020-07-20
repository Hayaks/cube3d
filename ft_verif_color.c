/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 10:43:08 by jsaguez           #+#    #+#             */
/*   Updated: 2020/07/20 10:43:19 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_verif_color(char **tab, t_struct *info)
{
	if (ft_atoi(tab[0]) < 0 || ft_atoi(tab[0]) > 255)
		ft_error(3, info);
	if (ft_atoi(tab[1]) < 0 || ft_atoi(tab[1]) > 255)
		ft_error(3, info);
	if (ft_atoi(tab[2]) < 0 || ft_atoi(tab[2]) > 255)
		ft_error(3, info);
}
