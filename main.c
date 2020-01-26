#include "./includes/cub3d.h"

void    ft_newmap(t_struct *info)
{
    info->r = NULL;
    info->no = NULL;
    info->so = NULL;
    info->we = NULL;
    info->ea = NULL;
    info->s = NULL;
    info->f = NULL;
    info->c = NULL;
    info->map = NULL;
    info->i = 0;
    info->len = 0;
}

int	main(int ac, char **av)
{
	int         fd;
    int         ret;
    char        *line;
    t_struct    *info;

    if (!(info = malloc(sizeof(*info))))
        return (-1);
    ft_newmap(info);
    if (ac != 2)
        return (-1);
    else
    {
        fd = open(av[1], O_RDONLY);
        while ((ret = get_next_line(fd, &line)) > 0)
        {
            ft_parsing(line, info);
            free(line);
        }
    }
    printf("r1: %s\n", info->r[0]);
    printf("r2: %s\n", info->r[1]);
    printf("no: %s\n", info->no);
    printf("so: %s\n", info->so);
    printf("we: %s\n", info->we);
    printf("ea: %s\n", info->ea);
    printf("s: %s\n", info->s);
    printf("f1: %s\n", info->f[0]);
    printf("f2: %s\n", info->f[1]);
    printf("f3: %s\n", info->f[2]);
    printf("c1: %s\n", info->c[0]);
    printf("c2: %s\n", info->c[1]);
    printf("c3: %s\n", info->c[2]);
}