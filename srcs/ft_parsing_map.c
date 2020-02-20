/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 12:56:07 by jsaguez           #+#    #+#             */
/*   Updated: 2020/01/25 12:56:11 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void ft_setplayer(char *temp, int j, t_struct *info)
{
  if (info->mlx->dirx == 0 && info->mlx->diry == 0)
  {
    info->mlx->posx = info->i + 0.5;
    info->mlx->posy = j + 0.5;

    if (temp[j] == 'N')
		  info->mlx->dirx = -1.0;
	  else if (temp[j] == 'S')
		  info->mlx->dirx = 1.0;
	  else if (temp[j] == 'E')
		  info->mlx->diry = 1.0;
	  else
		  info->mlx->diry = -1.0;
    if (info->mlx->dirx != 0)
		  info->mlx->planey = -info->mlx->dirx;
    else
		  info->mlx->planex = -info->mlx->diry;
  }
  else
    exit(0);
}

void    ft_parsing_map(char *line, t_struct *info)
{
    char  *temp;
    int   j;

    temp = ft_trimset(line, " ");
    j = 0;
    while (temp[j])
    {
      if (!(ft_strchr(MAP, temp[j])))
        exit(0);
      if (ft_strchr(POS, temp[j]))
        ft_setplayer(temp, j, info);
      if (temp[j] == '2')
      {
        if (!(info->sprites[info->nb] = malloc(sizeof(s_param))))
        exit(0);
        info->sprites[info->nb]->x = info->i;
        info->sprites[info->nb]->y = j;
        info->sprites[info->nb]->dist = 0.0;
        info->nb++;
      }
      j++;
    }
    if (info->i == 0)
      if (!(info->map = malloc(sizeof(*info->map) * 30)))
        exit(0);
    info->map[info->i] = ft_strdup(temp);
    if (info->map[info->i][j - 1] != '1')
      exit(0);
    info->i++;
    temp = NULL;
    free(temp);
}
