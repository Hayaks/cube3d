/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:43:03 by jsaguez           #+#    #+#             */
/*   Updated: 2020/09/24 13:13:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_size(char *str, int size)
{
	str[0] = (unsigned char)(size);
	str[1] = (unsigned char)(size >> 8);
	str[2] = (unsigned char)(size >> 16);
	str[3] = (unsigned char)(size >> 24);
}

void	ft_screen(t_struct *info)
{
	int						i;
	int						j;
	static unsigned char	rgb[3];

	i = 0;
	ft_bzero(rgb, sizeof(*rgb) * 3);
	while (i < (info->y - 1))
	{
		j = 0;
		while (j < info->x)
		{
			rgb[0] = ((info->d->img[((info->y - 1) - i) *
			(info->x) + j]) >> 16);
			rgb[1] = ((info->d->img[((info->y - 1) - i) * (info->x) + j]) >> 8);
			rgb[2] = (info->d->img[((info->y - 1) - i) * (info->x) + j]);
			if (write(info->fd, rgb + 2, 1) < 0)
				ft_error(4, info);
			if (write(info->fd, rgb + 1, 1) < 0)
				ft_error(4, info);
			if (write(info->fd, rgb, 1) < 0)
				ft_error(4, info);
			j++;
		}
		i++;
	}
}

void	ft_header_file(t_struct *info)
{
	int		size;
	char	header[14];

	ft_bzero(header, sizeof(*header) * 14);
	size = 54 + (3 * info->x + ((4 - (info->x * 3) % 4) % 4) * info->y);
	header[0] = 'B';
	header[1] = 'M';
	ft_size(header + 2, size);
	ft_size(header + 10, 54);
	if (write(info->fd, header, 14) < 0)
		ft_error(4, info);
}

void	ft_header_img(t_struct *info)
{
	char	header[40];

	ft_bzero(header, sizeof(*header) * 40);
	ft_size(header, 40);
	ft_size(header + 4, info->x);
	ft_size(header + 8, info->y);
	header[12] = (unsigned char)1;
	ft_size(header + 14, 24);
	if (write(info->fd, header, 40) < 0)
		ft_error(4, info);
}

void	ft_bmp(t_struct *info)
{
	mlx_destroy_window(info->mlx->init, info->mlx->window);
	if ((info->fd = open(BMP, O_CREAT | O_WRONLY, 0777)) < 0)
		ft_error(4, info);
	ft_header_file(info);
	ft_header_img(info);
	ft_screen(info);
	close(info->fd);
	ft_error(4, info);
}
