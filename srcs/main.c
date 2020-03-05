#include "../includes/cub3d.h"
#include "../includes/key.h"

void    ft_map(int ret, int fd, char *line, t_struct *info)
{
    int i;

    i = 0;
    info->nb = 0;
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
    ft_verif_map(info);
    while (info->map[0][i] && info->map[0][i] == '1')
        i++;
    if (info->map[0][i] && info->map[0][i] != '1')
            ft_error(2, info);
    i = 0;
    while (info->map[info->i - 1][i] && info->map[info->i - 1][i] == '1')
        i++;
    if (info->map[info->i - 1][i] && info->map[info->i - 1][i] != '1')
            ft_error(2, info);
}

void    ft_mlx(t_struct *info, char **av)
{
    int         fd;
    int         ret;
    char        *line;

    ret = 0;
    line = NULL;
    fd = open(av[1], O_RDONLY);
    ft_map(ret, fd, line, info);
    close(fd);
    info->mlx->init = mlx_init();
    info->mlx->window = mlx_new_window(info->mlx->init, info->x, info->y, "wesh");
    ft_set_texture(info, info->text);
    ft_draw(info, info->mlx, info->d);
    mlx_hook(info->mlx->window, KEYPRESS, KEYPRESSMASK, &ft_presskey, info);
	mlx_hook(info->mlx->window, KEYRELEASE, KEYRELEASEMASK, &ft_releasekey, info);
    mlx_hook(info->mlx->window, DESTROYNOTIFY, STRUCTURENOTIFYMASK, &ft_error, info);
    mlx_loop_hook(info->mlx->init, &ft_update, info);
    mlx_loop(info->mlx->init);
}

void    ft_nbsprites(t_struct *info, char **av)
{
    int         fd;
    int         ret;
    char        *line;
    int         j;

    ret = 0;
    line = NULL;
    fd = open(av[1], O_RDONLY);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        j = 0;
        if (line[j] == '1')
            while (line[j])
            {
                if (line[j] == '2')
                    info->nb++;
                j++;
            }
        free(line);
    }
    close(fd);
}

void    ft_verif_arg(t_struct *info, char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    i = i - 4;
    if (ft_strncmp(&str[i], ARG, ft_strlen(ARG)))
        ft_error(3, info);
}

int	    main(int ac, char **av)
{
    t_struct    *info;

    if (!(info = malloc(sizeof(t_struct))) && (ac != 2 || ac != 3))
        ft_error(1, info);
    ft_bzero(info, sizeof(t_struct));
    info->ac = ac;
    ft_nbsprites(info, av);
    if (!(info->mlx = malloc(sizeof(mlx_param))))
        ft_error(1, info);
    if (!(info->text = malloc(sizeof(text_param))))
        ft_error(1, info);
    if (!(info->sprites = malloc(sizeof(*info->sprites) * (info->nb * 2))))
        ft_error(1, info);
    if (!(info->d = malloc(sizeof(draw_param))))
        ft_error(1, info);
    if (!(info->sp = malloc(sizeof(s_param))))
        ft_error(1, info);
    ft_newmap(info);
    ft_verif_arg(info, av[1]);
    if (ac == 3 && ft_strncmp(av[2], SAVE, ft_strlen(SAVE)))
        ft_error(3, info);
    ft_mlx(info, av);
    return (0);
}