/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imgaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:12:16 by jsaguez           #+#    #+#             */
/*   Updated: 2020/09/07 15:55:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	*ft_imgaddr(void *img)
{
	int lgthbytes;
	int sizeline;
	int endian;
	int *stockimg;

	lgthbytes = sizeof(int);
	stockimg = (int*)mlx_get_data_addr(img, &lgthbytes, &sizeline, &endian);
	return (stockimg);
}
