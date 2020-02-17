#include "./includes/cub3d.h"
#include "./includes/key.h"

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
    info->nbsprites = 0;

    info->mlx->posx = 0;
    info->mlx->posy = 0;
    info->mlx->dirx = 0;
    info->mlx->diry = 0;
    info->mlx->planex = 0;
    info->mlx->planey = 0;
    info->mlx->up = 0;
    info->mlx->down = 0;
    info->mlx->left = 0;
    info->mlx->right = 0;
    info->mlx->leftr = 0;
    info->mlx->rightr = 0;
    info->mlx->v = 0.05;
    info->mlx->perp = malloc(sizeof(float) * (3000));

    info->text->no = NULL;
    info->text->nox = 0;
    info->text->noy = 0;
    info->text->so = NULL;
    info->text->sox = 0;
    info->text->soy = 0;
    info->text->we = NULL;
    info->text->wex = 0;
    info->text->wey = 0;
    info->text->ea = NULL;
    info->text->eax = 0;
    info->text->eay = 0;
    info->text->s = NULL;
    info->text->sx = 0;
    info->text->sy = 0;
    info->text->c = NULL;
    info->text->cx = 0;
    info->text->cy = 0;
    info->text->f = NULL;
    info->text->fx = 0;
    info->text->fy = 0;
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
    ft_draw(info);
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
        return (-1);
    if (!(info->mlx = malloc(sizeof(mlx_param))))
        return (-1);
    if (!(info->text = malloc(sizeof(text_param))))
        return (-1);
    ft_newmap(info);
    if (!(info->sprites = malloc(sizeof(*info->sprites) * (info->nbsprites + 1))))
        return (-1);
    if (!(info->sprites[0] = malloc(sizeof(s_param))))
        return (-1);
    info->sprites[0]->x = 3;/*rajouter une fonction pour ajouter un sprite a retenir*/
    info->sprites[0]->y = 3;
    fd = open(av[1], O_RDONLY);
    ft_map(ret, fd, line, info);
    close(fd);
    ft_mlx(info);
}