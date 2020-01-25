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
    map->map = NULL;
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
    printf("r1: %s\n", map->r[0]);
    printf("r2: %s\n", map->r[1]);
    printf("no: %s\n", map->no);
    printf("so: %s\n", map->so);
    printf("we: %s\n", map->we);
    printf("ea: %s\n", map->ea);
    printf("s: %s\n", map->s);
    printf("f1: %s\n", map->f[0]);
    printf("f2: %s\n", map->f[1]);
    printf("f3: %s\n", map->f[2]);
    printf("c1: %s\n", map->c[0]);
    printf("c2: %s\n", map->c[1]);
    printf("c3: %s\n", map->c[2]);
}