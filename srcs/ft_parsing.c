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

char    *ft_trimset(char *str, char *set)
{
    char    *new;
    int     i;
    int     j;
    int     c;

    i = 0;
    j = 0;
    c = 0;
    while (str[i])
    {
        while (set[j] && str[i] != set[j])
            j++;
        if (str[i] != set[j])
            c++;
        i++;
        j = 0;
    }
    i = 0;
    if (!(new = malloc(sizeof(*new) * (c + 1))))
        return (-1);
    c = 0;
    while (str[i])
    {
        while (set[j] && str[i] != set[j])
            j++;
        if (str[i] != set[j])
        {
            new[c] = str[i];
            c++;
        }
        i++;
        j = 0;
    }
    new[c + 1] = '\0';
    return (new);
}

void    ft_errors(char *line, t_struct *info, int i)
{
    if (!(ft_strchr(OPTIONS, line[i])))
            exit(0);
    if ((line[i] == 'R' && info->r != NULL) ||
    (line[i] == 'N' && line[i + 1] == 'O' && info->no != NULL) ||
    (line[i] == 'S' && line[i + 1] == 'O' && info->so != NULL) ||
    (line[i] == 'W' && line[i + 1] == 'E' && info->we != NULL) ||
    (line[i] == 'E' && line[i + 1] == 'A' && info->ea != NULL) ||
    (line[i] == 'S' && line[i + 1] == ' ' && info->s != NULL) ||
    (line[i] == 'F' && info->f != NULL) ||
    (line[i] == 'C' && info->c != NULL))
            exit(0);
    if (line[i] == '1' && (info->r == NULL || info->no == NULL ||
    info->so == NULL || info->we == NULL || info->ea == NULL ||
    info->s == NULL || info->f == NULL || info->c == NULL))
            exit(0);
}

void    ft_resolution(char *line, t_struct *info, int i)
{
    int j;

    j = 0;
    info->r = ft_split(&line[i + 1], ' ');
    while (info->r[j])
        j++;
    if (j != 2)
        exit(0);
}

void    ft_color(char *line, t_struct *info, int i, int type)
{
    int j;

    j = 0;
    if (type == 1)
    {
        ft_trimset(&line[i + 1], " ");
        info->f = ft_split(&line[i + 2], ',');
        while (info->f[j])
            j++;
    }
    else
    {
        ft_trimset(&line[i + 1], " ");
        info->c = ft_split(&line[i + 2], ',');
        while (info->f[j])
            j++;
    }   
    if (j != 3)
        exit(0);
}

void    ft_options(char *line, t_struct *info, int i)
{
    if (line[i] == 'R')
        ft_resolution(line, info, i);
    if (line[i] == 'N' && line[i + 1] == 'O')
        info->no = ft_strtrim(&line[i + 2], " ");
    if (line[i] == 'S' && line[i + 1] == 'O')
        info->so = ft_strtrim(&line[i + 2], " ");
    if (line[i] == 'W' && line[i + 1] == 'E')
        info->we = ft_strtrim(&line[i + 2], " ");
    if (line[i] == 'E' && line[i + 1] == 'A')
        info->ea = ft_strtrim(&line[i + 2], " ");
    if (line[i] == 'S' && line[i + 1] == ' ')
        info->s = ft_strtrim(&line[i + 2], " ");
    if (line[i] == 'F')
        ft_color(line, info, i, 1);
    if (line[i] == 'C')
        ft_color(line, info, i, 2);
}

void    ft_parsing(char *line, t_struct *info)
{
    int i;

    i = 0;
    while (line[i] == ' ')
        i++;
    if (!(line[i]))
        return ;
    ft_errors(line, info, i);
    ft_options(line, info, i);
    ft_parsing_map(line, info);
}
