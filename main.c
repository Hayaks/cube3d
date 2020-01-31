#include "./includes/cub3d.h"

void    ft_newmap(t_struct *info)
{
    info->x = 0;
    info->y = 0;
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
    info->mlx->posx = 0;
    info->mlx->posy = 0;
    info->mlx->dirx = 0;
    info->mlx->diry = 0;
    info->mlx->planex = 0;
    info->mlx->planey = 0;
}

void    ft_map(int ret, int fd, char *line, t_struct *info)
{
    int i;

    i = 0;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        ft_parsing(line, info);
        free(line);
    }
    if (ret == 0)
    {
        ft_parsing(line, info);
        free(line);
    }
    while (info->map[0][i])
    {
        if (info->map[0][i] != '1' ||
        info->map[info->i - 1][i] != '1')
            exit(0);
        i++;
    }
}

void    ft_draw(t_struct *info)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x <= info->x)
    {
        while (y <= info->y)
        {
            mlx_pixel_put(info->mlx->init, info->mlx->window, x, y, 0xB9EDF0);
            y++;
        }
        y = 0;
        x++;
    }   
}

void    ft_mlx(t_struct *info)
{
    info->mlx->init = mlx_init();
    info->mlx->window = mlx_new_window(info->mlx->init, info->x, info->y, "wesh");
    info->mlx->img = mlx_new_image(info->mlx->init, info->x, info->y);
    ft_draw(info);
    mlx_loop(info->mlx->init);
}

int	main(int ac, char **av)
{
	int         fd;
    int         ret;
    char        *line;
    t_struct    *info;

    if (!(info = malloc(sizeof(*info))) && ac != 2)
        return (-1);
    else
    {
        if(!(info->mlx = malloc(sizeof(mlx_param))))
            return (-1);
        ft_newmap(info);
        fd = open(av[1], O_RDONLY);
        ft_map(ret, fd, line, info);
        close(fd);
    }
    ft_mlx(info);
    printf("r1: %d\n", info->x);
    printf("r2: %d\n", info->y);
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
    printf("%s\n", info->map[0]);
    printf("%s\n", info->map[1]);
    printf("%s\n", info->map[2]);
    printf("%s\n", info->map[3]);
    printf("%s\n", info->map[4]);
    printf("%s\n", info->map[5]);
    printf("%s\n", info->map[6]);
    printf("i: %d\n", info->i);
    printf("len: %d\n", info->len);
    printf("posx: %f\n", info->mlx->posx);
    printf("posy: %f\n", info->mlx->posy);
    printf("dirx: %f\n", info->mlx->dirx);
    printf("diry: %f\n", info->mlx->diry);
    printf("planex: %f\n", info->mlx->planex);
    printf("planey: %f\n", info->mlx->planey);
}