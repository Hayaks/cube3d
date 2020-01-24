#include "../includes/cub3d.h"

void    ft_resolution(char *line, t_struct *map, int i)
{
    int j;

    j = 0;
    if (map->r != NULL)
        exit(0);
    map->r = ft_split(&line[i + 1], ' ');
    while (map->r[j])
        j++;
    if (j != 2)
        exit(0);
    printf("r1: %s\n", map->r[0]);
    printf("r2: %s\n", map->r[1]);
}

void    ft_texture(char *line, t_struct *map, int i, char *type)
{
    int j;

    j = 0;
    if (map->type != NULL)
        exit(0);
    map->type = ft_strdup(&line[i + 2]);
    printf("%s: %s\n", type, map->type);
}

void    ft_color(char *line, t_struct *map, int i)
{
    int j;

    j = 0;
    if (map->r != NULL)
        exit(0);
    map->r = ft_split(&line[i + 1], ' ');
    while (map->r[j])
        j++;
    if (j != 2)
        exit(0);
    printf("r1: %s\n", map->r[0]);
    printf("r1: %s\n", map->r[1]);
}

void    ft_options(char *line, t_struct *map, int i)
{
    if (line[i] == 'R')
        ft_resolution(line, map, i);
    if (line[i] == 'N' && line[i + 1] == 'O')
        ft_texture(line, map, i, "no");
    if (line[i] == 'S' && line[i + 1] == 'O')
        ft_texture(line, map, i, "so");
    if (line[i] == 'W' && line[i + 1] == 'E')
        ft_texture(line, map, i, "we");
    if (line[i] == 'E' && line[i + 1] == 'A')
        ft_texture(line, map, i, "ea");
    if (line[i] == 'S' && line[i + 1] == ' ')
        ft_texture(line, map, i, "s");
    if ((line[i] == 'F') || (line[i] == 'C'))
        ft_color(line, map, i);
    //if (line[i] == '1')
        //a voir
}

void    ft_parsing(char *line, t_struct *map)
{
    int i;

    i = 0;
    while (line[i] == ' ')
        i++;
    if (!(line[i]) || !(ft_strchr(OPTIONS, line[i])))
        return ;
    ft_options(line, map, i);
}