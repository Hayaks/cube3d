#include "../includes/cub3d.h"

/*void    ft_newinfo(t_struct *info)
{
    ft_bzero(info, sizeof(t_struct));

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
    info->nb = 0;
}*/

void    ft_newmlx(mlx_param *mlx)
{
    mlx->posx = 0;
    mlx->posy = 0;
    mlx->dirx = 0;
    mlx->diry = 0;
    mlx->planex = 0;
    mlx->planey = 0;
    mlx->up = 0;
    mlx->down = 0;
    mlx->left = 0;
    mlx->right = 0;
    mlx->leftr = 0;
    mlx->rightr = 0;
    mlx->v = 0.05;
    mlx->perp = malloc(sizeof(float) * (3000));
}

void    ft_newtext(text_param *text)
{
    text->no = NULL;
    text->nox = 0;
    text->noy = 0;
    text->so = NULL;
    text->sox = 0;
    text->soy = 0;
    text->we = NULL;
    text->wex = 0;
    text->wey = 0;
    text->ea = NULL;
    text->eax = 0;
    text->eay = 0;
    text->s = NULL;
    text->sx = 0;
    text->sy = 0;
    text->c = NULL;
    text->cx = 0;
    text->cy = 0;
    text->f = NULL;
    text->fx = 0;
    text->fy = 0;
}

void    ft_newmap(t_struct *info)
{
    //ft_newinfo(info);
    ft_newmlx(info->mlx);
    ft_newtext(info->text);
}