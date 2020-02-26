#include "./includes/cub3d.h"
#include "./includes/key.h"

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
    ft_verif_map(info);
    while (info->map[0][i] && info->map[0][i] == '1')
        i++;
    if (info->map[0][i] && info->map[0][i] != '1')
            ft_error(2);
    i = 0;
    while (info->map[info->i - 1][i] && info->map[info->i - 1][i] == '1')
        i++;
    if (info->map[info->i - 1][i] && info->map[info->i - 1][i] != '1')
            ft_error(2);
}

void    ft_set_texture(t_struct *info, text_param *text)
{
    info->text->no = ft_imgaddr(mlx_xpm_file_to_image(info->mlx->init, info->no, &text->nox, &text->noy));
    info->text->so = ft_imgaddr(mlx_xpm_file_to_image(info->mlx->init, info->so, &text->sox, &text->soy));
    info->text->we = ft_imgaddr(mlx_xpm_file_to_image(info->mlx->init, info->we, &text->wex, &text->wey));
    info->text->ea = ft_imgaddr(mlx_xpm_file_to_image(info->mlx->init, info->ea, &text->eax, &text->eay));
    info->text->s = ft_imgaddr(mlx_xpm_file_to_image(info->mlx->init, info->s, &text->sx, &text->sy));
    info->text->c = ft_imgaddr(mlx_xpm_file_to_image(info->mlx->init, info->c, &text->cx, &text->cy));
    info->text->f = ft_imgaddr(mlx_xpm_file_to_image(info->mlx->init, info->f, &text->fx, &text->fy));
}

void    ft_mlx(t_struct *info)
{
    info->mlx->init = mlx_init();
    info->mlx->window = mlx_new_window(info->mlx->init, info->x, info->y, "wesh");
    ft_set_texture(info, info->text);
    ft_draw(info, info->mlx, info->d);
    mlx_hook(info->mlx->window, KEYPRESS, KEYPRESSMASK, &ft_presskey, info->mlx);
	mlx_hook(info->mlx->window, KEYRELEASE, KEYRELEASEMASK, &ft_releasekey, info->mlx);
    mlx_loop_hook(info->mlx->init, &ft_update, info);
    mlx_loop(info->mlx->init);
}

int	main(int ac, char **av)
{
	int         fd;
    int         ret;
    char        *line;
    t_struct    *info;

    if (!(info = malloc(sizeof(t_struct))) && ac != 2)
        ft_error(1);
    if (!(info->mlx = malloc(sizeof(mlx_param))))
        ft_error(1);
    if (!(info->text = malloc(sizeof(text_param))))
        ft_error(1);
    if (!(info->sprites = malloc(sizeof(*info->sprites) * (20 + 1))))
        ft_error(1);
    if (!(info->d = malloc(sizeof(draw_param))))
        ft_error(1);
    if (!(info->sp = malloc(sizeof(s_param))))
        ft_error(1);
    ft_newmap(info);
    fd = open(av[1], O_RDONLY);
    ft_map(ret, fd, line, info);
    close(fd);
    ft_mlx(info);
}