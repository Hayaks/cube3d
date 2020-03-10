/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imgaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:12:16 by jsaguez           #+#    #+#             */
/*   Updated: 2020/03/09 14:12:19 by jsaguez          ###   ########.fr       */
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
