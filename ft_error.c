/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:12:03 by jsaguez           #+#    #+#             */
/*   Updated: 2020/08/17 11:52:46 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_free_s(t_struct *info)
{
	int i;

	i = 0;
	while (i < info->nb)
	{
		if (info->sprites[i] != NULL)
			free(info->sprites[i]);
		i++;
	}
	free(info->sprites);
}

void	ft_free_text(t_text *text)
{
	free(text);
}

void	ft_free_info(t_struct *info)
{
	int i;

	i = 0;
	while (i < info->i)
	{
		if (info->map[i] != NULL)
			free(info->map[i]);
		i++;
	}
	if (info->map != NULL)
		free(info->map);
	if (info->no != NULL)
		free(info->no);
	if (info->so != NULL)
		free(info->so);
	if (info->we != NULL)
		free(info->we);
	if (info->ea != NULL)
		free(info->ea);
	if (info->s != NULL)
		free(info->s);
	if (info->f != NULL)
		free(info->f);
	if (info->c != NULL)
		free(info->c);
}

void	ft_free_mlx(t_mlx *mlx, int i)
{
	if (mlx->perp != NULL)
		free(mlx->perp);
	if (i == 5)
	{
		mlx_destroy_image(mlx->init, mlx->img);
		mlx_destroy_window(mlx->init, mlx->window);
	}
	free(mlx);
}

int		ft_error(int i, t_struct *info)
{
	if (i > 0 && i != 5)
		write(1, "Erreur\n", 8);
	if (i < 0 || i > 5)
		exit(0);
	if (i == 1)
		write(1, "Probleme de malloc\n", 20);
	if (i == 2)
		write(1, "Mauvaise map\n", 14);
	if (i == 3)
		write(1, "Mauvais argument\n", 18);
	if (i == 4)
		write(1, "BMP\n", 5);
	free(info->sp);
	free(info->d);
	ft_free_s(info);
	ft_free_text(info->text);
	ft_free_mlx(info->mlx, i);
	ft_free_info(info);
	free(info);
	exit(0);
	return (1);
}
