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
    printf("r1: %s\n", map->r[1]);
}

void    ft_texture(char *line, t_struct *map, int i)
{
    int j;

    j = 0;
    if (map->no != NULL)
        exit(0);
    map->no = ft_strdup(&line[i + 2]);
    printf("nord: %s\n", map->no);
}

void    ft_options(char *line, t_struct *map, int i)
{
    if (line[i] == 'R')
        ft_resolution(line, map, i);
    if ((line[i] == 'N' && line[i + 1] == 'O') ||
    (line[i] == 'S' && line[i + 1] == 'O') ||
    (line[i] == 'W' && line[i + 1] == 'E') ||
    (line[i] == 'E' && line[i + 1] == 'S') ||
    (line[i] == 'S' && line[i + 1] == ' '))
        ft_texture(line, map, i);
    //if ((line[i] == 'F') || (line[i] == 'C'))
      //  map->r = ft_color(line, ',');
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