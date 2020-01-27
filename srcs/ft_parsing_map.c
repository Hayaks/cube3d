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

void    ft_parsing_map(char *line, t_struct *info)
{
    char  *temp;
    int   j;

    //temp = ft_trimset(line, " ");
    temp = ft_strdup(line);
    if(!(info->map = malloc(sizeof(*info->map) * 10)))
      exit(0);
    info->map[info->i] = ft_strdup(temp);
    if(info->i == 0)
        info->len = ft_strlen(info->map[info->i]);
    printf("info->i: %d \n", info->i);
    j = 0;
    printf("map: %s \n", info->map[info->i]);
    /*while (info->map[info->i][j])
    {
      if (!(ft_strchr(OPTIONS, info->map[info->i][j])))
        exit(0);
      j++;
    }*/
    info->i++;
}
