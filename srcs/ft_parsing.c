/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 12:56:22 by jsaguez           #+#    #+#             */
/*   Updated: 2020/01/25 12:56:35 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_verif(char *line, t_struct *info, int i)
{
    if (!(ft_strchr(OPTIONS, line[i])))
            ft_error(3, info);
    if ((line[i] == 'R' && info->x != 0) ||
    (line[i] == 'N' && line[i + 1] == 'O' && info->no != NULL) ||
    (line[i] == 'S' && line[i + 1] == 'O' && info->so != NULL) ||
    (line[i] == 'W' && line[i + 1] == 'E' && info->we != NULL) ||
    (line[i] == 'E' && line[i + 1] == 'A' && info->ea != NULL) ||
    (line[i] == 'S' && line[i + 1] == ' ' && info->s != NULL) ||
    (line[i] == 'F' && info->f != NULL) ||
    (line[i] == 'C' && info->c != NULL))
            ft_error(3, info);
    if (line[i] == '1' && (info->x == 0 || info->no == NULL ||
    info->so == NULL || info->we == NULL || info->ea == NULL ||
    info->s == NULL || info->f == NULL || info->c == NULL))
            ft_error(3, info);
}

void    ft_resolution(char *line, t_struct *info, int i)
{
    char    **temp;
    int     j;

    j = 0;
    temp = ft_split(&line[i + 1], ' ');
    while (temp[j])
        j++;
    if (j != 2)
        ft_error(3, info);
    info->x = ft_atoi(temp[0]);
    info->y = ft_atoi(temp[1]);
    if (info->x > 2560)
        info->x = 2560;
    if (info->y > 1440)
        info->y = 1440;
    if ((info->x % 2) == 1)
        info->x++;
    if ((info->y % 2) == 1)
        info->y++;
    if (info->x <= 0 || info->y <= 0)
        ft_error(3, info);
    j = 0;
    while (temp[j])
    {
        free(temp[j]);
        j++;
    }
    free(temp);
}

/*void    ft_color(char *line, t_struct *info, int i, int type)
{
    char    *temp;
    int     j;

    j = 0;
    if (type == 1)
    {
        temp = ft_trimset(&line[i + 1], " ");
        info->f = ft_split(temp, ',');
        while (info->f[j])
            j++;
    }
    else
    {
        temp = ft_trimset(&line[i + 1], " ");
        info->c = ft_split(temp, ',');
        while (info->c[j])
            j++;
    }
    temp = NULL;
    free(temp);
    if (j != 3)
        exit(0);
}*/

void    ft_options(char *line, t_struct *info, int i)
{
    if (line[i] == 'R')
        ft_resolution(line, info, i);
    else if (line[i] == 'N' && line[i + 1] == 'O')
        info->no = ft_strtrim(&line[i + 2], " ");
    else if (line[i] == 'S' && line[i + 1] == 'O')
        info->so = ft_strtrim(&line[i + 2], " ");
    else if (line[i] == 'W' && line[i + 1] == 'E')
        info->we = ft_strtrim(&line[i + 2], " ");
    else if (line[i] == 'E' && 
    line[i + 1] == 'A')
        info->ea = ft_strtrim(&line[i + 2], " ");
    else if (line[i] == 'S' && line[i + 1] == ' ')
        info->s = ft_strtrim(&line[i + 2], " ");
    else if (line[i] == 'F')
        info->f = ft_strtrim(&line[i + 2], " ");
        //ft_color(line, info, i, 1);
    else if (line[i] == 'C')
        info->c = ft_strtrim(&line[i + 2], " ");
        //ft_color(line, info, i, 2);
    else if (line[i] == '1')
        ft_parsing_map(line, info);
    else
        ft_error(3, info);
}

void    ft_parsing(char *line, t_struct *info)
{
    int i;

    i = 0;
    while (line[i] == ' ')
        i++;
    if (!(line[i]))
        return ;
    ft_verif(line, info, i);
    ft_options(line, info, i);
}
