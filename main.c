#include "./includes/cub3d.h"

void    ft_newmap(t_struct *map)
{
    map->r = NULL;
    map->no = NULL;
    map->so = NULL;
    map->we = NULL;
    map->ea = NULL;
    map->s = NULL;
    map->f = NULL;
    map->c = NULL;
}

int	main(int ac, char **av)
{
	int fd;
    int ret;
    char *line;
    t_struct    *map;

    if (!(map = malloc(sizeof(t_struct))))
        return (-1);
    ft_newmap(map);
    if (ac != 2)
        return (-1);
    else
    {
        fd = open(av[1], O_RDONLY);
        while ((ret = get_next_line(fd, &line)) > 0)
        {
            ft_parsing(line, map);
            free(line);
        }
    }
}