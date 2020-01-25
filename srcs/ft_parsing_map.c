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
    int j;

    ft_strtrim(line, " ");
    //info->map[info->i] = ft_strdup(line);
    //if(info->i == 0)
      //  info->len = ft_strlen(info->map[info->i]);
    info->i++;
    j = 0;
   /* while (info->map[info->i][j])
    {
        if (info->map[info->i][j] != )
            exit(0);
    }*/
}
