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

    temp = ft_trimset(line, " ");
    j = 0;
    while (temp[j])
    {
      if (!(ft_strchr(MAP, temp[j])))
        exit(0);
      j++;
    }
    if (info->i == 0)
      if (!(info->map = malloc(sizeof(*info->map) * 10)))
        exit(0);
    info->map[info->i] = ft_strdup(temp);
    if (info->i == 0)
        info->len = ft_strlen(info->map[info->i]);
    info->i++;
    temp = NULL;
    free(temp);
}
