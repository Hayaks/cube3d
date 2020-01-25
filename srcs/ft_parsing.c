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

void    ft_errors(char *line, t_struct *map, int i)
{
    if (!(ft_strchr(OPTIONS, line[i])))
            exit(0);
    if ((line[i] == 'R' && map->r != NULL) ||
    (line[i] == 'N' && line[i + 1] == 'O' && map->no != NULL) ||
    (line[i] == 'S' && line[i + 1] == 'O' && map->so != NULL) ||
    (line[i] == 'W' && line[i + 1] == 'E' && map->we != NULL) ||
    (line[i] == 'E' && line[i + 1] == 'A' && map->ea != NULL) ||
    (line[i] == 'S' && line[i + 1] == ' ' && map->s != NULL) ||
    (line[i] == 'F' && map->f != NULL) ||
    (line[i] == 'C' && map->c != NULL))
            exit(0);
    if (line[i] == '1' && (map->r == NULL || map->no == NULL ||
    map->so == NULL || map->we == NULL || map->ea == NULL ||
    map->s == NULL || map->f == NULL || map->c == NULL))
            exit(0);
}

void    ft_resolution(char *line, t_struct *map, int i)
{
    int j;

    j = 0;
    map->r = ft_split(&line[i + 1], ' ');
    while (map->r[j])
        j++;
    if (j != 2)
        exit(0);
}

void    ft_color(char *line, t_struct *map, int i, int type)
{
    int j;

    j = 0;
    if (type == 1)
    {
        ft_strtrim(&line[i + 1], " ");
        map->f = ft_split(&line[i + 2], ',');
        while (map->f[j])
            j++;
    }
    else
    {
        ft_strtrim(&line[i + 1], " ");
        map->c = ft_split(&line[i + 2], ',');
        while (map->f[j])
            j++;
    }
    
    if (j != 3)
        exit(0);
}

void    ft_options(char *line, t_struct *map, int i)
{
    if (line[i] == 'R')
        ft_resolution(line, map, i);
    if (line[i] == 'N' && line[i + 1] == 'O')
        map->no = ft_strtrim(&line[i + 2], " ");
    if (line[i] == 'S' && line[i + 1] == 'O')
        map->so = ft_strtrim(&line[i + 2], " ");
    if (line[i] == 'W' && line[i + 1] == 'E')
        map->we = ft_strtrim(&line[i + 2], " ");
    if (line[i] == 'E' && line[i + 1] == 'A')
        map->ea = ft_strtrim(&line[i + 2], " ");
    if (line[i] == 'S' && line[i + 1] == ' ')
        map->s = ft_strtrim(&line[i + 2], " ");
    if (line[i] == 'F')
        ft_color(line, map, i, 1);
    if (line[i] == 'C')
        ft_color(line, map, i, 2);
}

void    ft_parsing(char *line, t_struct *map)
{
    int i;

    i = 0;
    while (line[i] == ' ')
        i++;
    if (!(line[i]))
        return ;
    ft_errors(line, map, i);
    ft_options(line, map, i);
    ft_parsing_map(line, map);
}
