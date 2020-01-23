#include "../includes/cub3d.h"

void ft_options(char *line, t_struct *map, int i)
{
    if (line[i] == 'R')
        map->r = ft_split(line, ' ');
    if (line[i] == 'N' && line[i + 1] == 'O')
        map->no = ft_strdup(line);
    if (line[i] == 'S' && line[i + 1] == 'O')
        map->so = ft_strdup(line);
    if (line[i] == 'W' && line[i + 1] == 'E')
        map->we = ft_strdup(line);
    if (line[i] == 'E' && line[i + 1] == 'A')
        map->ea = ft_strdup(line);
    if (line[i] == 'F')
        map->r = ft_split(line, ',');
    if (line[i] == 'C')
        map->r = ft_split(line, ',');
    //if (line[i] == '1')
        //a voir
}

void ft_parsing(char *line, t_struct *map)
{
    int i;

    i = 0;
    while (line[i] == ' ')
        i++;
    if (line[i] == '/0' || line[i] != OPTIONS)
        return ;
    ft_options(line, map, i);
}